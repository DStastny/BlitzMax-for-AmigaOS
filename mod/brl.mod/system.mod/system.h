
#ifndef BB_BRL_SYSTEM_H
#define BB_BRL_SYSTEM_H

#include <brl.mod/blitz.mod/blitz.h>

#include <brl.mod/event.mod/event.h>	//event enums

#include <brl.mod/keycodes.mod/keycodes.h>	//keycode enums

typedef int (*BBAsyncOp)( int asyncInfo );
typedef void (*BBSyncOp)( BBObject *syncInfo,int asyncRet );

void bbSystemPostSyncOp( BBSyncOp syncOp,BBObject *syncInfo,int asyncRet );
void bbSystemStartAsyncOp( BBAsyncOp asyncOp,int asyncInfo,BBSyncOp syncOp,BBObject *syncInfo );

#ifdef __cplusplus
extern "C"{
#endif

void bbSystemEmitEvent( int id,BBObject *source,int data,int mods,int x,int y,BBObject *extra );

#if _WIN32

#include <windows.h>

#define WM_BBRESERVED1 0x7001

void bbSystemEmitOSEvent( HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam,BBObject *source );
	
#elif __APPLE__

#define BB_RESERVEDEVENTSUBTYPE1 0x7001	//reserved event substype

#ifdef __OBJC__
#include <AppKit/AppKit.h>
#else
typedef void *NSView;
typedef void *NSEvent;
#endif

int bbSystemTranslateKey( int key );
int	bbSystemTranslateChar( int chr );
int	bbSystemTranslateMods( int mods );
void bbSystemViewClosed( NSView *view );
void bbSystemEmitOSEvent( NSEvent *event,NSView *view,BBObject *source );

BBString * brl_blitz_bbStringFromUTF8String(const char * text);

#elif __linux

#include <X11/Xlib.h>
void bbSystemEmitOSEvent( XEvent *event,BBObject *source );

#endif

#if __amigaos4__
#include <exec/types.h>               /* Amiga data types.               */
#include <exec/libraries.h>
#include <dos/dos.h>
#include <libraries/asl.h>


#include <intuition/intuition.h>      /* Lots of important Intuition     */
#include <intuition/screens.h>        /* structures we will be using.    */
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/asl.h>
#include <proto/keymap.h>
extern struct Library *IntuitionBase;
extern struct Library *GfxBase;
extern struct Library *AslBase;
extern struct Library *KeymapBase;

extern struct IntuitionIFace *IIntuition;
extern struct GraphicsIFace * IGraphics;
extern struct AslIFace *IAsl;
extern struct KeymapIFace *IKeymap;


struct MsgPort* bbSharedUserPort();
void bbSetSystemWindow(struct Window* w);

struct MsgData
{
	uint32 Class;
	uint16 Code;
	uint16 Qualifier;
	struct Gadget* Gadget;
	struct Window* IDCMPWindow;
	int16 PointerX;
	int16 PointerY;
	int16 ScreenPointerX;
	int16 ScreenPointerY;
	int16 Width;
	int16 Height;
};

void bbSystemEmitOSEvent(struct MsgData* msg, BBObject* source);


#endif

#ifdef __cplusplus
}
#endif

#endif
