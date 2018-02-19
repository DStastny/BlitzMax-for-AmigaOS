#include <brl.mod/system.mod/system.h>
#include <devices/timer.h>

void brl_timer__TimerFired( BBObject *bbTimer );

struct TimerEvent {
	struct TimeRequest  TR;
	uint32 Period;
	BBObject *bbTimer;
};

#define MAX_TIMERS 16


struct AmigaTimerContext {
	int TimerDeviceOpened;
	struct Process *TimerTask;
	struct Process *ParentTask;
	struct MsgPort *TimerUserPort;
	struct MsgPort *DeathPort;
	struct DeathMessage *DeathMsg;
	struct TimerEvent *TimerEvents[MAX_TIMERS];
	int ActiveTimers;
};

static struct AmigaTimerContext atc;

static void timerSyncOp(BBObject *bbTimer,int timer )
{
	int i;
	for(i=0;i<atc.ActiveTimers && timer!=(int)atc.TimerEvents[i];++i ) {}
	if( i<atc.ActiveTimers) brl_timer__TimerFired( bbTimer );
}

static int32 timerEventDispatcher(STRPTR *args UNUSED, int32 arglen UNUSED, struct ExecBase *sysbase)
{
	struct ExecIFace *IExec = (APTR)sysbase->MainInterface;
	// create port
	atc.TimerUserPort=IExec->AllocSysObject(ASOT_PORT, NULL);
	// signal parent to check port
	IExec->Signal((struct Task*)atc.ParentTask, SIGBREAKF_CTRL_F);
	// if have port start waiting for time events
	if(atc.TimerUserPort != NULL) {
		uint32 waitMask =(1  << atc.TimerUserPort->mp_SigBit) |  SIGBREAKF_CTRL_C;  
		for(;;) {
			int sig = IExec->Wait(waitMask) ;
			if (sig & SIGBREAKF_CTRL_C) {
				while (IExec->GetMsg(atc.TimerUserPort)!=NULL) ;
				break;
			}
			struct TimerEvent *event;
			while((event= IExec->GetMsg(atc.TimerUserPort)) !=NULL) {
				if (event->bbTimer) {
					event->TR.Time.Microseconds  =  event->Period;
					bbSystemPostSyncOp( timerSyncOp,(BBObject*)event->bbTimer,(int)event);
					IExec->SendIO((struct IORequest *)event);	
				}
			}			
		}

		int i;
		for(i=0;i<atc.ActiveTimers;++i ) {
			if (atc.TimerEvents[i]) {
				IExec->AbortIO(atc.TimerEvents[i]);
			}
		}
		
		IExec->FreeSysObject(ASOT_PORT, atc.TimerUserPort);
		atc.TimerUserPort = NULL;
	}	
	return(RETURN_OK);
}

static void amiga_TimerCleanup()
{
	if(atc.TimerTask!=NULL) {
		if (atc.TimerUserPort!=NULL)	{ 
			IExec->Signal(atc.TimerTask, SIGBREAKF_CTRL_C);
	        	IExec->WaitPort(atc.DeathPort);
	             	IExec->GetMsg(atc.DeathPort);
	          }
		atc.TimerTask=NULL;
	}
	if (atc.DeathMsg!=NULL){
		IExec->FreeSysObject(ASOT_MESSAGE, atc.DeathMsg);
		atc.DeathMsg=NULL;
	}
	if (atc.DeathPort != NULL){
		IExec->FreeSysObject(ASOT_PORT, atc.DeathPort);
		atc.DeathPort=NULL;
	}
	if (atc.TimerDeviceOpened!=0) {
		int i;
		for( i=1;i<MAX_TIMERS;++i ) {
			if (atc.TimerEvents[i]) { 
				IExec->FreeSysObject(ASOT_IOREQUEST, atc.TimerEvents[i]);
				atc.TimerEvents[i] = NULL;
			}
		}				
		IExec->CloseDevice((struct IORequest *)atc.TimerEvents[0]);
		atc.TimerDeviceOpened=0;
	}
        if (atc.TimerEvents[0] != NULL){
		IExec->FreeSysObject(ASOT_IOREQUEST, atc.TimerEvents[0]);
		atc.TimerEvents[0] = NULL;
	}
}

static fail(char* msg)
{
	IDOS->Printf(msg);
	abort();
}

static void amiga_TimerInit()
{
	if (atc.TimerDeviceOpened != 0){
	 	return;
	}
	atexit(amiga_TimerCleanup);

	atc.ParentTask= IExec->FindTask(0);
 	if((atc.DeathPort = IExec->AllocSysObject(ASOT_PORT, NULL)) !=NULL) {
  		atc.DeathMsg = IExec->AllocSysObjectTags(ASOT_MESSAGE,
          		ASOMSG_Size, sizeof(struct DeathMessage),
          		ASOMSG_ReplyPort, atc.DeathPort,
          		TAG_END);
		if (atc.DeathMsg != NULL) {
			if((atc.TimerTask = IDOS->CreateNewProcTags(NP_Entry,timerEventDispatcher,
	                 	           NP_Child, TRUE,
	                 	           NP_EntryData, IDOS, /* passed to child */
	                 	           NP_NotifyOnDeathMessage,atc.DeathMsg, TAG_DONE)) != NULL) {
				IExec->Wait(SIGBREAKF_CTRL_F);
				if (atc.TimerUserPort) {
					if((atc.TimerEvents[0]  = IExec->AllocSysObjectTags(ASOT_IOREQUEST,
							ASOIOR_Size, sizeof(struct TimerEvent),
							ASOIOR_ReplyPort, atc.TimerUserPort,
							TAG_END)) != NULL) {
						atc.TimerDeviceOpened = IExec->OpenDevice( TIMERNAME, UNIT_MICROHZ,
										(struct IORequest *) atc.TimerEvents[0], 0L) == 0;

						if (atc.TimerDeviceOpened){
							int i;
							for( i=1;i<MAX_TIMERS;++i ) {
								if ((atc.TimerEvents[i] = IExec->AllocSysObjectTags(ASOT_IOREQUEST,
									ASOIOR_Duplicate, atc.TimerEvents[0],
									TAG_END))==NULL) {
									fail("failed to duplicate events\n");
								}
							}
							return;
						}
						fail("failed to open timer device\n");
					}
					fail("failed to create timer events\n");
				}
				fail("failed to create timer userport\n");
			}
			fail("failed to create timer thread\n");
		}
		fail("failed to create death message\n");
	}
	fail("failed to create death reply port\n");
}

int bbTimerStart( float hertz,BBObject *bbTimer )
{	
	if(atc.ActiveTimers==MAX_TIMERS ){
		return 0;
	}

	amiga_TimerInit();
	struct TimerEvent* ev  = atc.TimerEvents[atc.ActiveTimers++];
	ev->bbTimer = bbTimer;
	ev->Period = 1000000 / hertz;
	ev->TR.Request.io_Command = TR_ADDREQUEST;
	ev->TR.Time.Seconds       =  0;
	ev->TR.Time.Microseconds  = ev->Period ;
	IExec->SendIO((struct IORequest *)ev);
	BBRETAIN( bbTimer );
	return (int)ev;
}

void bbTimerStop( int timer,BBObject *bbTimer )
{
	int i;

	for( i=0;i<atc.ActiveTimers && timer!=(int)atc.TimerEvents[i];++i ) {}
	if( i==atc.ActiveTimers){
		return;
	}

	struct TimerEvent* ev  = atc.TimerEvents[i];
	int j =atc.ActiveTimers;
	atc.TimerEvents[i] = atc.TimerEvents[--atc.ActiveTimers];
	atc.TimerEvents[j] = ev;
	IExec->AbortIO(ev);
	ev->bbTimer = NULL;

	BBRELEASE( bbTimer );

}

