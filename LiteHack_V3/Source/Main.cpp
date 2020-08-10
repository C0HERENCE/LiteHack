#include "Global.h"
#include "Hack/Common.h"

Global LiteHack;

int main()
{
	std::cout << Dec::ObjID(773927790) << std::endl;
	VMProtectBegin("Begin");
	if (!LiteHack.GMemory->Init())
	{
		MessageBox(NULL, VmpStr("Can't Access Memry"), "", 0);
		return 0;
	}
	if (!LiteHack.Canvas->Init())
	{
		MessageBox(NULL, VmpStr("Can't Create Overlay"), "", 0);
		return 0;
	}
	if (!LiteHack.GNames->Init(LiteHack.GMemory->GetBase() + Off::GNames))
	{
		MessageBox(NULL, VmpStr("Can't Read GNames"), "", 0);
		return 0;
	}
	LiteHack.GNames->CacheNames();
	printf("CacheNames Finished\n");
	LiteHack.GWorld->Init(LiteHack.GMemory->GetBase() + Off::UWorld);
	printf("GWorld Finished\n");
	LoadVehicleImages();
	LoadItemImages();
	printf("Load Item Images Finished\n");
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			continue;
		}

		if (LiteHack.Option->StartHack)
		{
			MainLoop();
		}
		else
		{
			LiteHack.Canvas->NewFrame();
			LiteHack.Draw->Text(FVector(10, 10, 0), FGREEN_GREEN, std::string("Lite Hack [Off]"));
			LiteHack.Canvas->RefreshAndSleep(16);
		}

		if (GetAsyncKeyState(VK_END) & 1)
		{
			MessageBox(NULL, VmpStr("See You Next Time"), "", 0);
			DestroyWindow(LiteHack.Canvas->MyWnd);
			break;
		}

		if (GetAsyncKeyState(VK_F10) & 1)
		{
			if (LiteHack.Option->StartHack)
			{
				LiteHack.Option->StartHack = false;
			}
			else
			{
				LiteHack.Option->StartHack = true;
				LiteHack.GWorld->Init(LiteHack.GMemory->GetBase() + Off::UWorld);
				speedhack = false;
			}
		}
	}
	LiteHack.Canvas->Cleanup();
	VMProtectEnd();
}

void MainLoop()
{
	LiteHack.Canvas->NewFrame();
	LiteHack.Draw->Text(FVector(10, 10, 0), FGREEN_GREEN, std::string("Lite Hack [On]"));

	auto Actors = LiteHack.GWorld->CurrentLevel().Actors();
	int actor_length = Actors.Length();
	if (actor_length > 25000) return;

	distances.clear(); 
	warning_count = 0;
	ASTExtraPlayerCharacter local_pawn = LiteHack.GWorld->OwningGameInstance().LocalPlayer().PlayerController().LocalPawn();
	ESPInfo info;
	UpdateLocalInfo(info, local_pawn);
	std::cout << local_pawn.PlayerName().ToString() << std::endl << actor_length << std::endl;
	for (int i = 0; i < Actors.Length(); i++)
	{
		AActor current_actor = ASTExtraPlayerCharacter(Actors.GetById(i));
		int id = current_actor.ComparisonIndex();
		std::cout << std::hex << current_actor.GetAddress() << std::dec << " -> id:" << id << " = " << LiteHack.GNames->GetById(id) << std::endl;
		if (LiteHack.GNames->IsEnemy(id)) DrawEnemy(info, current_actor.CastTo<ASTExtraPlayerCharacter>());
		else if (LiteHack.GNames->IsVehicle(id)) DrawVehicle(info, current_actor.CastTo<ASTExtraWheeledVehicle>());
		else if (LiteHack.GNames->IsAirdrop(id)) DrawAirdrop(info, current_actor.CastTo<AAirDropBoxActor>());
		else if (LiteHack.GNames->IsTombbox(id)) DrawTombbox(info, current_actor.CastTo<APlayerTombBox>());
	}
	SpectorWarning(local_pawn);
	NearbyEnemyWarning(local_pawn);
	if (true) Aimbot(info, local_pawn);
	if (false) SpeedHack(info, local_pawn);
	LiteHack.Canvas->RefreshAndSleep(16);
}
