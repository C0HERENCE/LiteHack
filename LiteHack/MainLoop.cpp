#include "Global.h"
#include <map>
#include <list>
std::list<int> rightarm = { 5,15,16,17,18 };
std::list<int> leftarm = { 5,35,36,37,38 };
std::list<int> upper = { 5,4,3,2,1 };
std::list<int> rightleg = { 1,56,57,58 };
std::list<int> leftleg = { 1,60,61,62 };
std::list<std::list<int>> part = { rightarm,leftarm,upper,rightleg,leftleg };

std::map<uint32_t, float> player_keys;
std::map<float, uint64_t> distances;
int warning_count;
#include <iostream>
void NoRecoil(AActor^ local_pawn)
{
	auto currentWeapon = local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp();
	std::cout << std::hex << currentWeapon->ReadOffset<uint64_t>(Off::ArrTslWeaponAttachmentData) << std::endl;
	//if (currentWeapon->BulletFireSpeed() > 1000.f)
	{
		auto WeaponData = currentWeapon->ArrTslWeaponAttachmentData();
		std::cout << std::hex<< WeaponData.GetAddress() << std::endl;
		if (WeaponData.Length() > 0 && WeaponData.Length() < 10)
		{
			auto data = gcnew FWeaponAttachmentData(Global::GMemory->Read64(WeaponData.GetAddress()));
			std::cout << data->ReadOffset<float>(Off::RecoilMultiplierVertical) << std::endl;
			data->SetZero();
		}
	}
}

void AimAtPos(float x, float y)
{
	float ScreenCenterX = ((Global::Canvas->Width - 1) / 2);
	float ScreenCenterY = ((Global::Canvas->Height - 1) / 2);
	Global::Draw->Line(FVector(x, y, 0) - FVector(10, 0, 0), FVector(x, y, 0) + FVector(10, 0, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(x, y, 0) - FVector(0, 10, 0), FVector(x, y, 0) + FVector(0, 10, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, -10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, 10, 0), FColor(255, 0, 0), 1.2f);
	Global::Draw->Line(FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(10, 10, 0), FVector(ScreenCenterX, ScreenCenterY, 0) + FVector(-10, -10, 0), FColor(255, 0, 0), 1.2f);
	float TargetX = 0;
	float TargetY = 0;
	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= Global::Option->aimbot_speed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= Global::Option->aimbot_speed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}
	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= Global::Option->aimbot_speed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= Global::Option->aimbot_speed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}
	mouse_event(0x0001, (uint32_t)(TargetX), (uint32_t)(TargetY), NULL, NULL);
}

struct ESPInfo
{
	uint64_t pEnemy;
	FVector EnemyPos;

	std::string PlayerName;
	float Health;
	float Distance;
	int TeamID;
	FVector RootScreenPos;
	FVector HeadScreenPos;
	bool IsAI;
	bool IsVisible;
	bool InScreen;
	FColor ESPColor;
	Off::FMinimalViewInfo POV;

	FVector LocalPos;
	int LocalTeamID;
};

FVector GetBoneWithRotation(AActor^ actor, int id)
{
	auto mesh = actor->Mesh();
	auto arrybone = mesh->BoneArray();
	FTransform bone = Global::GMemory->Read<FTransform>(arrybone + (id * 0x30));
	FTransform ComponentToWorld = mesh->ComponentToWorld();
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}

#define TextWidth 150
#define TextHeight 18.5
#define TextAboveHead 20
#define HealthHeight 10
#define BGColor FGRAY_DARKGRAY
#define TextColor FYELLOW_LIGHTGOLDENRODYELLOW

void Radar(ESPInfo& info)
{
	FVector Pos = info.EnemyPos;
	FVector myPos = info.LocalPos;
	if (abs(Pos.X - myPos.X) < 15001 && abs(Pos.Y - myPos.Y) < 150001)
	{
		FVector mapPos;
		mapPos.X = (Pos.X - myPos.X) / 157.f + (Global::Canvas->Width * 0.9166)-3;
		mapPos.Y = (Pos.Y - myPos.Y) / 157.f + (Global::Canvas->Height * 0.8563)-3;
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
	if (info.Distance<Global::Option->maxBoneDis)
	{
		float boxHeight = info.RootScreenPos.Y - info.HeadScreenPos.Y;
		float boxWidth = boxHeight / 1.7f;
		Global::Draw->Rectangle(info.HeadScreenPos - FVector(boxWidth / 2, TextAboveHead - TextHeight - HealthHeight, 0), boxHeight, boxWidth, info.ESPColor);
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
	if (info.Distance > Global::Option->maxBoneDis) return;
	FVector previous(0, 0, 0);
	FVector current, p1, c1;
	AActor^ enemy = gcnew AActor(info.pEnemy);
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
			Global::Draw->Line(p1, c1, info.ESPColor, 2.0f);
			previous = current;
		}
	}
}

void UpdateInfo(ESPInfo& info, AActor^ enemy)
{
	// enemy
	info.pEnemy = enemy->GetAddress();
	if (enemy->VehicleSeatIdx() == -1)
		info.EnemyPos = enemy->RootComponent()->Location();
	else
		info.EnemyPos = enemy->CurrentVehicle()->RootComponent()->Location();
	info.IsAI = enemy->IsAI();
	info.PlayerName = enemy->PlayerName().ToString();
	info.Distance = info.EnemyPos.Distance(info.LocalPos)/100.f;
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
			if (aimScreenPos.Distance(FVector(Global::Canvas->Width / 2, Global::Canvas->Height / 2, 0)) <= Global::Option->aimbot_radius)
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

void ESPEnemy(ESPInfo& info, AActor^ enemy)
{
	info.TeamID = enemy->TeamID();
	info.Health = enemy->Health();
	//HealthyAlive = 0,
	//HasLastBreath = 1,
	//FinishedLastBreath = 2,
	if (enemy->HealthStatus() == 0 || enemy->HealthStatus() == 1)
	{
		if (info.TeamID != info.LocalTeamID)
		{
			UpdateInfo(info, enemy);
			ESPText(info);
			ESPLine(info);
			ESPBone(info);
			Radar(info);
		}
	}
}
void Aimbot(AActor^ local_pawn)
{
	if (Global::Option->aimbot)
	{
		if (distances.size() > 0)
		{
			Global::Draw->Circle(FVector(Global::Canvas->Width / 2, Global::Canvas->Height / 2, 0), Global::Option->aimbot_radius, FGRAY_BLACK);
			auto weaponcomp = local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp();
			float myBulletSpeed = weaponcomp->BulletFireSpeed();
			if (myBulletSpeed > 100)
			{
				AActor^ nearest_enemy = gcnew AActor(distances.begin().operator*().second);
				if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000 || GetAsyncKeyState(VK_LBUTTON) & 0x8000))
				{
					FVector aimpos;
					if (weaponcomp->bHasAutoFireMode())
					{
						aimpos = GetBoneWithRotation(nearest_enemy, Global::Option->aimbot_part);
					}
					else
					{
						aimpos = GetBoneWithRotation(nearest_enemy, 6);
					}
					FVector velocity = nearest_enemy->RootComponent()->ComponentVelocity();
					float FlyTime = distances.begin().operator*().first / (myBulletSpeed/100.f);
					float Fall = 0.98 * FlyTime * FlyTime * distances.begin().operator*().first;
					aimpos = aimpos + velocity * FlyTime;
					auto aimScreenPos = Global::Draw->WorldToScreen(aimpos, local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo());
					AimAtPos(aimScreenPos.X, aimScreenPos.Y);
					if (GetAsyncKeyState(VK_CAPITAL) & 0x0001)
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					}
				}
			}
		}
	}
}

void ShowInfo(AActor^ local_pawn)
{
	std::string text;
	text = "Spectated Count:" + std::to_string(local_pawn->SpectatedCount());
	Global::Draw->Text(FVector(100,200,0),FYELLOW_DARKKHAKI, text);
	if (warning_count > 0)
	{
		text = "Warning: " + std::to_string(warning_count) + " Enemies Nearby!";
		Global::Draw->Text(FVector(600, 200, 0), FYELLOW_DARKKHAKI, text);
	}
}

void MainLoop()
{
	Global::GWorld = gcnew UWorld();
	Global::GNames = gcnew Names();
	Global::GWorld->Init(Global::GMemory->GetBase() + Off::UWorld);
	Global::GNames->Init(Global::GMemory->GetBase() + Off::GNames);
	std::cout << std::hex << Global::GWorld->GetAddress() << std::endl;
	player_keys.clear();
	while (1)
	{
		Global::Canvas->NewFrame();
		AActor^ local_pawn = Global::GWorld->OwningGameInstance()->LocalPlayer()->PlayerController()->LocalPawn();
		ESPInfo info;
		if (local_pawn->VehicleSeatIdx() == -1)
			info.LocalPos = local_pawn->RootComponent()->Location();
		else
			info.LocalPos = local_pawn->CurrentVehicle()->RootComponent()->Location();
		info.POV = local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo();
		info.LocalTeamID = local_pawn->TeamID();

		auto Actors = Global::GWorld->CurrentLevel()->Actors();
		distances.clear();
		warning_count = 0;
		for (size_t i = 0; i < Actors.Length(); i++)
		{
			AActor^ current_actor = gcnew AActor(Actors.GetById(i));
			// BP_PlayerPawnPC_C
			if (current_actor->ComparisonIndex() == Global::GNames->CharacterId)
			{
				ESPEnemy(info, current_actor);
			}
			else if (current_actor->ComparisonIndex() == Global::GNames->AirdropId)
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "AirDrop [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}
			else if (current_actor->ComparisonIndex() == Global::GNames->TombBox)
			{
				auto location = current_actor->RootComponent()->Location();
				Global::Draw->Text(Global::Draw->WorldToScreen(location, info.POV), FGREEN_CHARTREUSE, "TombBox [" + std::to_string((int)(location.Distance(info.LocalPos) / 100.f)) + "m]");
			}
			if (Global::MainForm->btnDeveloperMode->Checked)
			{
				Global::Draw->Text(Global::Draw->WorldToScreen(current_actor->RootComponent()->Location(), info.POV), FGREEN_CHARTREUSE, std::to_string(current_actor->ComparisonIndex()));
				//System::Console::WriteLine(current_actor->ComparisonIndex());
				//System::Console::WriteLine(Global::GNames->GetById(current_actor->ComparisonIndex()));
			}
		}
		auto weapon = local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp();
		//System::Console::WriteLine(weapon->ReadOffset<int>(0x374));
		//Global::Draw->Text(Global::Draw->WorldToScreen(local_pawn->RootComponent()->Location(), local_pawn->STPlayerController()->CameraCache()->MinimalViewInfo()), FRED_RED, std::to_string(local_pawn->WeaponManagerComponent()->CurrentWeapon()->WeaponEntityComp()->GetAddress));
		
		Aimbot(local_pawn);
		ShowInfo(local_pawn);
		Global::Canvas->RefreshAndSleep(16);
	}
}

