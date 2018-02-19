#include "amigaos.h"

#ifndef NDEBUG
void *bbintarraytoptr(BBArray *array)
{
	if (array->size==0) bbExThrowCString("Array size is zero");
	if (array->dims != 1) bbExThrowCString("Array dimensions not 1");
	if (array->type[0] != 'i') bbExThrowCString("Array type not int");
	return (void*)BBARRAYDATA(array,array->dims);
}
struct TagItem *bbarraytotags(BBArray *array)
{
	if (array->size==0) bbExThrowCString("tag array size is zero");
	if (array->dims != 1) bbExThrowCString("tag array dimensions not 1");
	if (array->type[0] != 'i') bbExThrowCString("tag array type not int");
	Tag lastTag = ((Tag*)BBARRAYDATA(array,array->dims))[array->scales[0]-(2 - (array->scales[0] % 2))];
	if ((lastTag != TAG_DONE) && (lastTag != TAG_MORE))	bbExThrowCString("tag array is malformed last Tag is not TAG_DONE | TAG_MORE");	
	return (struct TagItem *)BBARRAYDATA(array,array->dims);
}

#endif

static void bbFreeInterface(struct BBIInterface * intf)
{
	struct BBLibrary *lib = intf->Library;
	if (lib->IInterface) {
		if (lib->IInterface->Release() == 1 && lib->LibraryBase != NULL) {
			IExec->DropInterface(lib->IInterface);
			IExec->CloseLibrary(lib->LibraryBase);
			lib->IInterface = NULL;
			lib->LibraryBase = NULL;			
		}
	}
	intf->Library = NULL;
	intf->IInterface = NULL;
}


static int32 bbLoadInterface(struct BBIInterface * intf)
{
	struct BBLibrary *lib = intf->Library;
	if (lib->GlobalInterfaceRef != NULL) {
		lib->IInterface = *lib->GlobalInterfaceRef;
	}
	if (lib->IInterface == NULL && lib->LibraryBase == NULL) {
		lib->LibraryBase = IExec->OpenLibrary(lib->Name,  lib->Version);
		if (lib->LibraryBase) {
			lib->IInterface = IExec->GetInterface(lib->LibraryBase, lib->InterfaceName, lib->InterfaceVersion, NULL);
			if (lib->IInterface ==NULL)  {
				IExec->CloseLibrary(lib->LibraryBase);
				lib->LibraryBase = NULL;
			}
		}	
	}
	if (lib->IInterface) {
		lib->IInterface->Obtain();
		intf->IInterface = lib->IInterface;
		intf->VTable= lib->VTable;
		return BBAPI_OK;
	}
	return BBAPI_FAIL;
}


struct BBIInterface *bbObtainInterface(struct BBLibrary *lib)
{
	struct BBIInterface *intf = bbMemAlloc(sizeof(struct BBIInterface));
	if (intf != NULL) {
		intf->Library = lib;
		if (bbLoadInterface(intf)) {
			bbMemFree(intf);
			intf = NULL;
		}
	}
	return intf;
}

void bbReleaseInterface(struct BBIInterface * intf)
{
	if (intf != NULL) {
		bbFreeInterface(intf);	
		bbMemFree(intf);
	}
}



