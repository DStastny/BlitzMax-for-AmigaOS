#include <iutility.h>
#include <proto/utility.h>

#define IUtility(this) ((struct UtilityIFace*)this->IInterface)

static struct TagItem *bbAllocateTagItems(struct BBIInterface *this, ULONG count)
{
	return IUtility(this)->AllocateTagItems(count);
}

static void bbFreeTagItems(struct BBIInterface *this, struct TagItem *tags) 
{
	IUtility(this)->FreeTagItems(tags);
}

static void* _UtilityLibraryVTable[] = {
	bbAllocateTagItems,
	bbFreeTagItems
};

static struct BBLibrary  UtilityLibrary = {
	"dos.library",
	50,
	"main",
	1,
	_UtilityLibraryVTable,
	NULL,
	NULL,
	&IUtility
};

struct BBLibrary *bbUtilityLibrary = &UtilityLibrary;