#pragma once
#include "../Updates.h"

class Base
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

	uint64_t GetAddress()
	{
		return base_address;
	}

	template <typename T>
	T ReadOffset(uint64_t offset);

	template <typename T>
	bool WriteOffset(uint64_t offset, T value);

	template <typename T>
	T CastTo()
	{
		return T(base_address);
	}
protected:
	uint64_t base_address;
};

class USkeletalMeshComponent : public Base
{
public:
	using Base::Base;
	USkeletalMeshComponent(uint64_t address) : Base(address) {}

	uint64_t BoneArray();

	FTransform ComponentToWorld();

	float LastRenderedTime();
private:

};

class USceneComponent : public Base
{
public:
	USceneComponent(uint64_t address) : Base(address) {}

	FVector ComponentVelocity();

	FVector Location();
private:

};

class UShootWeaponEntity : public Base
{
public:
	UShootWeaponEntity(uint64_t address) : Base(address) { }

	TArray<uint64_t> ArrTslWeaponAttachmentData();

	float BulletFireSpeed();

	bool bHasAutoFireMode();
};

class UWeaponManagerComponent : public Base
{
public:
	UWeaponManagerComponent(uint64_t address) : Base(address) {}

	class ASTExtraWeapon CurrentWeapon();
private:

};

class AActor : public Base
{
public:
	AActor() : Base() {}

	AActor(uint64_t address) : Base(address) {}

	int ComparisonIndex();

	USkeletalMeshComponent Mesh();

	USceneComponent RootComponent();
};

class ASTExtraPlayerCharacter : public AActor
{
public:
	bool IsAI();

	int TeamID();

	float Health();

	FString PlayerName();

	uint32_t PlayerKey();

	int SpectatedCount();

	int VehicleSeatIdx();

	bool IsWeaponFiring();

	uint8_t HealthStatus();

	int LocalSimulateStates();

	class APlayerController STPlayerController();

	class ASTExtraWheeledVehicle CurrentVehicle();

	UWeaponManagerComponent WeaponManagerComponent();

	ASTExtraPlayerCharacter() : AActor() {}

	ASTExtraPlayerCharacter(uint64_t address) : AActor(address) {}
private:

};

class ASTExtraWheeledVehicle : public AActor
{
public:
	uint8_t VehicleShapeType();

	ASTExtraWheeledVehicle() : AActor() {}

	ASTExtraWheeledVehicle(uint64_t address) : AActor(address) {}
};

class ASTExtraWeapon : public Base
{
public:
	ASTExtraWeapon(uint64_t address) : Base(address) {}

	UShootWeaponEntity WeaponEntityComp();
};

class APickUpWrapperActor : public AActor
{
public:
	APickUpWrapperActor() : AActor() {}

	APickUpWrapperActor(uint64_t address) : AActor(address) {}
};

class AAirDropBoxActor : public AActor
{
public:
	AAirDropBoxActor() : AActor() {}

	AAirDropBoxActor(uint64_t address) : AActor(address) {}
};

class APlayerTombBox : public AActor
{
public:
	APlayerTombBox() : AActor() {}

	APlayerTombBox(uint64_t address) : AActor(address) {}
};