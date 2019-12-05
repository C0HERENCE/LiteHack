#include "VehiclesESP.h"

void DrawVehicle(ESPInfo& info, ASTExtraWheeledVehicle^ vehicle)
{
	auto screenpos = Global::Draw->WorldToScreen(vehicle->RootComponent()->Location(), info.POV);
	auto distance = info.LocalPos.Distance(vehicle->RootComponent()->Location()) / 100;
	Global::Draw->Text(screenpos + FVector(-24,24,0), FGREEN_CHARTREUSE, std::to_string((int)distance)+"m");
	Global::Draw->Image(VehicleImages[vehicle->VehicleShapeType()], screenpos - FVector(24, 24, 0), screenpos + FVector(24, 24, 0));
}