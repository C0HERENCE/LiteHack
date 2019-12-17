#include "EnemyESP.h"
#include "ItemsESP.h"
#include "VehiclesESP.h"
#include "Aimbot.h"
#include <iostream>

void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
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
	bool showMenu = false;
	int superjump = 0;
	bool speedhack = false;
	while (1)
	{
		Global::Canvas->NewFrame();
		//--------------------------------------------------------------------------------Draw InGame Menu
		if (GetAsyncKeyState(VK_OEM_3) & 0x0001) // ` key
		{
			showMenu = !showMenu;
			if (showMenu)
			{
				SetWindowLongPtr(Global::Canvas->hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT /*| WS_EX_TOOLWINDOW*/);
				SetActiveWindow(Global::Canvas->hwnd);
			}
			else
			{
				SetWindowLongPtr(Global::Canvas->hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT /*| WS_EX_TOOLWINDOW*/);
			}
		}
		if (showMenu)
		{
			ImGui::Begin("Lite Hack");
			ImGui::Text("What if we have a excellent in-game menu?");
			if (ImGui::CollapsingHeader("About"))
			{
				ImGui::Text("ABOUT THIS HACK:");
				ImGui::BulletText("It's made by ccwisp.");
				ImGui::BulletText("Enjoy it!");
				ImGui::Separator();
				ImGui::Text("USER GUIDE:");
				ImGui::BulletText("Press \"`(~)\" key to toggle in-game menu.");
				ImGui::BulletText("Contact with me:");
				ImGui::BulletText("QQ: 749976734 (ccwisp)\nDiscord: COHERENCE #3272\nGithub: https://github.com/C0HERENCE");
				ImGui::Separator();
			}
			if (ImGui::CollapsingHeader("ESP Settings"))
			{
				pin_ptr<bool> ptr = &(Global::Option->enemyESP);
				pin_ptr<int> ptr1 = &(Global::Option->maxBoneDis);
				ImGui::Checkbox("Enemy ESP", ptr);
				ImGui::SliderInt("Max Show Bone Distance: ", ptr1, 10, 200);
				ImGui::ColorEdit3("Visible Color", (float*) & *(Global::Option->VisColor));
			}


		}
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

			}
		}
		//---------------------------------------------------------------------------------Aimbot
		Aimbot(local_pawn);

		//---------------------------------------------------------------------------------Other Info
		ShowInfo(local_pawn);

		//---------------------------------------------------------------------------------Fast Sky Dive
		if (GetAsyncKeyState(VK_F9) & 0x0001)
		{
			auto pSkyDive = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x20c8));
			if (pSkyDive->ReadOffset<float>(0xac8 + 0x0004) <= 10000.f)
			{
				Global::GMemory->Write<float>(pSkyDive->GetAddress() + 0xac8 + 0x0004, 100000.f);
			}
			else
			{
				Global::GMemory->Write<float>(pSkyDive->GetAddress() + 0xac8 + 0x0004, 6500.f);
			}
		}

		//---------------------------------------------------------------------------------Super Jump
		if (superjump > 0)
		{
			superjump++;
			Global::Draw->Text(FVector(Global::Canvas->Width / 2.f - 100.f, 500.f, 0.f), FRED_DARKSALMON, "Super Jump Openning!");
			auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
			Global::GMemory->Write<float>(pMovement->GetAddress() + 0x01bc, 860.F);
			//Global::GMemory->Write<float>(pMovement->GetAddress() + 0x022C + 0x0, 10.f);
		}
		if (superjump >= 20)
		{
			superjump = 0;
			auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
			Global::GMemory->Write<float>(pMovement->GetAddress() + 0x01bc, 443.f);
			//Global::GMemory->Write<float>(pMovement->GetAddress() + 0x022C + 0x0, 10.f);
		}
		else if (superjump == 0 && GetAsyncKeyState(70) & 0x0001) // 70 = F
		{
			superjump = 1;
		}

		//---------------------------------------------------------------------------------Spring Arm Length
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

		//---------------------------------------------------------------------------------Speed Hack
		if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
		{
			speedhack = !speedhack;
			auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
			float m2 = pMovement->ReadOffset<float>(0x82c + 0x0);
			if (m2 >= 1000.f)
			{
				/*Global::GMemory->Write<float>(pMovement->GetAddress() + 0x958, 480.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x998, 120.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x9d8, 344.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa18, 100.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x82c, 670.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa20, 700.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa24, 520.f);*/
			}
			else
			{
			/*	Global::GMemory->Write<float>(pMovement->GetAddress() + 0x958, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x998, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x9d8, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa18, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x82c, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa20, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0xa24, 1000.F);*/
			}
		}
		if (speedhack && local_pawn->VehicleSeatIdx() == -1)
		{
			auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
			int pose = local_pawn->ReadOffset<int>(0x1570);
			if (pose == 11 || pose == 19)
			{
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x82c, 1000.F);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x83c, 3.4f);
			}
			else
			{
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x82c, 670.f);
				Global::GMemory->Write<float>(pMovement->GetAddress() + 0x83c, 0.5f);
			}
		}
		else
		{
			auto pMovement = gcnew AActor(local_pawn->ReadOffset<uint64_t>(0x0938));
			Global::GMemory->Write<float>(pMovement->GetAddress() + 0x82c, 670.f);
			Global::GMemory->Write<float>(pMovement->GetAddress() + 0x83c, 0.5f);
		}

		//---------------------------------------------------------------------------------New Func
		if (local_pawn->Health()>0.f)
		{
			//Global::GMemory->Write<FVector>(local_pawn->Mesh()->GetAddress() + 0x220 + 0x0, FVector(0.001f, 0.001f, 0.001f));
			/*
			if (auto num2 = local_pawn->Mesh()->ReadOffset<FVector>(0x220).X == 1.f)
			{
				Global::GMemory->Write<FVector>(local_pawn->Mesh()->GetAddress() + 0x220 + 0x0, FVector(0.001f, 0.001f, 0.001f)); // Mesh Scale;
			}
			else
			{
				Global::GMemory->Write<FVector>(local_pawn->Mesh()->GetAddress() + 0x220 + 0x0, FVector(1.f, 1.f, 1.f)); // Mesh Scale;
			}*/
			//Global::GMemory->Write<float>(local_pawn->GetAddress() + 0x0F18, 88.f);
			//Global::GMemory->Write<FVector>(local_pawn->GetAddress() + 0x1e00, local_pawn->RootComponent()->Location() + FVector(0.f, 0.f, 1000.f));
			
		}

		//---------------------------------------------------------------------------------Car Hack
		/*
		struct FVehicleEngineData
		{
			unsigned char                                      UnknownData01[0x078];                                              // 0x0000(0x0078) (Edit)
			float                                              MaxRPM;                                                   // 0x0078(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
			float                                              MOI;                                                      // 0x007C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
			float                                              DampingRateFullThrottle;                                  // 0x0080(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
			float                                              DampingRateZeroThrottleClutchEngaged;                     // 0x0084(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
			float                                              DampingRateZeroThrottleClutchDisengaged;                  // 0x0088(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
			unsigned char                                      UnknownData00[0x4];                                       // 0x008C(0x0004) MISSED OFFSET
		};
		if (local_pawn->VehicleSeatIdx() == 0)
		{
			auto pCar = local_pawn->CurrentVehicle();
			auto kph = pCar->ReadOffset<UINT64>(0x0878);
			AActor^ mov = gcnew AActor(kph);

			auto v = mov->ReadOffset<FVehicleEngineData>(0x308);
			std::cout << v.MaxRPM << "," << v.MOI << "," << v.DampingRateFullThrottle << std::endl;
			Global::GMemory->Write<float>(mov->GetAddress() + 0x308 + 0x0078, 1000.f);
			Global::GMemory->Write<float>(mov->GetAddress() + 0x01D4, 1000.f);
			Global::GMemory->Write<float>(mov->GetAddress() + 0x01b8, 1.f);
			Global::GMemory->Write<float>(mov->GetAddress() + 0x01bc, 0.001f);
			Global::GMemory->Write<float>(mov->GetAddress() + 0x01d0, 1.f); 
			Global::GMemory->Write<float>(mov->GetAddress() + 0x308 + 0x007C, 5.0f); 
			Global::GMemory->Write<float>(mov->GetAddress() + 0x308 + 0x0080, 0.01f);
			Global::GMemory->Write<FVector>(mov->GetAddress() + 0x025C, FVector(300.f, 300.f, 300.f));
			
			//std::cout << std::hex << kph << std::endl;
		}
		*/
		Global::Canvas->RefreshAndSleep(16);
	}
}