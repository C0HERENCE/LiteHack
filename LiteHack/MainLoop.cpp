#include "Commons.h"
#include <iostream>

void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
	player_keys.clear();
	if (true) DebugInfo();
	while (1)
	{
		Global::Canvas->NewFrame();
		if (GetAsyncKeyState(VK_OEM_3) & 0x0001) ChangeClickable();
		if (showMenu) DrawMenu();
		distances.clear();warning_count = 0;
		auto Actors = Global::GWorld->CurrentLevel()->Actors();
		ASTExtraPlayerCharacter^ local_pawn = Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn();
		ESPInfo info;
		UpdateLocalInfo(info, local_pawn);
		for (size_t i = 0; i < Actors.Length(); i++)
		{
			AActor^ current_actor = gcnew ASTExtraPlayerCharacter(Actors.GetById(i));
			int id = current_actor->ComparisonIndex();
			if (Global::GNames->IsEnemy(id)) DrawEnemy(info, current_actor->CastTo<ASTExtraPlayerCharacter>());
			else if (Global::GNames->IsAirdrop(id)) DrawAirdrop(info, current_actor->CastTo<AAirDropBoxActor>());
			else if (Global::GNames->IsTombbox(id)) DrawTombbox(info, current_actor->CastTo<APlayerTombBox>());
			else if (Global::GNames->IsVehicle(id)) DrawVehicle(info, current_actor->CastTo<ASTExtraWheeledVehicle>());
			else if (false) DevMode(info, current_actor);
		}
		Aimbot(local_pawn);
		SpectorWarning(local_pawn);
		NearbyEnemyWarning(local_pawn);
		FastSkyDive(local_pawn);
		SuperJump(local_pawn);
		SpringArm(local_pawn);
		SpeedHack(local_pawn);
		Global::Canvas->RefreshAndSleep(16);
	}
}