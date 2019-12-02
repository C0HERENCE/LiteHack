#pragma once
#include "Updates.h"

ref class Base
{
public:
	Base()
	{
		base_address = 0x0;
	}
	Base(uint64_t address)
	{
		base_address = address;
	}
	~Base()
	{

	}

	uint64_t GetAddress()
	{
		return base_address;
	}

	template <typename T>
	T ReadOffset(uint64_t offset)
	{
		return Global::GMemory->Read<T>(base_address + offset);
	}

protected:
	uint64_t base_address;
};

ref class APlayerCameraManager : public Base
{
public:
	APlayerCameraManager(uint64_t address) : Base(address) {}

	Off::FMinimalViewInfo MinimalViewInfo();
private:

};

ref class AActor;
ref class APlayerController : public Base
{
public:
	APlayerController(uint64_t address) : Base(address) {}

	AActor^ LocalPawn();

	APlayerCameraManager^ CameraCache();
private:

};


ref class ULocalPlayer : public Base
{
public:
	ULocalPlayer() : Base() {}

	ULocalPlayer(uint64_t address) : Base(address) {}

	APlayerController^ PlayerController();
private:

};

ref class UGameInstance : public Base
{
public:
	UGameInstance(uint64_t address) : Base(address) {}

	ULocalPlayer^ LocalPlayer();
private:

};

ref class USkeletalMeshComponent : public Base
{
public:
	USkeletalMeshComponent(uint64_t address) : Base(address) {}
	
	uint64_t BoneArray();

	FTransform ComponentToWorld();

	float LastRenderedTime();
private:

};

ref class USceneComponent : public Base
{
public:
	USceneComponent(uint64_t address) : Base(address) {}

	FVector ComponentVelocity();

	FVector Location();
private:

};

ref class UShootWeaponEntity : public Base
{
public:
	UShootWeaponEntity(uint64_t address) : Base(address) { }

	TArray<uint64_t> ArrTslWeaponAttachmentData();

	float BulletFireSpeed();

	bool bHasAutoFireMode();
};

ref class ASTExtraWeapon : public Base
{
public:
	ASTExtraWeapon(uint64_t address) : Base(address) {}

	UShootWeaponEntity^ WeaponEntityComp();
};

ref class UWeaponManagerComponent : public Base
{
public:
	UWeaponManagerComponent(uint64_t address) : Base(address) {}

	ASTExtraWeapon^ CurrentWeapon();
private:

};

ref class FWeaponAttachmentData : public Base
{
public:
	FWeaponAttachmentData(uint64_t address) : Base(address) {}

	void SetZero();
};

ref class AActor : public Base
{
public:
	AActor() : Base() {}

	AActor(uint64_t address) : Base(address) {}
	
	int ComparisonIndex();

	UWeaponManagerComponent^ WeaponManagerComponent();

	USkeletalMeshComponent^ Mesh();

	USceneComponent^ RootComponent();

	APlayerController^ STPlayerController();

	FString PlayerName();

	float Health();

	bool IsWeaponFiring();

	bool IsAI();

	int TeamID();

	uint32_t PlayerKey();

	int SpectatedCount();

	AActor^ CurrentVehicle();

	int VehicleSeatIdx();

	uint8_t HealthStatus();
private:

};

ref class ULevel : public Base
{
public:
	ULevel(uint64_t address) : Base(address) {}

	TArray<uint64_t> Actors();
private:

};

ref class UWorld : public Base
{
public:
	UWorld() : Base() {}

	void Init(uint64_t address);

	ULevel^ CurrentLevel();

	UGameInstance^ OwningGameInstance();
private:
};