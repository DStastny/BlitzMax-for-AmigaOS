SuperStrict
 
Module amiga.exec
ModuleInfo "Verison: 0.01"
ModuleInfo "License zlib/libpng"
ModuleInfo "Author:Doug Stastny"


?AmigaOS4
Import amiga.amigaos
Import "*.h"
Import "exec.c"

Extern
    Global ExecLibrary : TLibrary = "bbExecLibrary"
    
    Type TAVLNode Extends TAPTR
    End Type

    Type TInterrupt Extends TAPTR
    End Type

    Type TMsgPort Extends TAPTR
    End Type

    Type TResident Extends TAPTR
    End Type

    Type TTask Extends TAPTR
    End Type

    Type TDMAEntry Extends TAPTR
    End Type

    Type TDebugSymbol Extends TAPTR
    End Type

    Type TDevice Extends TAPTR
    End Type

    Type TExceptionContext Extends TAPTR
    End Type

    Type THook Extends TAPTR
    End Type

    Type TIORequest Extends TAPTR
    End Type

    Type TInterface Extends TAPTR
    End Type

    Type TList_ Extends TAPTR
    End Type

    Type TMemHeader Extends TAPTR
    End Type

    Type TMemList Extends TAPTR
    End Type

    Type TMessage Extends TAPTR
    End Type

    Type TMinList Extends TAPTR
    End Type

    Type TNode Extends TAPTR
    End Type

    Type TSemaphoreMessage Extends TAPTR
    End Type

    Type TSignalSemaphore Extends TAPTR
    End Type

    Type TStackSwapStruct Extends TAPTR
    End Type

    Type TTrackable Extends TAPTR
    End Type

    Type IIExec Extends IInterface
        Method AddHead(list : TList, node : TNode)
        Method AddMemHandler(memHandler : TInterrupt)
        Method AddTail(list : TList, node : TNode)
        Method AllocPooled: TAPTR(poolHeader : TAPTR, memSize : Int)
        Method AllocVecPooled: TAPTR(poolHeader : TAPTR, size : Int)
        Method AvailMem: Int(attributes : Int)
        Method CopyMem(source : TAPTR, dest : TAPTR, size : Int)
        Method CopyMemQuick(source : TAPTR, dest : TAPTR, size : Int)
        Method Enqueue(list : TList, node : TNode)
        Method FindName: TNode(start : TList, name : String)
        Method FindIName: TNode(start : TList, name : String)
        Method Forbid()
        Method FreeEntry(memList : TMemList)
        Method FreePooled(poolHeader : TAPTR, memory : TAPTR, memSize : Int)
        Method FreeVec(memoryBlock : TAPTR)
        Method FreeVecPooled(poolHeader : TAPTR, memory : TAPTR)
        Method Insert(list : TList, node : TNode, listNode : TNode)
        Method MakeInterface: TInterface(library : TLibrary, taglist : TTagItems)
        Method MakeInterfaceTags: TInterface(library : TLibrary, tag : Int[])
        Method Permit()
        Method RawDoFmt: TAPTR(formatString : String, dataStream : TAPTR, PutChProc(), PutChData : TAPTR)
        Method RemHead: TNode(list : TList)
        Method RemMemHandler(memHandler : TInterrupt)
        Method Remove(node : TNode)
        Method RemTail: TNode(list : TList)
        Method TypeOfMem: Int(address : TAPTR)
        Method InitResident: TAPTR(resident : TResident, segList : Int)
        Method InitCode(startClass : Int, version : Int)
        Method SumKickData: Int()
        Method AddTask: TAPTR(task : TTask, initialPC : TAPTR, finalPC : TAPTR, tagList : TTagItems)
        Method AddTaskTags: TAPTR(task : TTask, initialPC : TAPTR, finalPC : TAPTR, tag : Int[])
        Method Disable()
        Method Enable()
        Method FindTask: TTask(name : String)
        Method RemTask(task : TTask)
        Method SetTaskPri: Byte(task : TTask, priority : Byte)
        Method AllocSignal: Byte(signalNum : Byte)
        Method FreeSignal(signalNum : Byte)
        Method SetExcept: Int(newSignals : Int, signalMask : Int)
        Method SetSignal: Int(newSignals : Int, signalMask : Int)
        Method Signal(task : TTask, signals : Int)
        Method Wait: Int(signalSet : Int)
        Method AddPort(port : TMsgPort)
        Method FindPort: TMsgPort(name : String)
        Method GetMsg: TMessage(port : TMsgPort)
        Method PutMsg(port : TMsgPort, message : TMessage)
        Method RemPort(port : TMsgPort)
        Method ReplyMsg(message : TMessage)
        Method WaitPort: TMessage(port : TMsgPort)
        Method Cause(interrupt : TInterrupt)
        Method AddSemaphore(semaphore : TSignalSemaphore)
        Method AttemptSemaphore: Int(semaphore : TSignalSemaphore)
        Method AttemptSemaphoreShared: Int(semaphore : TSignalSemaphore)
        Method FindSemaphore: TSignalSemaphore(name : String)
        Method InitSemaphore(semaphore : TSignalSemaphore)
        Method ObtainSemaphore(semaphore : TSignalSemaphore)
        Method ObtainSemaphoreList(list : TList)
        Method ObtainSemaphoreShared(semaphore : TSignalSemaphore)
        Method Procure(semaphore : TSignalSemaphore, bidMessage : TSemaphoreMessage)
        Method ReleaseSemaphore(semaphore : TSignalSemaphore)
        Method ReleaseSemaphoreList(list : TList)
        Method RemSemaphore(semaphore : TSignalSemaphore)
        Method Vacate(semaphore : TSignalSemaphore, bidMessage : TSemaphoreMessage)
        Method CreateTask: TTask(name : String, pri : Int, initPC : TAPTR, stackSize : Int, tagList : TTagItems)
        Method CreateTaskTags: TTask(name : String, pri : Int, initPC : TAPTR, stackSize : Int, tag : Int[])
        Method DeleteTask(task : TTask)
        Method SumLibrary(library : TLibrary)
        Method CreateLibrary: TLibrary(taglist : TTagItems)
        Method CreateLibraryTags: TLibrary(tag : Int[])
        Method OpenLibrary: TLibrary(name : String, version : Int)
        Method CloseLibrary: TAPTR(library : TLibrary)
        Method AddLibrary(library : TLibrary)
        Method RemLibrary: Int(library : TLibrary)
        Method AddDevice(device : TDevice)
        Method RemDevice: Int(device : TDevice)
        Method GetInterface: TInterface(library : TLibrary, name : String, version : Int, taglist : TTagItems)
        Method GetInterfaceTags: TInterface(library : TLibrary, name : String, version : Int, tag1 : Int[])
        Method DropInterface(interface : TInterface)
        Method AddInterface(library : TLibrary, interface : TInterface)
        Method RemInterface(interface : TInterface)
        Method SumInterface(interface : TInterface)
        Method FindResident: TResident(name : String)
        Method SetMethod: TAPTR(interface : TInterface, funcOffset : Int, newFunc : TAPTR)
        Method DeleteInterface(interface : TInterface)
        Method DeleteLibrary(library : TLibrary)
        Method SetFunction: TAPTR(library : TLibrary, funcOffset : Int, newFunc : TAPTR)
        Method CacheClearE(address : TAPTR, length : Int, caches : Int)
        Method MakeFunctions: Int(target : TAPTR, functionArray : TAPTR, funcDispBase : TAPTR)
        Method OpenDevice: Int(devName : String, unitNumber : Int, ioRequest : TIORequest, flags : Int)
        Method CloseDevice: TAPTR(ioRequest : TIORequest)
        Method AbortIO(ioRequest : TIORequest)
        Method CheckIO: TIORequest(ioRequest : TIORequest)
        Method DoIO: Byte(ioRequest : TIORequest)
        Method SendIO(ioRequest : TIORequest)
        Method BeginIO(ioRequest : TIORequest)
        Method WaitIO: Byte(ioRequest : TIORequest)
        Method AddResource(resource : TAPTR)
        Method RemResource(resource : TAPTR)
        Method OpenResource: TAPTR(resName : String)
        Method AddIntServer: Short(intNum : Int, interrupt : TInterrupt)
        Method RemIntServer(intNum : Int, interrupt : TInterrupt)
        Method SetIntVector: TInterrupt(intNum : Int, interrupt : TInterrupt)
        Method Alert(alertNum : Int)
        Method SuperState: TAPTR()
        Method UserState(sysStack : TAPTR)
        Method Supervisor: Int(userFunc : TAPTR)
        Method SetTaskTrap: Short(trapNum : Int, trapCode : TAPTR, trapData : TAPTR)
        Method AVL_AddNode: TAVLNode(root : TAVLNode Var, node : TAVLNode, func(a1:TAVLNode, a2:TAVLNode))
        Method AVL_FindFirstNode: TAVLNode(root : TAVLNode)
        Method AVL_FindLastNode: TAVLNode(root : TAVLNode)
        Method AVL_FindNextNodeByAddress: TAVLNode(root : TAVLNode)
        Method AVL_FindNextNodeByKey: TAVLNode(root : TAVLNode, key : Byte Ptr, func (a1:TAVLNode, a2:Byte Ptr))
        Method AVL_FindNode: TAVLNode(root : TAVLNode, key : byte ptr, func(a1:TAVLNode, a2:TAVLNode))
        Method AVL_FindPrevNodeByAddress: TAVLNode(root : TAVLNode)
        Method AVL_FindPrevNodeByKey: TAVLNode(root : TAVLNode, key : Byte Ptr, func (a1:TAVLNode, a2:Byte Ptr))
        Method AVL_RemNodeByAddress: TAVLNode(root : TAVLNode Var, func (a1:TAVLNode, a2:Byte Ptr))
        Method AVL_RemNodeByKey: TAVLNode(root : TAVLNode Var, key : Byte Ptr, func (a1:TAVLNode, a2:Byte Ptr))
        Method CacheControl: Int(cacheBits : Int, cacheMask : Int)
        Method LockMem: Short(baseAddress : TAPTR, size : Int)
        Method UnlockMem(baseAddress : TAPTR, size : Int)
        Method ReallocVec: Int(memBlock : TAPTR, newSize : Int, flags : Int)
        Method CachePreDMA: TAPTR(vaddr : TAPTR, length : Int Ptr, flags : Int)
        Method CachePostDMA(vaddr : TAPTR, length : Int Ptr, flags : Int)
        Method StartDMA: Int(startAddr : TAPTR, blockSize : Int, flags : Int)
        Method EndDMA(startAddr : TAPTR, blockSize : Int, flags : Int)
        Method GetDMAList(startAddr : TAPTR, blockSize : Int, flags : Int, dmaList : TDMAEntry)
        Method AddTrackable: TTrackable(usingTask : TTask, object_ : TAPTR, destFunc : THook)
        Method FindTrackable: TTrackable(usingTask : TTask, object_ : TAPTR)
        Method RemTrackable: TTrackable(usingTask : TTask, trackable : TTrackable)
        Method DeleteTrackable(trackable : TTrackable)
        Method AllocSysObject: TAPTR(type_ : Int, tags : TTagItems)
        Method AllocSysObjectTags: TAPTR(type_ : Int, tag1 : Int[])
        Method FreeSysObject(type_ : Int, object_ : TAPTR)
        Method SuspendTask(whichTask : TTask, flags : Int)
        Method RestartTask(whichTask : TTask, flags : Int)
        Method MoveList(destinationList : TList, sourceList : TList)
        Method NewList(list : TList)
        Method NewMinList(list : TMinList)
        Method ColdReboot()
        Method MakeLibrary: TLibrary(vectors : TAPTR, structure : TAPTR, init : TAPTR, dataSize : Int, segList : TAPTR)
        Method Emulate: Int(InitPC : TAPTR, tagList : TTagItems)
        Method EmulateTags: Int(InitPC : TAPTR, tag1 : Int[])
        Method IsNative: Short(code : TAPTR)
        Method GetCPUInfo(TagList : TTagItems)
        Method GetCPUInfoTags(tag1 : Int[])
        Method OwnerOfMem: TTask(Address : TAPTR)
        Method AddResetCallback: Short(resetCallback : TInterrupt)
        Method RemResetCallback(resetCallback : TInterrupt)
        Method ItemPoolAlloc: TAPTR(itemPool : TAPTR)
        Method ItemPoolFree(itemPool : TAPTR, item : TAPTR)
        Method ItemPoolGC(itemPool : TAPTR)
        Method ItemPoolControl: Int(itemPool : TAPTR, tagList : TTagItems)
        Method ItemPoolControlTags: Int(itemPool : TAPTR, tag1 : Int[])
        Method ItemPoolFlush(itemPool : TAPTR)
        Method GetHead: TNode(list : TList)
        Method GetTail: TNode(list : TList)
        Method GetSucc: TNode(node : TNode)
        Method GetPred: TNode(node : TNode)
        Method IceColdReboot()
        Method Obsolete1()
        Method Obsolete2()
        Method Obsolete3()
        Method RMapAlloc: TAPTR(Map : TAPTR, size : Int, flags : Int)
        Method RMapFree(Map : TAPTR, addr : TAPTR, size : Int)
        Method AllocVecTagList: TAPTR(size : Int, tags : TTagItems)
        Method AllocVecTags: TAPTR(size : Int, tag1 : Int[])
        Method RMapExtAlloc: TAPTR(Map : TAPTR, size : Int, alignment : Int, flags : Int)
        Method RMapExtFree(Map : TAPTR, addr : TAPTR, size : Int)
        Method AllocNamedMemory: TAPTR(byteSize : Int, space : String, name : String, tagList : TTagItems)
        Method AllocNamedMemoryTags: TAPTR(byteSize : Int, space : String, name : String, tag : Int[])
        Method FreeNamedMemory: Short(space : String, name : String)
        Method FindNamedMemory: Byte Ptr(space : String, name : String)
        Method UpdateNamedMemory(space : String, name : String)
        Method LockNamedMemory: Byte Ptr(space : String, name : String)
        Method AttemptNamedMemory: Byte Ptr(space : String, name : String)
        Method UnlockNamedMemory(space : String, name : String)
        Method ScanNamedMemory: Int(scHook : THook, flags : Int, user : TAPTR)
        Method AllocTaskMemEntry: TMemList(memList : TMemList)
        Method MutexObtain(Mutex : TAPTR)
        Method MutexAttempt: Short(Mutex : TAPTR)
        Method MutexRelease(Mutex : TAPTR)
        Method MutexAttemptWithSignal: Int(Mutex : TAPTR, SigSet : Int)
        Method NewStackRun: Int(initPC : TAPTR, TagList : TTagItems)
        Method NewStackRunTags: Int(initPC : TAPTR, tag1 : Int[])
    End Type
End Extern

REM
 * Object types for AllocSysObject
END REM

Rem
 * Tag items used by AllocSysObject
End Rem

Const ASO_NoTrack        : Int =  (TAG_USER +  1) ' Don't track this object (i.e. do not free automatically) 
Const ASO_MemoryOvr      : Int =  (TAG_USER +  2) ' Memory type override 

' IORequest 
Const ASOIOR_Size        : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOIOR_ReplyPort   : Int =  (TAG_USER + 11) ' ReplyPort to use 
Const ASOIOR_Duplicate   : Int =  (TAG_USER + 12) ' Source IO request to duplicate 

' Hook 
Const ASOHOOK_Size       : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOHOOK_Entry      : Int =  (TAG_USER + 11) ' The hook's entry 
Const ASOHOOK_Subentry   : Int =  (TAG_USER + 12) ' The hook's subentry field 
Const ASOHOOK_Data       : Int =  (TAG_USER + 13) ' The hook's user data 

' Interrupt 
Const ASOINTR_Size       : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOINTR_Code       : Int =  (TAG_USER + 11) ' Code pointer 
Const ASOINTR_Data       : Int =  (TAG_USER + 12) ' Data pointer 
Const ASOINTR_SoftInt   : Int = (TAG_USER + 13) ' Interrupt is used by Cause() 

' List 
Const ASOLIST_Size       : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOLIST_Type       : Int =  (TAG_USER + 11) ' Type to set for the list 
Const ASOLIST_Min        : Int =  (TAG_USER + 12) ' Create a minlist 

' DMAEntry array 
Const ASODMAE_Size       : Int =  (TAG_USER + 10) ' Raw size of the object 
Const ASODMAE_NumEntries : Int =  (TAG_USER + 11) ' Number of entries 

' List node 
Const ASONODE_Size       : Int =  (TAG_USER + 10) ' Size of the node 
Const ASONODE_Min        : Int =  (TAG_USER + 11) ' Make it a MinNode 
Const ASONODE_Type       : Int =  (TAG_USER + 12) ' Node's type 
Const ASONODE_Pri        : Int =  (TAG_USER + 13) ' Node's priority 
Const ASONODE_Name       : Int =  (TAG_USER + 14) ' Pointer to a node string 

' Message port 
Const ASOPORT_Size       : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOPORT_AllocSig   : Int =  (TAG_USER + 11) ' Allocate a signal 
Const ASOPORT_Action     : Int =  (TAG_USER + 12) ' Action at message arrival (see ports.h, enMsgPortActions) 
Const ASOPORT_Pri        : Int =  (TAG_USER + 13) ' Priority used when the port is added to a list 
Const ASOPORT_Name       : Int =  (TAG_USER + 14) ' Name for the port 
Const ASOPORT_Signal     : Int =  (TAG_USER + 15) ' Preallocted signal number 
Const ASOPORT_Target     : Int =  (TAG_USER + 16) ' MsgPort's target, either a task, or a softint 
Const ASOPORT_Public     : Int =  (TAG_USER + 17) ' Make the port public 
Const ASOPORT_CopyName   : Int =  (TAG_USER + 18) ' Copy the name string 


' Message 
Const ASOMSG_Size        : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOMSG_ReplyPort   : Int =  (TAG_USER + 11) ' Reply port 
Const ASOMSG_Length      : Int =  (TAG_USER + 12) ' Message length 
Const ASOMSG_Name        : Int =  (TAG_USER + 13) ' Name to put into the node 

' Signal semaphore 
Const ASOSEM_Size        : Int =  (TAG_USER + 10) ' Size of the object 
Const ASOSEM_Name        : Int =  (TAG_USER + 11) ' Name 
Const ASOSEM_Pri         : Int =  (TAG_USER + 12) ' Node's priority (only used on public semaphores) 
Const ASOSEM_Public      : Int =  (TAG_USER + 13) ' Semaphore is public and will be added to the system 
Const ASOSEM_CopyName    : Int =  (TAG_USER + 14) ' Copy the name string 

' TagItem array 
Const ASOTAGS_Size       : Int =  (TAG_USER + 10) ' Raw size of the object, i.e. in bytes 
Const ASOTAGS_NumEntries : Int =  (TAG_USER + 11) ' Number of tagitems 

' Memory Pool 
Const ASOPOOL_MFlags     : Int =  (TAG_USER + 10) ' Memory flags/requirements for this pool 
Const ASOPOOL_Puddle     : Int =  (TAG_USER + 11) ' Size of each puddle 
Const ASOPOOL_Threshold  : Int =  (TAG_USER + 12) ' Largest alloction size that goes into the puddle 
Const ASOPOOL_Protected  : Int =  (TAG_USER + 13) ' Protect pool with a semaphore 
Const ASOPOOL_Name       : Int =  (TAG_USER + 14) ' Name for the pool (for informational purpose only) 
Const ASOPOOL_CopyName   : Int =  (TAG_USER + 15) ' Copy the name string 
Const ASOPOOL_LockMem    : Int =  (TAG_USER + 16) ' Lock memory allocated 

' Item Pool 
Const ASOITEM_MFlags     : Int =  (TAG_USER + 10) ' Memory flags for the pool 
Const ASOITEM_ItemSize   : Int =  (TAG_USER + 11) ' Size of individual items 
Const ASOITEM_BatchSize  : Int =  (TAG_USER + 12) ' Amount of items to be allocated in one batch 
Const ASOITEM_MaxSize    : Int =  (TAG_USER + 13) ' Maximum amount of items allowed in pool 
Const ASOITEM_GCPolicy   : Int =  (TAG_USER + 14) ' Garbage collection policy 
Const ASOITEM_GCParameter: Int =  (TAG_USER + 15) ' Garbage collection parameter 
Const ASOITEM_Constructor: Int =  (TAG_USER + 16) ' Constructor hook 
Const ASOITEM_Destructor : Int =  (TAG_USER + 17) ' Destructor hook 
Const ASOITEM_Protected  : Int =  (TAG_USER + 18) ' Protect pool with a semaphore 

' Mutex 
Const ASOMUTEX_Recursive : Int =  (TAG_USER + 10) ' Make mutex recursive 

' ExtMem 
Const ASOEXTMEM_Size          : Int = (TAG_USER + 10) ' Size of extended memory area 
Const ASOEXTMEM_AllocationPolicy : Int = (TAG_USER + 11) ' Allocation policy 

Const ASOT_IOREQUEST        : Int =   0 ' /* IORequest */
Const ASOT_HOOK             : Int =   1 ' /* Hook */
Const ASOT_INTERRUPT        : Int =   2 ' /* Interrupt structure */
Const ASOT_LIST             : Int =   3 ' /* List and MinList */
Const ASOT_DMAENTRY         : Int =   4 ' /* DMAEntry array */
Const ASOT_NODE             : Int =   5 ' /* List node and MinNode */
Const ASOT_PORT             : Int =   6 ' /* Message port */
Const ASOT_MESSAGE          : Int =   7 ' /* Exec Message */
Const ASOT_SEMAPHORE    : Int =   8 ' /* Signal Semaphore */
Const ASOT_TAGLIST          : Int =   9 ' /* TagItem list */
Const ASOT_MEMPOOL          : Int = 10 ' /* Memory pool */
Const ASOT_ITEMPOOL         : Int = 11 ' /* Item pool */
Const ASOT_RMAP             : Int = 12 ' /* Resource map */
Const ASOT_MUTEX            : Int = 13 ' /* Mutex */
Const ASOT_EXTMEM       : Int = 14' /* Extended memory */




Global IExec : IIExec = IIExec(OpenLibrary(ExecLibrary))

?