#include "Common.h"
#include "../Global.h"

bool speedhack = false;
void SpeedHack(ESPInfo& info, ASTExtraPlayerCharacter local_pawn)
{
	if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
	{
		speedhack = !speedhack;
		if (!speedhack)
		{
			auto pMovement = local_pawn.ReadOffset<uint64_t>(Off::STCharacterMovement);
			LiteHack.GMemory->Write<float>(pMovement + Off::WalkSpeedCurveScale, 670.f);
			LiteHack.GMemory->Write<float>(pMovement + Off::MinWalkSpeedModifier, 0.5f);
			return;
		}
	}
	if (speedhack)
	{
		auto pMovement = local_pawn.ReadOffset<uint64_t>(Off::STCharacterMovement);
		float movespeed = LiteHack.GMemory->Read<float>(pMovement + Off::WalkSpeedCurveScale);
		if (info.Local.isSprint && info.Local.isMove && !info.Local.isInVehicle)
		{
			if (movespeed < 800.f)
			{
				LiteHack.GMemory->Write<float>(pMovement + Off::WalkSpeedCurveScale, 1000.F);
				LiteHack.GMemory->Write<float>(pMovement + Off::MinWalkSpeedModifier, 3.4f);
			}
		}
		else
		{
			if (movespeed > 800.f)
			{
				LiteHack.GMemory->Write<float>(pMovement + Off::WalkSpeedCurveScale, 670.f);
				LiteHack.GMemory->Write<float>(pMovement + Off::MinWalkSpeedModifier, 0.5f);
			}
		}
	}
}