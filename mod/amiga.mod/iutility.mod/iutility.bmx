SuperStrict

Module amiga.iutility

ModuleInfo "Verison: 0.01"
ModuleInfo "License zlib/libpng"

ModuleInfo "Author:Doug Stastny"

?AmigaOS4
Import amiga.amigaos
Import "*.h"
Import "iutility.c"




Extern
	Global UtilityLibrary : TLibrary = "bbUtilityLibrary"

	Type IIUtility Extends IInterface
		Method AllocateTagItems:TTagItems(count:Int)
		Method FreeTagItems( taglist:TTagItems) 
	End Type 	
End Extern


Global IUtility : IIUTility =IIUTility(OpenLibrary(UtilityLibrary))

	
?