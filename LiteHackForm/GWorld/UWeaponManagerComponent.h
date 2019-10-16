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
		return GameMemory.Read<EWeaponType>(base + off_WeaponType);
	}

	int WeaponID()
	{
		return GameMemory.Read32(base+off_WeaponID);
	}

	float BulletFireSpeed()
	{
		return GameMemory.Read<float>(base + off_bulletSpeed);
	}

	bool HasAutoFireMode()
	{
		return GameMemory.Read<bool>(base + off_bAutoFire);
	}

	int BulletNumSingleShot()
	{
		return GameMemory.Read<int>(base + off_bulletNumPerSlot);
	}
private:
	uint64 off_WeaponType = 0x01E0;
	uint64 off_WeaponID = 0x2d4;
	uint64 off_bulletSpeed = 0x0450;
	uint64 off_bAutoFire = 0x628;
	uint64 off_bulletNumPerSlot = 0x3b0;
};


class ASTExtraWeapon : public Base
{
public:
	using Base::Base;
	int WeaponAvatarID()
	{
		return GameMemory.Read<int>(base + off_WeaponAvatarID);
	}

	UShootWeaponEntity WeaponEntityComp()
	{
		return UShootWeaponEntity(GameMemory.Read64(base + off_WeaponEntity));
	}

	int CurBulletNumInClip()
	{
		return GameMemory.Read32(base + off_CurBulletNum);
	}

	EGunFireMode FireMode()
	{
		return GameMemory.Read<EGunFireMode>(base + off_EGunFireMode);
	}

	int CurMaxBulletNumInOneClip()
	{
		return GameMemory.Read32(base + off_CurMaxBulletNum);
	}
private:
	uint64 off_WeaponAvatarID = 0x3cc;
	uint64 off_WeaponEntity = 0x438;
	uint64 off_CurBulletNum = 0x07AC;
	uint64 off_EGunFireMode = 0x8d1;
	uint64 off_CurMaxBulletNum = 0x09c0;
};

class UWeaponManagerComponent : public Base
{
public:
	using Base::Base;

	ASTExtraWeapon CurrentWeapon()
	{
		return ASTExtraWeapon(GameMemory.Read64(base + off_currentWeapon));
	}

private:
	uint64 off_currentWeapon = 0x4e8;
};