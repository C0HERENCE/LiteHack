#pragma once
#include <list>
#include "../SDK/GWorld.h"
#include <map>

extern std::list<int> rightarm;
extern std::list<int> leftarm;
extern std::list<int> upper;
extern std::list<int> rightleg;
extern std::list<int> leftleg;
extern std::list<std::list<int>> part;


extern std::map<float, uint64_t> distances;
extern std::map<uint32_t, float> player_keys;
extern int warning_count;


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

void UpdateEnemyInfo(ESPInfo& info, ASTExtraPlayerCharacter enemy);

void UpdateLocalInfo(ESPInfo& info, ASTExtraPlayerCharacter local_pawn);

FVector GetBoneWithRotation(ASTExtraPlayerCharacter actor, int id);

// Warning Info
void SpectorWarning(ASTExtraPlayerCharacter local_pawn);
void NearbyEnemyWarning(ASTExtraPlayerCharacter local_pawn);

// Enemy ESP
void DrawEnemy(ESPInfo& info, ASTExtraPlayerCharacter enemy);
void ESPLine(ESPInfo& info);
void ESPBone(ESPInfo& info);
void ESPText(ESPInfo& info);
void Radar(ESPInfo& info);

// Aimbot
void AimAtPos(float x, float y);
void Aimbot(ESPInfo& info, ASTExtraPlayerCharacter local_pawn);