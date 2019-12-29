#include "Commons.h"

int superjump = 0;
void SuperJump(ASTExtraPlayerCharacter^ local_pawn)
{
	if (superjump > 0)
	{
		superjump++;
		Global::Draw->Text(FVector(Global::Canvas->Width / 2.f - 100.f, 500.f, 0.f), FRED_DARKSALMON, "Super Jump Openning!");
		auto pMovement = local_pawn->ReadOffset<uint64_t>(Off::STCharacterMovement);
		Global::GMemory->Write<float>(pMovement + Off::JumpZVelocity, 860.F);

		Global::GMemory->Write<float>(pMovement + 0x22C, 1.f);
		Global::GMemory->Write<float>(pMovement + 0x1f4, 250000.f);
		Global::GMemory->Write<float>(pMovement + 0x238, 250000.f);
	}
	if (superjump >= 20)
	{
		superjump = 0;
		auto pMovement = local_pawn->ReadOffset<uint64_t>(Off::STCharacterMovement);
		Global::GMemory->Write<float>(pMovement + Off::JumpZVelocity, 443.f);

		Global::GMemory->Write<float>(pMovement + 0x22C, 0.05F);
		Global::GMemory->Write<float>(pMovement + 0x1f4, 1000.f);
		Global::GMemory->Write<float>(pMovement + 0x238, 1000.f);

	}
	else if (superjump == 0 && GetAsyncKeyState(VK_LMENU) & 0x0001)
	{
		superjump = 1;
	}
}