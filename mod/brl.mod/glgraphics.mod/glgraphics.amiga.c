#include <brl.mod/system.mod/system.h>
#include <intuition/pointerclass.h>
#include <gl/gl.h>

enum{
	_BACKBUFFER=	0x2,
	_ALPHABUFFER=	0x4,
	_DEPTHBUFFER=	0x8,
	_STENCILBUFFER=	0x10,
	_ACCUMBUFFER=	0x20,
};

enum{
	MODE_SHARED,
	MODE_WIDGET,
	MODE_WINDOW,
	MODE_DISPLAY
};

typedef struct BBGLContext BBGLContext;
struct BBGLContext{
	BBGLContext *succ;
	int mode,width,height,depth,hertz,flags;
	struct GLContextIFace *mglContext;
};



static BBGLContext *_contexts;
static BBGLContext *_sharedContext;
static BBGLContext *_currentContext;
static int _count = 0;
static int _n = 0;
static int* _modes = 0;
static uint16 _findw;
static uint16 _findh;
static uint16 _findd;
static uint32 _fmode;
static struct MiniGLIFace *IMiniGL = 0;

static void _mglCleanup()
{
	struct Library *lib = IMiniGL->Data.LibBase;
	IExec->DropInterface(IMiniGL);
	IExec->CloseLibrary(lib);	
}

static int _mglInit()
{
	if (IMiniGL==NULL) {
		struct Library *lib;
		lib = IExec->OpenLibrary("minigl.library", 2);
		if (lib)  {
			if (IMiniGL =(struct MiniGLIFace *)IExec->GetInterface(lib, "main", 1, NULL)){
				atexit(_mglCleanup);
			}
		}
	}
	return (IMiniGL ==NULL) ? 1 : 0;
}


static GLboolean screenModes(MGLScreenMode *mode)
{
	if(mode->bit_depth <16) return GL_FALSE;
	if (_n< _count){

		*_modes++=mode->width;
		*_modes++=mode->height;
		*_modes++=mode->bit_depth;
		*_modes++=60; // freq... no clue.
		++_n;
		return GL_FALSE;
	}
	return GL_TRUE;
}



static GLboolean findMode(MGLScreenMode *mode)
{	
	if (mode->width == _findw && mode->height == _findh && mode->bit_depth == _findd) {
		_fmode = mode->id;
		return GL_TRUE;
	}
	return GL_FALSE;
}

// fixes wazp3d for minigl defaulting incorrect

void initMiniGLContext(BBGLContext *context)
{
	struct GLContextIFace *IGL = context->mglContext;
	IGL->SetState(GL_CULL_FACE, GL_FALSE);
	IGL->SetState(GL_ALPHA_TEST, GL_FALSE);
	IGL->SetState(GL_DEPTH_TEST, GL_FALSE);
}


void bbGLGraphicsShareContexts()
{
	if (_mglInit()) return;
}

int bbGLGraphicsGraphicsModes( int *modes,int count )
{
	if (_mglInit()) return 0;
	_modes = modes;
	_count = count;
	_n = 0;
	IMiniGL->GetSupportedScreenModes(screenModes);
	return _n;
}

BBGLContext *bbGLGraphicsAttachGraphics(void* hwnd,int flags )
{
	if (_mglInit()) return 0;

	BBGLContext *context;
	context=0;
	return context;
}





BBGLContext *bbGLGraphicsCreateGraphics( int width,int height,int depth,int hertz,int flags )
{
	if (_mglInit()) return 0;
	
	int windowed = depth ? FALSE : TRUE;
//printf("left=%d\n",(bbSystemDesktopWidth()- width) / 2);
//printf("top=%d\n",(bbSystemDesktopHeight()-height)/2);
	BBGLContext *context = 0;
	struct GLContextIFace *IGL = 0;
	if (windowed) {
		IGL = IMiniGL->CreateContextTags(
			MGLCC_Width,		width,
			MGLCC_Height,		height,
			MGLCC_Windowed,	 	TRUE,
			MGLCC_CloseGadget,	TRUE,			
			MGLCC_Buffers, 		flags & _BACKBUFFER ? 2 : 1,
			MGLCC_StencilBuffer, flags & _STENCILBUFFER,
			TAG_DONE);
	}
	else {
		_findw= width;
		_findh= height;
		_findd= depth;
		if (IMiniGL->GetSupportedScreenModes(findMode) == GL_FALSE) return NULL;

		IGL = IMiniGL->CreateContextTags(
			MGLCC_Width,		width,
			MGLCC_Height,		height,	
			MGLCC_Windowed,	 	FALSE,		
			MGLCC_Buffers, 		flags & _BACKBUFFER ? 2 : 1,
			MGLCC_ScreenMode, _fmode,
			MGLCC_StencilBuffer, flags & _STENCILBUFFER,
			TAG_DONE);
	}
	if (IGL) {
	
		struct Window *win = IGL->GetWindowHandle();
		STRPTR t = bbTmpCString( bbAppTitle );
		IIntuition->SetWindowTitles(win,t,t);
		IIntuition->SetWindowPointer(win,  WA_PointerType,  POINTERTYPE_NORMAL, TAG_DONE);
		win->UserPort = bbSharedUserPort();
		IIntuition->ModifyIDCMP(win, IDCMP_RAWKEY|IDCMP_MOUSEMOVE|IDCMP_MOUSEBUTTONS|
									 IDCMP_CLOSEWINDOW| IDCMP_EXTENDEDMOUSE |IDCMP_ACTIVEWINDOW |
									 IDCMP_INACTIVEWINDOW);
	//	IGL->LockMode(MGL_LOCK_SMART);
		context=(BBGLContext*)malloc( sizeof(BBGLContext) );
		memset( context,0,sizeof(context) );
	
		context->mode= windowed ? MODE_WINDOW :  MODE_DISPLAY;
		context->width=width;
		context->height=height;
		context->depth=depth;
		context->hertz=hertz;
		context->flags=flags;
		context->mglContext = IGL;
		context->succ=_contexts;
		_contexts=context;
		initMiniGLContext(context);
	}
	return context;
}

void bbGLGraphicsGetSettings( BBGLContext *context,int *width,int *height,int *depth,int *hertz,int *flags )
{


//	_validateSize( context );
	*width=context->width;
	*height=context->height;
	*depth=context->depth;
	*hertz=context->hertz;
	*flags=context->flags;
}

void bbGLGraphicsClose( BBGLContext *context )
{
	if (_mglInit()) return;

	BBGLContext **p,*t;
	
	for( p=&_contexts;(t=*p) && (t!=context);p=&t->succ ){}
	if( !t ) return;
	
	if( t==_currentContext ){
		bbGLGraphicsSetGraphics( 0 );
	}	

	struct GLContextIFace *IGL =context->mglContext;
	struct Window *win = IGL->GetWindowHandle();
	IExec->Forbid();
	IIntuition->StripIntuiMessages(win->UserPort, win);
	win->UserPort = NULL;
	IIntuition->ModifyIDCMP(win, 0L);	
	IExec->Permit();
	IGL->DeleteContext();
	
	free(context);	
	*p=t->succ;
}

void bbGLGraphicsSetGraphics( BBGLContext *context )
{
	if (_mglInit()) return;

	if( context==_currentContext ) return;
	
	_currentContext=context;

	struct Window *w = NULL;
	if( context ){
		struct GLContextIFace *IGL =context->mglContext;
		mglMakeCurrent(IGL);
		w=IGL->GetWindowHandle();
	}else{
		mglMakeCurrent(0);
	}
	bbSetSystemWindow(w);
}

void bbGLGraphicsFlip( int sync )
{
	if (_mglInit()) return;

	if( !_currentContext ) return;
	struct GLContextIFace *IGL = _currentContext->mglContext;
	IGL->UnlockDisplay();
	IGL->EnableSync(sync ? GL_TRUE : GL_FALSE);
	IGL->SwitchDisplay();
}
