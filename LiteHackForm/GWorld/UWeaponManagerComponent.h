#pragma once
#include "Base.h"
enum class EWeaponType : uint8_t
{
	EWeaponType__AWT_None = 0,
	EWeaponType__AWT_Pistol = 1,
	EWeaponType__AWT_PistolSilencer = 2,
	EWeaponType__AWT_ShotGun = 3,
	EWeaponType__AWT_SubmachineGun = 4,
	EWeaponType__AWT_RPG = 5,
	EWeaponType__AWT_ChargeGun = 6,
	EWeaponType__AWT_Knife = 7,
	EWeaponType__AWT_EnegyCaptureWhip = 8,
	EWeaponType__AWT_RifleGun = 9,
	EWeaponType__AWT_MAX = 10,
};
enum class EGunFireMode : uint8_t
{
	EGunFireMode__OneBulletBursting = 0,
	EGunFireMode__MultiBulletsBursting = 1,
	EGunFireMode__Auto = 2,
	EGunFireMode__None = 3,
	EGunFireMode__EGunFireMode_MAX = 4,
};
class UShootWeaponEntity : public Base
{
public:
	using Base::Base;
	EWeaponType WeaponType()
	{
		return GameMemory.Read<EWeaponType>(base + updates::off::WeaponType);
	}

	int WeaponID()
	{
		return GameMemory.Read32(base+ updates::off::WeaponID);
	}

	float BulletFireSpeed()
	{
		return GameMemory.Read<float>(base + updates::off::bulletSpeed);
	}

	bool HasAutoFireMode()
	{
		return GameMemory.Read<bool>(base + updates::off::bAutoFire);
	}

	int BulletNumSingleShot()
	{
		return GameMemory.Read<int>(base + updates::off::bulletNumPerSlot);
	}
};


class ASTExtraWeapon : public Base
{
public:
	using Base::Base;
	int WeaponAvatarID()
	{
		return GameMemory.Read<int>(base + updates::off::WeaponAvatarID);
	}

	UShootWeaponEntity WeaponEntityComp()
	{
		return UShootWeaponEntity(GameMemory.Read64(base + updates::off::WeaponEntity));
	}

	int CurBulletNumInClip()
	{
		return GameMemory.Read32(base + updates::off::CurBulletNum);
	}

	EGunFireMode FireMode()
	{
		return GameMemory.Read<EGunFireMode>(base + updates::off::EGunFireMode);
	}

	int CurMaxBulletNumInOneClip()
	{
		return GameMemory.Read32(base + updates::off::CurMaxBulletNum);
	}
};

class UWeaponManagerComponent : public Base
{
public:
	using Base::Base;

	ASTExtraWeapon CurrentWeapon()
	{
		return ASTExtraWeapon(GameMemory.Read64(base + updates::off::currentWeapon));
	}
};