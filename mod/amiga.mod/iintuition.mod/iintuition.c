#include <iintuition.h>
#include <proto/intuition.h>
 
 
#define IIntuition(this) ((struct IntuitionIFace*)this->IInterface)

static VOID bbOpenIntuition(struct BBIInterface *this)
{
    IIntuition(this)->OpenIntuition();
}

static VOID bbIntuition(struct BBIInterface *this, struct InputEvent *iEvent)
{
    IIntuition(this)->Intuition(iEvent);
}

static UWORD bbAddGadget(struct BBIInterface *this, struct Window *window, struct Gadget *gadget, UWORD position)
{
    return IIntuition(this)->AddGadget(window, gadget, position);
}

static BOOL bbClearDMRequest(struct BBIInterface *this, struct Window *window)
{
    return IIntuition(this)->ClearDMRequest(window);
}

static VOID bbClearMenuStrip(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->ClearMenuStrip(window);
}

static VOID bbClearPointer(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->ClearPointer(window);
}

static BOOL bbCloseScreen(struct BBIInterface *this, struct Screen *screen)
{
    return IIntuition(this)->CloseScreen(screen);
}

static VOID bbCloseWindow(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->CloseWindow(window);
}

static LONG bbCloseWorkBench(struct BBIInterface *this)
{
    return IIntuition(this)->CloseWorkBench();
}

static VOID bbCurrentTime(struct BBIInterface *this, ULONG *seconds, ULONG *micros)
{
    IIntuition(this)->CurrentTime(seconds, micros);
}

static BOOL bbDisplayAlert(struct BBIInterface *this, uint32 alertNumber, BBString *string, uint16 height)
{
    return IIntuition(this)->DisplayAlert(alertNumber, NULLORCSTR(string), height);
}

static VOID bbDisplayBeep(struct BBIInterface *this, struct Screen *screen)
{
    IIntuition(this)->DisplayBeep(screen);
}

static BOOL bbDoubleClick(struct BBIInterface *this, ULONG sSeconds, ULONG sMicros, ULONG cSeconds, ULONG cMicros)
{
    return IIntuition(this)->DoubleClick(sSeconds, sMicros, cSeconds, cMicros);
}

static VOID bbDrawBorder(struct BBIInterface *this, struct RastPort *rp, const struct Border *border, WORD leftOffset, WORD topOffset)
{
    IIntuition(this)->DrawBorder(rp, border, leftOffset, topOffset);
}

static VOID bbDrawImage(struct BBIInterface *this, struct RastPort *rp, struct Image *image, WORD leftOffset, WORD topOffset)
{
    IIntuition(this)->DrawImage(rp, image, leftOffset, topOffset);
}

static VOID bbEndRequest(struct BBIInterface *this, struct Requester *requester, struct Window *window)
{
    IIntuition(this)->EndRequest(requester, window);
}

static struct Preferences * bbGetDefPrefs(struct BBIInterface *this, struct Preferences *preferences, WORD size)
{
    return IIntuition(this)->GetDefPrefs(preferences, size);
}

static struct Preferences * bbGetPrefs(struct BBIInterface *this, struct Preferences *preferences, WORD size)
{
    return IIntuition(this)->GetPrefs(preferences, size);
}

static VOID bbInitRequester(struct BBIInterface *this, struct Requester *requester)
{
    IIntuition(this)->InitRequester(requester);
}

static struct MenuItem * bbItemAddress(struct BBIInterface *this, const struct Menu *menuStrip, UWORD menuNumber)
{
    return IIntuition(this)->ItemAddress(menuStrip, menuNumber);
}

static BOOL bbModifyIDCMP(struct BBIInterface *this, struct Window *window, ULONG flags)
{
    return IIntuition(this)->ModifyIDCMP(window, flags);
}

static VOID bbModifyProp(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester, UWORD flags, UWORD horizPot, UWORD vertPot, UWORD horizBody, UWORD vertBody)
{
    IIntuition(this)->ModifyProp(gadget, window, requester, flags, horizPot, vertPot, horizBody, vertBody);
}

static VOID bbMoveScreen(struct BBIInterface *this, struct Screen *screen, WORD dx, WORD dy)
{
    IIntuition(this)->MoveScreen(screen, dx, dy);
}

static VOID bbMoveWindow(struct BBIInterface *this, struct Window *window, WORD dx, WORD dy)
{
    IIntuition(this)->MoveWindow(window, dx, dy);
}

static VOID bbOffGadget(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester)
{
    IIntuition(this)->OffGadget(gadget, window, requester);
}

static VOID bbOffMenu(struct BBIInterface *this, struct Window *window, UWORD menuNumber)
{
    IIntuition(this)->OffMenu(window, menuNumber);
}

static VOID bbOnGadget(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester)
{
    IIntuition(this)->OnGadget(gadget, window, requester);
}

static VOID bbOnMenu(struct BBIInterface *this, struct Window *window, UWORD menuNumber)
{
    IIntuition(this)->OnMenu(window, menuNumber);
}

static struct Screen * bbOpenScreen(struct BBIInterface *this, const struct NewScreen *newScreen)
{
    return IIntuition(this)->OpenScreen(newScreen);
}

static struct Window * bbOpenWindow(struct BBIInterface *this, const struct NewWindow *newWindow)
{
    return IIntuition(this)->OpenWindow(newWindow);
}

static ULONG bbOpenWorkBench(struct BBIInterface *this)
{
    return IIntuition(this)->OpenWorkBench();
}

static VOID bbPrintIText(struct BBIInterface *this, struct RastPort *rp, const struct IntuiText *iText, WORD left, WORD top)
{
    IIntuition(this)->PrintIText(rp, iText, left, top);
}

static VOID bbRefreshGadgets(struct BBIInterface *this, struct Gadget *gadgets, struct Window *window, struct Requester *requester)
{
    IIntuition(this)->RefreshGadgets(gadgets, window, requester);
}

static UWORD bbRemoveGadget(struct BBIInterface *this, struct Window *window, struct Gadget *gadget)
{
    return IIntuition(this)->RemoveGadget(window, gadget);
}

static VOID bbReportMouse(struct BBIInterface *this, BOOL flag, struct Window *window)
{
    IIntuition(this)->ReportMouse(flag, window);
}

static VOID bbReportMouse1(struct BBIInterface *this, struct Window *window, BOOL flag)
{
    IIntuition(this)->ReportMouse1(window, flag);
}

static BOOL bbRequest(struct BBIInterface *this, struct Requester *requester, struct Window *window)
{
    return IIntuition(this)->Request(requester, window);
}

static VOID bbScreenToBack(struct BBIInterface *this, struct Screen *screen)
{
    IIntuition(this)->ScreenToBack(screen);
}

static VOID bbScreenToFront(struct BBIInterface *this, struct Screen *screen)
{
    IIntuition(this)->ScreenToFront(screen);
}

static BOOL bbSetDMRequest(struct BBIInterface *this, struct Window *window, struct Requester *requester)
{
    return IIntuition(this)->SetDMRequest(window, requester);
}

static BOOL bbSetMenuStrip(struct BBIInterface *this, struct Window *window, struct Menu *menu)
{
    return IIntuition(this)->SetMenuStrip(window, menu);
}

static VOID bbSetPointer(struct BBIInterface *this, struct Window *window, UWORD *pointer, WORD height, WORD width, WORD xOffset, WORD yOffset)
{
    IIntuition(this)->SetPointer(window, pointer, height, width, xOffset, yOffset);
}

static void bbSetWindowTitles(struct BBIInterface *this, struct Window *window, BBString *windowTitle, BBString *screenTitle)
{
    IIntuition(this)->SetWindowTitles(window, NULLORCSTR(windowTitle), NULLORCSTR(screenTitle));
}

static VOID bbShowTitle(struct BBIInterface *this, struct Screen *screen, BOOL showIt)
{
    IIntuition(this)->ShowTitle(screen, showIt);
}

static VOID bbSizeWindow(struct BBIInterface *this, struct Window *window, WORD dx, WORD dy)
{
    IIntuition(this)->SizeWindow(window, dx, dy);
}

static struct View * bbViewAddress(struct BBIInterface *this)
{
    return IIntuition(this)->ViewAddress();
}

static struct ViewPort * bbViewPortAddress(struct BBIInterface *this, const struct Window *window)
{
    return IIntuition(this)->ViewPortAddress(window);
}

static VOID bbWindowToBack(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->WindowToBack(window);
}

static VOID bbWindowToFront(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->WindowToFront(window);
}

static BOOL bbWindowLimits(struct BBIInterface *this, struct Window *window, LONG widthMin, LONG heightMin, ULONG widthMax, ULONG heightMax)
{
    return IIntuition(this)->WindowLimits(window, widthMin, heightMin, widthMax, heightMax);
}

static struct Preferences * bbSetPrefs(struct BBIInterface *this, const struct Preferences *preferences, LONG size, BOOL inform)
{
    return IIntuition(this)->SetPrefs(preferences, size, inform);
}

static LONG bbIntuiTextLength(struct BBIInterface *this, const struct IntuiText *iText)
{
    return IIntuition(this)->IntuiTextLength(iText);
}

static BOOL bbWBenchToBack(struct BBIInterface *this)
{
    return IIntuition(this)->WBenchToBack();
}

static BOOL bbWBenchToFront(struct BBIInterface *this)
{
    return IIntuition(this)->WBenchToFront();
}

static BOOL bbAutoRequest(struct BBIInterface *this, struct Window *window, const struct IntuiText *body, const struct IntuiText *posText, const struct IntuiText *negText, ULONG pFlag, ULONG nFlag, UWORD width, UWORD height)
{
    return IIntuition(this)->AutoRequest(window, body, posText, negText, pFlag, nFlag, width, height);
}

static VOID bbBeginRefresh(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->BeginRefresh(window);
}

static struct Window * bbBuildSysRequest(struct BBIInterface *this, struct Window *window, const struct IntuiText *body, const struct IntuiText *posText, const struct IntuiText *negText, ULONG flags, UWORD width, UWORD height)
{
    return IIntuition(this)->BuildSysRequest(window, body, posText, negText, flags, width, height);
}

static VOID bbEndRefresh(struct BBIInterface *this, struct Window *window, LONG complete)
{
    IIntuition(this)->EndRefresh(window, complete);
}

static VOID bbFreeSysRequest(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->FreeSysRequest(window);
}

static LONG bbMakeScreen(struct BBIInterface *this, struct Screen *screen)
{
    return IIntuition(this)->MakeScreen(screen);
}

static LONG bbRemakeDisplay(struct BBIInterface *this)
{
    return IIntuition(this)->RemakeDisplay();
}

static LONG bbRethinkDisplay(struct BBIInterface *this)
{
    return IIntuition(this)->RethinkDisplay();
}

static APTR bbAllocRemember(struct BBIInterface *this, struct Remember **rememberKey, ULONG size, ULONG flags)
{
    return IIntuition(this)->AllocRemember(rememberKey, size, flags);
}

static VOID bbAlohaWorkbench(struct BBIInterface *this, LONG wbport)
{
    IIntuition(this)->AlohaWorkbench(wbport);
}

static VOID bbFreeRemember(struct BBIInterface *this, struct Remember **rememberKey, BOOL reallyForget)
{
    IIntuition(this)->FreeRemember(rememberKey, reallyForget);
}

static ULONG bbLockIBase(struct BBIInterface *this, ULONG dontknow)
{
    return IIntuition(this)->LockIBase(dontknow);
}

static VOID bbUnlockIBase(struct BBIInterface *this, ULONG ibLock)
{
    IIntuition(this)->UnlockIBase(ibLock);
}

static LONG bbGetScreenData(struct BBIInterface *this, APTR buffer, UWORD size, UWORD type, const struct Screen *screen)
{
    return IIntuition(this)->GetScreenData(buffer, size, type, screen);
}

static VOID bbRefreshGList(struct BBIInterface *this, struct Gadget *gadgets, struct Window *window, struct Requester *requester, WORD numGad)
{
    IIntuition(this)->RefreshGList(gadgets, window, requester, numGad);
}

static UWORD bbAddGList(struct BBIInterface *this, struct Window *window, struct Gadget *gadget, UWORD position, WORD numGad, struct Requester *requester)
{
    return IIntuition(this)->AddGList(window, gadget, position, numGad, requester);
}

static UWORD bbRemoveGList(struct BBIInterface *this, struct Window *remPtr, struct Gadget *gadget, WORD numGad)
{
    return IIntuition(this)->RemoveGList(remPtr, gadget, numGad);
}

static VOID bbActivateWindow(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->ActivateWindow(window);
}

static VOID bbRefreshWindowFrame(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->RefreshWindowFrame(window);
}

static BOOL bbActivateGadget(struct BBIInterface *this, struct Gadget *gadgets, struct Window *window, struct Requester *requester)
{
    return IIntuition(this)->ActivateGadget(gadgets, window, requester);
}

static VOID bbNewModifyProp(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester, UWORD flags, UWORD horizPot, UWORD vertPot, UWORD horizBody, UWORD vertBody, WORD numGad)
{
    IIntuition(this)->NewModifyProp(gadget, window, requester, flags, horizPot, vertPot, horizBody, vertBody, numGad);
}

static LONG bbQueryOverscan(struct BBIInterface *this, ULONG displayID, struct Rectangle *rect, WORD oScanType)
{
    return IIntuition(this)->QueryOverscan(displayID, rect, oScanType);
}

static VOID bbMoveWindowInFrontOf(struct BBIInterface *this, struct Window *window, struct Window *behindWindow)
{
    IIntuition(this)->MoveWindowInFrontOf(window, behindWindow);
}

static VOID bbChangeWindowBox(struct BBIInterface *this, struct Window *window, WORD left, WORD top, WORD width, WORD height)
{
    IIntuition(this)->ChangeWindowBox(window, left, top, width, height);
}

static struct Hook * bbSetEditHook(struct BBIInterface *this, struct Hook *hook)
{
    return IIntuition(this)->SetEditHook(hook);
}

static LONG bbSetMouseQueue(struct BBIInterface *this, struct Window *window, UWORD queueLength)
{
    return IIntuition(this)->SetMouseQueue(window, queueLength);
}

static VOID bbZipWindow(struct BBIInterface *this, struct Window *window)
{
    IIntuition(this)->ZipWindow(window);
}

static struct Screen * bbLockPubScreen(struct BBIInterface *this, BBString *name)
{
    return IIntuition(this)->LockPubScreen(NULLORCSTR(name));
}

static void bbUnlockPubScreen(struct BBIInterface *this, BBString *name, struct Screen *screen)
{
    IIntuition(this)->UnlockPubScreen(NULLORCSTR(name), screen);
}

static struct List * bbLockPubScreenList(struct BBIInterface *this)
{
    return IIntuition(this)->LockPubScreenList();
}

static VOID bbUnlockPubScreenList(struct BBIInterface *this)
{
    IIntuition(this)->UnlockPubScreenList();
}

static STRPTR bbNextPubScreen(struct BBIInterface *this, const struct Screen *screen, BBString *namebuf)
{
    return IIntuition(this)->NextPubScreen(screen, NULLORCSTR(namebuf));
}

static void bbSetDefaultPubScreen(struct BBIInterface *this, BBString *name)
{
    IIntuition(this)->SetDefaultPubScreen(NULLORCSTR(name));
}

static UWORD bbSetPubScreenModes(struct BBIInterface *this, UWORD modes)
{
    return IIntuition(this)->SetPubScreenModes(modes);
}

static UWORD bbPubScreenStatus(struct BBIInterface *this, struct Screen *screen, UWORD statusFlags)
{
    return IIntuition(this)->PubScreenStatus(screen, statusFlags);
}

static struct RastPort * bbObtainGIRPort(struct BBIInterface *this, struct GadgetInfo *gInfo)
{
    return IIntuition(this)->ObtainGIRPort(gInfo);
}

static VOID bbReleaseGIRPort(struct BBIInterface *this, struct RastPort *rp)
{
    IIntuition(this)->ReleaseGIRPort(rp);
}

static VOID bbGadgetMouse(struct BBIInterface *this, struct Gadget *gadget, struct GadgetInfo *gInfo, WORD *mousePoint)
{
    IIntuition(this)->GadgetMouse(gadget, gInfo, mousePoint);
}

static APTR bbSetIPrefs(struct BBIInterface *this, APTR ptr, LONG size, LONG type)
{
    return IIntuition(this)->SetIPrefs(ptr, size, type);
}

static VOID bbGetDefaultPubScreen(struct BBIInterface *this, BBString *nameBuffer)
{
    IIntuition(this)->GetDefaultPubScreen(NULLORCSTR(nameBuffer));
}

static LONG bbEasyRequestArgs(struct BBIInterface *this, struct Window *window, const struct EasyStruct *easyStruct, ULONG *idcmpPtr, const APTR args)
{
    return IIntuition(this)->EasyRequestArgs(window, easyStruct, idcmpPtr, args);
}

static LONG bbEasyRequest(struct BBIInterface *this, struct Window *window, const struct EasyStruct *easyStruct, ULONG *idcmpPtr, BBArray *dummy)
{
    return IIntuition(this)->EasyRequestArgs(window, easyStruct, idcmpPtr, (const APTR)BBINTARRAYTOPTR(dummy));
}

static struct Window * bbBuildEasyRequestArgs(struct BBIInterface *this, struct Window *window, const struct EasyStruct *easyStruct, ULONG idcmp, const APTR args)
{
    return IIntuition(this)->BuildEasyRequestArgs(window, easyStruct, idcmp, args);
}

static struct Window * bbBuildEasyRequest(struct BBIInterface *this, struct Window *window, const struct EasyStruct *easyStruct, ULONG idcmp, BBArray *dummy)
{
    return IIntuition(this)->BuildEasyRequestArgs(window, easyStruct, idcmp, (const APTR)BBINTARRAYTOPTR(dummy));
}

static LONG bbSysReqHandler(struct BBIInterface *this, struct Window *window, ULONG *idcmpPtr, BOOL waitInput)
{
    return IIntuition(this)->SysReqHandler(window, idcmpPtr, waitInput);
}

static struct Window * bbOpenWindowTagList(struct BBIInterface *this, const struct NewWindow *newWindow, const struct TagItem *tagList)
{
    return IIntuition(this)->OpenWindowTagList(newWindow, tagList);
}

static struct Window * bbOpenWindowTags(struct BBIInterface *this, const struct NewWindow *newWindow, BBArray *tag1Type)
{
    return IIntuition(this)->OpenWindowTagList(newWindow, BBINTARRAYTOTAGS(tag1Type));
}

static struct Screen * bbOpenScreenTagList(struct BBIInterface *this, const struct NewScreen *newScreen, const struct TagItem *tagList)
{
    return IIntuition(this)->OpenScreenTagList(newScreen, tagList);
}

static struct Screen * bbOpenScreenTags(struct BBIInterface *this, const struct NewScreen *newScreen, BBArray *tag1Type)
{
    return IIntuition(this)->OpenScreenTagList(newScreen, BBINTARRAYTOTAGS(tag1Type));
}

static VOID bbDrawImageState(struct BBIInterface *this, struct RastPort *rp, struct Image *image, WORD leftOffset, WORD topOffset, ULONG state, const struct DrawInfo *drawInfo)
{
    IIntuition(this)->DrawImageState(rp, image, leftOffset, topOffset, state, drawInfo);
}

static BOOL bbPointInImage(struct BBIInterface *this, ULONG point, struct Image *image)
{
    return IIntuition(this)->PointInImage(point, image);
}

static VOID bbEraseImage(struct BBIInterface *this, struct RastPort *rp, struct Image *image, WORD leftOffset, WORD topOffset)
{
    IIntuition(this)->EraseImage(rp, image, leftOffset, topOffset);
}

static Object * bbNewObjectA(struct BBIInterface *this, Class *cl, BBString *classID, const struct TagItem *tagList)
{
    return IIntuition(this)->NewObjectA(cl, NULLORCSTR(classID), tagList);
}

static Object * bbNewObject(struct BBIInterface *this, Class *cl, BBString *classID, BBArray *tag1)
{
    return IIntuition(this)->NewObjectA(cl, NULLORCSTR(classID), BBINTARRAYTOTAGS(tag1));
}

static void bbDisposeObject(struct BBIInterface *this, Object *object)
{
    IIntuition(this)->DisposeObject(object);
}

static uint32 bbSetAttrsA(struct BBIInterface *this, Object *object, const struct TagItem *tagList)
{
    return IIntuition(this)->SetAttrsA(object, tagList);
}

static uint32 bbSetAttrs(struct BBIInterface *this, APTR object, BBArray *tag1)
{
    return IIntuition(this)->SetAttrsA(object, BBINTARRAYTOTAGS(tag1));
}

static uint32 bbGetAttr(struct BBIInterface *this, uint32 attrID, Object *object, uint32 *storagePtr)
{
    return IIntuition(this)->GetAttr(attrID, object, storagePtr);
}

static uint32 bbSetGadgetAttrsA(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester, const struct TagItem *tagList)
{
    return IIntuition(this)->SetGadgetAttrsA(gadget, window, requester, tagList);
}

static uint32 bbSetGadgetAttrs(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *requester, BBArray *tag1)
{
    return IIntuition(this)->SetGadgetAttrsA(gadget, window, requester, BBINTARRAYTOTAGS(tag1));
}

static Object * bbNextObject(struct BBIInterface *this, Object **objectPtrPtr)
{
    return IIntuition(this)->NextObject(objectPtrPtr);
}

static Class * bbFindClass(struct BBIInterface *this, BBString *classID)
{
    return IIntuition(this)->FindClass(NULLORCSTR(classID));
}

static Class * bbMakeClass(struct BBIInterface *this, BBString *classID, BBString *superClassID, const Class *superClassPtr, uint16 instanceSize, uint32 flags)
{
    return IIntuition(this)->MakeClass(NULLORCSTR(classID), NULLORCSTR(superClassID), superClassPtr, instanceSize, flags);
}

static void bbAddClass(struct BBIInterface *this, Class *cl)
{
    IIntuition(this)->AddClass(cl);
}

static struct DrawInfo * bbGetScreenDrawInfo(struct BBIInterface *this, struct Screen *screen)
{
    return IIntuition(this)->GetScreenDrawInfo(screen);
}

static VOID bbFreeScreenDrawInfo(struct BBIInterface *this, struct Screen *screen, struct DrawInfo *drawInfo)
{
    IIntuition(this)->FreeScreenDrawInfo(screen, drawInfo);
}

static BOOL bbResetMenuStrip(struct BBIInterface *this, struct Window *window, struct Menu *menu)
{
    return IIntuition(this)->ResetMenuStrip(window, menu);
}

static void bbRemoveClass(struct BBIInterface *this, Class *cl)
{
    IIntuition(this)->RemoveClass(cl);
}

static BOOL bbFreeClass(struct BBIInterface *this, Class *cl)
{
    return IIntuition(this)->FreeClass(cl);
}

static struct List * bbLockClassList(struct BBIInterface *this)
{
    return IIntuition(this)->LockClassList();
}

static VOID bbUnlockClassList(struct BBIInterface *this)
{
    IIntuition(this)->UnlockClassList();
}

static void bbReserved1(struct BBIInterface *this)
{
    IIntuition(this)->Reserved1();
}

static void bbReserved2(struct BBIInterface *this)
{
    IIntuition(this)->Reserved2();
}

static void bbReserved3(struct BBIInterface *this)
{
    IIntuition(this)->Reserved3();
}

static void bbReserved4(struct BBIInterface *this)
{
    IIntuition(this)->Reserved4();
}

static void bbReserved5(struct BBIInterface *this)
{
    IIntuition(this)->Reserved5();
}

static void bbReserved6(struct BBIInterface *this)
{
    IIntuition(this)->Reserved6();
}

static struct ScreenBuffer * bbAllocScreenBuffer(struct BBIInterface *this, struct Screen *sc, struct BitMap *bm, ULONG flags)
{
    return IIntuition(this)->AllocScreenBuffer(sc, bm, flags);
}

static VOID bbFreeScreenBuffer(struct BBIInterface *this, struct Screen *sc, struct ScreenBuffer *sb)
{
    IIntuition(this)->FreeScreenBuffer(sc, sb);
}

static ULONG bbChangeScreenBuffer(struct BBIInterface *this, struct Screen *sc, struct ScreenBuffer *sb)
{
    return IIntuition(this)->ChangeScreenBuffer(sc, sb);
}

static VOID bbScreenDepth(struct BBIInterface *this, struct Screen *screen, ULONG flags, APTR reserved)
{
    IIntuition(this)->ScreenDepth(screen, flags, reserved);
}

static VOID bbScreenPosition(struct BBIInterface *this, struct Screen *screen, ULONG flags, LONG x1, LONG y1, LONG x2, LONG y2)
{
    IIntuition(this)->ScreenPosition(screen, flags, x1, y1, x2, y2);
}

static VOID bbScrollWindowRaster(struct BBIInterface *this, struct Window *win, WORD dx, WORD dy, WORD xMin, WORD yMin, WORD xMax, WORD yMax)
{
    IIntuition(this)->ScrollWindowRaster(win, dx, dy, xMin, yMin, xMax, yMax);
}

static VOID bbLendMenus(struct BBIInterface *this, struct Window *fromwindow, struct Window *towindow)
{
    IIntuition(this)->LendMenus(fromwindow, towindow);
}

static uint32 bbDoGadgetMethodA(struct BBIInterface *this, struct Gadget *gad, struct Window *win, struct Requester *req, BBMsg *message)
{
    return IIntuition(this)->DoGadgetMethodA(gad, win, req, &message->MethodId);
}

static uint32 bbDoGadgetMethod(struct BBIInterface *this, struct Gadget *gad, struct Window *win, struct Requester *req, BBArray *methodID)
{
    return IIntuition(this)->DoGadgetMethodA(gad, win, req, (Msg)BBINTARRAYTOPTR(methodID));
}

static VOID bbSetWindowPointerA(struct BBIInterface *this, struct Window *win, const struct TagItem *taglist)
{
    IIntuition(this)->SetWindowPointerA(win, taglist);
}

static VOID bbSetWindowPointer(struct BBIInterface *this, struct Window *win, BBArray *tag1)
{
    IIntuition(this)->SetWindowPointerA(win, BBINTARRAYTOTAGS(tag1));
}

static BOOL bbTimedDisplayAlert(struct BBIInterface *this, uint32 alertNumber, BBString *string, uint16 height, uint32 Time)
{
    return IIntuition(this)->TimedDisplayAlert(alertNumber, NULLORCSTR(string), height, Time);
}

static VOID bbHelpControl(struct BBIInterface *this, struct Window *win, ULONG flags)
{
    IIntuition(this)->HelpControl(win, flags);
}

static BOOL bbShowWindow(struct BBIInterface *this, struct Window *window, struct Window *other)
{
    return IIntuition(this)->ShowWindow(window, other);
}

static BOOL bbHideWindow(struct BBIInterface *this, struct Window *window)
{
    return IIntuition(this)->HideWindow(window);
}

static uint32 bbGetAttrsA(struct BBIInterface *this, Object *object, struct TagItem *tagList)
{
    return IIntuition(this)->GetAttrsA(object, tagList);
}

static uint32 bbGetAttrs(struct BBIInterface *this, APTR object, BBArray *tag1)
{
    return IIntuition(this)->GetAttrsA(object, BBINTARRAYTOTAGS(tag1));
}

static APTR bbLockGUIPrefs(struct BBIInterface *this, ULONG reserved)
{
    return IIntuition(this)->LockGUIPrefs(reserved);
}

static VOID bbUnlockGUIPrefs(struct BBIInterface *this, APTR lock)
{
    IIntuition(this)->UnlockGUIPrefs(lock);
}

static ULONG bbSetGUIAttrsA(struct BBIInterface *this, APTR reserved, struct DrawInfo *drawinfo, struct TagItem *taglist)
{
    return IIntuition(this)->SetGUIAttrsA(reserved, drawinfo, taglist);
}

static ULONG bbSetGUIAttrs(struct BBIInterface *this, APTR reserved, struct DrawInfo *drawinfo, BBArray *tag1)
{
    return IIntuition(this)->SetGUIAttrsA(reserved, drawinfo, BBINTARRAYTOTAGS(tag1));
}

static ULONG bbGetGUIAttrsA(struct BBIInterface *this, APTR reserved, struct DrawInfo *drawinfo, struct TagItem *taglist)
{
    return IIntuition(this)->GetGUIAttrsA(reserved, drawinfo, taglist);
}

static ULONG bbGetGUIAttrs(struct BBIInterface *this, APTR reserved, struct DrawInfo *drawinfo, BBArray *tag1)
{
    return IIntuition(this)->GetGUIAttrsA(reserved, drawinfo, BBINTARRAYTOTAGS(tag1));
}

static ULONG bbGetHalfPens(struct BBIInterface *this, struct DrawInfo *drawinfo, ULONG basepen, UWORD *halfshineptr, UWORD *halfshadowptr)
{
    return IIntuition(this)->GetHalfPens(drawinfo, basepen, halfshineptr, halfshadowptr);
}

static ULONG bbGadgetBox(struct BBIInterface *this, struct Gadget *gadget, APTR domain, ULONG domaintype, ULONG flags, APTR box)
{
    return IIntuition(this)->GadgetBox(gadget, domain, domaintype, flags, box);
}

static void bbRefreshSetGadgetAttrsA(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *req, struct TagItem *taglist)
{
    IIntuition(this)->RefreshSetGadgetAttrsA(gadget, window, req, taglist);
}

static void bbRefreshSetGadgetAttrs(struct BBIInterface *this, struct Gadget *gadget, struct Window *window, struct Requester *req, BBArray *tag1)
{
    IIntuition(this)->RefreshSetGadgetAttrsA(gadget, window, req, BBINTARRAYTOTAGS(tag1));
}

static uint32 bbIDoSuperMethodA(struct BBIInterface *this, Class *cl, Object *object, BBMsg *msg)
{
    return IIntuition(this)->IDoSuperMethodA(cl, object, &msg->MethodId);
}

static uint32 bbIDoSuperMethod(struct BBIInterface *this, Class *cl, Object *object, BBArray *tag1)
{
    return IIntuition(this)->IDoSuperMethodA(cl, object, (Msg)BBINTARRAYTOPTR(tag1));
}

static uint32 bbISetSuperAttrsA(struct BBIInterface *this, Class *cl, Object *object, struct TagItem *taglist)
{
    return IIntuition(this)->ISetSuperAttrsA(cl, object, taglist);
}

static uint32 bbISetSuperAttrs(struct BBIInterface *this, Class *cl, Object *object, BBArray *tag1)
{
    return IIntuition(this)->ISetSuperAttrsA(cl, object, BBINTARRAYTOTAGS(tag1));
}

static uint32 bbICoerceMethodA(struct BBIInterface *this, Class *cl, Object *object, BBMsg *msg)
{
    return IIntuition(this)->ICoerceMethodA(cl, object, &msg->MethodId);
}

static uint32 bbICoerceMethod(struct BBIInterface *this, Class *cl, Object *object, BBArray *tag1)
{
    return IIntuition(this)->ICoerceMethodA(cl, object, (Msg)BBINTARRAYTOPTR(tag1));
}

static uint32 bbIDoMethodA(struct BBIInterface *this, Object *object, BBMsg *msg)
{
    return IIntuition(this)->IDoMethodA(object, &msg->MethodId);
}

static uint32 bbIDoMethod(struct BBIInterface *this, Object *object, BBArray *tag1)
{
    return IIntuition(this)->IDoMethodA(object, (Msg)BBINTARRAYTOPTR(tag1));
}

static struct ClassLibrary * bbOpenClass(struct BBIInterface *this, BBString *name, uint32 version, Class **cl_ptr)
{
    return IIntuition(this)->OpenClass(NULLORCSTR(name), version, cl_ptr);
}

static void bbCloseClass(struct BBIInterface *this, struct ClassLibrary *cl)
{
    IIntuition(this)->CloseClass(cl);
}

static struct Hook * bbSetDisplayBeepHook(struct BBIInterface *this, struct Hook *hook)
{
    return IIntuition(this)->SetDisplayBeepHook(hook);
}

static BOOL bbLockScreen(struct BBIInterface *this, struct Screen *screen, ULONG micros)
{
    return IIntuition(this)->LockScreen(screen, micros);
}

static VOID bbUnlockScreen(struct BBIInterface *this, struct Screen *screen)
{
    IIntuition(this)->UnlockScreen(screen);
}

static LONG bbGetWindowAttrsA(struct BBIInterface *this, struct Window *win, struct TagItem *taglist)
{
    return IIntuition(this)->GetWindowAttrsA(win, taglist);
}

static LONG bbGetWindowAttrs(struct BBIInterface *this, struct Window *win, BBArray *tag1)
{
    return IIntuition(this)->GetWindowAttrsA(win, BBINTARRAYTOTAGS(tag1));
}

static LONG bbSetWindowAttrsA(struct BBIInterface *this, struct Window *win, struct TagItem *taglist)
{
    return IIntuition(this)->SetWindowAttrsA(win, taglist);
}

static LONG bbSetWindowAttrs(struct BBIInterface *this, struct Window *win, BBArray *tag1)
{
    return IIntuition(this)->SetWindowAttrsA(win, BBINTARRAYTOTAGS(tag1));
}

static LONG bbGetWindowAttr(struct BBIInterface *this, struct Window *win, ULONG attr, APTR data, ULONG size)
{
    return IIntuition(this)->GetWindowAttr(win, attr, data, size);
}

static LONG bbSetWindowAttr(struct BBIInterface *this, struct Window *win, ULONG attr, APTR data, ULONG size)
{
    return IIntuition(this)->SetWindowAttr(win, attr, data, size);
}

static VOID bbStripIntuiMessages(struct BBIInterface *this, struct MsgPort *port, struct Window *win)
{
    IIntuition(this)->StripIntuiMessages(port, win);
}

static void bbReserved7(struct BBIInterface *this)
{
    IIntuition(this)->Reserved7();
}

static void bbReserved8(struct BBIInterface *this)
{
    IIntuition(this)->Reserved8();
}

static LONG bbGetScreenAttrsA(struct BBIInterface *this, struct Screen *scr, struct TagItem *taglist)
{
    return IIntuition(this)->GetScreenAttrsA(scr, taglist);
}

static LONG bbGetScreenAttrs(struct BBIInterface *this, struct Screen *scr, BBArray *tag1)
{
    return IIntuition(this)->GetScreenAttrsA(scr, BBINTARRAYTOTAGS(tag1));
}

static LONG bbSetScreenAttrsA(struct BBIInterface *this, struct Screen *scr, struct TagItem *taglist)
{
    return IIntuition(this)->SetScreenAttrsA(scr, taglist);
}

static LONG bbSetScreenAttrs(struct BBIInterface *this, struct Screen *scr, BBArray *tag1)
{
    return IIntuition(this)->SetScreenAttrsA(scr, BBINTARRAYTOTAGS(tag1));
}

static LONG bbGetScreenAttr(struct BBIInterface *this, struct Screen *scr, ULONG attr, APTR data, ULONG size)
{
    return IIntuition(this)->GetScreenAttr(scr, attr, data, size);
}

static LONG bbSetScreenAttr(struct BBIInterface *this, struct Screen *scr, ULONG attr, APTR data, ULONG size)
{
    return IIntuition(this)->SetScreenAttr(scr, attr, data, size);
}

static struct Screen * bbLockScreenList(struct BBIInterface *this)
{
    return IIntuition(this)->LockScreenList();
}

static VOID bbUnlockScreenList(struct BBIInterface *this)
{
    IIntuition(this)->UnlockScreenList();
}

static struct RastPort * bbLockScreenGI(struct BBIInterface *this, struct GadgetInfo *gi, ULONG micros)
{
    return IIntuition(this)->LockScreenGI(gi, micros);
}

static VOID bbUnlockScreenGI(struct BBIInterface *this, struct GadgetInfo *gi, struct RastPort *rp)
{
    IIntuition(this)->UnlockScreenGI(gi, rp);
}

static ULONG bbGetMarkedBlock(struct BBIInterface *this, struct SGWork *sgw)
{
    return IIntuition(this)->GetMarkedBlock(sgw);
}

static VOID bbSetMarkedBlock(struct BBIInterface *this, struct SGWork *sgw, ULONG block)
{
    IIntuition(this)->SetMarkedBlock(sgw, block);
}

static APTR bbObtainBitMapSourceA(struct BBIInterface *this, BBString *name, struct TagItem *taglist)
{
    return IIntuition(this)->ObtainBitMapSourceA(NULLORCSTR(name), taglist);
}

static APTR bbObtainBitMapSource(struct BBIInterface *this, BBString *name, BBArray *tag1)
{
    return IIntuition(this)->ObtainBitMapSourceA(NULLORCSTR(name), BBINTARRAYTOTAGS(tag1));
}

static VOID bbReleaseBitMapSource(struct BBIInterface *this, APTR bitmapsource)
{
    IIntuition(this)->ReleaseBitMapSource(bitmapsource);
}

static APTR bbObtainBitMapInstanceA(struct BBIInterface *this, APTR bitmapsource, struct Screen *screen, struct TagItem *taglist)
{
    return IIntuition(this)->ObtainBitMapInstanceA(bitmapsource, screen, taglist);
}

static APTR bbObtainBitMapInstance(struct BBIInterface *this, APTR bitmapsource, struct Screen *screen, BBArray *tag1)
{
    return IIntuition(this)->ObtainBitMapInstanceA(bitmapsource, screen, BBINTARRAYTOTAGS(tag1));
}

static VOID bbReleaseBitMapInstance(struct BBIInterface *this, APTR bitmapinstance)
{
    IIntuition(this)->ReleaseBitMapInstance(bitmapinstance);
}

static void bbEmbossDisableRect(struct BBIInterface *this, struct RastPort *rp, int32 minx, int32 miny, int32 maxx, int32 maxy, uint32 backtype, uint32 contrast, struct DrawInfo *dri)
{
    IIntuition(this)->EmbossDisableRect(rp, minx, miny, maxx, maxy, backtype, contrast, dri);
}

static void bbEmbossDisableText(struct BBIInterface *this, struct RastPort *rp, BBString *text, uint32 len, uint32 backtype, uint32 contrast, struct DrawInfo *dri)
{
    IIntuition(this)->EmbossDisableText(rp, NULLORCSTR(text), len, backtype, contrast, dri);
}

static VOID bbPrintEmbossedDisabledIText(struct BBIInterface *this, struct RastPort *rp, struct IntuiText *itext, LONG left, LONG top, ULONG backtype, ULONG contrast, struct DrawInfo *dri)
{
    IIntuition(this)->PrintEmbossedDisabledIText(rp, itext, left, top, backtype, contrast, dri);
}

static ULONG bbIntuiTextExtent(struct BBIInterface *this, struct RastPort *rp, struct IntuiText *itext, struct TextExtent *textent)
{
    return IIntuition(this)->IntuiTextExtent(rp, itext, textent);
}

static ULONG bbShadeRectOld(struct BBIInterface *this, struct RastPort *rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo *dri)
{
    return IIntuition(this)->ShadeRectOld(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri);
}

static VOID bbDisableTemplateRGB(struct BBIInterface *this, struct RastPort *rp, LONG left, LONG top, LONG width, LONG height, PLANEPTR template_ptr, ULONG brightlevel, ULONG darklevel)
{
    IIntuition(this)->DisableTemplateRGB(rp, left, top, width, height, template_ptr, brightlevel, darklevel);
}

static ULONG bbSetScreenBitMapInstance(struct BBIInterface *this, struct Screen *scr, ULONG id, APTR source)
{
    return IIntuition(this)->SetScreenBitMapInstance(scr, id, source);
}

static UWORD bbFindMenuKey(struct BBIInterface *this, struct Menu *menu, LONG code)
{
    return IIntuition(this)->FindMenuKey(menu, code);
}

static ULONG bbBitMapInstanceControlA(struct BBIInterface *this, APTR bitmapinstance, struct TagItem *taglist)
{
    return IIntuition(this)->BitMapInstanceControlA(bitmapinstance, taglist);
}

static ULONG bbBitMapInstanceControl(struct BBIInterface *this, APTR bitmapinstance, BBArray *tag1)
{
    return IIntuition(this)->BitMapInstanceControlA(bitmapinstance, BBINTARRAYTOTAGS(tag1));
}

static struct List * bbObtainIPluginList(struct BBIInterface *this, ULONG type, ULONG attrmask, ULONG applymask)
{
    return IIntuition(this)->ObtainIPluginList(type, attrmask, applymask);
}

static VOID bbReleaseIPluginList(struct BBIInterface *this, struct List *list)
{
    IIntuition(this)->ReleaseIPluginList(list);
}

static struct GUIPlugin * bbOpenGUIPlugin(struct BBIInterface *this, BBString *name, ULONG version, ULONG type, ULONG attrmask, ULONG applymask)
{
    return IIntuition(this)->OpenGUIPlugin(NULLORCSTR(name), version, type, attrmask, applymask);
}

static VOID bbCloseGUIPlugin(struct BBIInterface *this, struct GUIPlugin *plugin)
{
    IIntuition(this)->CloseGUIPlugin(plugin);
}

static ULONG bbDrawSysImageA(struct BBIInterface *this, struct RastPort *rp, LONG left, LONG top, LONG width, LONG height, ULONG which, ULONG backtype, ULONG state, struct DrawInfo *dri, struct TagItem *taglist)
{
    return IIntuition(this)->DrawSysImageA(rp, left, top, width, height, which, backtype, state, dri, taglist);
}

static ULONG bbDrawSysImage(struct BBIInterface *this, struct RastPort *rp, LONG left, LONG top, LONG width, LONG height, ULONG which, ULONG backtype, ULONG state, struct DrawInfo *dri, BBArray *tag1)
{
    return IIntuition(this)->DrawSysImageA(rp, left, top, width, height, which, backtype, state, dri, BBINTARRAYTOTAGS(tag1));
}

static uint32 bbDoRender(struct BBIInterface *this, Object *o, struct GadgetInfo *gi, uint32 flags)
{
    return IIntuition(this)->DoRender(o, gi, flags);
}

static ULONG bbSetRenderDomain(struct BBIInterface *this, struct RastPort *rp, struct Rectangle *domain)
{
    return IIntuition(this)->SetRenderDomain(rp, domain);
}

static ULONG bbGetRenderDomain(struct BBIInterface *this, struct RastPort *rp, struct Rectangle *domain)
{
    return IIntuition(this)->GetRenderDomain(rp, domain);
}

static ULONG bbDrawGradient(struct BBIInterface *this, struct RastPort *rp, LONG left, LONG top, LONG width, LONG height, struct IBox *domain, ULONG reserved, struct GradientSpec *gradientspec, struct DrawInfo *dri)
{
    return IIntuition(this)->DrawGradient(rp, left, top, width, height, domain, reserved, gradientspec, dri);
}

static ULONG bbDirectionVector(struct BBIInterface *this, ULONG degrees)
{
    return IIntuition(this)->DirectionVector(degrees);
}

static ULONG bbShadeRectA(struct BBIInterface *this, struct RastPort *rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo *dri, struct TagItem *taglist)
{
    return IIntuition(this)->ShadeRectA(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri, taglist);
}

static ULONG bbShadeRect(struct BBIInterface *this, struct RastPort *rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo *dri, BBArray *tag1)
{
    return IIntuition(this)->ShadeRectA(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri, BBINTARRAYTOTAGS(tag1));
}

static VOID bbDoScrollHook(struct BBIInterface *this, struct ScrollHook *scrollhook, LONG scrollmode)
{
    IIntuition(this)->DoScrollHook(scrollhook, scrollmode);
}

static struct Hook * bbObtainIBackFill(struct BBIInterface *this, struct DrawInfo *dri, ULONG element, ULONG state, ULONG flags)
{
    return IIntuition(this)->ObtainIBackFill(dri, element, state, flags);
}

static VOID bbReleaseIBackFill(struct BBIInterface *this, struct Hook *hook)
{
    IIntuition(this)->ReleaseIBackFill(hook);
}

static ULONG bbIntuitionControlA(struct BBIInterface *this, APTR object, struct TagItem *taglist)
{
    return IIntuition(this)->IntuitionControlA(object, taglist);
}

static ULONG bbIntuitionControl(struct BBIInterface *this, APTR object, BBArray *tag1)
{
    return IIntuition(this)->IntuitionControlA(object, BBINTARRAYTOTAGS(tag1));
}

static APTR bbStartScreenNotifyTagList(struct BBIInterface *this, struct TagItem *taglist)
{
    return IIntuition(this)->StartScreenNotifyTagList(taglist);
}

static APTR bbStartScreenNotifyTags(struct BBIInterface *this, BBArray *tag1)
{
    return IIntuition(this)->StartScreenNotifyTagList(BBINTARRAYTOTAGS(tag1));
}

static BOOL bbEndScreenNotify(struct BBIInterface *this, APTR request)
{
    return IIntuition(this)->EndScreenNotify(request);
}

static VOID bbDisableTemplate(struct BBIInterface *this, struct RastPort *rp, LONG left, LONG top, LONG width, LONG height, APTR template_ptr, LONG offx, ULONG template_type, ULONG bytesperrow, ULONG backtype, struct DrawInfo *dri)
{
    IIntuition(this)->DisableTemplate(rp, left, top, width, height, template_ptr, offx, template_type, bytesperrow, backtype, dri);
}


static void* _IntuitionLibraryVTable[] = {
	 bbOpenIntuition,
     bbIntuition,
     bbAddGadget,
     bbClearDMRequest,
     bbClearMenuStrip,
     bbClearPointer,
     bbCloseScreen,
     bbCloseWindow,
     bbCloseWorkBench,
     bbCurrentTime,
     bbDisplayAlert,
     bbDisplayBeep,
     bbDoubleClick,
     bbDrawBorder,
     bbDrawImage,
     bbEndRequest,
     bbGetDefPrefs,
     bbGetPrefs,
     bbInitRequester,
     bbItemAddress,
     bbModifyIDCMP,
     bbModifyProp,
     bbMoveScreen,
     bbMoveWindow,
     bbOffGadget,
     bbOffMenu,
     bbOnGadget,
     bbOnMenu,
     bbOpenScreen,
     bbOpenWindow,
     bbOpenWorkBench,
     bbPrintIText,
     bbRefreshGadgets,
     bbRemoveGadget,
     bbReportMouse,
     bbReportMouse1,
     bbRequest,
     bbScreenToBack,
     bbScreenToFront,
     bbSetDMRequest,
     bbSetMenuStrip,
     bbSetPointer,
     bbSetWindowTitles,
     bbShowTitle,
     bbSizeWindow,
     bbViewAddress,
     bbViewPortAddress,
     bbWindowToBack,
     bbWindowToFront,
     bbWindowLimits,
     bbSetPrefs,
     bbIntuiTextLength,
     bbWBenchToBack,
     bbWBenchToFront,
     bbAutoRequest,
     bbBeginRefresh,
     bbBuildSysRequest,
     bbEndRefresh,
     bbFreeSysRequest,
     bbMakeScreen,
     bbRemakeDisplay,
     bbRethinkDisplay,
     bbAllocRemember,
     bbAlohaWorkbench,
     bbFreeRemember,
     bbLockIBase,
     bbUnlockIBase,
     bbGetScreenData,
     bbRefreshGList,
     bbAddGList,
     bbRemoveGList,
     bbActivateWindow,
     bbRefreshWindowFrame,
     bbActivateGadget,
     bbNewModifyProp,
     bbQueryOverscan,
     bbMoveWindowInFrontOf,
     bbChangeWindowBox,
     bbSetEditHook,
     bbSetMouseQueue,
     bbZipWindow,
     bbLockPubScreen,
     bbUnlockPubScreen,
     bbLockPubScreenList,
     bbUnlockPubScreenList,
     bbNextPubScreen,
     bbSetDefaultPubScreen,
     bbSetPubScreenModes,
     bbPubScreenStatus,
     bbObtainGIRPort,
     bbReleaseGIRPort,
     bbGadgetMouse,
     bbSetIPrefs,
     bbGetDefaultPubScreen,
     bbEasyRequestArgs,
     bbEasyRequest,
     bbBuildEasyRequestArgs,
     bbBuildEasyRequest,
     bbSysReqHandler,
     bbOpenWindowTagList,
     bbOpenWindowTags,
     bbOpenScreenTagList,
     bbOpenScreenTags,
     bbDrawImageState,
     bbPointInImage,
     bbEraseImage,
     bbNewObjectA,
     bbNewObject,
     bbDisposeObject,
     bbSetAttrsA,
     bbSetAttrs,
     bbGetAttr,
     bbSetGadgetAttrsA,
     bbSetGadgetAttrs,
     bbNextObject,
     bbFindClass,
     bbMakeClass,
     bbAddClass,
     bbGetScreenDrawInfo,
     bbFreeScreenDrawInfo,
     bbResetMenuStrip,
     bbRemoveClass,
     bbFreeClass,
     bbLockClassList,
     bbUnlockClassList,
     bbReserved1,
     bbReserved2,
     bbReserved3,
     bbReserved4,
     bbReserved5,
     bbReserved6,
     bbAllocScreenBuffer,
     bbFreeScreenBuffer,
     bbChangeScreenBuffer,
     bbScreenDepth,
     bbScreenPosition,
     bbScrollWindowRaster,
     bbLendMenus,
     bbDoGadgetMethodA,
     bbDoGadgetMethod,
     bbSetWindowPointerA,
     bbSetWindowPointer,
     bbTimedDisplayAlert,
     bbHelpControl,
     bbShowWindow,
     bbHideWindow,
     bbGetAttrsA,
     bbGetAttrs,
     bbLockGUIPrefs,
     bbUnlockGUIPrefs,
     bbSetGUIAttrsA,
     bbSetGUIAttrs,
     bbGetGUIAttrsA,
     bbGetGUIAttrs,
     bbGetHalfPens,
     bbGadgetBox,
     bbRefreshSetGadgetAttrsA,
     bbRefreshSetGadgetAttrs,
     bbIDoSuperMethodA,
     bbIDoSuperMethod,
     bbISetSuperAttrsA,
     bbISetSuperAttrs,
     bbICoerceMethodA,
     bbICoerceMethod,
     bbIDoMethodA,
     bbIDoMethod,
     bbOpenClass,
     bbCloseClass,
     bbSetDisplayBeepHook,
     bbLockScreen,
     bbUnlockScreen,
     bbGetWindowAttrsA,
     bbGetWindowAttrs,
     bbSetWindowAttrsA,
     bbSetWindowAttrs,
     bbGetWindowAttr,
     bbSetWindowAttr,
     bbStripIntuiMessages,
     bbReserved7,
     bbReserved8,
     bbGetScreenAttrsA,
     bbGetScreenAttrs,
     bbSetScreenAttrsA,
     bbSetScreenAttrs,
     bbGetScreenAttr,
     bbSetScreenAttr,
     bbLockScreenList,
     bbUnlockScreenList,
     bbLockScreenGI,
     bbUnlockScreenGI,
     bbGetMarkedBlock,
     bbSetMarkedBlock,
     bbObtainBitMapSourceA,
     bbObtainBitMapSource,
     bbReleaseBitMapSource,
     bbObtainBitMapInstanceA,
     bbObtainBitMapInstance,
     bbReleaseBitMapInstance,
     bbEmbossDisableRect,
     bbEmbossDisableText,
     bbPrintEmbossedDisabledIText,
     bbIntuiTextExtent,
     bbShadeRectOld,
     bbDisableTemplateRGB,
     bbSetScreenBitMapInstance,
     bbFindMenuKey,
     bbBitMapInstanceControlA,
     bbBitMapInstanceControl,
     bbObtainIPluginList,
     bbReleaseIPluginList,
     bbOpenGUIPlugin,
     bbCloseGUIPlugin,
     bbDrawSysImageA,
     bbDrawSysImage,
     bbDoRender,
     bbSetRenderDomain,
     bbGetRenderDomain,
     bbDrawGradient,
     bbDirectionVector,
     bbShadeRectA,
     bbShadeRect,
     bbDoScrollHook,
     bbObtainIBackFill,
     bbReleaseIBackFill,
     bbIntuitionControlA,
     bbIntuitionControl,
     bbStartScreenNotifyTagList,
     bbStartScreenNotifyTags,
     bbEndScreenNotify,
     bbDisableTemplate
};

static struct BBLibrary  IntuitionLibrary = {
	"intuition.library",
	52,
	"main",
	1,
	_IntuitionLibraryVTable,
	NULL,
	NULL,
	NULL
};

struct BBLibrary *bbIntuitionLibrary = &IntuitionLibrary;