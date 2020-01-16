#pragma once
#include "Global.h"
#include <map>
#include <list>
#include <d3d11.h>
#include <string>
#include <iostream>


extern std::list<int> rightarm;
extern std::list<int> leftarm;
extern std::list<int> upper;
extern std::list<int> rightleg;
extern std::list<int> leftleg;
extern std::list<std::list<int>> part;
extern bool showMenu;

struct ESPInfo
{
	struct LocalInfo
	{
		FVector Pos;
		int TeamID;
		FMinimalViewInfo POV;

		bool isInVehicle;
		bool isGunFire;
		bool isGunADS;
		bool isInParachute;
		bool isSprint;
		bool isShoulderFiring;
		bool isMove;
	} Local;

	struct EnemyInfo
	{
		uint64_t Address;
		FVector Pos;
		float Health;
		float Distance;
		FVector RootScreenPos;
		FVector HeadScreenPos;
		bool IsAI;
		bool IsVisible;
		bool InScreen;
		FColor ESPColor;
		std::string PlayerName;
		int TeamID;
	} Enemy;
};

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter^ enemy);
void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn);

// Enemy ESP
void DrawEnemy(ESPInfo& info, ASTExtraPlayerCharacter^ enemy);
extern std::map<uint32_t, float> player_keys;
void ESPLine(ESPInfo& info);
void ESPBone(ESPInfo& info);
void ESPText(ESPInfo& info);
void Radar(ESPInfo& info);

// Warning Info
void SpectorWarning(ASTExtraPlayerCharacter^ local_pawn);
extern int warning_count;
void NearbyEnemyWarning(ASTExtraPlayerCharacter^ local_pawn);

// Aimbot
void NoRecoil(UShootWeaponEntity^ weaponcomp);
void AimAtPos(float x, float y);
extern std::map<float, uint64_t> distances;
void Aimbot(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn);

// Vehicle ESP
void DrawVehicle(ESPInfo& info, ASTExtraWheeledVehicle^ vehicle);

// Speed Hack
extern bool speedhack;
void SpeedHack(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn);
void SpringArm(ASTExtraPlayerCharacter^ local_pawn);
extern int superjump;
void SuperJump(ASTExtraPlayerCharacter^ local_pawn);
void FastSkyDive(ESPInfo& info, ASTExtraPlayerCharacter^ local_pawn);

// Item ESP
void DrawTombbox(ESPInfo& info, APlayerTombBox^ item);
void DrawAirdrop(ESPInfo& info, AAirDropBoxActor^ item);

//Menu
void DrawMenu();
void ChangeClickable();
void DebugInfo();
void DevMode(ESPInfo& info, AActor^ current_actor);

FVector GetBoneWithRotation(ASTExtraPlayerCharacter^ actor, int id);