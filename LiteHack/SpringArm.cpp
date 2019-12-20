#include "Commons.h"

void SpringArm(ASTExtraPlayerCharacter^ local_pawn)
{
	return;
	if (GetAsyncKeyState(VK_OEM_PLUS) & 0x0001)
	{
		auto pSpringArm = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x1ca0));
		float m = pSpringArm->ReadOffset<float>(0x02D0);
		Global::GMemory->Write<float>(pSpringArm->GetAddress() + 0x02D0, m + 100.f);
	}
	if (GetAsyncKeyState(VK_OEM_MINUS) & 0x0001)
	{
		auto pSpringArm = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x1ca0));
		float m = pSpringArm->ReadOffset<float>(0x02D0);
		Global::GMemory->Write<float>(pSpringArm->GetAddress() + 0x02D0, 276.f);
	}
}