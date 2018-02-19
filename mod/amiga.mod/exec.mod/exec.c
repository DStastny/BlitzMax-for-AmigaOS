#include <exec.h>
#include <proto/exec.h>

#define IExec(this) ((struct ExecIFace*)this->IInterface)


static void bbAddHead(struct BBIInterface *this, struct List *list, struct Node *node)
{
    IExec(this)->AddHead(list, node);
}

static VOID bbAddMemHandler(struct BBIInterface *this, struct Interrupt *memHandler)
{
    IExec(this)->AddMemHandler(memHandler);
}

static void bbAddTail(struct BBIInterface *this, struct List *list, struct Node *node)
{
    IExec(this)->AddTail(list, node);
}

static APTR bbAllocPooled(struct BBIInterface *this, APTR poolHeader, ULONG memSize)
{
    return IExec(this)->AllocPooled(poolHeader, memSize);
}

static APTR bbAllocVecPooled(struct BBIInterface *this, APTR poolHeader, ULONG size)
{
    return IExec(this)->AllocVecPooled(poolHeader, size);
}

static ULONG bbAvailMem(struct BBIInterface *this, ULONG attributes)
{
    return IExec(this)->AvailMem(attributes);
}

static void bbCopyMem(struct BBIInterface *this, CONST_APTR source, APTR dest, ULONG size)
{
    IExec(this)->CopyMem(source, dest, size);
}

static void bbCopyMemQuick(struct BBIInterface *this, CONST_APTR source, APTR dest, ULONG size)
{
    IExec(this)->CopyMemQuick(source, dest, size);
}

static void bbEnqueue(struct BBIInterface *this, struct List *list, struct Node *node)
{
    IExec(this)->Enqueue(list, node);
}

static struct Node * bbFindName(struct BBIInterface *this, struct List *start, BBString *name)
{
    return IExec(this)->FindName(start, NULLORCSTR(name));
}

static struct Node * bbFindIName(struct BBIInterface *this, struct List *start, BBString *name)
{
    return IExec(this)->FindIName(start, NULLORCSTR(name));
}

static void bbForbid(struct BBIInterface *this)
{
    IExec(this)->Forbid();
}

static void bbFreeEntry(struct BBIInterface *this, struct MemList *memList)
{
    IExec(this)->FreeEntry(memList);
}

static void bbFreePooled(struct BBIInterface *this, APTR poolHeader, APTR memory, ULONG memSize)
{
    IExec(this)->FreePooled(poolHeader, memory, memSize);
}

static void bbFreeVec(struct BBIInterface *this, APTR memoryBlock)
{
    IExec(this)->FreeVec(memoryBlock);
}

static void bbFreeVecPooled(struct BBIInterface *this, APTR poolHeader, APTR memory)
{
    IExec(this)->FreeVecPooled(poolHeader, memory);
}

static void bbInsert(struct BBIInterface *this, struct List *list, struct Node *node, struct Node *listNode)
{
    IExec(this)->Insert(list, node, listNode);
}

static struct Interface * bbMakeInterface(struct BBIInterface *this, struct Library *library, const struct TagItem *taglist)
{
    return IExec(this)->MakeInterface(library, taglist);
}

static struct Interface * bbMakeInterfaceTags(struct BBIInterface *this, struct Library *library, BBArray *tag)
{
    return IExec(this)->MakeInterface(library, BBINTARRAYTOTAGS(tag));
}

static void bbPermit(struct BBIInterface *this)
{
    IExec(this)->Permit();
}

static APTR bbRawDoFmt(struct BBIInterface *this, BBString *formatString, CONST_APTR dataStream, void (*PutChProc)(), APTR PutChData)
{
    return IExec(this)->RawDoFmt(NULLORCSTR(formatString), dataStream, PutChProc, PutChData);
}

static struct Node * bbRemHead(struct BBIInterface *this, struct List *list)
{
    return IExec(this)->RemHead(list);
}

static VOID bbRemMemHandler(struct BBIInterface *this, struct Interrupt *memHandler)
{
    IExec(this)->RemMemHandler(memHandler);
}

static void bbRemove(struct BBIInterface *this, struct Node *node)
{
    IExec(this)->Remove(node);
}

static struct Node * bbRemTail(struct BBIInterface *this, struct List *list)
{
    return IExec(this)->RemTail(list);
}

static ULONG bbTypeOfMem(struct BBIInterface *this, CONST_APTR address)
{
    return IExec(this)->TypeOfMem(address);
}

static APTR bbInitResident(struct BBIInterface *this, const struct Resident *resident, ULONG segList)
{
    return IExec(this)->InitResident(resident, segList);
}

static void bbInitCode(struct BBIInterface *this, ULONG startClass, ULONG version)
{
    IExec(this)->InitCode(startClass, version);
}

static ULONG bbSumKickData(struct BBIInterface *this)
{
    return IExec(this)->SumKickData();
}

static APTR bbAddTask(struct BBIInterface *this, struct Task *task, CONST_APTR initialPC, CONST_APTR finalPC, const struct TagItem *tagList)
{
    return IExec(this)->AddTask(task, initialPC, finalPC, tagList);
}

static APTR bbAddTaskTags(struct BBIInterface *this, struct Task *task, CONST_APTR initialPC, CONST_APTR finalPC, BBArray *tag)
{
    return IExec(this)->AddTask(task, initialPC, finalPC, BBINTARRAYTOTAGS(tag));
}

static void bbDisable(struct BBIInterface *this)
{
    IExec(this)->Disable();
}

static void bbEnable(struct BBIInterface *this)
{
    IExec(this)->Enable();
}

static struct Task * bbFindTask(struct BBIInterface *this, BBString *name)
{
    return IExec(this)->FindTask(NULLORCSTR(name));
}

static void bbRemTask(struct BBIInterface *this, struct Task *task)
{
    IExec(this)->RemTask(task);
}

static BYTE bbSetTaskPri(struct BBIInterface *this, struct Task *task, BYTE priority)
{
    return IExec(this)->SetTaskPri(task, priority);
}

static BYTE bbAllocSignal(struct BBIInterface *this, BYTE signalNum)
{
    return IExec(this)->AllocSignal(signalNum);
}

static void bbFreeSignal(struct BBIInterface *this, BYTE signalNum)
{
    IExec(this)->FreeSignal(signalNum);
}

static ULONG bbSetExcept(struct BBIInterface *this, ULONG newSignals, ULONG signalMask)
{
    return IExec(this)->SetExcept(newSignals, signalMask);
}

static ULONG bbSetSignal(struct BBIInterface *this, ULONG newSignals, ULONG signalMask)
{
    return IExec(this)->SetSignal(newSignals, signalMask);
}

static void bbSignal(struct BBIInterface *this, struct Task *task, ULONG signals)
{
    IExec(this)->Signal(task, signals);
}

static ULONG bbWait(struct BBIInterface *this, ULONG signalSet)
{
    return IExec(this)->Wait(signalSet);
}

static void bbAddPort(struct BBIInterface *this, struct MsgPort *port)
{
    IExec(this)->AddPort(port);
}

static struct MsgPort * bbFindPort(struct BBIInterface *this, BBString *name)
{
    return IExec(this)->FindPort(NULLORCSTR(name));
}

static struct Message * bbGetMsg(struct BBIInterface *this, struct MsgPort *port)
{
    return IExec(this)->GetMsg(port);
}

static void bbPutMsg(struct BBIInterface *this, struct MsgPort *port, struct Message *message)
{
    IExec(this)->PutMsg(port, message);
}

static void bbRemPort(struct BBIInterface *this, struct MsgPort *port)
{
    IExec(this)->RemPort(port);
}

static void bbReplyMsg(struct BBIInterface *this, struct Message *message)
{
    IExec(this)->ReplyMsg(message);
}

static struct Message * bbWaitPort(struct BBIInterface *this, struct MsgPort *port)
{
    return IExec(this)->WaitPort(port);
}

static void bbCause(struct BBIInterface *this, struct Interrupt *interrupt)
{
    IExec(this)->Cause(interrupt);
}

static void bbAddSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->AddSemaphore(semaphore);
}

static LONG bbAttemptSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    return IExec(this)->AttemptSemaphore(semaphore);
}

static LONG bbAttemptSemaphoreShared(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    return IExec(this)->AttemptSemaphoreShared(semaphore);
}

static struct SignalSemaphore * bbFindSemaphore(struct BBIInterface *this, BBString *name)
{
    return IExec(this)->FindSemaphore(NULLORCSTR(name));
}

static void bbInitSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->InitSemaphore(semaphore);
}

static void bbObtainSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->ObtainSemaphore(semaphore);
}

static void bbObtainSemaphoreList(struct BBIInterface *this, struct List *list)
{
    IExec(this)->ObtainSemaphoreList(list);
}

static void bbObtainSemaphoreShared(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->ObtainSemaphoreShared(semaphore);
}

static void bbProcure(struct BBIInterface *this, struct SignalSemaphore *semaphore, struct SemaphoreMessage *bidMessage)
{
    IExec(this)->Procure(semaphore, bidMessage);
}

static void bbReleaseSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->ReleaseSemaphore(semaphore);
}

static void bbReleaseSemaphoreList(struct BBIInterface *this, struct List *list)
{
    IExec(this)->ReleaseSemaphoreList(list);
}

static void bbRemSemaphore(struct BBIInterface *this, struct SignalSemaphore *semaphore)
{
    IExec(this)->RemSemaphore(semaphore);
}

static void bbVacate(struct BBIInterface *this, struct SignalSemaphore *semaphore, struct SemaphoreMessage *bidMessage)
{
    IExec(this)->Vacate(semaphore, bidMessage);
}

static struct Task * bbCreateTask(struct BBIInterface *this, BBString *name, LONG pri, CONST_APTR initPC, ULONG stackSize, const struct TagItem *tagList)
{
    return IExec(this)->CreateTask(NULLORCSTR(name), pri, initPC, stackSize, tagList);
}

static struct Task * bbCreateTaskTags(struct BBIInterface *this, BBString *name, LONG pri, CONST_APTR initPC, ULONG stackSize, BBArray *tag)
{
    return IExec(this)->CreateTask(NULLORCSTR(name), pri, initPC, stackSize, BBINTARRAYTOTAGS(tag));
}

static void bbDeleteTask(struct BBIInterface *this, struct Task *task)
{
    IExec(this)->DeleteTask(task);
}

static void bbSumLibrary(struct BBIInterface *this, struct Library *library)
{
    IExec(this)->SumLibrary(library);
}

static struct Library * bbCreateLibrary(struct BBIInterface *this, const struct TagItem *taglist)
{
    return IExec(this)->CreateLibrary(taglist);
}

static struct Library * bbCreateLibraryTags(struct BBIInterface *this, BBArray *tag)
{
    return IExec(this)->CreateLibrary(BBINTARRAYTOTAGS(tag));
}

static struct Library * bbOpenLibrary(struct BBIInterface *this, BBString *name, ULONG version)
{
    return IExec(this)->OpenLibrary(NULLORCSTR(name), version);
}

static APTR bbCloseLibrary(struct BBIInterface *this, struct Library *library)
{
    return IExec(this)->CloseLibrary(library);
}

static void bbAddLibrary(struct BBIInterface *this, struct Library *library)
{
    IExec(this)->AddLibrary(library);
}

static ULONG bbRemLibrary(struct BBIInterface *this, struct Library *library)
{
    return IExec(this)->RemLibrary(library);
}

static void bbAddDevice(struct BBIInterface *this, struct Device *device)
{
    IExec(this)->AddDevice(device);
}

static ULONG bbRemDevice(struct BBIInterface *this, struct Device *device)
{
    return IExec(this)->RemDevice(device);
}

static struct Interface * bbGetInterface(struct BBIInterface *this, struct Library *library, BBString *name, ULONG version, const struct TagItem *taglist)
{
    return IExec(this)->GetInterface(library, NULLORCSTR(name), version, taglist);
}

static struct Interface * bbGetInterfaceTags(struct BBIInterface *this, struct Library *library, BBString *name, ULONG version, BBArray *tag1)
{
    return IExec(this)->GetInterface(library, NULLORCSTR(name), version, BBINTARRAYTOTAGS(tag1));
}

static void bbDropInterface(struct BBIInterface *this, struct Interface *interface)
{
    IExec(this)->DropInterface(interface);
}

static void bbAddInterface(struct BBIInterface *this, struct Library *library, struct Interface *interface)
{
    IExec(this)->AddInterface(library, interface);
}

static void bbRemInterface(struct BBIInterface *this, struct Interface *interface)
{
    IExec(this)->RemInterface(interface);
}

static void bbSumInterface(struct BBIInterface *this, struct Interface *interface)
{
    IExec(this)->SumInterface(interface);
}

static struct Resident * bbFindResident(struct BBIInterface *this, BBString *name)
{
    return IExec(this)->FindResident(NULLORCSTR(name));
}

static APTR bbSetMethod(struct BBIInterface *this, struct Interface *interface, LONG funcOffset, CONST_APTR newFunc)
{
    return IExec(this)->SetMethod(interface, funcOffset, newFunc);
}

static void bbDeleteInterface(struct BBIInterface *this, struct Interface *interface)
{
    IExec(this)->DeleteInterface(interface);
}

static void bbDeleteLibrary(struct BBIInterface *this, struct Library *library)
{
    IExec(this)->DeleteLibrary(library);
}

static APTR bbSetFunction(struct BBIInterface *this, struct Library *library, LONG funcOffset, CONST_APTR newFunc)
{
    return IExec(this)->SetFunction(library, funcOffset, newFunc);
}

static void bbCacheClearE(struct BBIInterface *this, APTR address, ULONG length, ULONG caches)
{
    IExec(this)->CacheClearE(address, length, caches);
}

static ULONG bbMakeFunctions(struct BBIInterface *this, APTR target, CONST_APTR functionArray, CONST_APTR funcDispBase)
{
    return IExec(this)->MakeFunctions(target, functionArray, funcDispBase);
}

static LONG bbOpenDevice(struct BBIInterface *this, BBString *devName, ULONG unitNumber, struct IORequest *ioRequest, ULONG flags)
{
    return IExec(this)->OpenDevice(NULLORCSTR(devName), unitNumber, ioRequest, flags);
}

static APTR bbCloseDevice(struct BBIInterface *this, struct IORequest *ioRequest)
{
    return IExec(this)->CloseDevice(ioRequest);
}

static void bbAbortIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    IExec(this)->AbortIO(ioRequest);
}

static struct IORequest * bbCheckIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    return IExec(this)->CheckIO(ioRequest);
}

static BYTE bbDoIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    return IExec(this)->DoIO(ioRequest);
}

static void bbSendIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    IExec(this)->SendIO(ioRequest);
}

static void bbBeginIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    IExec(this)->BeginIO(ioRequest);
}

static BYTE bbWaitIO(struct BBIInterface *this, struct IORequest *ioRequest)
{
    return IExec(this)->WaitIO(ioRequest);
}

static void bbAddResource(struct BBIInterface *this, APTR resource)
{
    IExec(this)->AddResource(resource);
}

static void bbRemResource(struct BBIInterface *this, APTR resource)
{
    IExec(this)->RemResource(resource);
}

static APTR bbOpenResource(struct BBIInterface *this, BBString *resName)
{
    return IExec(this)->OpenResource(NULLORCSTR(resName));
}

static BOOL bbAddIntServer(struct BBIInterface *this, ULONG intNum, struct Interrupt *interrupt)
{
    return IExec(this)->AddIntServer(intNum, interrupt);
}

static void bbRemIntServer(struct BBIInterface *this, ULONG intNum, struct Interrupt *interrupt)
{
    IExec(this)->RemIntServer(intNum, interrupt);
}

static struct Interrupt * bbSetIntVector(struct BBIInterface *this, ULONG intNum, const struct Interrupt *interrupt)
{
    return IExec(this)->SetIntVector(intNum, interrupt);
}

static void bbAlert(struct BBIInterface *this, ULONG alertNum)
{
    IExec(this)->Alert(alertNum);
}

static APTR bbSuperState(struct BBIInterface *this)
{
    return IExec(this)->SuperState();
}

static void bbUserState(struct BBIInterface *this, APTR sysStack)
{
    IExec(this)->UserState(sysStack);
}

static ULONG bbSupervisor(struct BBIInterface *this, APTR userFunc)
{
    return IExec(this)->Supervisor(userFunc);
}

static BOOL bbSetTaskTrap(struct BBIInterface *this, ULONG trapNum, CONST_APTR trapCode, CONST_APTR trapData)
{
    return IExec(this)->SetTaskTrap(trapNum, trapCode, trapData);
}

static struct AVLNode * bbAVL_AddNode(struct BBIInterface *this, struct AVLNode **root, struct AVLNode *node, AVLNODECOMP func)
{
    return IExec(this)->AVL_AddNode(root, node, func);
}

static struct AVLNode * bbAVL_FindFirstNode(struct BBIInterface *this, const struct AVLNode *root)
{
    return IExec(this)->AVL_FindFirstNode(root);
}

static struct AVLNode * bbAVL_FindLastNode(struct BBIInterface *this, const struct AVLNode *root)
{
    return IExec(this)->AVL_FindLastNode(root);
}

static struct AVLNode * bbAVL_FindNextNodeByAddress(struct BBIInterface *this, const struct AVLNode *root)
{
    return IExec(this)->AVL_FindNextNodeByAddress(root);
}

static struct AVLNode * bbAVL_FindNextNodeByKey(struct BBIInterface *this, const struct AVLNode *root, AVLKey key, AVLKEYCOMP func)
{
    return IExec(this)->AVL_FindNextNodeByKey(root, key, func);
}

static struct AVLNode * bbAVL_FindNode(struct BBIInterface *this, const struct AVLNode *root, AVLKey key, AVLKEYCOMP func)
{
    return IExec(this)->AVL_FindNode(root, key, func);
}

static struct AVLNode * bbAVL_FindPrevNodeByAddress(struct BBIInterface *this, const struct AVLNode *root)
{
    return IExec(this)->AVL_FindPrevNodeByAddress(root);
}

static struct AVLNode * bbAVL_FindPrevNodeByKey(struct BBIInterface *this, const struct AVLNode *root, AVLKey key, AVLKEYCOMP func)
{
    return IExec(this)->AVL_FindPrevNodeByKey(root, key, func);
}

static struct AVLNode * bbAVL_RemNodeByAddress(struct BBIInterface *this, struct AVLNode **root, struct AVLNode *node)
{
    return IExec(this)->AVL_RemNodeByAddress(root, node);
}

static struct AVLNode * bbAVL_RemNodeByKey(struct BBIInterface *this, struct AVLNode **root, AVLKey key, AVLKEYCOMP func)
{
    return IExec(this)->AVL_RemNodeByKey(root, key, func);
}

static ULONG bbCacheControl(struct BBIInterface *this, ULONG cacheBits, ULONG cacheMask)
{
    return IExec(this)->CacheControl(cacheBits, cacheMask);
}

static BOOL bbLockMem(struct BBIInterface *this, APTR baseAddress, ULONG size)
{
    return IExec(this)->LockMem(baseAddress, size);
}

static void bbUnlockMem(struct BBIInterface *this, APTR baseAddress, ULONG size)
{
    IExec(this)->UnlockMem(baseAddress, size);
}

static ULONG bbReallocVec(struct BBIInterface *this, APTR memBlock, ULONG newSize, ULONG flags)
{
    return IExec(this)->ReallocVec(memBlock, newSize, flags);
}

static APTR bbCachePreDMA(struct BBIInterface *this, CONST_APTR vaddr, ULONG *length, ULONG flags)
{
    return IExec(this)->CachePreDMA(vaddr, length, flags);
}

static void bbCachePostDMA(struct BBIInterface *this, CONST_APTR vaddr, ULONG *length, ULONG flags)
{
    IExec(this)->CachePostDMA(vaddr, length, flags);
}

static ULONG bbStartDMA(struct BBIInterface *this, CONST_APTR startAddr, ULONG blockSize, ULONG flags)
{
    return IExec(this)->StartDMA(startAddr, blockSize, flags);
}

static void bbEndDMA(struct BBIInterface *this, CONST_APTR startAddr, ULONG blockSize, ULONG flags)
{
    IExec(this)->EndDMA(startAddr, blockSize, flags);
}

static void bbGetDMAList(struct BBIInterface *this, CONST_APTR startAddr, ULONG blockSize, ULONG flags, struct DMAEntry *dmaList)
{
    IExec(this)->GetDMAList(startAddr, blockSize, flags, dmaList);
}

static struct Trackable * bbAddTrackable(struct BBIInterface *this, struct Task *usingTask, APTR object, struct Hook *destFunc)
{
    return IExec(this)->AddTrackable(usingTask, object, destFunc);
}

static struct Trackable * bbFindTrackable(struct BBIInterface *this, struct Task *usingTask, APTR object)
{
    return IExec(this)->FindTrackable(usingTask, object);
}

static struct Trackable * bbRemTrackable(struct BBIInterface *this, struct Task *usingTask, struct Trackable *trackable)
{
    return IExec(this)->RemTrackable(usingTask, trackable);
}

static void bbDeleteTrackable(struct BBIInterface *this, struct Trackable *trackable)
{
    IExec(this)->DeleteTrackable(trackable);
}

static APTR bbAllocSysObject(struct BBIInterface *this, ULONG type, const struct TagItem *tags)
{
    return IExec(this)->AllocSysObject(type, tags);
}

static APTR bbAllocSysObjectTags(struct BBIInterface *this, ULONG type, BBArray *tag1)
{
    return IExec(this)->AllocSysObject(type, BBINTARRAYTOTAGS(tag1));
}

static void bbFreeSysObject(struct BBIInterface *this, ULONG type, APTR object)
{
    IExec(this)->FreeSysObject(type, object);
}

static void bbSuspendTask(struct BBIInterface *this, struct Task *whichTask, ULONG flags)
{
    IExec(this)->SuspendTask(whichTask, flags);
}

static void bbRestartTask(struct BBIInterface *this, struct Task *whichTask, ULONG flags)
{
    IExec(this)->RestartTask(whichTask, flags);
}

static void bbMoveList(struct BBIInterface *this, struct List *destinationList, struct List *sourceList)
{
    IExec(this)->MoveList(destinationList, sourceList);
}

static void bbNewList(struct BBIInterface *this, struct List *list)
{
    IExec(this)->NewList(list);
}

static void bbNewMinList(struct BBIInterface *this, struct MinList *list)
{
    IExec(this)->NewMinList(list);
}

static void bbColdReboot(struct BBIInterface *this)
{
    IExec(this)->ColdReboot();
}

static struct Library * bbMakeLibrary(struct BBIInterface *this, CONST_APTR vectors, CONST_APTR structure, CONST_APTR init, ULONG dataSize, APTR segList)
{
    return IExec(this)->MakeLibrary(vectors, structure, init, dataSize, segList);
}

static ULONG bbEmulate(struct BBIInterface *this, CONST_APTR InitPC, const struct TagItem *tagList)
{
    return IExec(this)->Emulate(InitPC, tagList);
}

static ULONG bbEmulateTags(struct BBIInterface *this, CONST_APTR InitPC, BBArray *tag1)
{
    return IExec(this)->Emulate(InitPC, BBINTARRAYTOTAGS(tag1));
}


static BOOL bbIsNative(struct BBIInterface *this, CONST_APTR code)
{
    return IExec(this)->IsNative(code);
}

static void bbGetCPUInfo(struct BBIInterface *this, const struct TagItem *TagList)
{
    IExec(this)->GetCPUInfo(TagList);
}

static void bbGetCPUInfoTags(struct BBIInterface *this, BBArray *tag1)
{
    IExec(this)->GetCPUInfo(BBINTARRAYTOTAGS(tag1));
}

static struct Task * bbOwnerOfMem(struct BBIInterface *this, CONST_APTR Address)
{
    return IExec(this)->OwnerOfMem(Address);
}

static BOOL bbAddResetCallback(struct BBIInterface *this, struct Interrupt *resetCallback)
{
    return IExec(this)->AddResetCallback(resetCallback);
}

static void bbRemResetCallback(struct BBIInterface *this, struct Interrupt *resetCallback)
{
    IExec(this)->RemResetCallback(resetCallback);
}

static APTR bbItemPoolAlloc(struct BBIInterface *this, APTR itemPool)
{
    return IExec(this)->ItemPoolAlloc(itemPool);
}

static void bbItemPoolFree(struct BBIInterface *this, APTR itemPool, APTR item)
{
    IExec(this)->ItemPoolFree(itemPool, item);
}

static void bbItemPoolGC(struct BBIInterface *this, APTR itemPool)
{
    IExec(this)->ItemPoolGC(itemPool);
}

static uint32 bbItemPoolControl(struct BBIInterface *this, APTR itemPool, const struct TagItem *tagList)
{
    return IExec(this)->ItemPoolControl(itemPool, tagList);
}

static uint32 bbItemPoolControlTags(struct BBIInterface *this, APTR itemPool, BBArray *tag1)
{
    return IExec(this)->ItemPoolControl(itemPool, BBINTARRAYTOTAGS(tag1));
}

static void bbItemPoolFlush(struct BBIInterface *this, APTR itemPool)
{
    IExec(this)->ItemPoolFlush(itemPool);
}

static struct Node * bbGetHead(struct BBIInterface *this, struct List *list)
{
    return IExec(this)->GetHead(list);
}

static struct Node * bbGetTail(struct BBIInterface *this, struct List *list)
{
    return IExec(this)->GetTail(list);
}

static struct Node * bbGetSucc(struct BBIInterface *this, struct Node *node)
{
    return IExec(this)->GetSucc(node);
}

static struct Node * bbGetPred(struct BBIInterface *this, struct Node *node)
{
    return IExec(this)->GetPred(node);
}

static void bbIceColdReboot(struct BBIInterface *this)
{
    IExec(this)->IceColdReboot();
}

static void bbObsolete1(struct BBIInterface *this)
{
    IExec(this)->Obsolete1();
}

static void bbObsolete2(struct BBIInterface *this)
{
    IExec(this)->Obsolete2();
}

static void bbObsolete3(struct BBIInterface *this)
{
    IExec(this)->Obsolete3();
}

static APTR bbRMapAlloc(struct BBIInterface *this, APTR Map, uint32 size, uint32 flags)
{
    return IExec(this)->RMapAlloc(Map, size, flags);
}

static void bbRMapFree(struct BBIInterface *this, APTR Map, APTR addr, uint32 size)
{
    IExec(this)->RMapFree(Map, addr, size);
}

static APTR bbAllocVecTagList(struct BBIInterface *this, uint32 size, const struct TagItem *tags)
{
    return IExec(this)->AllocVecTagList(size, tags);
}

static APTR bbAllocVecTags(struct BBIInterface *this, uint32 size, BBArray *tag1)
{
    return IExec(this)->AllocVecTagList(size, BBINTARRAYTOTAGS(tag1));
}

static APTR bbRMapExtAlloc(struct BBIInterface *this, APTR Map, uint32 size, uint32 alignment, uint32 flags)
{
    return IExec(this)->RMapExtAlloc(Map, size, alignment, flags);
}

static void bbRMapExtFree(struct BBIInterface *this, APTR Map, APTR addr, uint32 size)
{
    IExec(this)->RMapExtFree(Map, addr, size);
}

static APTR bbAllocNamedMemory(struct BBIInterface *this, uint32 byteSize, BBString *space, BBString *name, struct TagItem *tagList)
{
    return IExec(this)->AllocNamedMemory(byteSize, NULLORCSTR(space), NULLORCSTR(name), tagList);
}

static APTR bbAllocNamedMemoryTags(struct BBIInterface *this, uint32 byteSize, BBString *space, BBString *name, BBArray *tag)
{
    return IExec(this)->AllocNamedMemory(byteSize, NULLORCSTR(space), NULLORCSTR(name), BBINTARRAYTOTAGS(tag));
}

static BOOL bbFreeNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    return IExec(this)->FreeNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static void * bbFindNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    return IExec(this)->FindNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static void bbUpdateNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    IExec(this)->UpdateNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static void * bbLockNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    return IExec(this)->LockNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static void * bbAttemptNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    return IExec(this)->AttemptNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static void bbUnlockNamedMemory(struct BBIInterface *this, BBString *space, BBString *name)
{
    IExec(this)->UnlockNamedMemory(NULLORCSTR(space), NULLORCSTR(name));
}

static uint32 bbScanNamedMemory(struct BBIInterface *this, struct Hook *scHook, uint32 flags, APTR user)
{
    return IExec(this)->ScanNamedMemory(scHook, flags, user);
}

static struct MemList * bbAllocTaskMemEntry(struct BBIInterface *this, struct MemList *memList)
{
    return IExec(this)->AllocTaskMemEntry(memList);
}

static VOID bbMutexObtain(struct BBIInterface *this, APTR Mutex)
{
    IExec(this)->MutexObtain(Mutex);
}

static BOOL bbMutexAttempt(struct BBIInterface *this, APTR Mutex)
{
    return IExec(this)->MutexAttempt(Mutex);
}

static VOID bbMutexRelease(struct BBIInterface *this, APTR Mutex)
{
    IExec(this)->MutexRelease(Mutex);
}

static uint32 bbMutexAttemptWithSignal(struct BBIInterface *this, APTR Mutex, uint32 SigSet)
{
    return IExec(this)->MutexAttemptWithSignal(Mutex, SigSet);
}

static int32 bbNewStackRun(struct BBIInterface *this, APTR initPC, const struct TagItem *TagList)
{
    return IExec(this)->NewStackRun(initPC, TagList);
}

static int32 bbNewStackRunTags(struct BBIInterface *this, APTR initPC, BBArray *tag1)
{
    return IExec(this)->NewStackRun(initPC, BBINTARRAYTOTAGS(tag1));
}





static void* _ExecLibraryVTable[] = {
	    bbAddHead,
     bbAddMemHandler,
     bbAddTail,
     bbAllocPooled,
     bbAllocVecPooled,
     bbAvailMem,
     bbCopyMem,
     bbCopyMemQuick,
     bbEnqueue,
     bbFindName,
     bbFindIName,
     bbForbid,
     bbFreeEntry,
     bbFreePooled,
     bbFreeVec,
     bbFreeVecPooled,
     bbInsert,
     bbMakeInterface,
     bbMakeInterfaceTags,
     bbPermit,
     bbRawDoFmt,
     bbRemHead,
     bbRemMemHandler,
     bbRemove,
     bbRemTail,
     bbTypeOfMem,
     bbInitResident,
     bbInitCode,
     bbSumKickData,
     bbAddTask,
     bbAddTaskTags,
     bbDisable,
     bbEnable,
     bbFindTask,
     bbRemTask,
     bbSetTaskPri,
     bbAllocSignal,
     bbFreeSignal,
     bbSetExcept,
     bbSetSignal,
     bbSignal,
     bbWait,
     bbAddPort,
     bbFindPort,
     bbGetMsg,
     bbPutMsg,
     bbRemPort,
     bbReplyMsg,
     bbWaitPort,
     bbCause,
     bbAddSemaphore,
     bbAttemptSemaphore,
     bbAttemptSemaphoreShared,
     bbFindSemaphore,
     bbInitSemaphore,
     bbObtainSemaphore,
     bbObtainSemaphoreList,
     bbObtainSemaphoreShared,
     bbProcure,
     bbReleaseSemaphore,
     bbReleaseSemaphoreList,
     bbRemSemaphore,
     bbVacate,
     bbCreateTask,
     bbCreateTaskTags,
     bbDeleteTask,
     bbSumLibrary,
     bbCreateLibrary,
     bbCreateLibraryTags,
     bbOpenLibrary,
     bbCloseLibrary,
     bbAddLibrary,
     bbRemLibrary,
     bbAddDevice,
     bbRemDevice,
     bbGetInterface,
     bbGetInterfaceTags,
     bbDropInterface,
     bbAddInterface,
     bbRemInterface,
     bbSumInterface,
     bbFindResident,
     bbSetMethod,
     bbDeleteInterface,
     bbDeleteLibrary,
     bbSetFunction,
     bbCacheClearE,
     bbMakeFunctions,
     bbOpenDevice,
     bbCloseDevice,
     bbAbortIO,
     bbCheckIO,
     bbDoIO,
     bbSendIO,
     bbBeginIO,
     bbWaitIO,
     bbAddResource,
     bbRemResource,
     bbOpenResource,
     bbAddIntServer,
     bbRemIntServer,
     bbSetIntVector,
     bbAlert,
     bbSuperState,
     bbUserState,
     bbSupervisor,
     bbSetTaskTrap,
     bbAVL_AddNode,
     bbAVL_FindFirstNode,
     bbAVL_FindLastNode,
     bbAVL_FindNextNodeByAddress,
     bbAVL_FindNextNodeByKey,
     bbAVL_FindNode,
     bbAVL_FindPrevNodeByAddress,
     bbAVL_FindPrevNodeByKey,
     bbAVL_RemNodeByAddress,
     bbAVL_RemNodeByKey,
     bbCacheControl,
     bbLockMem,
     bbUnlockMem,
     bbReallocVec,
     bbCachePreDMA,
     bbCachePostDMA,
     bbStartDMA,
     bbEndDMA,
     bbGetDMAList,
     bbAddTrackable,
     bbFindTrackable,
     bbRemTrackable,
     bbDeleteTrackable,
     bbAllocSysObject,
     bbAllocSysObjectTags,
     bbFreeSysObject,
     bbSuspendTask,
     bbRestartTask,
     bbMoveList,
     bbNewList,
     bbNewMinList,
     bbColdReboot,
     bbMakeLibrary,
     bbEmulate,
     bbEmulateTags,
     bbIsNative,
     bbGetCPUInfo,
     bbGetCPUInfoTags,
     bbOwnerOfMem,
     bbAddResetCallback,
     bbRemResetCallback,
     bbItemPoolAlloc,
     bbItemPoolFree,
     bbItemPoolGC,
     bbItemPoolControl,
     bbItemPoolControlTags,
     bbItemPoolFlush,
     bbGetHead,
     bbGetTail,
     bbGetSucc,
     bbGetPred,
     bbIceColdReboot,
     bbObsolete1,
     bbObsolete2,
     bbObsolete3,
     bbRMapAlloc,
     bbRMapFree,
     bbAllocVecTagList,
     bbAllocVecTags,
     bbRMapExtAlloc,
     bbRMapExtFree,
     bbAllocNamedMemory,
     bbAllocNamedMemoryTags,
     bbFreeNamedMemory,
     bbFindNamedMemory,
     bbUpdateNamedMemory,
     bbLockNamedMemory,
     bbAttemptNamedMemory,
     bbUnlockNamedMemory,
     bbScanNamedMemory,
     bbAllocTaskMemEntry,
     bbMutexObtain,
     bbMutexAttempt,
     bbMutexRelease,
     bbMutexAttemptWithSignal,
     bbNewStackRun,
     bbNewStackRunTags
};

static struct BBLibrary  ExecLibrary = {
	"exec.library",
	50,
	"main",
	1,
	_ExecLibraryVTable,
	NULL,
	NULL,
	&IExec
};

struct BBLibrary *bbExecLibrary = &ExecLibrary;