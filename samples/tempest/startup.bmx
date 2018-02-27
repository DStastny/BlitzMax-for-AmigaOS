Strict
Import "transformfunctions.bmx"
Import "vectorfont.bmx"



Function CalcMax()
	Local MaxDepth = 0
	If GraphicsModeExists( CWidth,CHeight,16) MaxDepth = 16
	If GraphicsModeExists( CWidth,CHeight,24) MaxDepth = 24
	If GraphicsModeExists( CWidth,CHeight,32) MaxDepth = 32
	If MaxDepth = 0 
		Print "Unable to find adequate graphics mode."
		End
	End If
	Return MaxDepth
End Function


Function PickMode()
	AppTitle = "Blitz Tempest"
	Local MaxDepth = CalcMax()
	Local sc#=4.0
	Graphics 640, 480
	HideMouse
	Repeat
		Cls
		Local i = MilliSecs() 
		Local R = 128+ (Sin(i) * 128)
  		Local G = 128+ (Sin(i+90) * 128)

  		Local B = 128+ (Sin(i+180) * 128)
	


		SetColor R,G,B
		DrawString("Play Full Screen Y/N",320-sc*40,225-sc*10,sc)
		If KeyHit(Key_Escape) End
		If KeyHit(Key_Y)
			Return MaxDepth
		End If
		If KeyHit(Key_N)
			Return 0
		End If
		Flip
	Forever
End Function

