Const GA_Dummy            : Int =TAG_USER+$30000
Const GA_Left             : Int =GA_Dummy+1
Const GA_RelRight         : Int =GA_Dummy+2
Const GA_Top              : Int =GA_Dummy+3
Const GA_RelBottom        : Int =GA_Dummy+4
Const GA_Width            : Int =GA_Dummy+5
Const GA_RelWidth         : Int =GA_Dummy+6
Const GA_Height           : Int =GA_Dummy+7
Const GA_RelHeight        : Int =GA_Dummy+8
Const GA_Text             : Int =GA_Dummy+9
Const GA_Image            : Int =GA_Dummy+10
Const GA_Border           : Int =GA_Dummy+11
Const GA_SelectRender     : Int =GA_Dummy+12
Const GA_Highlight        : Int =GA_Dummy+13
Const GA_Disabled         : Int =GA_Dummy+14
Const GA_GZZGadget        : Int =GA_Dummy+15
Const GA_ID               : Int =GA_Dummy+16
Const GA_UserData         : Int =GA_Dummy+17
Const GA_SpecialInfo      : Int =GA_Dummy+18
Const GA_Selected         : Int =GA_Dummy+19
Const GA_EndGadget        : Int =GA_Dummy+20
Const GA_Immediate        : Int =GA_Dummy+21
Const GA_RelVerify        : Int =GA_Dummy+22
Const GA_FollowMouse      : Int =GA_Dummy+23
Const GA_RightBorder      : Int =GA_Dummy+24
Const GA_LeftBorder       : Int =GA_Dummy+25
Const GA_TopBorder        : Int =GA_Dummy+26
Const GA_BottomBorder     : Int =GA_Dummy+27
Const GA_ToggleSelect     : Int =GA_Dummy+28
Const GA_SysGadget        : Int =GA_Dummy+29
Const GA_SysGType         : Int =GA_Dummy+30
Const GA_Previous         : Int =GA_Dummy+31
Const GA_Next             : Int =GA_Dummy+32
Const GA_DrawInfo         : Int =GA_Dummy+33
Const GA_IntuiText        : Int =GA_Dummy+34
Const GA_LabelImage       : Int =GA_Dummy+35
Const GA_TabCycle         : Int =GA_Dummy+36
Const GA_GadgetHelp       : Int =GA_Dummy+37
Const GA_Bounds           : Int =GA_Dummy+38
Const GA_RelSpecial       : Int =GA_Dummy+39
Const GA_TextAttr         : Int =GA_Dummy+40
Const GA_ReadOnly         : Int =GA_Dummy+41
Const GA_Underscore       : Int =GA_Dummy+42
Const GA_ActivateKey      : Int =GA_Dummy+43
Const GA_BackFill         : Int =GA_Dummy+44
Const GA_GadgetHelpText   : Int =GA_Dummy+45
Const GA_UserInput        : Int =GA_Dummy+46
Const GA_DoLayout         : Int =GA_Dummy+51
Const GA_NoFilterMenuKeys : Int =GA_Dummy+52
Const GA_Titlebar         : Int =GA_Dummy+53
Const GA_Hidden           : Int =GA_Dummy+54
Const GA_NoFilterWheel    : Int =GA_Dummy+55
Const GA_HintInfo         : Int =GA_Dummy+56
Const GA_ContextMenu      : Int =GA_Dummy+57
Rem
 PROPGCLASS attributes 
End Rem

Const PGA_Dummy      : Int =TAG_USER+$31000
Const PGA_Freedom    : Int =PGA_Dummy+$0001
Const PGA_Borderless : Int =PGA_Dummy+$0002
Const PGA_HorizPot   : Int =PGA_Dummy+$0003
Const PGA_HorizBody  : Int =PGA_Dummy+$0004
Const PGA_VertPot    : Int =PGA_Dummy+$0005
Const PGA_VertBody   : Int =PGA_Dummy+$0006
Const PGA_Total      : Int =PGA_Dummy+$0007
Const PGA_Visible    : Int =PGA_Dummy+$0008
Const PGA_Top        : Int =PGA_Dummy+$0009
Const PGA_NewLook    : Int =PGA_Dummy+$000A
Const PGA_ArrowDelta : Int =PGA_Dummy+$000B
Const PGA_ArrowDown  : Int =PGA_Dummy+$000C

Rem
* STRGCLASS attributes
End Rem

Const STRINGA_Dummy          : Int =TAG_USER     +$32000
Const STRINGA_MaxChars       : Int =STRINGA_Dummy+$0001


Const STRINGA_Buffer         : Int =STRINGA_Dummy+$0002
Const STRINGA_UndoBuffer     : Int =STRINGA_Dummy+$0003
Const STRINGA_WorkBuffer     : Int =STRINGA_Dummy+$0004
Const STRINGA_BufferPos      : Int =STRINGA_Dummy+$0005
Const STRINGA_DispPos        : Int =STRINGA_Dummy+$0006
Const STRINGA_AltKeyMap      : Int =STRINGA_Dummy+$0007
Const STRINGA_Font           : Int =STRINGA_Dummy+$0008
Const STRINGA_Pens           : Int =STRINGA_Dummy+$0009
Const STRINGA_ActivePens     : Int =STRINGA_Dummy+$000A
Const STRINGA_EditHook       : Int =STRINGA_Dummy+$000B
Const STRINGA_EditModes      : Int =STRINGA_Dummy+$000C


Const STRINGA_ReplaceMode    : Int =STRINGA_Dummy+$000D
Const STRINGA_FixedFieldMode : Int =STRINGA_Dummy+$000E
Const STRINGA_NoFilterMode   : Int =STRINGA_Dummy+$000F

Const STRINGA_Justification  : Int =STRINGA_Dummy+$0010
Const STRINGA_LongVal        : Int =STRINGA_Dummy+$0011
Const STRINGA_TextVal        : Int =STRINGA_Dummy+$0012
Const STRINGA_ExitHelp       : Int =STRINGA_Dummy+$0013
Const STRINGA_MarkedBlock    : Int =STRINGA_Dummy+$0014
Const SG_DEFAULTMAXCHARS : Int =128

Rem
* Gadget layout related attributes
End Rem

Const LAYOUTA_Dummy          : Int =TAG_USER+$38000
Const LAYOUTA_LayoutObj      : Int =LAYOUTA_Dummy+$0001
Const LAYOUTA_Spacing        : Int =LAYOUTA_Dummy+$0002
Const LAYOUTA_Orientation    : Int =LAYOUTA_Dummy+$0003

Const LAYOUTA_ChildMaxWidth  : Int =LAYOUTA_Dummy+$0004
Const LAYOUTA_ChildMaxHeight : Int =LAYOUTA_Dummy+$0005
  
Const LORIENT_NONE  : Int = 0
Const LORIENT_HORIZ : Int = 1
Const LORIENT_VERT  : Int = 2

Rem
* Gadget Method ID's
End Rem

Const GM_Dummy         : Int =-1
Const GM_HITTEST       : Int =0
Const GM_RENDER        : Int =1
Const GM_GOACTIVE      : Int =2
Const GM_HANDLEINPUT   : Int =3
Const GM_GOINACTIVE    : Int =4
Const GM_HELPTEST      : Int =5
Const GM_LAYOUT        : Int =6
Const GM_DOMAIN        : Int =7
Const GM_KEYTEST       : Int =8
Const GM_KEYGOACTIVE   : Int =9
Const GM_KEYGOINACTIVE : Int =10
Const GM_PRERENDER     : Int =11
Const GM_POSTRENDER    : Int =12
Const GM_EXTENT        : Int =13
Const GM_HANDLESCROLL  : Int =14
Const GM_QUERY         : Int =15
Const GM_MENUPICK      : Int =16
Const GM_MENUHELP      : Int =17

Type TgpHitTest Extends TMsg
    Field _gpht_GInfo : Byte Ptr
    Field _gpht_Mouse_X : Short
	Field _gpht_Mouse_Y : Short
End Type

Const GMR_GADGETHIT : Int =$00000004 
Const GMR_NOHELPHIT : Int =$00000000 
Const GMR_HELPHIT   : Int =$FFFFFFFF
Const GMR_HELPCODE  : Int =$00010000 

Type TgpRender Extends TMsg
	Field _gpht_GInfo : Byte Ptr
	Field _gpr_RPort  : Byte Ptr
    Field _gpr_Redraw : Int
End Type


Const GREDRAW_UPDATE : Int =2 
Const GREDRAW_REDRAW : Int =1
Const GREDRAW_TOGGLE : Int =0


Type TgpInput Extends TMsg
    Field _gpi_GInfo : Byte Ptr
    Field _gpi_IEvent : Byte Ptr
    Field _gpi_Termination : Byte Ptr
    Field _gpi_Mouse_X : Short
    Field _gpi_Mouse_Y : Short
    Field _gpi_TabletData : Byte Ptr
End Type

Const GMR_MEACTIVE   : Int =0
Const GMR_NOREUSE    : Int =1 shl 1
Const GMR_REUSE      : Int =1 shl 2
Const GMR_VERIFY     : Int =1 shl 3

Const GMR_NEXTACTIVE : Int =1 shl 4
Const GMR_PREVACTIVE : Int =1 shl 5



Type TgpGoInactive  Extends TMsg
	Field _gpi_GInfo : Byte Ptr
    Field _gpgi_Abort: Int
End Type


Type TgpLayout Extends TMsg
	Field _gpi_GInfo : Byte Ptr
    Field _gpl_Initial: Int
End Type



Const GDOMAIN_MINIMUM : Int =0 
Const GDOMAIN_NOMINAL : Int =1 
Const GDOMAIN_MAXIMUM : Int =2 


Type TgpKeyTest Extends TMsg
	Field _gpme_GInfo 	: Byte Ptr 
	Field _gpkt_IMsg 	: Byte Ptr 
	Field _gpkt_VanillaKey 	: Int
End Type


Type TgpKeyInput Extends TMsg
	Field _gpme_GInfo 	: Byte Ptr 
	Field gpk_IEvent 	: Byte Ptr 
	Field gpk_Termination 	: Int
End Type

Const GMR_KEYACTIVATE : Int =$00000000 
Const GMR_KEYACTIVE   : Int =$00000010 
Const GMR_KEYVERIFY   : Int =$00000020 


Type TgpKeyGoInactive Extends TMsg
	Field _gpme_GInfo 	: Byte Ptr 
	Field _gpki_Abort 	: Int
End Type


Type TgpExtent Extends TMsg
	Field _gpme_GInfo 	: Byte Ptr 
	Field _gpe_RPort 	: Byte Ptr 
	Field _gpe_Region 	: Byte Ptr 
	Field _gpe_Action 	: Int
	Field _gpe_Flags 	: Int 	
	Field _gpe_Attrs 	: TTagItems  
End Type

Const GEXTENT_REMOVE : Int =0 
Const GEXTENT_ADD    : Int =1 
Const GEXTENT_INVERT : Int =2 
Const GEXTENT_SECT   : Int =3 
 
Const GPEF_ALLOWSUPER : Int =$00000001 
Const GMR_INVALID  : Int =$00000000
Const GMR_FULLHBOX : Int =$00000010
Const GMR_FULLBBOX : Int =$00000020
Const GMR_CLIPDONE : Int =$00000040
Const GMR_MASKDONE : Int =$00000080


Type TgpQuery Extends TMsg
	Field _gpme_GInfo : Byte Ptr 
	Field _gpq_IEvent : Byte Ptr
	Field _gpq_Type   : Int
	Field _gpq_Data		: Int Ptr   
End Type

Const GMQ_HINTINFO    : Int =1
Const GMQ_WHICHMEMBER : Int =2
Const GMQ_CONTEXTMENU : Int =3



Type TgpMenuEvent Extends TMsg
   Field _gpme_GInfo : Byte Ptr       
   Field _gpme_MenuAddress: TAPTR
   Field _gpme_MenuNumber : Int
   Field _gpme_Window : TWindow    
End Type

