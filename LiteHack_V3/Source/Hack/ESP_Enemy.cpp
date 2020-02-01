#include "Common.h"
#include "../Global.h"

std::list<int> rightarm = { 5,15,16,17,18 };
std::list<int> leftarm = { 5,35,36,37,38 };
std::list<int> upper = { 5,4,3,2,1 };
std::list<int> rightleg = { 1,56,57,58 };
std::list<int> leftleg = { 1,60,61,62 };
std::list<std::list<int>> part = { rightarm,leftarm,upper,rightleg,leftleg };

#define TextWidth 150
#define TextHeight 18.5
#define TextAboveHead 50
#define HealthHeight 10
#define BGColor FGRAY_DARKGRAY
#define TextColor FYELLOW_LIGHTGOLDENRODYELLOW

void SpectorWarning(ASTExtraPlayerCharacter local_pawn)
{
	std::string text;
	text = "Spectated Count:" + std::to_string(local_pawn.SpectatedCount());
	LiteHack.Draw->Text(FVector(100, 200, 0), FYELLOW_DARKKHAKI, text);
}

void NearbyEnemyWarning(ASTExtraPlayerCharacter local_pawn)
{
	std::string text;
	if (warning_count > 0)
	{
		text = "Warning: " + std::to_string(warning_count) + " Enemies Nearby!";
		LiteHack.Draw->Text(FVector(600, 200, 0), FYELLOW_DARKKHAKI, text);
	}
}

void DrawEnemy(ESPInfo& info, ASTExtraPlayerCharacter enemy)
{
	info.Enemy.TeamID = enemy.TeamID();
	if (info.Enemy.TeamID != info.Local.TeamID && (enemy.HealthStatus() == 0 || enemy.HealthStatus() == 1))
	{
		UpdateEnemyInfo(info, enemy);
		ESPText(info);
		ESPLine(info);
		ESPBone(info);
		Radar(info);
	}
}

void ESPText(ESPInfo& info)
{
	if (!info.Enemy.InScreen) return;
	if (true)
	{
		LiteHack.Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), TextHeight, TextWidth - TextHeight, info.Enemy.ESPColor);
		LiteHack.Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), TextHeight, TextHeight, BGColor);
		if (!info.Enemy.IsAI)
			LiteHack.Draw->Text(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead, 0), FGRAY_BLACK, std::to_string(info.Enemy.TeamID));
		LiteHack.Draw->Text(info.Enemy.HeadScreenPos - FVector(TextWidth / 2 - TextHeight, TextAboveHead, 0), FYELLOW_LIGHTGOLDENRODYELLOW, info.Enemy.PlayerName + "\t[" + std::to_string((int)info.Enemy.Distance) + "m]");
	}

	LiteHack.Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, TextWidth, FWHITE_ALICEBLUE);
	LiteHack.Draw->RectangleFilled(info.Enemy.HeadScreenPos - FVector(TextWidth / 2, TextAboveHead - TextHeight, 0), HealthHeight, info.Enemy.Health * 0.01f * TextWidth, FGREEN_LAWNGREEN);
	if (info.Enemy.Distance < LiteHack.Option->maxBoneDis || info.Local.isGunADS)
	{
		float boxHeight = info.Enemy.RootScreenPos.Y - info.Enemy.HeadScreenPos.Y;
		float boxWidth = boxHeight / 1.7f;
		LiteHack.Draw->Rectangle(info.Enemy.HeadScreenPos - FVector(boxWidth / 2, 0, 0), boxHeight, boxWidth, info.Enemy.ESPColor);
	}
}

void ESPLine(ESPInfo& info)
{
	if (info.Enemy.InScreen)return;
	LiteHack.Draw->Line(FVector(LiteHack.Canvas->Width / 2.0f, 0, 0), info.Enemy.RootScreenPos, info.Enemy.ESPColor);
}

void ESPBone(ESPInfo& info)
{
	if (!LiteHack.Option->bone) return;
	if (info.Enemy.Distance > LiteHack.Option->maxBoneDis && !info.Local.isGunADS) return;
	FVector previous(0, 0, 0);
	FVector current, p1, c1;
	ASTExtraPlayerCharacter enemy = ASTExtraPlayerCharacter(info.Enemy.Address);
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
			p1 = LiteHack.Draw->WorldToScreen(previous, info.Local.POV);
			c1 = LiteHack.Draw->WorldToScreen(current, info.Local.POV);
			LiteHack.Draw->Line(p1, c1, info.Enemy.ESPColor);
			previous = current;
		}
	}
}

void Radar(ESPInfo& info)
{
	FVector Pos = info.Enemy.Pos;
	FVector myPos = info.Local.Pos;
	if (abs(Pos.X - myPos.X) < 15001 && abs(Pos.Y - myPos.Y) < 150001)
	{
		FVector mapPos;
		mapPos.X = (Pos.X - myPos.X) / 157.f + (LiteHack.Canvas->Width * (float)0.9166) - 3;
		mapPos.Y = (Pos.Y - myPos.Y) / 157.f + (LiteHack.Canvas->Height * (float)0.8563) - 3;
		LiteHack.Draw->RectangleFilled(mapPos, 6, 6, FRED_RED);
	}
}
