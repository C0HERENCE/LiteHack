#include "Commons.h"

void DrawAirdrop(ESPInfo& info, AAirDropBoxActor^ item)
{
	auto screenpos = Global::Draw->WorldToScreen(item->RootComponent()->Location(), info.Local.POV);
	auto distance = info.Local.Pos.Distance(item->RootComponent()->Location()) / 100;
	Global::Draw->Text(screenpos + FVector(-24, 24, 0), FGREEN_CHARTREUSE, std::to_string((int)distance) + "m");
	Global::Draw->Image(AirDropNormalImages, screenpos - FVector(24, 24, 0), screenpos + FVector(24, 24, 0));

}

void DrawTombbox(ESPInfo& info, APlayerTombBox^ item)
{
	auto screenpos = Global::Draw->WorldToScreen(item->RootComponent()->Location(), info.Local.POV);
	auto distance = info.Local.Pos.Distance(item->RootComponent()->Location()) / 100;
	Global::Draw->Text(screenpos + FVector(-24, 24, 0), FGREEN_CHARTREUSE, std::to_string((int)distance) + "m");
	Global::Draw->Image(TombboxImage, screenpos - FVector(24, 24, 0), screenpos + FVector(24, 24, 0));

}