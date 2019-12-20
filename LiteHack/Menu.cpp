#include "Commons.h"

bool showMenu = false;
void DrawMenu()
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

void ChangeClickable()
{
	showMenu = !showMenu;
	if (showMenu)
	{
		SetWindowLongPtr(Global::Canvas->hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT);
		SetActiveWindow(Global::Canvas->hwnd);
	}
	else
	{
		SetWindowLongPtr(Global::Canvas->hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT);
	}
}

void DebugInfo()
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
}