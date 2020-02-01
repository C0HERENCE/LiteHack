#pragma once
#include "AActor.h"

class APlayerCameraManager : public Base
{
public:
	APlayerCameraManager(uint64_t address) : Base(address) {}

	FMinimalViewInfo MinimalViewInfo();
private:

};

class ASTExtraPlayerCharacter;
class APlayerController : public Base
{
public:
	APlayerController(uint64_t address) : Base(address) {}

	ASTExtraPlayerCharacter LocalPawn();

	APlayerCameraManager CameraCache();
private:

};


class ULocalPlayer : public Base
{
public:
	ULocalPlayer() : Base() {}

	ULocalPlayer(uint64_t address) : Base(address) {}

	APlayerController PlayerController();
private:

};

class UGameInstance : public Base
{
public:
	UGameInstance(uint64_t address) : Base(address) {}

	ULocalPlayer LocalPlayer();
private:

};

class ULevel : public Base
{
public:
	ULevel(uint64_t address) : Base(address) {}

	TArray<uint64_t> Actors();
private:

};

class UWorld : public Base
{
public:
	UWorld() : Base() {}

	void Init(uint64_t address);

	class ULevel CurrentLevel();

	class UGameInstance OwningGameInstance();
private:
};