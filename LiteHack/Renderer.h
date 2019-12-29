#pragma once
#include "Core.h"
#include "Updates.h"
#include <string>
#include <d3d11.h>
#include "imgui.h"

struct FMinimalViewInfo;
ref class Renderer
{
public:
	Renderer() {};
	~Renderer() {};
	bool Alpha;
	void Line(FVector from, FVector end, FColor color, float thickness);
	void Text(FVector pos, FColor color, std::string string);
	void Text(FVector pos, FColor color, char* string, int length);
	void Circle(FVector center, float radius, FColor color);
	void Rectangle(FVector a, float, float, FColor color);
	void RectangleFilled(FVector a, float, float, FColor color);
	void Image(ID3D11ShaderResourceView* texture, FVector a, FVector b);
	FVector WorldToScreen(FVector WorldLocation, FMinimalViewInfo POV);
private:
	ImU32 ConvertColor(FColor color);
};

#define FRED_INDIANRED  FColor(205, 92, 92)
#define FRED_LIGHTCORAL  FColor(240, 128, 128)
#define FRED_SALMON  FColor(250, 128, 114)
#define FRED_DARKSALMON  FColor(233, 150, 122)
#define FRED_LIGHTSALMON  FColor(255, 160, 122)
#define FRED_CRIMSON  FColor(220, 20, 60)
#define FRED_RED  FColor(255, 0, 0)
#define FRED_FIREBRICK  FColor(178, 34, 34)
#define FRED_DARKRED  FColor(139, 0, 0)

#define FPINK_PINK  FColor(255, 192, 203)
#define FPINK_LIGHTPINK  FColor(255, 182, 193)
#define FPINK_HOTPINK  FColor(255, 105, 180)
#define FPINK_DEEPPINK  FColor(255, 20, 147)
#define FPINK_MEDIUMVIOLETRED  FColor(199, 21, 133)
#define FPINK_PALEVIOLETRED  FColor(219, 112, 147)

#define FORANGE_LIGHTSALMON  FColor(255, 160, 122)
#define FORANGE_CORAL  FColor(255, 127, 80)
#define FORANGE_TOMATO  FColor(255, 99, 71)
#define FORANGE_ORANGERED  FColor(255, 69, 0)
#define FORANGE_DARKORANGE  FColor(255, 140, 0)
#define FORANGE_ORANGE  FColor(255, 165, 0)

#define FYELLOW_GOLD  FColor(255, 215, 0)
#define FYELLOW_YELLOW  FColor(255, 255, 0)
#define FYELLOW_LIGHTYELLOW  FColor(255, 255, 224)
#define FYELLOW_LEMONCHIFFON  FColor(255, 250, 205)
#define FYELLOW_LIGHTGOLDENRODYELLOW  FColor(250, 250, 210)
#define FYELLOW_PAPAYAWHIP  FColor(255, 239, 213)
#define FYELLOW_MOCCASIN  FColor(255, 228, 181)
#define FYELLOW_PEACHPUFF  FColor(255, 218, 185)
#define FYELLOW_PALEGOLDENROD  FColor(238, 232, 170)
#define FYELLOW_KHAKI  FColor(240, 230, 140)
#define FYELLOW_DARKKHAKI  FColor(189, 183, 107)

#define FPURPLE_LAVENDER  FColor(230, 230, 250)
#define FPURPLE_THISTLE  FColor(216, 191, 216)
#define FPURPLE_PLUM  FColor(221, 160, 221)
#define FPURPLE_VIOLET  FColor(238, 130, 238)
#define FPURPLE_ORCHID  FColor(218, 112, 214)
#define FPURPLE_FUCHSIA  FColor(255, 0, 255)
#define FPURPLE_MAGENTA  FColor(255, 0, 255)
#define FPURPLE_MEDIUMORCHID  FColor(186, 85, 211)
#define FPURPLE_MEDIUMPURPLE  FColor(147, 112, 219)
#define FPURPLE_REBECCAPURPLE  FColor(102, 51, 153)
#define FPURPLE_BLUEVIOLET  FColor(138, 43, 226)
#define FPURPLE_DARKVIOLET  FColor(148, 0, 211)
#define FPURPLE_DARKORCHID  FColor(153, 50, 204)
#define FPURPLE_DARKMAGENTA  FColor(139, 0, 139)
#define FPURPLE_PURPLE  FColor(128, 0, 128)
#define FPURPLE_INDIGO  FColor(75, 0, 130)
#define FPURPLE_SLATEBLUE  FColor(106, 90, 205)
#define FPURPLE_DARKSLATEBLUE  FColor(72, 61, 139)
#define FPURPLE_MEDIUMSLATEBLUE  FColor(123, 104, 238)

#define FGREEN_GREENYELLOW  FColor(173, 255, 47)
#define FGREEN_CHARTREUSE  FColor(127, 255, 0)
#define FGREEN_LAWNGREEN  FColor(124, 252, 0)
#define FGREEN_LIME  FColor(0, 255, 0)
#define FGREEN_LIMEGREEN  FColor(50, 205, 50)
#define FGREEN_PALEGREEN  FColor(152, 251, 152)
#define FGREEN_LIGHTGREEN  FColor(144, 238, 144)
#define FGREEN_MEDIUMSPRINGGREEN  FColor(0, 250, 154)
#define FGREEN_SPRINGGREEN  FColor(0, 255, 127)
#define FGREEN_MEDIUMSEAGREEN  FColor(60, 179, 113)
#define FGREEN_SEAGREEN  FColor(46, 139, 87)
#define FGREEN_FORESTGREEN  FColor(34, 139, 34)
#define FGREEN_GREEN  FColor(0, 128, 0)
#define FGREEN_DARKGREEN  FColor(0, 100, 0)
#define FGREEN_YELLOWGREEN  FColor(154, 205, 50)
#define FGREEN_OLIVEDRAB  FColor(107, 142, 35)
#define FGREEN_OLIVE  FColor(128, 128, 0)
#define FGREEN_DARKOLIVEGREEN  FColor(85, 107, 47)
#define FGREEN_MEDIUMAQUAMARINE  FColor(102, 205, 170)
#define FGREEN_DARKSEAGREEN  FColor(143, 188, 139)
#define FGREEN_LIGHTSEAGREEN  FColor(32, 178, 170)
#define FGREEN_DARKCYAN  FColor(0, 139, 139)
#define FGREEN_TEAL  FColor(0, 128, 128)

#define FBLUE_AQUA  FColor(0, 255, 255)
#define FBLUE_CYAN  FColor(0, 255, 255)
#define FBLUE_LIGHTCYAN  FColor(224, 255, 255)
#define FBLUE_PALETURQUOISE  FColor(175, 238, 238)
#define FBLUE_AQUAMARINE  FColor(127, 255, 212)
#define FBLUE_TURQUOISE  FColor(64, 224, 208)
#define FBLUE_MEDIUMTURQUOISE  FColor(72, 209, 204)
#define FBLUE_DARKTURQUOISE  FColor(0, 206, 209)
#define FBLUE_CADETBLUE  FColor(95, 158, 160)
#define FBLUE_STEELBLUE  FColor(70, 130, 180)
#define FBLUE_LIGHTSTEELBLUE  FColor(176, 196, 222)
#define FBLUE_POWDERBLUE  FColor(176, 224, 230)
#define FBLUE_LIGHTBLUE  FColor(173, 216, 230)
#define FBLUE_SKYBLUE  FColor(135, 206, 235)
#define FBLUE_LIGHTSKYBLUE  FColor(135, 206, 250)
#define FBLUE_DEEPSKYBLUE  FColor(0, 191, 255)
#define FBLUE_DODGERBLUE  FColor(30, 144, 255)
#define FBLUE_CORNFLOWERBLUE  FColor(100, 149, 237)
#define FBLUE_MEDIUMSLATEBLUE  FColor(123, 104, 238)
#define FBLUE_ROYALBLUE  FColor(65, 105, 225)
#define FBLUE_BLUE  FColor(0, 0, 255)
#define FBLUE_MEDIUMBLUE  FColor(0, 0, 205)
#define FBLUE_DARKBLUE  FColor(0, 0, 139)
#define FBLUE_NAVY  FColor(0, 0, 128)
#define FBLUE_MIDNIGHTBLUE  FColor(25, 25, 112)

#define FBROWN_CORNSILK  FColor(255, 248, 220)
#define FBROWN_BLANCHEDALMOND  FColor(255, 235, 205)
#define FBROWN_BISQUE  FColor(255, 228, 196)
#define FBROWN_NAVAJOWHITE  FColor(255, 222, 173)
#define FBROWN_WHEAT  FColor(245, 222, 179)
#define FBROWN_BURLYWOOD  FColor(222, 184, 135)
#define FBROWN_TAN  FColor(210, 180, 140)
#define FBROWN_ROSYBROWN  FColor(188, 143, 143)
#define FBROWN_SANDYBROWN  FColor(244, 164, 96)
#define FBROWN_GOLDENROD  FColor(218, 165, 32)
#define FBROWN_DARKGOLDENROD  FColor(184, 134, 11)
#define FBROWN_PERU  FColor(205, 133, 63)
#define FBROWN_CHOCOLATE  FColor(210, 105, 30)
#define FBROWN_SADDLEBROWN  FColor(139, 69, 19)
#define FBROWN_SIENNA  FColor(160, 82, 45)
#define FBROWN_BROWN  FColor(165, 42, 42)
#define FBROWN_MAROON  FColor(128, 0, 0)

#define FWHITE_WHITE  FColor(255, 255, 255)
#define FWHITE_SNOW  FColor(255, 250, 250)
#define FWHITE_HONEYDEW  FColor(240, 255, 240)
#define FWHITE_MINTCREAM  FColor(245, 255, 250)
#define FWHITE_AZURE  FColor(240, 255, 255)
#define FWHITE_ALICEBLUE  FColor(240, 248, 255)
#define FWHITE_GHOSTWHITE  FColor(248, 248, 255)
#define FWHITE_WHITESMOKE  FColor(245, 245, 245)
#define FWHITE_SEASHELL  FColor(255, 245, 238)
#define FWHITE_BEIGE  FColor(245, 245, 220)
#define FWHITE_OLDLACE  FColor(253, 245, 230)
#define FWHITE_FLORALWHITE  FColor(255, 250, 240)
#define FWHITE_IVORY  FColor(255, 255, 240)
#define FWHITE_ANTIQUEWHITE  FColor(250, 235, 215)
#define FWHITE_LINEN  FColor(250, 240, 230)
#define FWHITE_LAVENDERBLUSH  FColor(255, 240, 245)
#define FWHITE_MISTYROSE  FColor(255, 228, 225)

#define FGRAY_GAINSBORO  FColor(220, 220, 220)
#define FGRAY_LIGHTGRAY  FColor(211, 211, 211)
#define FGRAY_SILVER  FColor(192, 192, 192)
#define FGRAY_DARKGRAY  FColor(169, 169, 169)
#define FGRAY_GRAY  FColor(128, 128, 128)
#define FGRAY_DIMGRAY  FColor(105, 105, 105)
#define FGRAY_LIGHTSLATEGRAY  FColor(119, 136, 153)
#define FGRAY_SLATEGRAY  FColor(112, 128, 144)
#define FGRAY_DARKSLATEGRAY  FColor(47, 79, 79)
#define FGRAY_BLACK  FColor(0, 0, 0)
