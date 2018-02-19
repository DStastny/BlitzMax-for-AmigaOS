SuperStrict
 
Module amiga.amigaos
ModuleInfo "Verison: 0.01"
ModuleInfo "License zlib/libpng"
ModuleInfo "Author:Doug Stastny"


?AmigaOS4
Import brl.blitz
Import brl.linkedlist
Import "*.h"
Import "amigaos.c"
Import "tags.c"




Extern "C"
	Type TAPTR
	End Type
	
	Type TLibrary
	End Type

	Type IInterface
	End Type

	Type TTagItems Extends TAPTR
	End Type



	Function IntArrayToTagList : TTagItems(Tags:Int[]) = "bbIntArrayToTagList"
	Function FreeTagList(Tags:TTagItems) = "bbFreeTagList"

End Extern


Type TAmigaLibFail Extends TBlitzException
	Field _Msg : String
	Function Create:TAmigaLibFail(Lib : TLibrary)
		Local e: TAmigaLibFail = New TAmigaLibFail
		e._Msg = "Failed to Load : "+String.FromCString(Lib)
		Return e
	End Function
End Type

Function CastAPTR : TAPTR(I:Int) NoDebug
	Local r:TAPTR 
	Int Ptr(varptr R)[0]=i
	Return r
End Function

Function CastInt:Int(A:TAPTR) NoDebug
	Return Int Ptr(varptr A)[0]
End Function

Type TCStringCache
	Field _Size  : Int = 256 
	Field _Idx   : Int = 0
	Field _Cache : Byte Ptr[]

	Method New()
		_Cache = New Byte Ptr[_Size]
	End Method

	Method Delete()
		For local p:Byte Ptr = EachIn _Cache
			MemFree p
		Next
	End Method

	Method CStr : Byte Ptr(Txt:String)
		Local s : Byte Ptr = Txt.ToCString()
		Local idx : Int = AtomicAdd(_Idx,1) & (_Size-1)
		MemFree _Cache[idx]
		_Cache[idx] = s
		Return s
	End Method

	Method CastInt : Int(Txt:String)
		Return Int(CStr(Txt))
	End Method

End Type

Function LibName:String(Lib:TLibrary)
	If Lib = NULL Return "No Lib"
	Return String.FromCString( Byte Ptr Ptr(Byte Ptr(Lib))[0])
End Function

' constants for Tag.ti_Tag, control tag values 
Const TAG_DONE :  Int  = $0
Const TAG_END   :  Int  = $0
Const TAG_IGNORE :  Int = $1 
Const TAG_MORE   :  Int = $2
Const  TAG_SKIP   :  Int = $3


' differentiates user tags from control tags 
Const TAG_USER   :  Int = ($1 shl 31)


Function OpenLibrary:IInterface(Library:TLibrary)
	Return TLibManager.Instance.OpenLibrary(Library)
End Function


Function CloseLibrary(Intf: IInterface)
	TLibManager.Instance.CloseLibrary(Intf)
End Function


Private


Extern
	Function AtomicAdd(target:Int Var,value : Int) = "bbAtomicAdd"
	Function ObtainInterface:IInterface(Lib : TLibrary) = "bbObtainInterface"
	Function ReleaseInterface(Inf:IInterface) ="bbReleaseInterface"
End Extern


Type TLibItem
	Field Lib   : TLibrary
	Field Intf  : IInterface
	Field RefCount : Int
End Type

Type TLibManager
	Global Instance: TLibManager =  TLibManager.Init()
	Function Init:TLibManager()
		Function Cleanup()
			TLibManager.Instance.Purge()
		End Function
		OnEnd Cleanup
		Return New TLibManager
	End Function

	Field _Libs : TList = New TList
	
	Method Purge()
		While Not _Libs.IsEmpty()
			Local item:TLibItem = TLibItem(_Libs.RemoveLast())
'			WriteStdOut "Purge:"+LibName(item.Lib) +"~n"
			ReleaseInterface(item.Intf)
		Wend
	End Method
	
	Method OpenLibrary:IInterface(Lib:TLibrary)
'		WriteStdOut "OpenLibrary:"+LibName(Lib) +"~n"
		For Local item :TLibItem = EachIn _Libs
			If item.Lib = Lib 
				AtomicAdd(item.RefCount, 1)
				Return item.Intf
			End If
		Next
		Local newItem : TLibItem = New TLibItem
		newItem.Lib = Lib
		newItem.Intf = ObtainInterface(Lib)
		If newItem.Intf
			newItem.RefCount = 1
			_Libs.AddLast(newItem)
			Return newItem.Intf
		End If
		Throw New TAmigaLibFail.Create(Lib)
	End Method
	
	Method CloseLibrary(Intf:IInterface)
		If Not Intf Return
		For Local item :TLibItem = EachIn _Libs
			If item.Intf = Intf
				item.RefCount :-1
				If AtomicAdd(item.RefCount,-1) = 1
					_Libs.Remove( item)
					ReleaseInterface(item.Intf)
				End If
				Return
			End If
		Next
		RuntimeError "Unable to unload Lib"
	End Method
	
End Type

?
