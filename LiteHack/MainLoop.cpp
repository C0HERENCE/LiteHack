#include "EnemyESP.h"
#include "ItemsESP.h"
#include "VehiclesESP.h"
#include "Aimbot.h"
#include <iostream>

void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GNames = gcnew Names();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
	Global::GNames->Init(Global::GMemory->GetBase() + Off::GNames);
	player_keys.clear();

	if (true)
	{
		System::Console::WriteLine(System::String::Format("GWord: 0x{0:x}", Global::GWorld->GetAddress()));
		System::Console::WriteLine(System::String::Format("GNames: 0x{0:x}", Global::GNames->GetAddress()));
		System::Console::WriteLine(System::String::Format("CurrentLevel: 0x{0:x}", Global::GWorld->CurrentLevel()->GetAddress()));
		System::Console::WriteLine(System::String::Format("Actors: 0x{0:x}", Global::GWorld->CurrentLevel()->Actors().GetAddress()));
		System::Console::WriteLine(System::String::Format("Actors Length: {0}", Global::GWorld->CurrentLevel()->Actors().Length()));
		System::Console::WriteLine(System::String::Format("OwningGameInstance: 0x{0:x}", Global::GWorld->OwningGameInstance()->GetAddress()));
		System::Console::WriteLine(System::String::Format("LocalPlayer: 0x{0:x}", Global::GWorld->OwningGameInstance()->LocalPlayer()->GetAddress()));
		System::Console::WriteLine(System::String::Format("LocalPlayer Name: {0}", Global::GNames->GetStringById(AActor(Global::GWorld->OwningGameInstance()->LocalPlayer()->GetAddress()).ComparisonIndex())));

		System::Console::WriteLine(System::String::Format("PlayerController: 0x{0:x}", Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->GetAddress()));
		System::Console::WriteLine(System::String::Format("PlayerController Name: {0}", Global::GNames->GetStringById(AActor(Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->GetAddress()).ComparisonIndex())));


		System::Console::WriteLine(System::String::Format("CameraManager: 0x{0:x}", Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->CameraCache()->GetAddress()));
		System::Console::WriteLine(System::String::Format("LocalPawn: 0x{0:x}", Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn()->GetAddress()));
		std::cout << "Player Name: " << Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn()->PlayerName().ToString() << std::endl;
	}

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

			if ( Global::Option->enemyESP && current_actor->ComparisonIndex() == ComparisonIndexs[PlayerID])
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

			else if (current_actor->ComparisonIndex() == ComparisonIndexs[AirdropID])
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "AirDrop [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}


			//----------------------------------------------------------------------------Vehicles ESP

			else if (current_actor->ComparisonIndex() == ComparisonIndexs[TombBoxID])
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "TombBox [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}

			else if (VehiclesIndexs.count(current_actor->ComparisonIndex()) == 1)
			{
				DrawVehicle(info, current_actor->CastTo<ASTExtraWheeledVehicle>());
			}


			//----------------------------------------------------------------------------Dev Mode

			if (Global::MainForm->btnDeveloperMode->Checked)
			{
				Global::Draw->Text(Global::Draw->WorldToScreen(current_actor->RootComponent()->Location(), info.POV), FGREEN_CHARTREUSE, std::to_string(current_actor->ComparisonIndex()));
			}


			if (Global::MainForm->btnTestFunc->Checked)
			{
				auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
				auto pBreathe = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0F80));
				auto num1 = pBreathe->ReadOffset<float>(0x018c + 0x0);
				//auto num2 = pMovement->ReadOffset<float>(0x022C +0x0);

				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x998 + 0x0, 1400.f); // prone speed
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x9d8 + 0x0, 1500.f); // crouch speed
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa18 + 0x0, 1500.f); // groggy speed
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa20 + 0x0, 3720.f);// max acc
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa24 + 0x0, 3520.f);// min acc
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x0278 + 0x0, 1.f); // mass
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x01bc + 0x0, 886.f); // jump z
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x022C + 0x0, 1.0f); // aircontrol;

				//Global::GMemory->Write<float>(pSwim->GetAddress() + 0x180 + 0x0, 25.5f); //swim speed factor

				System::Console::WriteLine(System::String::Format("test num1: {0}", num1));
				//System::Console::WriteLine(System::String::Format("test num2: {0}", num2));
			}
		}
		//---------------------------------------------------------------------------------Aimbot
		Aimbot(local_pawn);

		Global::GMemory->Write<bool>(local_pawn->GetAddress() + 0xd0, false);

		//---------------------------------------------------------------------------------Other Info
		ShowInfo(local_pawn);

		Global::Canvas->RefreshAndSleep(16);
	}
}