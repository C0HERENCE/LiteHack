#include "Commons.h"

#define TextWidth 150
#define TextHeight 18.5
#define TextAboveHead 50
#define HealthHeight 10
#define BGColor FGRAY_DARKGRAY
#define TextColor FYELLOW_LIGHTGOLDENRODYELLOW

void DrawEnemy(ESPInfo& info, ASTExtraPlayerCharacter^ enemy)
{
	info.Enemy.TeamID = enemy->TeamID();
	if (info.Enemy.TeamID != info.Local.TeamID && (enemy->HealthStatus() == 0 || enemy->HealthStatus() == 1))
	{
		UpdateEnemyInfo(info, enemy);
		ESPText(info);
		ESPLine(info);
		ESPBone(info);
		Radar(info);
	}
}

void Radar(ESPInfo& info)
{
	FVector Pos = info.Enemy.Pos;
	FVector myPos = info.Local.Pos;
	if (abs(Pos.X - myPos.X) < 15001 && abs(Pos.Y - myPos.Y) < 150001)
	{
		FVector mapPos;
		mapPos.X = (Pos.X - myPos.X) / 157.f + (Global::Canvas->Width * (float)0.9166) - 3;
		mapPos.Y = (Pos.Y - myPos.Y) / 157.f + (Global::Canvas->Height * (float)0.8563) - 3;
		Global::Draw->RectangleFilled(mapPos, 6, 6, FRED_RED);
	}
}

void ESPText(ESPInfo& info)
{
	if (!info.Enemy.InScreen) return;
	if (true)
	{
		Global::Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), TextHeight, TextWidth - TextHeight, info.Enemy.ESPColor);
		Global::Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), TextHeight, TextHeight, BGColor);
		if (!info.Enemy.IsAI)
			Global::Draw->Text(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), FGRAY_BLACK, std::to_string(info.Enemy.TeamID));
		Global::Draw->Text(info.Enemy.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), FYELLOW_LIGHTGOLDENRODYELLOW, info.Enemy.PlayerName + "\t[" + std::to_string((int)info.Enemy.Distance) + "m]");
	}

	Global::Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, TextWidth, FWHITE_ALICEBLUE);
	Global::Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, info.Enemy.Health * 0.01f * TextWidth, FGREEN_LAWNGREEN);
	if (info.Enemy.Distance < Global::Option->maxBoneDis || info.Local.isGunADS)
	{
		float boxHeight = info.Enemy.RootScreenPos.Y - info.Enemy.HeadScreenPos.Y;
		float boxWidth = boxHeight / 1.7f;
		Global::Draw->Rectangle(info.Enemy.HeadScreenPos - FVector(boxWidth / 2, 0, 0), boxHeight, boxWidth, info.Enemy.ESPColor);
	}
}

void ESPLine(ESPInfo& info)
{
	if (info.Enemy.InScreen)return;
	Global::Draw->Line(FVector(Global::Canvas->Width / 2.0f, 0, 0), info.Enemy.RootScreenPos, info.Enemy.ESPColor, 1.2f);
}

void ESPBone(ESPInfo& info)
{
	if (!Global::Option->bone) return;
	if (info.Enemy.Distance > Global::Option->maxBoneDis && !info.Local.isGunADS) return;
	FVector previous(0, 0, 0);
	FVector current, p1, c1;
	ASTExtraPlayerCharacter^ enemy = gcnew ASTExtraPlayerCharacter(info.Enemy.Address);
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
			p1 = Global::Draw->WorldToScreen(previous, info.Local.POV);
			c1 = Global::Draw->WorldToScreen(current, info.Local.POV);
			Global::Draw->Line(p1, c1, info.Enemy.ESPColor, 1.2f);
			previous = current;
		}
	}
}

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter^ enemy)
{
	// enemy
	info.Enemy.Health = enemy->Health();
	info.Enemy.Address = enemy->GetAddress();
	if (enemy->VehicleSeatIdx() == -1)
		info.Enemy.Pos = enemy->RootComponent()->Location();
	else
		info.Enemy.Pos = enemy->CurrentVehicle()->RootComponent()->Location();
	info.Enemy.IsAI = enemy->IsAI();
	info.Enemy.PlayerName = enemy->PlayerName().ToString();
	info.Enemy.Distance = info.Enemy.Pos.Distance(info.Local.Pos) / 100.f;
	
	// visible & color
	info.Enemy.HeadScreenPos = Global::Draw->WorldToScreen(GetBoneWithRotation(enemy, 6), info.Local.POV);
	info.Enemy.RootScreenPos = Global::Draw->WorldToScreen(GetBoneWithRotation(enemy, 0), info.Local.POV);
	info.Enemy.InScreen = !(info.Enemy.HeadScreenPos.X<0 || info.Enemy.HeadScreenPos.X>Global::Canvas->Width || info.Enemy.HeadScreenPos.Y<0 || info.Enemy.HeadScreenPos.Y>Global::Canvas->Height);
	float lastRenderedTime = enemy->Mesh()->LastRenderedTime();
	info.Enemy.IsVisible = lastRenderedTime > player_keys[enemy->PlayerKey()];
	player_keys[enemy->PlayerKey()] = lastRenderedTime;
	if (info.Enemy.IsVisible)
	{
		info.Enemy.ESPColor = *(Global::Option->VisColor);
		if (Global::Option->aimbot)
		{
			auto aimpos = GetBoneWithRotation(enemy, Global::Option->aimbot_part);
			auto aimScreenPos = Global::Draw->WorldToScreen(aimpos, info.Local.POV);
			if (aimScreenPos.Distance(FVector(Global::Canvas->Width / 2.f, Global::Canvas->Height / 2.f, 0)) <= Global::Option->aimbot_radius)
			{
				distances[info.Enemy.Distance] = info.Enemy.Address;
			}
		}
	}
	else
		info.Enemy.ESPColor = info.Enemy.IsAI ? *(Global::Option->BotColor) : *(Global::Option->HumColor);
	if (info.Enemy.Distance < 50)
	{
		warning_count++;
	}
}

void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn)
{
	info.Local.POV = local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo();
	info.Local.TeamID = local_pawn->TeamID();
	uint64_t state = local_pawn->LocalSimulateStates();
	info.Local.isGunADS = (state >> 9) & 1;
	info.Local.isGunFire = (state >> 7) & 1;
	info.Local.isInParachute = (state >> 23) & 1;
	info.Local.isInVehicle = ((state >> 19) & 1) || ((state >> 20) & 1);
	info.Local.isSprint = (state >> 1) & 1;
	info.Local.isShoulderFiring = (state >> 29) & 1;
	info.Local.isMove = (state >> 0) & 1;
	if (info.Local.isInVehicle)
		info.Local.Pos = local_pawn->CurrentVehicle()->RootComponent()->Location();
	else
		info.Local.Pos = local_pawn->RootComponent()->Location();
	Global::Draw->Alpha = info.Local.isGunADS || info.Local.isShoulderFiring;
}

void SpectorWarning(ASTExtraPlayerCharacter^ local_pawn)
{
	std::string text;
	text = "Spectated Count:" + std::to_string(local_pawn->SpectatedCount());
	Global::Draw->Text(FVector(100, 200, 0), FYELLOW_DARKKHAKI, text);
}

void NearbyEnemyWarning(ASTExtraPlayerCharacter^ local_pawn)
{
	std::string text;
	if (warning_count > 0)
	{
		text = "Warning: " + std::to_string(warning_count) + " Enemies Nearby!";
		Global::Draw->Text(FVector(600, 200, 0), FYELLOW_DARKKHAKI, text);
	}
}