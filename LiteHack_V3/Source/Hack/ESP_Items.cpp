#include "Common.h"
#include "../Global.h"

ID3D11ShaderResourceView* AirDropNormalImages;
ID3D11ShaderResourceView* AirDropOpenImages;
ID3D11ShaderResourceView* AirDropFlyingImages;

ID3D11ShaderResourceView* TombboxImage;

void LoadItemImages()
{
	std::string path;
	path = "Images/CarePackage/Normal.png";
	LiteHack.Canvas->LoadTextureFromFile(path.c_str(), &AirDropNormalImages);
	path = "Images/CarePackage/Open.png";
	LiteHack.Canvas->LoadTextureFromFile(path.c_str(), &AirDropOpenImages);
	path = "Images/CarePackage/Flying.png";
	LiteHack.Canvas->LoadTextureFromFile(path.c_str(), &AirDropFlyingImages);
	path = "Images/Tombbox/Death.png";
	LiteHack.Canvas->LoadTextureFromFile(path.c_str(), &TombboxImage);
}

void DrawAirdrop(ESPInfo& info, AAirDropBoxActor item)
{
	auto screenpos = LiteHack.Draw->WorldToScreen(item.RootComponent().Location(), info.Local.POV);
	auto distance = info.Local.Pos.Distance(item.RootComponent().Location()) / 100;
	LiteHack.Draw->Text(screenpos + FVector(-24, 24, 0), FGREEN_CHARTREUSE, std::to_string((int)distance) + "m");
	LiteHack.Draw->Image(AirDropNormalImages, screenpos - FVector(10, 10, 0), screenpos + FVector(10, 10, 0));
}

void DrawTombbox(ESPInfo& info, APlayerTombBox item)
{
	auto screenpos = LiteHack.Draw->WorldToScreen(item.RootComponent().Location(), info.Local.POV);
	auto distance = info.Local.Pos.Distance(item.RootComponent().Location()) / 100;
	LiteHack.Draw->Text(screenpos + FVector(-24, 24, 0), FGREEN_CHARTREUSE, std::to_string((int)distance) + "m");
	LiteHack.Draw->Image(TombboxImage, screenpos - FVector(24, 18, 0), screenpos + FVector(24, 18, 0));
}