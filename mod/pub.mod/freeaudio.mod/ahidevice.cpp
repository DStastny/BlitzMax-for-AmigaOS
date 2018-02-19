// ahidevice.cpp
#if  __amigaos4__
#include "freeaudio.h"
#include <unistd.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <devices/ahi.h>
//#include <stdio.h>

extern "C" audiodevice *OpenAHIDevice();

#define BUFFERSIZE 2048

int32 audioprocess(void);

struct ahiaudio:audiodevice{
	struct Process *maintask;
	struct Process *audiotask;
	int32			running,playing;

	struct MsgPort       *ahiReplyPort;
    struct AHIRequest    *ahiRequest[2];
    uint32                ahiType;
    int32                 currentBuffer; 
    struct AHIRequest    *link;          
    int16               *audioBuffer[2];
	int32				buffersize;

	void dlog(char* txt) 
	{
	//	printf("Free Audio - AHI: %s\n",txt);
	}


	ahiaudio() : audiodevice()
	{
		dlog("ahiaudio()");
		maintask = NULL;
		audiotask = NULL;
		running = playing = 0;
		ahiReplyPort = NULL;
    	ahiRequest[0] = NULL;
		ahiRequest[1] = NULL;
    	ahiType = AHIST_S16S;
     	currentBuffer = 0; 
    	link = NULL;          
    	audioBuffer[0] = NULL;
    	audioBuffer[1] = NULL;
		buffersize = 0;	
	}

	int opendevice()
	{
		dlog("opendevice");
		if (ahiReplyPort = (struct MsgPort *)IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE)) {
            if (ahiRequest[0] = (struct AHIRequest *)IExec->AllocSysObjectTags(ASOT_IOREQUEST, ASOIOR_ReplyPort, ahiReplyPort,
                			ASOIOR_Size,      sizeof(struct AHIRequest), TAG_DONE)) {
            	if (!IExec->OpenDevice(AHINAME, 0, (struct IORequest *) ahiRequest[0], 0)) {
                	if (ahiRequest[1] = (struct AHIRequest *) IExec->AllocSysObjectTags(ASOT_IOREQUEST, ASOIOR_Duplicate, ahiRequest[0], TAG_DONE)) {
                    	currentBuffer = 0;
                    	link = NULL;
						dlog("AHI Device open success!");
						return 1;
					}
                }
            }
        } 
		dlog("AHI Device open failed!");
		return 0;
    }
   
	void closedevice()
	{
		dlog("closedevice");
    	if (ahiRequest[0]) {
        	if (link) {
            	IExec->AbortIO((struct IORequest *)link);
            	IExec->WaitIO((struct IORequest *)link);
        	}
        	IExec->CloseDevice((struct IORequest *)ahiRequest[0]);
        	IExec->FreeSysObject(ASOT_IOREQUEST, ahiRequest[0]);
        	ahiRequest[0] = NULL;

        	if (ahiRequest[1]) {
            	IExec->FreeSysObject(ASOT_IOREQUEST, ahiRequest[1]);
            	ahiRequest[1] = NULL;
        	}
    	}

    	if (ahiReplyPort) {
        	IExec->FreeSysObject(ASOT_PORT, ahiReplyPort);
        	ahiReplyPort = NULL;
    	}
    }


	int reset()
	{
		dlog("reset");
		maintask = (struct Process *)IExec->FindTask(NULL);
		running=0;
		playing=0;
		mix=new mixer(BUFFERSIZE);
		audioBuffer[0] = new int16[BUFFERSIZE];
		audioBuffer[1] = new int16[BUFFERSIZE];
		buffersize=BUFFERSIZE*2;
		if (mix && audioBuffer[0] && audioBuffer[1]){
			dlog("buffers allocated");
			mix->freq=44100;
			mix->channels=2;
			if (audiotask = IDOS->CreateNewProcTags(
                    NP_Entry,       audioprocess,  
                    NP_Name,        "FreeAudio AHI mixer",
                    NP_FreeSeglist, FALSE,
                    NP_Child,       TRUE,
					NP_UserData, (int)this,
                    TAG_END)) {
				IExec->SetSignal(0, SIGF_SINGLE);  
            	IExec->Signal((struct Task *)audiotask, SIGBREAKF_CTRL_F); 
            	IExec->Wait(SIGF_SINGLE); 
				dlog("audiotask setup complete");
			}
			else {
				dlog("failed to create process");	
			}
		}	
		return running ? 0 : -1;
	}
	
	int close()
	{	
		dlog("close");
		int	timeout;
		timeout=5;
		running=0;
		while (timeout-- && playing) sleep(1);
		if (mix) {
			delete mix;
			mix=NULL;
		}
		if (audioBuffer[0]){
			delete []audioBuffer[0]; 
			audioBuffer[0] = NULL;
		}
		if (audioBuffer[1]){
			delete []audioBuffer[1]; 
			audioBuffer[1] = NULL;
		} 
		dlog("cleaned up");
		return 0;
	}

	void Run()
	{
		IExec->Wait(SIGBREAKF_CTRL_F);
		dlog("running mixer");
		//open up device
		// if ok set running true
		// signal caller
		playing=running=opendevice();
		IExec->Signal((struct Task *)maintask, SIGF_SINGLE);
		while (playing && running) {
		    struct AHIRequest  *req;
			req =  ahiRequest[currentBuffer];
    		req->ahir_Std.io_Message.mn_Node.ln_Pri = 60;
    		req->ahir_Std.io_Data    = audioBuffer[currentBuffer];
    		req->ahir_Std.io_Length  = buffersize;
    		req->ahir_Std.io_Offset  = 0;
    		req->ahir_Std.io_Command = CMD_WRITE;
    		req->ahir_Volume         = 0x10000;
    		req->ahir_Position       = 0x8000;
    		req->ahir_Link           = link;
    		req->ahir_Frequency      = 44100;
    		req->ahir_Type           = ahiType;



			mix->mix16(audioBuffer[currentBuffer]);
			IExec->SendIO((struct IORequest *)req);
    		if (link) {
        		IExec->WaitIO((struct IORequest *)link);
    		}
    		link = req;
			currentBuffer = 1-currentBuffer;
		}
		// if device opened close it and clean up
		if (playing) {
			closedevice();
			playing = 0;
		}
		dlog("cleaning up");
	}
};

int32 audioprocess()
{
	struct Process *p = (struct Process *)IExec->FindTask(NULL);
	((struct ahiaudio *)p->pr_Task.tc_UserData)->Run();
	return 0;
}

audiodevice *OpenAHIDevice(){
	return new ahiaudio();
}

#endif


