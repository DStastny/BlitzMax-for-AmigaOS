#ifndef AMIGAOS_H
#define AMIGAOS_H 

#include <brl.mod/blitz.mod/blitz.h>
#include <exec/types.h>
#include <exec/interfaces.h>


#define BBAPI_OK 0;
#define BBAPI_FAIL 1;

#define NULLORCSTR(str) (str == &bbEmptyString ? NULL : bbTmpCString(str))

#ifndef NDEBUG
void *bbintarraytoptr(BBArray *array);
struct TagItem *bbarraytotags(BBArray *array);
#define BBINTARRAYTOPTR(A) bbintarraytoptr(A)
#define BBINTARRAYTOTAGS(A) bbarraytotags(A)	
#else

#define BBINTARRAYTOPTR(A) BBARRAYDATA(A,A->dims)
#define BBINTARRAYTOTAGS(A) ((struct TagItem *)BBARRAYDATA(A,A->dims))
#endif

struct BBIInterface
{
	void **VTable;
	struct BBLibrary *Library;
	struct Interface *IInterface;
};

struct BBLibrary
{
	CONST_STRPTR Name;
	uint32 Version;
	CONST_STRPTR InterfaceName; // main
	uint32 InterfaceVersion;  // 1
	void** VTable;
	struct Library *LibraryBase;
	struct Interface *IInterface;
	struct Interface **GlobalInterfaceRef;
};


struct BBIInterface *bbObtainInterface(struct BBLibrary *lib);
void bbReleaseInterface(struct BBIInterface * intf);




#endif
