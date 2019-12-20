#include "Commons.h"

bool speedhack = false;
void SpeedHack(ASTExtraPlayerCharacter^ local_pawn)
{
	if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
	{
		speedhack = !speedhack;
		if (speedhack && local_pawn->VehicleSeatIdx() == -1)
		{
			auto pMovement = local_pawn->ReadOffset<uint64_t>(Off::STCharacterMovement);
			Global::GMemory->Write<float>(pMovement + Off::WalkSpeedCurveScale, 1000.F);
			Global::GMemory->Write<float>(pMovement + Off::MinWalkSpeedModifier, 3.4f);
		}
		else
		{
			auto pMovement = local_pawn->ReadOffset<uint64_t>(Off::STCharacterMovement);
			Global::GMemory->Write<float>(pMovement + Off::WalkSpeedCurveScale, 670.f);
			Global::GMemory->Write<float>(pMovement + Off::MinWalkSpeedModifier, 0.5f);
		}
	}
}