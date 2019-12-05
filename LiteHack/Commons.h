#pragma once
#include "Global.h"
#include <map>
#include <list>
#include <d3d11.h>
#include <string>

extern ID3D11ShaderResourceView* my_texture;

extern std::map<float, uint64_t> distances;
extern std::map<uint32_t, float> player_keys;
extern int warning_count;
extern std::list<int> rightarm;
extern std::list<int> leftarm;
extern std::list<int> upper;
extern std::list<int> rightleg;
extern std::list<int> leftleg;
extern std::list<std::list<int>> part;

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

FVector GetBoneWithRotation(ASTExtraPlayerCharacter^ actor, int id);
