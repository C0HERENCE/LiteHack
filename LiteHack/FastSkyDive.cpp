#include "Commons.h"

void FastSkyDive(ASTExtraPlayerCharacter^ local_pawn)
{
	if (GetAsyncKeyState(VK_F9) & 0x0001)
	{
		uint64_t pUTslSkydiveComponent = local_pawn->ReadOffset<uint64_t>(Off::SkydivingComponent);
		
		if (Global::GMemory->Read<float>(pUTslSkydiveComponent + Off::FreefallVelocitySettings_SpeedMax) <= 7000.f)
		{
			Global::GMemory->Write<float>(pUTslSkydiveComponent + Off::FreefallVelocitySettings_SpeedMax, 300000.f);
		}
		else
		{
			Global::GMemory->Write<float>(pUTslSkydiveComponent + Off::FreefallVelocitySettings_SpeedMax, 6500.f);
		}
	}
}
