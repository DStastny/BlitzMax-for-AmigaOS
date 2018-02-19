SuperStrict
Module Amiga.IIntuition

ModuleInfo "Verison: 0.01"
ModuleInfo "License zlib/libpng"

ModuleInfo "Author:Doug Stastny"

?AmigaOS4
Import amiga.amigaos
Import amiga.exec
Import "*.h"
Import "iintuition.c"


Type TMsg
	Field MethodId : Int
	
	Method Init:TMsg(Id:Int)
		MethodId = Id
		Return self
	End Method
End Type

Function Msg:TMsg(Id:Int)
	Return (New TMsg).Init(Id)
End Function


Extern
	Global IntuitionLibrary : TLibrary = "bbIntuitionLibrary" 

    Type TClass Extends TAPTR
    End Type

    Type TObject Extends TAPTR
    End Type

    Type TBorder Extends TAPTR
    End Type

    Type TDrawInfo Extends TAPTR
    End Type

    Type TEasyStruct Extends TAPTR
    End Type

    Type TIntuiText Extends TAPTR
    End Type

    Type TMenu Extends TAPTR
    End Type

    Type TNewScreen Extends TAPTR
    End Type

    Type TNewWindow Extends TAPTR
    End Type

    Type TPreferences Extends TAPTR
    End Type

    Type TScreen Extends TAPTR
    End Type

    Type TTagItem Extends TAPTR
    End Type

    Type TWindow Extends TAPTR
    End Type

    Type TBitMap Extends TAPTR
    End Type

    Type TClassLibrary Extends TAPTR
    End Type

    Type TGUIPlugin Extends TAPTR
    End Type

    Type TGadget Extends TAPTR
    End Type

    Type TGadgetInfo Extends TAPTR
    End Type

    Type TGradientSpec Extends TAPTR
    End Type

    Type THook Extends TAPTR
    End Type

    Type TIBox Extends TAPTR
    End Type

    Type TImage Extends TAPTR
    End Type

    Type TInputEvent Extends TAPTR
    End Type

    Type TMenuItem Extends TAPTR
    End Type


    Type TRastPort Extends TAPTR
    End Type

    Type TRectangle Extends TAPTR
    End Type

    Type TRequester Extends TAPTR
    End Type

    Type TSGWork Extends TAPTR
    End Type

    Type TScreenBuffer Extends TAPTR
    End Type

    Type TScrollHook Extends TAPTR
    End Type

    Type TTextExtent Extends TAPTR
    End Type

    Type TView Extends TAPTR
    End Type

    Type TViewPort Extends TAPTR
    End Type

	Type TRemember Extends TAPTR
	End Type

	Type TPLANEPTR Extends TAPTR
	End Type

    Type IIIntuition Extends IInterface

        Method OpenIntuition()
        Method Intuition(iEvent : TInputEvent)
        Method AddGadget: Short(window : TWindow, gadget : TGadget, position : Short)
        Method ClearDMRequest: Short(window : TWindow)
        Method ClearMenuStrip(window : TWindow)
        Method ClearPointer(window : TWindow)
        Method CloseScreen: Short(screen : TScreen)
        Method CloseWindow(window : TWindow)
        Method CloseWorkBench: Int()
        Method CurrentTime(seconds : Int Ptr, micros : Int Ptr)
        Method DisplayAlert: Short(alertNumber : Int, string_ : String, height : Short)
        Method DisplayBeep(screen : TScreen)
        Method DoubleClick: Short(sSeconds : Int, sMicros : Int, cSeconds : Int, cMicros : Int)
        Method DrawBorder(rp : TRastPort, border : TBorder, leftOffset : Short, topOffset : Short)
        Method DrawImage(rp : TRastPort, image : TImage, leftOffset : Short, topOffset : Short)
        Method EndRequest(requester : TRequester, window : TWindow)
        Method GetDefPrefs: TPreferences(preferences : TPreferences, size : Short)
        Method GetPrefs: TPreferences(preferences : TPreferences, size : Short)
        Method InitRequester(requester : TRequester)
        Method ItemAddress: TMenuItem(menuStrip : TMenu, menuNumber : Short)
        Method ModifyIDCMP: Short(window : TWindow, flags : Int)
        Method ModifyProp(gadget : TGadget, window : TWindow, requester : TRequester, flags : Short, horizPot : Short, vertPot : Short, horizBody : Short, vertBody : Short)
        Method MoveScreen(screen : TScreen, dx : Short, dy : Short)
        Method MoveWindow(window : TWindow, dx : Short, dy : Short)
        Method OffGadget(gadget : TGadget, window : TWindow, requester : TRequester)
        Method OffMenu(window : TWindow, menuNumber : Short)
        Method OnGadget(gadget : TGadget, window : TWindow, requester : TRequester)
        Method OnMenu(window : TWindow, menuNumber : Short)
        Method OpenScreen: TScreen(newScreen : TNewScreen)
        Method OpenWindow: TWindow(newWindow : TNewWindow)
        Method OpenWorkBench: Int()
        Method PrintIText(rp : TRastPort, iText : TIntuiText, left : Short, top : Short)
        Method RefreshGadgets(gadgets : TGadget, window : TWindow, requester : TRequester)
        Method RemoveGadget: Short(window : TWindow, gadget : TGadget)
        Method ReportMouse(flag : Short, window : TWindow)
        Method ReportMouse1(window : TWindow, flag : Short)
        Method Request: Short(requester : TRequester, window : TWindow)
        Method ScreenToBack(screen : TScreen)
        Method ScreenToFront(screen : TScreen)
        Method SetDMRequest: Short(window : TWindow, requester : TRequester)
        Method SetMenuStrip: Short(window : TWindow, menu : TMenu)
        Method SetPointer(window : TWindow, pointer : Short Ptr, height : Short, width : Short, xOffset : Short, yOffset : Short)
        Method SetWindowTitles(window : TWindow, windowTitle : String, screenTitle : String)
        Method ShowTitle(screen : TScreen, showIt : Short)
        Method SizeWindow(window : TWindow, dx : Short, dy : Short)
        Method ViewAddress: TView()
        Method ViewPortAddress: TViewPort(window : TWindow)
        Method WindowToBack(window : TWindow)
        Method WindowToFront(window : TWindow)
        Method WindowLimits: Short(window : TWindow, widthMin : Int, heightMin : Int, widthMax : Int, heightMax : Int)
        Method SetPrefs: TPreferences(preferences : TPreferences, size : Int, inform : Short)
        Method IntuiTextLength: Int(iText : TIntuiText)
        Method WBenchToBack: Short()
        Method WBenchToFront: Short()
        Method AutoRequest: Short(window : TWindow, body : TIntuiText, posText : TIntuiText, negText : TIntuiText, pFlag : Int, nFlag : Int, width : Short, height : Short)
        Method BeginRefresh(window : TWindow)
        Method BuildSysRequest: TWindow(window : TWindow, body : TIntuiText, posText : TIntuiText, negText : TIntuiText, flags : Int, width : Short, height : Short)
        Method EndRefresh(window : TWindow, complete : Int)
        Method FreeSysRequest(window : TWindow)
        Method MakeScreen: Int(screen : TScreen)
        Method RemakeDisplay: Int()
        Method RethinkDisplay: Int()
        Method AllocRemember: TAPTR(rememberKey : TRemember Var, size : Int, flags : Int)
        Method AlohaWorkbench(wbport : Int)
        Method FreeRemember(rememberKey : TRemember Var, reallyForget : Short)
        Method LockIBase: Int(dontknow : Int)
        Method UnlockIBase(ibLock : Int)
        Method GetScreenData: Int(buffer : TAPTR, size : Short, type_ : Short, screen : TScreen)
        Method RefreshGList(gadgets : TGadget, window : TWindow, requester : TRequester, numGad : Short)
        Method AddGList: Short(window : TWindow, gadget : TGadget, position : Short, numGad : Short, requester : TRequester)
        Method RemoveGList: Short(remPtr : TWindow, gadget : TGadget, numGad : Short)
        Method ActivateWindow(window : TWindow)
        Method RefreshWindowFrame(window : TWindow)
        Method ActivateGadget: Short(gadgets : TGadget, window : TWindow, requester : TRequester)
        Method NewModifyProp(gadget : TGadget, window : TWindow, requester : TRequester, flags : Short, horizPot : Short, vertPot : Short, horizBody : Short, vertBody : Short, numGad : Short)
        Method QueryOverscan: Int(displayID : Int, rect : TRectangle, oScanType : Short)
        Method MoveWindowInFrontOf(window : TWindow, behindWindow : TWindow)
        Method ChangeWindowBox(window : TWindow, left : Short, top : Short, width : Short, height : Short)
        Method SetEditHook: THook(hook : THook)
        Method SetMouseQueue: Int(window : TWindow, queueLength : Short)
        Method ZipWindow(window : TWindow)
        Method LockPubScreen: TScreen(name : String)
        Method UnlockPubScreen(name : String, screen : TScreen)
        Method LockPubScreenList: TList_()
        Method UnlockPubScreenList()
        Method NextPubScreen: String(screen : TScreen, namebuf : String)
        Method SetDefaultPubScreen(name : String)
        Method SetPubScreenModes: Short(modes : Short)
        Method PubScreenStatus: Short(screen : TScreen, statusFlags : Short)
        Method ObtainGIRPort: TRastPort(gInfo : TGadgetInfo)
        Method ReleaseGIRPort(rp : TRastPort)
        Method GadgetMouse(gadget : TGadget, gInfo : TGadgetInfo, mousePoint : Short Ptr)
        Method SetIPrefs: TAPTR(ptr_ : TAPTR, size : Int, type_ : Int)
        Method GetDefaultPubScreen(nameBuffer : String)
        Method EasyRequestArgs: Int(window : TWindow, easyStruct : TEasyStruct, idcmpPtr : Int Ptr, args : TAPTR)
        Method EasyRequest: Int(window : TWindow, easyStruct : TEasyStruct, idcmpPtr : Int Ptr, dummy : Int[])
        Method BuildEasyRequestArgs: TWindow(window : TWindow, easyStruct : TEasyStruct, idcmp : Int, args : TAPTR)
        Method BuildEasyRequest: TWindow(window : TWindow, easyStruct : TEasyStruct, idcmp : Int, dummy : Int[])
        Method SysReqHandler: Int(window : TWindow, idcmpPtr : Int Ptr, waitInput : Short)
        Method OpenWindowTagList: TWindow(newWindow : TNewWindow, tagList : TTagItem)
        Method OpenWindowTags: TWindow(newWindow : TNewWindow, tag1Type : Int[])
        Method OpenScreenTagList: TScreen(newScreen : TNewScreen, tagList : TTagItem)
        Method OpenScreenTags: TScreen(newScreen : TNewScreen, tag1Type : Int[])
        Method DrawImageState(rp : TRastPort, image : TImage, leftOffset : Short, topOffset : Short, state : Int, drawInfo : TDrawInfo)
        Method PointInImage: Short(point : Int, image : TImage)
        Method EraseImage(rp : TRastPort, image : TImage, leftOffset : Short, topOffset : Short)
        Method NewObjectA: TObject(cl : TClass, classID : String, tagList : TTagItem)
        Method NewObject: TObject(cl : TClass, classID : String, tag1 : Int[])
        Method DisposeObject(object_ : TObject)
        Method SetAttrsA: Int(objec_ : TObject, tagList : TTagItem)
        Method SetAttrs: Int(object_ : TAPTR, tag1 : Int[])
        Method GetAttr: Int(attrID : Int, object_ : TObject, storagePtr : Int Ptr)
        Method SetGadgetAttrsA: Int(gadget : TGadget, window : TWindow, requester : TRequester, tagList : TTagItem)
        Method SetGadgetAttrs: Int(gadget : TGadget, window : TWindow, requester : TRequester, tag1 : Int[])
        Method NextObject: TObject(objectPtrPtr : TObject Var)
        Method FindClass: TClass(classID : String)
        Method MakeClass: TClass(classID : String, superClassID : String, superClassPtr : TClass, instanceSize : Short, flags : Int)
        Method AddClass(cl : TClass)
        Method GetScreenDrawInfo: TDrawInfo(screen : TScreen)
        Method FreeScreenDrawInfo(screen : TScreen, drawInfo : TDrawInfo)
        Method ResetMenuStrip: Short(window : TWindow, menu : TMenu)
        Method RemoveClass(cl : TClass)
        Method FreeClass: Short(cl : TClass)
        Method LockClassList: TList_()
        Method UnlockClassList()
        Method Reserved1()
        Method Reserved2()
        Method Reserved3()
        Method Reserved4()
        Method Reserved5()
        Method Reserved6()
        Method AllocScreenBuffer: TScreenBuffer(sc : TScreen, bm : TBitMap, flags : Int)
        Method FreeScreenBuffer(sc : TScreen, sb : TScreenBuffer)
        Method ChangeScreenBuffer: Int(sc : TScreen, sb : TScreenBuffer)
        Method ScreenDepth(screen : TScreen, flags : Int, reserved : TAPTR)
        Method ScreenPosition(screen : TScreen, flags : Int, x1 : Int, y1 : Int, x2 : Int, y2 : Int)
        Method ScrollWindowRaster(win : TWindow, dx : Short, dy : Short, xMin : Short, yMin : Short, xMax : Short, yMax : Short)
        Method LendMenus(fromwindow : TWindow, towindow : TWindow)
        Method DoGadgetMethodA: Int(gad : TGadget, win : TWindow, req : TRequester, message : TMsg)
        Method DoGadgetMethod: Int(gad : TGadget, win : TWindow, req : TRequester, methodID : Int[])
        Method SetWindowPointerA(win : TWindow, taglist : TTagItem)
        Method SetWindowPointer(win : TWindow, tag1 : Int[])
        Method TimedDisplayAlert: Short(alertNumber : Int, string_ : String, height : Short, Time : Int)
        Method HelpControl(win : TWindow, flags : Int)
        Method ShowWindow: Short(window : TWindow, other : TWindow)
        Method HideWindow: Short(window : TWindow)
        Method GetAttrsA: Int(object_ : TObject, tagList : TTagItem)
        Method GetAttrs: Int(object_ : TAPTR, tag1 : Int[])
        Method LockGUIPrefs: TAPTR(reserved : Int)
        Method UnlockGUIPrefs(lock : TAPTR)
        Method SetGUIAttrsA: Int(reserved : TAPTR, drawinfo : TDrawInfo, taglist : TTagItem)
        Method SetGUIAttrs: Int(reserved : TAPTR, drawinfo : TDrawInfo, tag1 : Int[])
        Method GetGUIAttrsA: Int(reserved : TAPTR, drawinfo : TDrawInfo, taglist : TTagItem)
        Method GetGUIAttrs: Int(reserved : TAPTR, drawinfo : TDrawInfo, tag1 : Int[])
        Method GetHalfPens: Int(drawinfo : TDrawInfo, basepen : Int, halfshineptr : Short Ptr, halfshadowptr : Short Ptr)
        Method GadgetBox: Int(gadget : TGadget, domain : TAPTR, domaintype : Int, flags : Int, box : TAPTR)
        Method RefreshSetGadgetAttrsA(gadget : TGadget, window : TWindow, req : TRequester, taglist : TTagItem)
        Method RefreshSetGadgetAttrs(gadget : TGadget, window : TWindow, req : TRequester, tag1 : Int[])
        Method IDoSuperMethodA: Int(cl : TClass, object_ : TObject, msg : TMsg)
        Method IDoSuperMethod: Int(cl : TClass, object_ : TObject, tag1 : Int[])
        Method ISetSuperAttrsA: Int(cl : TClass, object_ : TObject, taglist : TTagItem)
        Method ISetSuperAttrs: Int(cl : TClass, object_ : TObject, tag1 : Int[])
        Method ICoerceMethodA: Int(cl : TClass, object_ : TObject, msg : TMsg)
        Method ICoerceMethod: Int(cl : TClass, object_ : TObject, tag1 : Int[])
        Method IDoMethodA: Int(object_ : TObject, msg : TMsg)
        Method IDoMethod: Int(object_ : TObject, tag1 : Int[])
        Method OpenClass: TClassLibrary(name : String, version : Int, cl_ptr : TClass Var)
        Method CloseClass(cl : TClassLibrary)
        Method SetDisplayBeepHook: THook(hook : THook)
        Method LockScreen: Short(screen : TScreen, micros : Int)
        Method UnlockScreen(screen : TScreen)
        Method GetWindowAttrsA: Int(win : TWindow, taglist : TTagItem)
        Method GetWindowAttrs: Int(win : TWindow, tag1 : Int[])
        Method SetWindowAttrsA: Int(win : TWindow, taglist : TTagItem)
        Method SetWindowAttrs: Int(win : TWindow, tag1 : Int[])
        Method GetWindowAttr: Int(win : TWindow, attr : Int, data : TAPTR, size : Int)
        Method SetWindowAttr: Int(win : TWindow, attr : Int, data : TAPTR, size : Int)
        Method StripIntuiMessages(port : TMsgPort, win : TWindow)
        Method Reserved7()
        Method Reserved8()
        Method GetScreenAttrsA: Int(scr : TScreen, taglist : TTagItem)
        Method GetScreenAttrs: Int(scr : TScreen, tag1 : Int[])
        Method SetScreenAttrsA: Int(scr : TScreen, taglist : TTagItem)
        Method SetScreenAttrs: Int(scr : TScreen, tag1 : Int[])
        Method GetScreenAttr: Int(scr : TScreen, attr : Int, data : TAPTR, size : Int)
        Method SetScreenAttr: Int(scr : TScreen, attr : Int, data : TAPTR, size : Int)
        Method LockScreenList: TScreen()
        Method UnlockScreenList()
        Method LockScreenGI: TRastPort(gi : TGadgetInfo, micros : Int)
        Method UnlockScreenGI(gi : TGadgetInfo, rp : TRastPort)
        Method GetMarkedBlock: Int(sgw : TSGWork)
        Method SetMarkedBlock(sgw : TSGWork, block : Int)
        Method ObtainBitMapSourceA: TAPTR(name : String, taglist : TTagItem)
        Method ObtainBitMapSource: TAPTR(name : String, tag1 : Int[])
        Method ReleaseBitMapSource(bitmapsource : TAPTR)
        Method ObtainBitMapInstanceA: TAPTR(bitmapsource : TAPTR, screen : TScreen, taglist : TTagItem)
        Method ObtainBitMapInstance: TAPTR(bitmapsource : TAPTR, screen : TScreen, tag1 : Int[])
        Method ReleaseBitMapInstance(bitmapinstance : TAPTR)
        Method EmbossDisableRect(rp : TRastPort, minx : Int, miny : Int, maxx : Int, maxy : Int, backtype : Int, contrast : Int, dri : TDrawInfo)
        Method EmbossDisableText(rp : TRastPort, text : String, len_ : Int, backtype : Int, contrast : Int, dri : TDrawInfo)
        Method PrintEmbossedDisabledIText(rp : TRastPort, itext : TIntuiText, left : Int, top : Int, backtype : Int, contrast : Int, dri : TDrawInfo)
        Method IntuiTextExtent: Int(rp : TRastPort, itext : TIntuiText, textent : TTextExtent)
        Method ShadeRectOld: Int(rp : TRastPort, minx : Int, miny : Int, maxx : Int, maxy : Int, shadelevel : Int, backtype : Int, state : Int, dri : TDrawInfo)
        Method DisableTemplateRGB(rp : TRastPort, left : Int, top : Int, width : Int, height : Int, template_ptr : TPLANEPTR, brightlevel : Int, darklevel : Int)
        Method SetScreenBitMapInstance: Int(scr : TScreen, id : Int, source : TAPTR)
        Method FindMenuKey: Short(menu : TMenu, code : Int)
        Method BitMapInstanceControlA: Int(bitmapinstance : TAPTR, taglist : TTagItem)
        Method BitMapInstanceControl: Int(bitmapinstance : TAPTR, tag1 : Int[])
        Method ObtainIPluginList: TList_(type_ : Int, attrmask : Int, applymask : Int)
        Method ReleaseIPluginList(list : TList_)
        Method OpenGUIPlugin: TGUIPlugin(name : String, version : Int, type_ : Int, attrmask : Int, applymask : Int)
        Method CloseGUIPlugin(plugin : TGUIPlugin)
        Method DrawSysImageA: Int(rp : TRastPort, left : Int, top : Int, width : Int, height : Int, which : Int, backtype : Int, state : Int, dri : TDrawInfo, taglist : TTagItem)
        Method DrawSysImage: Int(rp : TRastPort, left : Int, top : Int, width : Int, height : Int, which : Int, backtype : Int, state : Int, dri : TDrawInfo, tag1 : Int[])
        Method DoRender: Int(o : TObject, gi : TGadgetInfo, flags : Int)
        Method SetRenderDomain: Int(rp : TRastPort, domain : TRectangle)
        Method GetRenderDomain: Int(rp : TRastPort, domain : TRectangle)
        Method DrawGradient: Int(rp : TRastPort, left : Int, top : Int, width : Int, height : Int, domain : TIBox, reserved : Int, gradientspec : TGradientSpec, dri : TDrawInfo)
        Method DirectionVector: Int(degrees : Int)
        Method ShadeRectA: Int(rp : TRastPort, minx : Int, miny : Int, maxx : Int, maxy : Int, shadelevel : Int, backtype : Int, state : Int, dri : TDrawInfo, taglist : TTagItem)
        Method ShadeRect: Int(rp : TRastPort, minx : Int, miny : Int, maxx : Int, maxy : Int, shadelevel : Int, backtype : Int, state : Int, dri : TDrawInfo, tag1 : Int[])
        Method DoScrollHook(scrollhook : TScrollHook, scrollmode : Int)
        Method ObtainIBackFill: THook(dri : TDrawInfo, element : Int, state : Int, flags : Int)
        Method ReleaseIBackFill(hook : THook)
        Method IntuitionControlA: Int(object_ : TAPTR, taglist : TTagItem)
        Method IntuitionControl: Int(object_ : TAPTR, tag1 : Int[])
        Method StartScreenNotifyTagList: TAPTR(taglist : TTagItem)
        Method StartScreenNotifyTags: TAPTR(tag1 : Int[])
        Method EndScreenNotify: Short(request : TAPTR)
        Method DisableTemplate(rp : TRastPort, left : Int, top : Int, width : Int, height : Int, template_ptr : TAPTR, offx : Int, template_type : Int, bytesperrow : Int, backtype : Int, dri : TDrawInfo)
    End Type
End Extern


Const  WA_Dummy   : Int =(TAG_USER + 99) 
Const  WA_Left              : Int = (WA_Dummy + $01)
Const  WA_Top               : Int = (WA_Dummy + $02)
Const  WA_Width             : Int = (WA_Dummy + $03)
Const  WA_Height            : Int = (WA_Dummy + $04)
Const  WA_DetailPen         : Int = (WA_Dummy + $05)
Const  WA_BlockPen          : Int = (WA_Dummy + $06)
Const  WA_IDCMP             : Int = (WA_Dummy + $07)
Const  WA_Flags             : Int = (WA_Dummy + $08)
Const  WA_Gadgets           : Int = (WA_Dummy + $09)
Const  WA_Checkmark         : Int = (WA_Dummy + $0A)
Const  WA_Title             : Int = (WA_Dummy + $0B)
Const  WA_ScreenTitle       : Int = (WA_Dummy + $0C)
Const  WA_CustomScreen      : Int = (WA_Dummy + $0D)
Const  WA_SuperBitMap       : Int = (WA_Dummy + $0E)
Const  WA_MinWidth          : Int = (WA_Dummy + $0F)
Const  WA_MinHeight         : Int = (WA_Dummy + $10)
Const  WA_MaxWidth          : Int = (WA_Dummy + $11)
Const  WA_MaxHeight         : Int = (WA_Dummy + $12)
Const  WA_InnerWidth        : Int = (WA_Dummy + $13)
Const  WA_InnerHeight       : Int = (WA_Dummy + $14)
Const  WA_PubScreenName     : Int = (WA_Dummy + $15)
Const  WA_PubScreen         : Int = (WA_Dummy + $16)
Const  WA_PubScreenFallBack : Int = (WA_Dummy + $17)
Const  WA_WindowName        : Int = (WA_Dummy + $18)
Const  WA_Colors            : Int = (WA_Dummy + $19)
Const  WA_Zoom              : Int = (WA_Dummy + $1A)
Const  WA_MouseQueue        : Int = (WA_Dummy + $1B)
Const  WA_BackFill          : Int = (WA_Dummy + $1C)
Const  WA_RptQueue          : Int = (WA_Dummy + $1D)
Const  WA_SizeGadget        : Int = (WA_Dummy + $1E)
Const  WA_DragBar           : Int = (WA_Dummy + $1F)
Const  WA_DepthGadget       : Int = (WA_Dummy + $20)

Const  WA_CloseGadget       : Int = (WA_Dummy + $21)
Const  WA_Backdrop          : Int = (WA_Dummy + $22)
Const  WA_ReportMouse       : Int = (WA_Dummy + $23)
Const  WA_NoCareRefresh     : Int = (WA_Dummy + $24)
Const  WA_Borderless        : Int = (WA_Dummy + $25)
Const  WA_Activate          : Int = (WA_Dummy + $26)
Const  WA_RMBTrap           : Int = (WA_Dummy + $27)
Const  WA_WBenchWindow      : Int = (WA_Dummy + $28) 
Const  WA_SimpleRefresh     : Int = (WA_Dummy + $29)
Const  WA_SmartRefresh      : Int = (WA_Dummy + $2A)
Const  WA_SizeBRight        : Int = (WA_Dummy + $2B)
Const  WA_SizeBBottom       : Int = (WA_Dummy + $2C)
Const  WA_AutoAdjust        : Int = (WA_Dummy + $2D)
Const  WA_GimmeZeroZero     : Int = (WA_Dummy + $2E)
Const  WA_MenuHelp          : Int = (WA_Dummy + $2F)
Const  WA_NewLookMenus      : Int = (WA_Dummy + $30)
Const  WA_AmigaKey          : Int = (WA_Dummy + $31)
Const  WA_NotifyDepth       : Int = (WA_Dummy + $32)
Const  WA_Pointer           : Int = (WA_Dummy + $34)
Const  WA_BusyPointer       : Int = (WA_Dummy + $35)
Const  WA_PointerDelay      : Int = (WA_Dummy + $36)
Const  WA_TabletMessages    : Int = (WA_Dummy + $37)
Const  WA_HelpGroup         : Int = (WA_Dummy + $38)
Const  WA_HelpGroupWindow   : Int = (WA_Dummy + $39)
Const  WA_UserPort          : Int = (WA_Dummy + $3a)
Const  WA_WindowBox         : Int = (WA_Dummy + $3b)
Const  WA_Hidden            : Int = (WA_Dummy + $3c)
Const  WA_ToolBox           : Int = (WA_Dummy + $3d)
Const  WA_Reserved1         : Int = (WA_Dummy + $3e)
Const  WA_MenuHook          : Int = (WA_Dummy + $3f)
Const  WA_AutoAdjustDClip   : Int = (WA_Dummy + $40)
Const  WA_ShapeRegion       : Int = (WA_Dummy + $41)
Const  WA_ShapeHook         : Int = (WA_Dummy + $42)
Const  WA_InFrontOf         : Int = (WA_Dummy + $43)
Const  WA_GrabFocus         : Int = (WA_Dummy + $44)
Const  WA_StayTop           : Int = (WA_Dummy + $45)
Const  WA_MouseLimits       : Int = (WA_Dummy + $46)
Const  WA_NoMenuKeyVerify   : Int = (WA_Dummy + $47)
Const  WA_Reserved2         : Int = (WA_Dummy + $48)
Const  WA_AlphaClips        : Int = (WA_Dummy + $49)
Const  WA_AlphaHook         : Int = (WA_Dummy + $4A)
Const  WA_Opaqueness        : Int = (WA_Dummy + $4B)
Const  WA_FadeTime          : Int = (WA_Dummy + $4C)
Const  WA_OverrideOpaqueness : Int = (WA_Dummy + $4D)
Const  WA_NoHitThreshold    : Int = (WA_Dummy + $4E)
Const  WA_DropShadows       : Int = (WA_Dummy + $4F)  
Const  WA_PointerType       : Int = (WA_Dummy + $50)
Const  WA_MenuStrip         : Int = (WA_Dummy + $51)
Const  WA_ContextMenuHook   : Int = (WA_Dummy + $52)


include "gadgetclass.bmx"

Const REACTION_Dummy : Int =  (TAG_USER + $5000000)
Const REACTION_BackFill  : Int =  (REACTION_Dummy + 1)
Const REACTION_TextAttr : Int =  (REACTION_Dummy + 5)
Const REACTION_ChangePrefs : Int =  (REACTION_Dummy + 6)
Const REACTION_SpecialPens : Int = (REACTION_Dummy + 7)
 
Include "classes/window.bmx"
Include "gadgets/layout.bmx"




Global IIntuition : IIIntuition = IIIntuition(OpenLibrary(IntuitionLibrary))

?
