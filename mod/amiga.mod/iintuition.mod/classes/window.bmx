Rem
  classes/window.h
End Rem

Rem
** Attributes specific to window.class
End Rem

Const  WINDOW_Dummy : Int =   (REACTION_Dummy + $25000)

Const WINDOW_Window             : Int = (WINDOW_Dummy  + 1)
Const WINDOW_SigMask            : Int = (WINDOW_Dummy  + 2)
Const WINDOW_MenuStrip          : Int = (WINDOW_Dummy  + 4)

Const WINDOW_Layout             : Int = (WINDOW_Dummy  + 5)
Const WINDOW_ParentLayout  :Int =      WINDOW_Layout
Const WINDOW_ParentGroup    :Int =    WINDOW_Layout
Const WINDOW_UserData           : Int = (WINDOW_Dummy  + 6)
Const WINDOW_SharedPort         : Int = (WINDOW_Dummy  + 7)
Const WINDOW_Zoom               : Int = (WINDOW_Dummy  + 8)
Const WINDOW_FrontBack          : Int = (WINDOW_Dummy  + 9)
Const WINDOW_Activate           : Int = (WINDOW_Dummy  + 10)
Const WINDOW_LockWidth          : Int = (WINDOW_Dummy  + 11)
Const WINDOW_LockHeight         : Int = (WINDOW_Dummy  + 12)
Const WINDOW_AppPort            : Int = (WINDOW_Dummy  + 13)
Const WINDOW_Position           : Int = (WINDOW_Dummy  + 14)
Const WINDOW_IDCMPHook          : Int = (WINDOW_Dummy  + 15)
Const WINDOW_IDCMPHookBits      : Int = (WINDOW_Dummy  + 16)
Const WINDOW_GadgetUserData     : Int = (WINDOW_Dummy  + 17)
Const WINDOW_InterpretUserData  :Int = WINDOW_GadgetUserData
Const WINDOW_MenuUserData       : Int = (WINDOW_Dummy  + 25)  
Const WGUD_HOOK  :Int = 0
Const WGUD_FUNC   : Int = 1 
Const WGUD_IGNORE : Int = 2 

Const WINDOW_IconTitle          : Int = (WINDOW_Dummy  + 18)
Const WINDOW_AppMsgHook         : Int = (WINDOW_Dummy  + 19)
Const WINDOW_Icon               : Int = (WINDOW_Dummy  + 20)
Const WINDOW_AppWindow          : Int = (WINDOW_Dummy  + 21)
Const WINDOW_GadgetHelp         : Int = (WINDOW_Dummy  + 22)
Const WINDOW_IconifyGadget      : Int = (WINDOW_Dummy  + 23)
Const WINDOW_TextAttr           : Int = (WINDOW_Dummy  + 24)
Const WINDOW_BackFillName       : Int = (WINDOW_Dummy  + 26)
Const WINDOW_RefWindow          : Int = (WINDOW_Dummy  + 41)
Const WINDOW_InputEvent         : Int = (WINDOW_Dummy  + 42)
Const WINDOW_HintInfo           : Int = (WINDOW_Dummy  + 43)
Const WINDOW_KillWindow         : Int = (WINDOW_Dummy  + 44)
Const WINDOW_Application        : Int = (WINDOW_Dummy  + 45)
Const WINDOW_InterpretIDCMPHook : Int = (WINDOW_Dummy  + 46)
Const WINDOW_Parent             : Int = (WINDOW_Dummy  + 47)
Const WINDOW_PreRefreshHook     : Int = (WINDOW_Dummy  + 48)
Const WINDOW_PostRefreshHook    : Int = (WINDOW_Dummy  + 49)
Const WINDOW_AppWindowPtr       : Int = (WINDOW_Dummy  + 50)
Const WINDOW_VertProp           : Int = (WINDOW_Dummy  + 27) 
Const WINDOW_VertObject         : Int = (WINDOW_Dummy  + 28)
Const WINDOW_HorizProp          : Int = (WINDOW_Dummy  + 29)
Const WINDOW_HorizObject        : Int = (WINDOW_Dummy  + 30)  
Const WINDOW_IconNoDispose      : Int = (WINDOW_Dummy  + 51) 
Const WINDOW_NewMenu            : Int = (WINDOW_Dummy  + 52)
Const WINDOW_Qualifier          : Int = (WINDOW_Dummy  + 53)
Const WINDOW_CharSet            : Int = (WINDOW_Dummy  + 54)
Const WINDOW_BuiltInScroll      : Int = (WINDOW_Dummy  + 55)
Const WINDOW_IDCMPSnoopHook     : Int = (WINDOW_Dummy  + 56)
 Const WINDOW_ShowingHint        : Int = (WINDOW_Dummy  + 57)
Const WINDOW_NewPrefsHook       : Int = (WINDOW_Dummy  + 58)
Const WINDOW_Iconifiable        : Int = (WINDOW_Dummy  + 59)  
Const WINDOW_PopupGadget        : Int = (WINDOW_Dummy  + 60)
Const WINDOW_PopupHook          : Int = (WINDOW_Dummy  + 61) 
Const WINDOW_PopupItem          : Int = (WINDOW_Dummy  + 62)  
Const WINDOW_JumpScreensMenu    : Int = (WINDOW_Dummy  + 63)
Const WINDOW_UniqueID           : Int = (WINDOW_Dummy  + 64)
Const WINDOW_MenuAddress        : Int = (WINDOW_Dummy  + 65)
Const WINDOW_MenuType           : Int = (WINDOW_Dummy  + 66)
Const WINDOW_MenuContext        : Int = (WINDOW_Dummy  + 67)
 
Const WMHI_LASTMSG    :  Int =   0
Const WMHI_IGNORE       :  Int = $FFFFFFFF
Const WMHI_GADGETMASK   : Int =   ($ffff)
Const WMHI_MENUMASK       : Int =  ($ffff) 
Const WMHI_KEYMASK         : Int = ($ff)
Const WMHI_CLASSMASK   :Int = ($ffff0000)
Const WMHI_CLOSEWINDOW   : Int =  (1 shl 16) 
Const WMHI_GADGETUP         : Int =  (2 shl 16) 
Const WMHI_INACTIVE         : Int =  (3 shl 16) 
Const WMHI_ACTIVE          : Int =  (4 shl 16) 
Const WMHI_NEWSIZE         : Int =  (5 shl 16) 
Const WMHI_MENUPICK        : Int =  (6 shl 16) 
Const WMHI_MENUHELP        : Int =  (7 shl 16) 
Const WMHI_GADGETHELP     : Int =  (8 shl 16) 
Const WMHI_ICONIFY          : Int =  (9 shl 16) 
Const WMHI_UNICONIFY     : Int =  (10 shl 16) 
Const WMHI_RAWKEY          : Int =  (11 shl 16) 
Const WMHI_VANILLAKEY      : Int =  (12 shl 16) 
Const WMHI_CHANGEWINDOW    : Int =  (13 shl 16) 
Const WMHI_INTUITICK       : Int =  (14 shl 16) 
Const WMHI_MOUSEMOVE      : Int =  (15 shl 16) 
Const WMHI_MOUSEBUTTONS    : Int =  (16 shl 16) 
Const WMHI_DISPOSEDWINDOW  : Int =  (17 shl 16) 
Const WMHI_JUMPSCREEN      : Int =  (18 shl 16) 
Const WMHI_POPUPMENU       : Int =  (19 shl 16) 
Const WMHI_GADGETDOWN      : Int =  (20 shl 16) 

Const WHOOKRSLT_IGNORE     :Int = 0  
Const WHOOKRSLT_CLOSEWINDOW  :Int = 1 
Const WHOOKRSLT_DISPOSEWINDOW: Int = 2

Const WMF_ZOOMED  :Int = $0001
Const WMF_ZIPWINDOW : Int = $0002


Const WT_FRONT : Int =TRUE
Const WT_BACK   : Int = FALSE

Const WPOS_CENTERSCREEN : Int= 1
Const WPOS_CENTERMOUSE : Int = 2
Const WPOS_TOPLEFT     : Int = 3
Const WPOS_CENTERWINDOW : Int = 4
Const WPOS_FULLSCREEN   :Int = 5

Rem
 * Window Methods
End Rem

Const WM_HANDLEINPUT : Int = ($570001)

Type TwmHandle Extends TMsg
	Field _wmh_Code : Short Ptr
	Field _storage    : Short
	
	Method New()
		MethodId = WM_HANDLEINPUT 
		_wmh_Code = varptr _storage
	End Method
	
	Method Code:Short()
		Return _storage
	End Method
End Type

Const WM_OPEN       : Int =    ($570002)
Const WM_CLOSE      : Int =    ($570003)
Const WM_NEWPREFS :Int =   ($570004)
Const WM_ICONIFY      :Int =   ($570005)
Const WM_RETHINK     :Int =   ($570006)
Const WM_ACTIVATEGADGET : Int =  ($570007)

Type TwmActivateGadget Extends TMsg
	Field _wma_Object: TGadget
	
	Method New()
		MethodId = WM_ACTIVATEGADGET		
	End Method
	
	Function Create:TwmActivateGadget(Gadget:TGadget)
		Local msg : TwmActivateGadget = New TwmActivateGadget
		msg._wma_Object = Gadget
		Return msg
	End Function	
End Type


Const WM_SNAPSHOT  : Int  =  ($570008)

Type TwmSnapshot Extends TMsg
	Const SAVE : Int = 0
	Const USE  :  Int = 1
	
	Field _How : Int
	
	Method New()
    		MethodID = WM_SNAPSHOT
    	End Method
    	
    	Function Create:TwmSnapshot(How:Int=SAVE)
    		Local msg :TwmSnapshot = New TwmSnapshot
    		msg._How = How
    		Return msg
    	End Function	
    	
End Type


Const WM_UNSNAPSHOT : Int = ($570009)
Const WM_RESTORE        : Int = ($570010)