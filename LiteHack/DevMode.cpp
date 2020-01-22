
#include "Commons.h";

void DevMode(ESPInfo& info, AActor^ current_actor)
{
	if (Global::MainForm->btnDeveloperMode->Checked)
	{
		std::string text = std::to_string(current_actor->ComparisonIndex());
		Global::Draw->Text(Global::Draw->WorldToScreen(current_actor->RootComponent()->Location(), info.Local.POV), FGREEN_CHARTREUSE, text);
	}
	return;
	char strs[2500];
	sprintf_s(strs,
		"UWorld: %p\nULevel: %p\nActors: %p\nActors Count: %d\nGameInstance: %p\nLocalPlayer: %p\nPlayerController: %p\nLocalPawn: %p\n",
		Global::GWorld->GetAddress(),
		Global::GWorld->CurrentLevel()->GetAddress(),
		Global::GWorld->CurrentLevel()->Actors().GetAddress(),
		Global::GWorld->CurrentLevel()->Actors().Length(),
		Global::GWorld->OwningGameInstance()->GetAddress(),
		Global::GWorld->OwningGameInstance()->LocalPlayer()->GetAddress(),
		Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->GetAddress(),
		Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn()->GetAddress()
	);
	std::cout << strs << std::endl;
}