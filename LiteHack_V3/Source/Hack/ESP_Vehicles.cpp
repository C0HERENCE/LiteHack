#include "Common.h"
#include "../Global.h"

std::map<uint8_t, ID3D11ShaderResourceView*> VehicleImages;

void LoadVehicleImages()
{
	for (int i = 1; i < 29; i++)
	{
		ID3D11ShaderResourceView* texture;
		std::string path = "Images/Vehicles/" + std::to_string(i) + ".png";
		LiteHack.Canvas->LoadTextureFromFile(path.c_str(), &texture);
		VehicleImages.insert({ i , texture });
	}
}

void DrawVehicle(ESPInfo& info, ASTExtraWheeledVehicle vehicle)
{
	std::cout << "xxxxxxxxxxxxxxxxx" << std::endl;
	auto screenpos = LiteHack.Draw->WorldToScreen(vehicle.RootComponent().Location(), info.Local.POV);
	auto distance = info.Local.Pos.Distance(vehicle.RootComponent().Location()) / 100;

	LiteHack.Draw->Text(screenpos + FVector(-24, 24, 0), FPINK_HOTPINK, std::to_string((int)distance) + "m");
	LiteHack.Draw->Image(VehicleImages[vehicle.VehicleShapeType()], screenpos - FVector(24, 24, 0), screenpos + FVector(24, 24, 0));
}