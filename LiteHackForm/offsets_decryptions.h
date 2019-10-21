#pragma once
#include "Utils/MemoryHelper.h"
#include "GWorld/Core/FRotator.h"
#include "GWorld/Core/FVector.h"

namespace updates
{
	static class off
	{
	public:
		// Main
		static const uint64 uworld = 0x4551B28;
		static const uint64 gnames = 0x466A2A0;
		static const uint64 gobjects = 0x4694e90;
		//GNames
		static const uint64 chunksize = 0x3F64;
		static const uint64 static_gnames = 0x20040;
		// UObject
		static const uint64 ulcass = 0x8;
		static const uint64 internal_id = 0x24;
		static const uint64 name = 0x1c;
		static const uint64 outer = 0x10;
		// FName
		static const uint64 number = 0x0;
		static const uint64 comparison_id = 0x4;
		// UField
		static const uint64 next = 0x28;
		// UEnum
		static const uint64 names = 0x40;
		// UStruct
		static const uint64 superfield = 0x50;
		static const uint64 property_size = 0x30;
		static const uint64 children = 0x68;
		// UProperty
		static const uint64 array_dim = 0x30;
		static const uint64 element_size = 0x34;
		static const uint64 offset = 0x44;
		static const uint64 uproperty_size = 0x70;
		// UWorld
		static const uint64 ulevel = 0x318;
		static const uint64 gameinstance = 0x9C0;
		static const uint64 game_state = 0x130;
		// ULevel
		static const uint64 actor = 0x208;
		// UGameInstance
		static const uint64 localplayer = 0xC0;
		// ULocalPlayer
		static const uint64 playerconroller = 0x30;
		static const uint64 local_pawn = 0x1A70;
		// APlayerController
		static const uint64 NowShotWeaponList = 0x1af8;
		static const uint64 CameraManager = 0x460;
		static const uint64 CameraCache = 0x9B0;
		struct FMinimalViewInfo
		{
			float FOV;
			float unknown[3];
			FVector Location;
			float unknown2[6];
			FRotator Rotation;
		};
		// AActor
		static const uint64 ObjID = 0x18;
		static const uint64 RootComponent = 0x250;
		static const uint64 PlayerName = 0x7d0;
		static const uint64 Health = 0xa6c;
		static const uint64 bIsWeaponFiring = 0x1858;
		static const uint64 Indoor = 0x1e5c;
		static const uint64 teamID = 0x800;
		static const uint64 isAI = 0x819;
		static const uint64 Mesh = 0x470;
		static const uint64 WeaponManager = 0x17a8;
		// USceneComponent
		static const uint64 Location = 0x130;
		static const uint64 Velocity = 0x1A8;
		static const uint64 Visible = 0x183;
		// USkeletalMeshComponent
		static const uint64 bRecentlyRendered = 0x7d8;
		static const uint64 BoneArray = 0x708;
		static const uint64 ComponentToWorld = 0x220;
		//UWeaponManagerComponent
		static const uint64 currentWeapon = 0x4e0;
		//ASTExtraWeapon
		static const uint64 WeaponAvatarID = 0x468;
		static const uint64 WeaponEntity = 0x6e8;
		static const uint64 CurBulletNum = 0x724;
		static const uint64 EGunFireMode = 0x6e4;
		static const uint64 CurMaxBulletNum = 0x738;
		//UShootWeaponEntity
		static const uint64 WeaponType = 0x300;
		static const uint64 WeaponID = 0x1d0;
		static const uint64 bulletSpeed = 0x680;
		static const uint64 bAutoFire = 0x5e0;
		static const uint64 bulletNumPerSlot = 0x714;
	};

	static class dec
	{
	public:
		// UObject
		static uint64 objobjects(uint64 v7)
		{
			uint64 v17;
			LODWORD(v17) = (~(_DWORD)v7 - 457995445) ^ 0x6202762C;
			HIDWORD(v17) = (~(HIDWORD(v7) + 846743355) + 2038027640) ^ 0x1CF21CB2;
			return v17;
			//return (~(_DWORD)v7 - 457995445) ^ 0x6202762C;;
		}
		static int32 internal_id(uint32 v2)
		{
			return __ROL4__(v2 ^ 0x3F686470, 14) ^ (__ROL4__(v2 ^ 0x3F686470, 14) << 16) ^ 0x185B81FF;
		}
		static uint64 uclass(uint64 v14)
		{
			return __ROR8__(v14 ^ 0x3A828B4FDDDA8241, 8) ^ (__ROR8__(v14 ^ 0x3A828B4FDDDA8241, 8) << 32) ^ 0xDA1A7C370173FC15;
		}
		static uint64 outer(uint64 v30)
		{
			return __ROL8__(v30 ^ 0xA0F2E6BF79BE33CF, 15) ^ (__ROL8__(v30 ^ 0xA0F2E6BF79BE33CF, 15) << 32) ^ 0x5C38004A438F6AD6;
		}
		static int32 comparison_id(uint64 v18)
		{
			return __ROR4__(v18 ^ 0xF528638A, 14) ^ (__ROR4__(v18 ^ 0xF528638A, 14) << 16) ^ 0x96A2F528;
		}
		static int32 number(uint64 v14)
		{
			return  __ROR4__(v14 ^ 0x9DDA8240, 8) ^ (__ROR4__(v14 ^ 0x9DDA8240, 8) << 16) ^ 0x3D65FC16;
		}
		// UWorld
		static uint64 ulevel(uint64 inst)
		{
			__int64 v14; // rdx@7
			int v15; // eax@7
			int v16; // eax@7
			__int64 v22; // [sp+40h] [bp+18h]@7

			v14 = inst;
			LODWORD(v22) = __ROL4__((__ROL4__(v14 ^ 0xD96203BD, 8) + 1962157132) ^ 0x746203BD, 8) ^ 0x74F4244C;
			HIDWORD(v22) = (_DWORD)(__ROR4__((__ROR4__(HIDWORD(v14) ^ 0x3E91C6E8, 16) + 1942713292) ^ 0xD991C6E8, 16) ^ 0x8C348C34);

			return v22;
		}
		static uint64 gameinstance(uint64 inst)
		{
			__int64 v1;
			__int64 v3;

			v1 = inst;
			LODWORD(v3) = (v1 + 1170409717) ^ 0x75D5017B;
			HIDWORD(v3) = (HIDWORD(v1) - 1897364949) ^ 0xB650BA5;

			return v3;
		}
		// ULevel
		static uint64 actor(uint64 inst)
		{
			__int64 v17;
			__int64 v22;

			v17 = inst;
			LODWORD(v22) = ((v17 ^ 0xD7C273EB) - 1166372314) ^ 0x30B8E1CD;
			HIDWORD(v22) = ((HIDWORD(v17) ^ 0x2441A658) - 1184515610) ^ 0x91DBE042;

			return v22;
		}
		// AActor
		static uint64 pawn(uint64 in)
		{
			__int64 v47; // rcx@59
			int v48; // eax@59
			int v49; // eax@59
			unsigned __int64 v55; // [sp+28h] [bp-50h]@3

			v47 = in;
			LODWORD(v55) = (v47 + 1522676725) ^ 0x5DBD4913;
			HIDWORD(v55) = (134925820 - HIDWORD(v47)) ^ 0xDC32DCF2;

			return v55;
		}
		// UGameInstance
		static uint64 localplayer(uint64 in)
		{
			__int64 v8;
			__int64 v15;

			v8 = in;
			LODWORD(v15) = (v8 - 181839515) ^ 0x56551EB;
			HIDWORD(v15) = ((v8 >> 32) + 1043206811) ^ 0x7BF57B35;

			return v15;
		}
		// ULocalPlayer
		static uint64 playercontroller(uint64 in)
		{
			unsigned __int64 v11;
			unsigned int v12;
			int v13;
			__int64 v6;
			__int64 v16;

			v11 = in;
			LODWORD(v16) = __ROL4__(__ROL4__(v11 - 564001859, 16) - 1300547276, 16) ^ 0x39193577;
			HIDWORD(v16) = __ROR4__(__ROR4__(HIDWORD(v11) + 1133627112, 8) - 1767342145, 8) ^ 0x47E94729;

			return v16;
		}
	};

}