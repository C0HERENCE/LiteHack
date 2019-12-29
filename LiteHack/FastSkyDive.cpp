#include "Commons.h"

void FastSkyDive(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn)
{
	if (info.Local.isInParachute)
	{
		uint64_t pUTslSkydiveComponent = local_pawn->ReadOffset<uint64_t>(Off::SkydivingComponent);
		if (Global::GMemory->Read<float>(pUTslSkydiveComponent + Off::FreefallVelocitySettings_SpeedMax) <= 7000.f)
		{
			Global::GMemory->Write<float>(pUTslSkydiveComponent + Off::FreefallVelocitySettings_SpeedMax, 300000.f);
		}
	}
}
