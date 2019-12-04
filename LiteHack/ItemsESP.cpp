#include "ItemsESP.h"

void DrawItem(ESPInfo& info, AActor^ current_actor)
{
	auto location = current_actor->RootComponent()->Location();
	Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "TombBox [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
}