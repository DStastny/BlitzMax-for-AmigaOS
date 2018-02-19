
Const LM_ADDCHILD  : Int = $540001

Type TlmAddChild  Extends TMsg
	Field _lm_Window : TWindow
    	Field _lm_Object : TObject
    	Field _lm_ObjectAttrs : TTagItems
End Type

Const LM_ADDIMAGE : Int = $540002

Type TlmAddImage Extends TMsg
	Field _lm_Window : TWindow
    	Field _lm_Object : TObject
    	Field _lm_ObjectAttrs : TTagItems
End Type

Const LM_REMOVECHILD : Int = $540003

Type TlmRemoveChild Extends TMsg
	Field _lm_Window : TWindow
    	Field _lm_Object : TObject
End Type

Const LM_MODIFYCHILD : Int = $540004

Type TlmModifyChild Extends TMsg
	Field _lm_Window : TWindow
    	Field _lm_Object : TObject
    	Field _lm_ObjectAttrs : TTagItems
End Type

Const LAYOUT_Dummy	: Int =     REACTION_Dummy+ $7000

Const LAYOUT_Orientation : Int =   LAYOUT_Dummy+1
Const LAYOUT_FixedHoriz  : Int =   LAYOUT_Dummy+2
Const LAYOUT_FixedVert   : Int =    LAYOUT_Dummy+3
Const LAYOUT_HorizAlignment : Int = LAYOUT_Dummy+4
Const LAYOUT_VertAlignment  : Int =  LAYOUT_Dummy+5
Const LAYOUT_ShrinkWrap     : Int = LAYOUT_Dummy+6
Const LAYOUT_EvenSize       : Int = LAYOUT_Dummy+7
Const LAYOUT_InnerSpacing   : Int = LAYOUT_Dummy+9
Const LAYOUT_HorizSpacing : Int = LAYOUT_InnerSpacing  
Const LAYOUT_VertSpacing   : Int = LAYOUT_InnerSpacing
Const INTERSPACING          : Int = 4      
Const INTERSPACE            : Int = INTERSPACING
Const LAYOUT_TopSpacing     : Int = LAYOUT_Dummy+10
Const LAYOUT_BottomSpacing  : Int = LAYOUT_Dummy+11
Const LAYOUT_LeftSpacing    : Int = LAYOUT_Dummy+12
Const LAYOUT_RightSpacing   : Int = LAYOUT_Dummy+13
Const LAYOUT_BevelState     : Int = LAYOUT_Dummy+14
Const LAYOUT_BevelStyle     : Int = LAYOUT_Dummy+15
Const LAYOUT_Label          : Int = LAYOUT_Dummy+16
Const LAYOUT_LabelImage     : Int = LAYOUT_Dummy+17
Const LAYOUT_LabelPlace     : Int = LAYOUT_Dummy+18
Const LAYOUT_RemoveChild   : Int =  LAYOUT_Dummy+19
Const LAYOUT_AddChild     : Int =  LAYOUT_Dummy+20
Const LAYOUT_AddImage     : Int =  LAYOUT_Dummy+21
Const LAYOUT_ModifyChild   : Int = LAYOUT_Dummy+22
Const LAYOUT_RelVerify      : Int = LAYOUT_Dummy+23
Const LAYOUT_RelCode        : Int = LAYOUT_Dummy+24
Const LAYOUT_Parent         : Int = LAYOUT_Dummy+25
Const LAYOUT_DeferLayout : Int =   LAYOUT_Dummy+26
Const LAYOUT_RequestLayout  : Int = LAYOUT_Dummy+27
Const LAYOUT_RequestRefresh : Int = LAYOUT_Dummy+28
Const LAYOUT_TextPen        : Int = LAYOUT_Dummy+29
Const LAYOUT_FillPen        : Int = LAYOUT_Dummy+30
Const LAYOUT_FillPattern    : Int = LAYOUT_Dummy+31
Const LAYOUT_PageBackFill   : Int = LAYOUT_Dummy+32
Const LAYOUT_BackFill        : Int = GA_BackFill
Const LAYOUT_TabVerify      : Int = LAYOUT_Dummy+33
Const LAYOUT_LabelColumn    : Int = LAYOUT_Dummy+34
Const LAYOUT_LabelWidth     : Int = LAYOUT_Dummy+35
Const LAYOUT_AlignLabels    : Int = LAYOUT_Dummy+36
Const LAYOUT_SpaceInner    : Int =  LAYOUT_Dummy+37
Const LAYOUT_SpaceOuter   : Int =   LAYOUT_Dummy+38
Const LAYOUT_RelAddress     : Int = LAYOUT_Dummy+39
Const LAYOUT_HelpHit        : Int = LAYOUT_Dummy+40
Const LAYOUT_HelpGadget     : Int = LAYOUT_Dummy+41
Const LAYOUT_DisposeLabels : Int = LAYOUT_Dummy 
Const LAYOUT_Inverted       : Int = LAYOUT_Dummy+42
Const LAYOUT_WeightBar      : Int = LAYOUT_Dummy+43
Const LAYOUT_NoLayout       : Int = LAYOUT_Dummy+44 
Const LAYOUT_LayoutBackFill : Int = LAYOUT_Dummy+45 
Const LAYOUT_CharSet        : Int = LAYOUT_Dummy+47 
Const LAYOUT_Immediate      : Int = LAYOUT_Dummy+48
Const LAYOUT_DoImmediate    : Int = LAYOUT_Dummy+49 

Rem
* Child tags! 
End Rem

Const CHILD_Dummy           : Int = LAYOUT_Dummy+$100
Const CHILD_MinWidth        : Int = CHILD_Dummy+1
Const CHILD_MinHeight       : Int = CHILD_Dummy+2
Const CHILD_NominalSize    : Int = CHILD_Dummy+11
Const CHILD_MaxWidth       : Int = CHILD_Dummy+3
Const CHILD_MaxHeight      : Int = CHILD_Dummy+4
Const CHILD_WeightedWidth   : Int = CHILD_Dummy+5
Const CHILD_WeightedHeight  : Int = CHILD_Dummy+6
Const CHILD_ReplaceObject   : Int = CHILD_Dummy+7
Const CHILD_ReplaceImage    : Int = LAYOUT_Dummy+8
Const CHILD_CacheDomain     : Int = CHILD_Dummy+9
Const CHILD_WeightMinimum   : Int = CHILD_Dummy+10
Const CHILD_Label           : Int = CHILD_Dummy+12
Const CHILD_NoDispose       : Int = CHILD_Dummy+13
Const CHILD_ScaleHeight     : Int = CHILD_Dummy+14
Const CHILD_ScaleWidth      : Int = CHILD_Dummy+15
Const CHILD_DataType        : Int = CHILD_Dummy+16


Global LCLABEL_NOLABEL   : TObject = TObject(CastAPTR(1))

Rem
*  Possible values for LAYOUT_Orientation. 
End Rem

Const LAYOUT_HORIZONTAL: Int =   0
Const LAYOUT_VERTICAL     : Int =  1

Const LAYOUT_ORIENT_HORIZ : Int = LAYOUT_HORIZONTAL
Const LAYOUT_ORIENT_VERT  : Int = LAYOUT_VERTICAL

Rem
* Possible values for LAYOUT_HorizAlignment. 
End Rem

Const LALIGN_LEFT          : Int = 0
Const LALIGN_RIGHT        : Int = 1
Const LALIGN_CENTER     : Int = 2
Const LALIGN_CENTRE     : Int = LALIGN_CENTER

Const LAYOUT_ALIGN_LEFT : Int =   LALIGN_LEFT
Const LAYOUT_ALIGN_RIGHT  : Int =LALIGN_RIGHT
Const LAYOUT_ALIGN_CENTER : Int =LALIGN_CENTER

Rem
* Possible values for LAYOUT_VertAlignment. 
End Rem

Const LALIGN_TOP        : Int =   0
Const LALIGN_BOTTOM : Int =   1


Const LAYOUT_ALIGN_TOP : Int = LALIGN_TOP
Const LAYOUT_ALIGN_BOTTOM :Int  = LALIGN_BOTTOM


Rem
* Page Class tags
End Rem

Const PAGE_Dummy  	: Int = LAYOUT_Dummy + $200
Const PAGE_Add        	: Int = PAGE_Dummy + 1
Const PAGE_Remove      	: Int = PAGE_Dummy+2
Const PAGE_Current     	: Int = PAGE_Dummy+3
Const PAGE_FixedVert   	: Int = PAGE_Dummy+4
Const PAGE_FixedHoriz  	: Int = PAGE_Dummy+5
Const PAGE_Transparent	: Int = PAGE_Dummy+6
Const PAGE_NoDispose   	: Int = PAGE_Dummy+7
