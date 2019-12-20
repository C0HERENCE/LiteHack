
#include "Commons.h";

void DevMode(ESPInfo& info, AActor^ current_actor)
{
	if (Global::MainForm->btnDeveloperMode->Checked)
	{
		std::string text = std::to_string(current_actor->ComparisonIndex());
		Global::Draw->Text(Global::Draw->WorldToScreen(current_actor->RootComponent()->Location(), info.Local.POV), FGREEN_CHARTREUSE, text);
	}
}