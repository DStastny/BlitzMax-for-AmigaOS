SuperStrict

Module amiga.idos

ModuleInfo "Verison: 0.01"
ModuleInfo "License zlib/libpng"

ModuleInfo "Author:Doug Stastny"

?AmigaOS4
Import amiga.amigaos
Import "*.h"
Import "idos.c"


Extern
	Global DOSLibrary : TLibrary = "bbDOSLibrary"
	Type IIDOS Extends IInterface
		Method Printf(text:String) 
	End Type
End Extern



Const SIGBREAKB_CTRL_C : Int = 12
Const SIGBREAKB_CTRL_D : Int = 13
Const SIGBREAKB_CTRL_E : Int = 14
Const SIGBREAKB_CTRL_F : Int = 15

Const SIGBREAKF_CTRL_C  : Int =(1 shl SIGBREAKB_CTRL_C)
Const SIGBREAKF_CTRL_D : Int = (1 shl SIGBREAKB_CTRL_D)
Const SIGBREAKF_CTRL_E  : Int = (1 shl SIGBREAKB_CTRL_E)
Const SIGBREAKF_CTRL_F  : Int = (1 shl SIGBREAKB_CTRL_F)






Global IDOS : IIDOS = IIDOS(OpenLibrary(DOSLibrary))



?
