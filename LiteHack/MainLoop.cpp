#include "Commons.h"
#include <iostream>
#include <bitset>
void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
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
		int actor_length = Actors.Length();
		if (actor_length > 25000) continue;
		for (int i = 0; i < actor_length; i++)
		{
			AActor^ current_actor = gcnew ASTExtraPlayerCharacter(Actors.GetById(i));
			int id = current_actor->ComparisonIndex();
			if (Global::GNames->IsEnemy(id)) DrawEnemy(info, current_actor->CastTo<ASTExtraPlayerCharacter>());
			else if (Global::GNames->IsAirdrop(id)) DrawAirdrop(info, current_actor->CastTo<AAirDropBoxActor>());
			else if (Global::GNames->IsTombbox(id)) DrawTombbox(info, current_actor->CastTo<APlayerTombBox>());
			else if (Global::GNames->IsVehicle(id)) DrawVehicle(info, current_actor->CastTo<ASTExtraWheeledVehicle>());
			else if (Global::MainForm->btnDeveloperMode->Checked) DevMode(info, current_actor);
		}
		if (true) Aimbot(info,local_pawn);
		SpectorWarning(local_pawn);
		NearbyEnemyWarning(local_pawn);
		if (true) FastSkyDive(info,local_pawn);
		if (false) SuperJump(local_pawn);
		if (false) SpringArm(local_pawn);
		if (false) SpeedHack(info,local_pawn);
		Global::Canvas->RefreshAndSleep(16);
	}
}