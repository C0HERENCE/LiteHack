#include "EnemyESP.h"
#include "Aimbot.h"
#include <iostream>

void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GNames = gcnew Names();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
	Global::GNames->Init(Global::GMemory->GetBase() + Off::GNames);
	player_keys.clear();

	while (1)
	{
		Global::Canvas->NewFrame();
		//--------------------------------------------------------------------------------Init
		distances.clear();
		warning_count = 0;
		ASTExtraPlayerCharacter^ local_pawn = Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn();
		ESPInfo info;
		UpdateLocalInfo(info, local_pawn);

		//--------------------------------------------------------------------------------For Loops
		auto Actors = Global::GWorld->CurrentLevel()->Actors();
		for (size_t i = 0; i < Actors.Length(); i++)
		{
			AActor^ current_actor = gcnew ASTExtraPlayerCharacter(Actors.GetById(i));

			//----------------------------------------------------------------------------Enemy Esp

			if (current_actor->ComparisonIndex() == Global::GNames->CharacterId)
			{
				ASTExtraPlayerCharacter^ enemy = current_actor->CastTo<ASTExtraPlayerCharacter>();
				info.TeamID = enemy->TeamID();
				if (info.TeamID != info.LocalTeamID && (enemy->HealthStatus() == 0 || enemy->HealthStatus() == 1))
				{
					UpdateEnemyInfo(info, enemy);
					ESPText(info);
					ESPLine(info);
					ESPBone(info);
					Radar(info);
				}
			}


			//----------------------------------------------------------------------------Items ESP

			else if (current_actor->ComparisonIndex() == Global::GNames->AirdropId)
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "AirDrop [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}


			//----------------------------------------------------------------------------Vehicles ESP

			else if (current_actor->ComparisonIndex() == Global::GNames->TombBox)
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "TombBox [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}


			//----------------------------------------------------------------------------Dev Mode

			if (Global::MainForm->btnDeveloperMode->Checked)
			{
				Global::Draw->Text(Global::Draw->WorldToScreen(current_actor->RootComponent()->Location(), info.POV), FGREEN_CHARTREUSE, std::to_string(current_actor->ComparisonIndex()));
			}
		}
		//---------------------------------------------------------------------------------Aimbot
		Aimbot(local_pawn);

		//---------------------------------------------------------------------------------Other Info
		ShowInfo(local_pawn);


		auto weapon = local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp();
		Global::Canvas->RefreshAndSleep(16);
	}
}