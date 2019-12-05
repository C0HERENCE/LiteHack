#include "EnemyESP.h"
void Radar(ESPInfo& info)
{
	FVector Pos = info.EnemyPos;
	FVector myPos = info.LocalPos;
	if (abs(Pos.X - myPos.X) < 15001 && abs(Pos.Y - myPos.Y) < 150001)
	{
		FVector mapPos;
		mapPos.X = (Pos.X - myPos.X) / 157.f + (Global::Canvas->Width * 0.9166) - 3;
		mapPos.Y = (Pos.Y - myPos.Y) / 157.f + (Global::Canvas->Height * 0.8563) - 3;
		Global::Draw->RectangleFilled(mapPos, 6, 6, FRED_RED);
	}
}

void ESPText(ESPInfo& info)
{
	if (!info.InScreen) return;
	Global::Draw->RectangleFilled(info.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), TextHeight, TextWidth - TextHeight, info.ESPColor);
	Global::Draw->RectangleFilled(info.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), TextHeight, TextHeight, BGColor);
	Global::Draw->RectangleFilled(info.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, TextWidth, FWHITE_ALICEBLUE);
	Global::Draw->RectangleFilled(info.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, info.Health * 0.01f * TextWidth, FGREEN_LAWNGREEN);
	if (info.Distance < Global::Option->maxBoneDis)
	{
		float boxHeight = info.RootScreenPos.Y - info.HeadScreenPos.Y;
		float boxWidth = boxHeight / 1.7f;
		Global::Draw->Rectangle(info.HeadScreenPos - FVector(boxWidth / 2, 0, 0), boxHeight, boxWidth, info.ESPColor);
	}
	if (!info.IsAI)
		Global::Draw->Text(info.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), FGRAY_BLACK, std::to_string(info.TeamID));
	Global::Draw->Text(info.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), FYELLOW_LIGHTGOLDENRODYELLOW, info.PlayerName + "\t[" + std::to_string((int)info.Distance) + "m]");
}

void ESPLine(ESPInfo& info)
{
	if (info.InScreen)return;
	Global::Draw->Line(FVector(Global::Canvas->Width / 2.0f, 0, 0), info.RootScreenPos, info.ESPColor, 1.2f);
}

void ESPBone(ESPInfo& info)
{
	if (!Global::Option->bone) return;
	if (info.Distance > Global::Option->maxBoneDis) return;
	FVector previous(0, 0, 0);
	FVector current, p1, c1;
	ASTExtraPlayerCharacter^ enemy = gcnew ASTExtraPlayerCharacter(info.pEnemy);
	auto neckpos = GetBoneWithRotation(enemy, 5);
	auto pelvispos = GetBoneWithRotation(enemy, 1);
	for (auto a : part)
	{
		previous = FVector(0, 0, 0);
		for (int bone : a)
		{
			current = bone == 5 ? neckpos : (bone == 1 ? pelvispos : GetBoneWithRotation(enemy, bone));
			if (previous.X == 0.f)
			{
				previous = current;
				continue;
			}
			p1 = Global::Draw->WorldToScreen(previous, info.POV);
			c1 = Global::Draw->WorldToScreen(current, info.POV);
			Global::Draw->Line(p1, c1, info.ESPColor, 1.2f);
			previous = current;
		}
	}
}

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter^ enemy)
{
	// enemy
	info.Health = enemy->Health();
	info.pEnemy = enemy->GetAddress();
	if (enemy->VehicleSeatIdx() == -1)
		info.EnemyPos = enemy->RootComponent()->Location();
	else
		info.EnemyPos = enemy->CurrentVehicle()->RootComponent()->Location();
	info.IsAI = enemy->IsAI();
	info.PlayerName = enemy->PlayerName().ToString();
	info.Distance = info.EnemyPos.Distance(info.LocalPos) / 100.f;

	// visible & color
	info.HeadScreenPos = Global::Draw->WorldToScreen(GetBoneWithRotation(enemy, 6), info.POV);
	info.RootScreenPos = Global::Draw->WorldToScreen(GetBoneWithRotation(enemy, 0), info.POV);
	info.InScreen = !(info.HeadScreenPos.X<0 || info.HeadScreenPos.X>Global::Canvas->Width || info.HeadScreenPos.Y<0 || info.HeadScreenPos.Y>Global::Canvas->Height);
	float lastRenderedTime = enemy->Mesh()->LastRenderedTime();
	info.IsVisible = lastRenderedTime > player_keys[enemy->PlayerKey()];
	player_keys[enemy->PlayerKey()] = lastRenderedTime;
	if (info.IsVisible)
	{
		info.ESPColor = *(Global::Option->VisColor);
		if (Global::Option->aimbot)
		{
			auto aimpos = GetBoneWithRotation(enemy, Global::Option->aimbot_part);
			auto aimScreenPos = Global::Draw->WorldToScreen(aimpos, info.POV);
			if (aimScreenPos.Distance(FVector(Global::Canvas->Width / 2.f, Global::Canvas->Height / 2.f, 0)) <= Global::Option->aimbot_radius)
			{
				distances[info.Distance] = info.pEnemy;
			}
		}
	}
	else
		info.ESPColor = info.IsAI ? *(Global::Option->BotColor) : *(Global::Option->HumColor);
	if (info.Distance < 50)
	{
		warning_count++;
	}
}

void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn)
{
	if (local_pawn->VehicleSeatIdx() == -1)
		info.LocalPos = local_pawn->RootComponent()->Location();
	else
		info.LocalPos = local_pawn->CurrentVehicle()->RootComponent()->Location();
	info.POV = local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo();
	info.LocalTeamID = local_pawn->TeamID();
}

void ShowInfo(ASTExtraPlayerCharacter^ local_pawn)
{
	std::string text;
	text = "Spectated Count:" + std::to_string(local_pawn->SpectatedCount());
	Global::Draw->Text(FVector(100, 200, 0), FYELLOW_DARKKHAKI, text);
	if (warning_count > 0)
	{
		text = "Warning: " + std::to_string(warning_count) + " Enemies Nearby!";
		Global::Draw->Text(FVector(600, 200, 0), FYELLOW_DARKKHAKI, text);
	}
}