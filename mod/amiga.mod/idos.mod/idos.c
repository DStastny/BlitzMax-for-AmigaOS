#include <proto/dos.h>
#include <idos.h>



#define IDOS(this) ((struct DOSIFace*)this->IInterface)

static void bbPrintf(struct BBIInterface *this,   BBString *text)
{
	IDOS(this)->Printf(bbTmpCString(text));
}

static void* _DOSLibraryVTable[] = {
	bbPrintf
};

static struct BBLibrary  DOSLibrary = {
	"dos.library",
	50,
	"main",
	1,
	_DOSLibraryVTable,
	NULL,
	NULL,
	&IDOS
};

struct BBLibrary *bbDOSLibrary = &DOSLibrary;