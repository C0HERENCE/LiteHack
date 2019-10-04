#pragma once
#include "..//GObjects/GenericTypes.h"
#include "Core/DummyTypes.h"
#include "Core/EngineTypes.h"

#define off_PlayerName 0x1
class ASTExtraWeapon
{
	class UWeaponEntity* WeaponEntityComp;// 0x0438 sizeof (0x0008)
};

struct FAnimStatusKeyList
{
	unsigned char UnknownData00[0x10];// 0x0000 sizeof (0x0010) MISSED OFFSET
	class ASTExtraWeapon* EquipWeapon;// 0x0010 sizeof (0x0008)
	unsigned char UnknownData01[0x8];// 0x0018 sizeof (0x0008) MISSED OFFSET
};

class AActor : public UEObject
{
public:

private:
};

class APawn : public AActor
{
public:
	class AController* LastHitBy;// 0x03E8 sizeof (0x0008)
	class AController* Controller;// 0x03F0 sizeof (0x0008)
	class APlayerState* PlayerState;// 0x03F8 sizeof (0x0008)
};

class ACharacter : public APawn
{
public:
	class USkeletalMeshComponent* Mesh;// 0x04D8 sizeof (0x0008)
};

class AUAECharacter : public ACharacter
{
public:
	bool bIsAI;// 0x07E0 sizeof (0x0001)
	int TeamID;// 0x0804 sizeof (0x0004)
	struct FString PlayerName;// 0x0818 sizeof (0x0010)
};



class ASTExtraBaseCharacter : public AUAECharacter
{
public:
	class ASTExtraPlayerState* STExtraPlayerState;// 0x08F0 sizeof (0x0008)
	TArray<class AActor*> InventoryData;// 0x09E8 sizeof (0x0010)
	class ASTExtraVehicleBase* LatestVehicle;// 0x0DE0 sizeof (0x0008)
	bool bWasOnVehicle;// 0x0E08 sizeof (0x0001)
	unsigned char bDead : 1;// 0x1238 sizeof (0x0001)
	bool bIsWeaponFiring;// 0x1550 sizeof (0x0001)
	struct FAnimStatusKeyList LastUpdateStatusKeyList;// 0x1660 sizeof (0x0020)
	float Health;// 0x1700 sizeof (0x0004)
	unsigned char bDying : 1;// 0x17C0 sizeof (0x0001)
};