#include "system.h"
#include <pthread.h>
#include <intuition/pointerclass.h>
#include <brl.mod/keycodes.mod/keycodes.h>



#include <stdlib.h>
#include <string.h>
#include <devices/input.h>
#include <devices/inputevent.h>

#define KEY_CAPSLOCK 20
#define KEY_SCROLLOCK  145
#define KEY_MENU  0
#define KEY_PAUSE 19
#define KEY_PRINT 42
#define KEY_NUMLEFTPAREN 0
#define KEY_NUMRIGHTPAREN 0

#define KEY_UNKNOWN 0
#define KEY_INTERNATIONAL1 0
#define KEY_INTERNATIONAL2 0
#define KEY_INTERNATIONAL3 0

static int const SCANCODES[] = {
    /*  0 */    KEY_TILDE,
    /*  1 */    KEY_1,
    /*  2 */    KEY_2,
    /*  3 */    KEY_3,
    /*  4 */    KEY_4,
    /*  5 */    KEY_5,
    /*  6 */    KEY_6,
    /*  7 */    KEY_7,
    /*  8 */    KEY_8,
    /*  9 */     KEY_9,
    /*  10 */    KEY_0,
    /*  11 */    KEY_MINUS,
    /*  12 */    KEY_EQUALS,
    /*  13 */    KEY_BACKSLASH,
    /*  14 */    KEY_INTERNATIONAL3,
    /*  15 */    KEY_NUM0,
    /*  16 */    KEY_Q,
    /*  17 */    KEY_W,
    /*  18 */    KEY_E,
    /*  19 */    KEY_R,
    /*  20 */    KEY_T,
    /*  21 */    KEY_Y,
    /*  22 */    KEY_U,
    /*  23 */    KEY_I,
    /*  24 */    KEY_O,
    /*  25 */    KEY_P,
    /*  26 */    KEY_OPENBRACKET,
    /*  27 */    KEY_CLOSEBRACKET,
    /*  28 */    KEY_UNKNOWN,
    /*  29 */    KEY_NUM1,
    /*  30 */    KEY_NUM2,
    /*  31 */    KEY_NUM3,
    /*  32 */    KEY_A,
    /*  33 */    KEY_S,
    /*  34 */    KEY_D,
    /*  35 */    KEY_F,
    /*  36 */    KEY_G,
    /*  37 */    KEY_H,
    /*  38 */    KEY_J,
    /*  39 */    KEY_K,
    /*  40 */    KEY_L,
    /*  41 */    KEY_SEMICOLON,
    /*  42 */    KEY_QUOTES,
    /*  43 */    KEY_INTERNATIONAL1,
    /*  44 */    KEY_UNKNOWN,
    /*  45 */    KEY_NUM4,
    /*  46 */    KEY_NUM5,
    /*  47 */    KEY_NUM6,
    /*  48 */    KEY_INTERNATIONAL2,
    /*  49 */    KEY_Z,
    /*  50 */    KEY_X,
    /*  51 */    KEY_C,
    /*  52 */    KEY_V,
    /*  53 */    KEY_B,
    /*  54 */    KEY_N,
    /*  55 */    KEY_M,
    /*  56 */    KEY_COMMA,
    /*  57 */    KEY_PERIOD,
    /*  58 */    KEY_SLASH,
    /*  59 */    KEY_UNKNOWN, // or KEY_INTERNATIONAL1,
    /*  60 */    KEY_NUMDECIMAL,
    /*  61 */    KEY_NUM7,
    /*  62 */    KEY_NUM8,
    /*  63 */    KEY_NUM9,
    /*  64 */    KEY_SPACE,
    /*  65 */    KEY_BACKSPACE,
    /*  66 */    KEY_TAB,
    /*  67 */    KEY_ENTER, // KEY_NUMENTER,
    /*  68 */    KEY_ENTER,
    /*  69 */    KEY_ESC,
    /*  70 */    KEY_DELETE,
    /*  71 */    KEY_INSERT,
    /*  72 */    KEY_PAGEUP,
    /*  73 */    KEY_PAGEDOWN,
    /*  74 */    KEY_NUMSUBTRACT,
    /*  75 */    KEY_F11,
    /*  76 */    KEY_UP,
    /*  77 */    KEY_DOWN,
    /*  78 */    KEY_RIGHT,
    /*  79 */    KEY_LEFT,
    /*  80 */    KEY_F1,
    /*  81 */    KEY_F2,
    /*  82 */    KEY_F3,
    /*  83 */    KEY_F4,
    /*  84 */    KEY_F5,
    /*  85 */    KEY_F6,
    /*  86 */    KEY_F7,
    /*  87 */    KEY_F8,
    /*  88 */    KEY_F9,
    /*  89 */    KEY_F10,
    /*  90 */    KEY_NUMLEFTPAREN,
    /*  91 */    KEY_NUMRIGHTPAREN,
    /*  92 */    KEY_NUMDIVIDE,
    /*  93 */    KEY_NUMMULTIPLY,
    /*  94 */    KEY_NUMADD,
    /*  95 */    KEY_SCROLLOCK, // or KEY_HELP,
    /*  96 */    KEY_LSHIFT,
    /*  97 */    KEY_RSHIFT,
    /*  98 */    KEY_CAPSLOCK,
    /*  99 */    KEY_LCONTROL,
    /*  100 */    KEY_LALT,
    /*  101 */    KEY_RALT,
    /*  102 */    KEY_LSYS,
    /*  103 */    KEY_RSYS,
    /*  104 */    KEY_UNKNOWN,
    /*  105 */    KEY_UNKNOWN,
    /*  106 */    KEY_UNKNOWN,
    /*  107 */    KEY_MENU,
    /*  108 */    KEY_NUMDECIMAL,
    /*  109 */    KEY_PRINT,
    /*  110 */    KEY_PAUSE,
    /*  111 */    KEY_F12,
    /*  112 */    KEY_HOME,
    /*  113 */    KEY_END,
};

typedef struct AsyncOp{
	struct Message Msg;
	BBSyncOp syncOp;
	BBObject *syncInfo;
	int asyncRet;
	BBAsyncOp asyncOp;
	int asyncInfo;
}AsyncOp;

struct Library *IntuitionBase = NULL;
struct Library *GfxBase = NULL;
struct Library *AslBase = NULL;
struct Library *KeymapBase = NULL;

struct IntuitionIFace *IIntuition = NULL;
struct GraphicsIFace * IGraphics = NULL;
struct AslIFace *IAsl = NULL;
struct KeymapIFace *IKeymap = NULL;

static struct MsgPort* SharedUserPort  = NULL;
static struct MsgPort* AsyncOpPort = NULL;
static uint32 WaitMask =0;
static mods = 0;
static struct Window *currentWindow =NULL;

struct MsgPort *inputport = NULL;
struct IOStdReq *inputreq = NULL;
static int inputDevOpen = FALSE;
struct InputEvent *inputevent = NULL;


struct Message xym_Msg;

static void NotImpl(char* txt)
{
	IDOS->Printf("%s is not implemented\n", txt);
	//abort();
}

void bbSetSystemWindow(struct Window* w)
{
	currentWindow = w;	
}

struct MsgPort* bbSharedUserPort()
{
	return SharedUserPort;
}

/*
void bbSystemEmitOSEvent( HWND hwnd,UINT msg,WPARAM wp,LPARAM lp,BBObject *source )
{
NotImpl("bbSystemEmitOSEvent");
}
*/



static void bbSystemShutdown(){	


	if (inputevent)	IExec->FreeVec(inputevent);
	if (inputDevOpen)IExec->CloseDevice ((struct IORequest *)inputreq);
    if (inputreq) IExec->FreeSysObject(ASOT_IOREQUEST, inputreq);
	if (inputport) IExec->FreeSysObject(ASOT_PORT, inputport);

	if (SharedUserPort) IExec->FreeSysObject(ASOT_PORT, SharedUserPort);
	if (AsyncOpPort) IExec->FreeSysObject(ASOT_PORT, AsyncOpPort);


	if (IKeymap) IExec->DropInterface((struct Interface*)IKeymap);
	if (IAsl) IExec->DropInterface((struct Interface*)IAsl);
	if (IGraphics) IExec->DropInterface((struct Interface*)IGraphics);
	if (IIntuition) IExec->DropInterface((struct Interface*)IIntuition);	


	if (KeymapBase) IExec->CloseLibrary(KeymapBase);
	if (AslBase) IExec->CloseLibrary(GfxBase);
	if (GfxBase) IExec->CloseLibrary(GfxBase);
  	if (IntuitionBase) IExec->CloseLibrary(IntuitionBase);

	SharedUserPort=NULL;
	IIntuition=NULL;
	GfxBase=NULL;
	IntuitionBase=NULL;
	IGraphics=NULL;
	IKeymap=NULL;
	KeymapBase=NULL;
}


void bbSystemStartup()
{
	if( IIntuition ) return;

 	IntuitionBase = IExec->OpenLibrary("intuition.library", 51);
	GfxBase = IExec->OpenLibrary("graphics.library", 54);
	AslBase = IExec->OpenLibrary("asl.library", 50);
	KeymapBase = IExec->OpenLibrary("keymap.library", 51);

	if (!(GfxBase || IntuitionBase || AslBase || KeymapBase)) {
		bbSystemShutdown();
		abort();
	}

	IIntuition = (struct IntuitionIFace*)IExec->GetInterface(IntuitionBase, "main", 1, NULL);
	IGraphics = (struct GraphicsIFace*)IExec->GetInterface(GfxBase, "main", 1, NULL);
 	IAsl = (struct AslIFace*)IExec->GetInterface(AslBase, "main", 1, NULL);
	IKeymap = (struct KeymapIFace*)IExec->GetInterface(KeymapBase, "main", 1, NULL);

	if (!(IIntuition || IGraphics || IAsl || IKeymap)) {
		bbSystemShutdown();
		abort();
	}

	if(!(SharedUserPort=IExec->AllocSysObject(ASOT_PORT, NULL))) {
		bbSystemShutdown();
		abort();
	}
	
	if(!(AsyncOpPort=IExec->AllocSysObject(ASOT_PORT, NULL))) {
		bbSystemShutdown();
		abort();
	}


	WaitMask = (1  << AsyncOpPort->mp_SigBit) | (1  << SharedUserPort->mp_SigBit) | SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_D ;   


	atexit( bbSystemShutdown );
}



static int GetMsg(struct MsgData* data)
{
	struct IntuiMessage *msg = IExec->GetMsg(SharedUserPort);
	if (msg) {
		data->Class = msg->Class;
		data->Code = msg->Code;
		data->Qualifier = msg->Qualifier;
		data->Gadget = (struct Gadget*)msg->IAddress;
		data-> IDCMPWindow = msg->IDCMPWindow;
		data-> PointerX = msg->IDCMPWindow->MouseX - msg->IDCMPWindow->BorderLeft;
		data-> PointerY = msg->IDCMPWindow->MouseY - msg->IDCMPWindow->BorderTop;
		data-> ScreenPointerX = msg->IDCMPWindow->WScreen->MouseX;
		data-> ScreenPointerY = msg->IDCMPWindow->WScreen->MouseY;
		data-> Width = msg->IDCMPWindow->Width - msg->IDCMPWindow->BorderLeft - msg->IDCMPWindow->BorderRight;
		data-> Height= msg->IDCMPWindow->Height - msg->IDCMPWindow->BorderTop - msg->IDCMPWindow->BorderBottom;
		IExec->ReplyMsg((struct Message*)msg);
	}
	return (msg!=NULL)	;
}	

static void updatemods(UWORD qualifier)
{
	mods=0;
	if (qualifier & IEQUALIFIER_LSHIFT || qualifier & IEQUALIFIER_RSHIFT) mods |=MODIFIER_SHIFT;
	if (qualifier & IEQUALIFIER_CONTROL) mods|=MODIFIER_CONTROL;
	if (qualifier & IEQUALIFIER_LALT || qualifier & IEQUALIFIER_RALT) mods|=MODIFIER_OPTION;
	if (qualifier & IEQUALIFIER_LCOMMAND || qualifier & IEQUALIFIER_RCOMMAND)  mods|=MODIFIER_SYSTEM;
}

void bbSystemEmitOSEvent(struct MsgData* msg, BBObject* source)
{
	int id, data=0, x=msg->PointerX, y=msg->PointerY;

	switch (msg->Class) {
		case IDCMP_CLOSEWINDOW:
			id = BBEVENT_APPTERMINATE;
			break;	
		case IDCMP_MOUSEMOVE:
			updatemods(msg->Qualifier);
			id = BBEVENT_MOUSEMOVE;
		        if (x < 0 || y < 0 || x >= msg->Width || y >= msg->Height) return;
			break;
		case IDCMP_MOUSEBUTTONS:	
			updatemods(msg->Qualifier);
			id = msg->Code & IECODE_UP_PREFIX ? BBEVENT_MOUSEUP : BBEVENT_MOUSEDOWN;
			switch (msg->Code & ~IECODE_UP_PREFIX) {
			case IECODE_LBUTTON:
				data = 1;
				break;
			case IECODE_MBUTTON:
				data = 3;
				break;
			case IECODE_RBUTTON:
				data = 2;
				break;
			default:
				return 0;
			}
			break;
		case IDCMP_EXTENDEDMOUSE:
			updatemods(msg->Qualifier);
			id = BBEVENT_MOUSEWHEEL;
		        if (x < 0 || y < 0 || x >= msg->Width || y >= msg->Height || msg->Code != IMSGCODE_INTUIWHEELDATA) return;
			struct IntuiWheelData *wheelData = (struct IntuiWheelData *)msg->Gadget;
			if (wheelData==NULL || wheelData->WheelY==0) return;
			data = wheelData->WheelY>0? 1 : -1;
			break;
		case IDCMP_RAWKEY:
			updatemods(msg->Qualifier);
			uint8 rawkey = msg->Code &  0x7F;
  			if (rawkey < sizeof(SCANCODES) / sizeof(SCANCODES[0])) {
				data= SCANCODES[rawkey];

            			if (msg->Code <= 0x80) {
					id = (msg->Qualifier & IEQUALIFIER_REPEAT) ? BBEVENT_KEYREPEAT : BBEVENT_KEYDOWN;
					bbSystemEmitEvent(id, source, data, mods, x, y, &bbNullObject);

 					struct InputEvent ie;
    					ie.ie_Class = IECLASS_RAWKEY;
    					ie.ie_SubClass = 0;
   					ie.ie_Code  = msg->Code  & ~(IECODE_UP_PREFIX);
   					ie.ie_Qualifier = msg->Qualifier;
    					ie.ie_EventAddress = NULL;
					char buffer[10];
					int i, n =  IKeymap->MapRawKey(&ie, buffer, sizeof(buffer), NULL);
					for (i=0;i<n;i++){
						bbSystemEmitEvent(BBEVENT_KEYCHAR,source,buffer[i],mods,x,y,&bbNullObject);
					}
            			}
				else {
					bbSystemEmitEvent(BBEVENT_KEYUP, source, data, mods, x, y, &bbNullObject);        
            			}
			}
			return;
		case IDCMP_ACTIVEWINDOW:
			id = BBEVENT_APPRESUME;
			break;
		case IDCMP_INACTIVEWINDOW:
			id = BBEVENT_APPSUSPEND;
			break;
		default:		
			printf("Got msg - Class: %d Code%d:\n", msg->Class, msg->Code);
			return;		
	}
	bbSystemEmitEvent(id, source, data, mods, x, y, &bbNullObject);
}

void bbSystemPoll()
{	
	struct MsgData msg;
	while (GetMsg(&msg)) {
		bbSystemEmitOSEvent(&msg, &bbNullObject);		
	}

	struct AsyncOp *op;
	while( (op = IExec->GetMsg(AsyncOpPort)) !=NULL) {
			op->syncOp( op->syncInfo,op->asyncRet );
			if( op->asyncOp ){
				BBRELEASE( op->syncInfo );
			}
			IExec->FreeSysObject(ASOT_MESSAGE, op);
	}
}

void bbSystemWait()
{ 
	IExec->Wait(WaitMask);
	bbSystemPoll();
}


void bbSystemMoveMouse( int x,int y )
{
	if (currentWindow==NULL) return;
	if (inputport==NULL) inputport=IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);
	if (inputport) {
		if (inputreq==NULL) inputreq = (struct IOStdReq *)IExec->AllocSysObjectTags(ASOT_IOREQUEST,
                ASOIOR_Size, sizeof(struct IOStdReq),
                ASOIOR_ReplyPort, inputport,
                TAG_END);
		if (inputreq){
			if (!inputDevOpen) inputDevOpen = !IExec->OpenDevice("input.device", NULL, (struct IORequest *)inputreq, NULL); 
			if (inputDevOpen) {
		 		if (inputevent==NULL) inputevent = (struct InputEvent *)IExec->AllocVecTags(
							sizeof(struct InputEvent) + sizeof(struct IEPointerPixel),
							AVT_Type, MEMF_SHARED,	TAG_END);	
				if (inputevent) {
					struct IEPointerPixel *ptrpixel = (struct IEPointerPixel *)(inputevent + 1);
					struct Screen *scr = currentWindow->WScreen;
					if (scr){
						ptrpixel->iepp_Screen     = scr;
						ptrpixel->iepp_Position.X = x+currentWindow->LeftEdge;
						ptrpixel->iepp_Position.Y = y+currentWindow->TopEdge;
						inputevent->ie_EventAddress = ptrpixel;
						inputevent->ie_Class        = IECLASS_NEWPOINTERPOS;
						inputevent->ie_SubClass     = IESUBCLASS_PIXEL;
						inputevent->ie_Code         = IECODE_NOBUTTON;

						inputreq->io_Data    = inputevent;
						inputreq->io_Length  = sizeof(struct InputEvent);
						inputreq->io_Command = IND_WRITEEVENT;
						IExec->DoIO ((struct IORequest *)inputreq);
					}
				}	
			}
        }
	}
}

void bbSystemSetMouseVisible( int visible )
{
	if (currentWindow==NULL) return;
	IIntuition->SetWindowPointer(currentWindow,  WA_PointerType,  visible ? POINTERTYPE_NORMAL : POINTERTYPE_NONE, TAG_DONE);	
}

static int MsgBox(BBString* message, CONST_STRPTR title, CONST_STRPTR buttons)
{
	struct EasyStruct es = {
				sizeof(struct EasyStruct),
				0, // Flags
				buttons,
				(CONST_STRPTR)bbTmpCString(message),
				buttons,
				NULL, // Screen
				NULL  // TagList
			};

	return IIntuition->EasyRequest(NULL, &es, 0, NULL);
}


void bbSystemNotify(BBString* text,int serious )
{
	MsgBox(text, "Notify!", "Ok");
}

int bbSystemConfirm(BBString* text,int serious )
{
	return MsgBox(text,"Confirm?", "Yes|No");
}

int bbSystemProceed(BBString* text,int serious )
{
	return MsgBox(text, "Proceed?", "Ok|Cancel");
}

 
BBString* bbSystemRequestFile(BBString* text,BBString* exts,int defext,int save,BBString* file,BBString* dir)
{
	struct TagItem frtags[] =
	{
    		ASLFR_TitleText,       (uint32)bbTmpCString(text),
    		ASLFR_InitialDrawer, (uint32)bbTmpCString(dir),
		ASLFR_InitialFile,        (uint32)bbTmpCString(file),
		ASLFR_InitialPattern, (uint32)"",
    		ASLFR_DoPatterns, (uint32) defext ? TRUE : FALSE,
		ASLFR_DoSaveMode, (uint32) save ? TRUE : FALSE,
    		TAG_END
	};
	BBString* result = &bbEmptyString;
	struct FileRequester *fr = IAsl->AllocAslRequest(ASL_FileRequest, frtags);
        if (fr) {
            if (IAsl->AslRequest(fr, NULL)) {
		char tmp[1024];
		strncpy(tmp, fr->fr_Drawer, 1024);
		IDOS->AddPart(tmp, fr->fr_File, 1024);
		result = bbStringFromCString(tmp);
            }
            IAsl->FreeAslRequest(fr);
        }	
	return result;
}


BBString* bbSystemRequestDir(BBString* text,BBString* dir)
{
	struct TagItem frtags[] =
	{
    		ASLFR_TitleText, (uint32)bbTmpCString(text),
    		ASLFR_InitialDrawer, (uint32)bbTmpCString(dir),
    		ASLFR_DrawersOnly, (uint32)TRUE,
    		TAG_END
	};
	BBString* result = &bbEmptyString;
	struct FileRequester *fr = IAsl->AllocAslRequest(ASL_FileRequest, frtags);
        if (fr != NULL) {
            if (IAsl->AslRequest(fr, NULL)) {
		result= bbStringFromCString(fr->fr_Drawer);
            }
            IAsl->FreeAslRequest(fr);
        }	
	return result;
}

int bbOpenURL( BBString *url )
{
	BPTR h =	IDOS->Open(bbTmpCString(url),MODE_OLDFILE);
	if (h) {
		IDOS->Close(h);
		return 1;
	}
	return 0;
}

void bbSystemPostSyncOp( BBSyncOp syncOp,BBObject *syncInfo,int asyncRet )
{
	struct AsyncOp *p = IExec->AllocSysObjectTags(ASOT_MESSAGE, ASOMSG_Size, sizeof(struct AsyncOp), TAG_END);
 	p->asyncOp=0;
	p->asyncRet=asyncRet;
	p->syncOp=syncOp;
	p->syncInfo=syncInfo;

	IExec->PutMsg(AsyncOpPort, p);
}

void *asyncOpThread( void *t ){
	AsyncOp *p=(AsyncOp*)t;
	p->asyncRet=p->asyncOp( p->asyncInfo );
	IExec->PutMsg(AsyncOpPort, p);
	return 0;
}

void bbSystemStartAsyncOp( BBAsyncOp asyncOp,int asyncInfo,BBSyncOp syncOp,BBObject *syncInfo )
{
	pthread_t thread;
	struct AsyncOp *p = IExec->AllocSysObjectTags(ASOT_MESSAGE, ASOMSG_Size, sizeof(struct AsyncOp), TAG_END);
	BBRETAIN( syncInfo );
	p->asyncOp=asyncOp;
	p->asyncInfo=asyncInfo;
	p->syncOp=syncOp;
	p->syncInfo=syncInfo;
	pthread_create( &thread,0,asyncOpThread,p );
	pthread_detach( thread );
}

int bbSystemDesktopWidth()
{
	int w= 0;
	struct Screen* wbScreen = IIntuition->LockPubScreen("Workbench");
	if (wbScreen) {
		IIntuition->GetScreenAttr(wbScreen, SA_Width , &w, sizeof(LONG)) ;
		IIntuition->UnlockPubScreen(NULL, wbScreen);
	}
	return w;
}

int bbSystemDesktopHeight()
{
	int h= 0;
	struct Screen* wbScreen = IIntuition->LockPubScreen("Workbench");
	if (wbScreen) {
		IIntuition->GetScreenAttr(wbScreen, SA_Height , &h, sizeof(LONG)) ;
		IIntuition->UnlockPubScreen(NULL, wbScreen);
	}
	return h;
}

int bbSystemDesktopDepth()
{
	LONG d= 0;
	struct Screen* wbScreen = IIntuition->LockPubScreen("Workbench");
	if (wbScreen) {
		IIntuition->GetScreenAttr(wbScreen, SA_Depth , &d, sizeof(LONG)) ;
		IIntuition->UnlockPubScreen(NULL, wbScreen);
	}
	return d;
}

int bbSystemDesktopHertz()
{
	return 0;
}


