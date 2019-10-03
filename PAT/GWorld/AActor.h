#pragma once
#include "..//GObjects/GenericTypes.h"
#include "Core/DummyTypes.h"
#include "Core/EngineTypes.h"

enum class EFreshWeaponStateType : uint8_t
{
	FreshWeaponStateType_None = 0,
	FreshWeaponStateType_Inactive = 1,
	FreshWeaponStateType_Idle = 2,
	FreshWeaponStateType_IdleToBackpack = 3,
	FreshWeaponStateType_Backpack = 4,
	FreshWeaponStateType_BackpackToIdle = 5,
	FreshWeaponStateType_Fire = 6,
	FreshWeaponStateType_Reload = 7,
	FreshWeaponStateType_NoBullet = 8,
	FreshWeaponStateType_PreFire = 9,
	FreshWeaponStateType_PostFire = 10,
	FreshWeaponStateType_MAX = 11,
};
	// Enum ShadowTrackerExtra.EAnimWeaponType
enum class EAnimWeaponType : uint8_t
{
	EAnimWeaponType__None = 0,
	EAnimWeaponType__SubmachineGun = 1,
	EAnimWeaponType__Rifle = 2,
	EAnimWeaponType__LongRifle = 3,
	EAnimWeaponType__Pistol = 4,
	EAnimWeaponType__Throwable = 5,
	EAnimWeaponType__Melee = 6,
	EAnimWeaponType__Shield = 7,
	EAnimWeaponType__EAnimWeaponType_MAX = 8,
};
	// Enum ShadowTrackerExtra.EWeaponComponentType
enum class EWeaponComponentType : uint8_t
{
	WCT_None = 0,
	WCT_Scope = 1,
	WCT_Max = 2,
};
	// Enum ShadowTrackerExtra.ESurvivePickUpGlobalCategory
enum class ESurvivePickUpGlobalCategory : uint8_t
{
	SurvivePickUpItemGlobalCategory_None = 0,
	SurvivePickUpItemGlobalCategory_Weapon = 1,
	SurvivePickUpItemGlobalCategory_PlayerEquipment = 2,
	SurvivePickUpItemGlobalCategory_WeaponComponent = 3,
	SurvivePickUpItemGlobalCategory_ConsumeItem = 4,
	SurvivePickUpItemGlobalCategory_MAX = 5,
};

	// Enum ShadowTrackerExtra.EWeaponAction
	enum class EWeaponAction : uint8_t
{
	WA_None = 0,
	WA_EquipWeapon = 1,
	WA_UnEquipWeapon = 2,
	WA_Shoot = 3,
	WA_IdleToNoneIdle = 4,
	WA_NoneShoot = 5,
	WA_Reload = 6,
	WA_AutoShoot = 7,
	WA_MAX = 8,
	};

	// Enum ShadowTrackerExtra.EWeaponState
	enum class EWeaponState : uint8_t
{
	EWeaponState__WS_Unavailable = 0,
	EWeaponState__WS_UnEquiped = 1,
	EWeaponState__WS_Equiped = 2,
	EWeaponState__WS_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EGunFireMode
	enum class EGunFireMode : uint8_t
{
	EGunFireMode__OneBulletBursting = 0,
	EGunFireMode__MultiBulletsBursting = 1,
	EGunFireMode__Auto = 2,
	EGunFireMode__None = 3,
	EGunFireMode__EGunFireMode_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EAvatarSlotType
	enum class EAvatarSlotType : uint8_t
{
	EAvatarSlotType__EAvatarSlotType_NONE = 0,
	EAvatarSlotType__EAvatarSlotType_HeadEquipemtSlot = 1,
	EAvatarSlotType__EAvatarSlotType_HairEquipemtSlot = 2,
	EAvatarSlotType__EAvatarSlotType_HatEquipemtSlot = 3,
	EAvatarSlotType__EAvatarSlotType_FaceEquipemtSlot = 4,
	EAvatarSlotType__EAvatarSlotType_ClothesEquipemtSlot = 5,
	EAvatarSlotType__EAvatarSlotType_PantsEquipemtSlot = 6,
	EAvatarSlotType__EAvatarSlotType_ShoesEquipemtSlot = 7,
	EAvatarSlotType__EAvatarSlotType_BackpackEquipemtSlot = 8,
	EAvatarSlotType__EAvatarSlotType_HelmetEquipemtSlot = 9,
	EAvatarSlotType__EAvatarSlotType_ArmorEquipemtSlot = 10,
	EAvatarSlotType__EAvatarSlotType_ParachuteEquipemtSlot = 11,
	EAvatarSlotType__EAvatarSlotType_MAX = 12,
	};

	// Enum ShadowTrackerExtra.EMeshType
	enum class EMeshType : uint8_t
{
	EMeshType__Skeletal = 0,
	EMeshType__Static = 1,
	EMeshType__SkeletalWithSocket = 2,
	EMeshType__EMeshType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EAvatarSubSlot
	enum class EAvatarSubSlot : uint8_t
{
	EAvatarSubSlot__ESubSlot_None = 0,
	EAvatarSubSlot__ESubSlot_VeilSlot = 1,
	EAvatarSubSlot__ESubSlot_HoodSlot = 2,
	EAvatarSubSlot__ESubSlot_StockingSlot = 3,
	EAvatarSubSlot__ESubSlot_BootsSlot = 4,
	EAvatarSubSlot__ESubSlot_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EWeaponAttachmentSocketType
	enum class EWeaponAttachmentSocketType : uint8_t
{
	EWeaponAttachmentSocketType__GunPoint = 0,
	EWeaponAttachmentSocketType__Grip = 1,
	EWeaponAttachmentSocketType__Magazine = 2,
	EWeaponAttachmentSocketType__Gunstock = 3,
	EWeaponAttachmentSocketType__OpticalSight = 4,
	EWeaponAttachmentSocketType__SideRail = 5,
	EWeaponAttachmentSocketType__EWeaponAttachmentSocketType_MAX = 6,
	};

	// Enum ShadowTrackerExtra.ESyncOperation
	enum class ESyncOperation : uint8_t
{
	ESyncOperation__PutOn = 0,
	ESyncOperation__PutOff = 1,
	ESyncOperation__PutOffHair = 2,
	ESyncOperation__ApplyHead = 3,
	ESyncOperation__ESyncOperation_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EOpticalSightType
	enum class EOpticalSightType : uint8_t
{
	EOpticalSightType__NoneSight = 0,
	EOpticalSightType__UpperRedDot = 1,
	EOpticalSightType__UpperLarge = 2,
	EOpticalSightType__UpperSmall = 3,
	EOpticalSightType__UpperDefault = 4,
	EOpticalSightType__UpperAngled = 5,
	EOpticalSightType__EOpticalSightType_MAX = 6,
	};

	// Enum ShadowTrackerExtra.EWeaponAttachmentSlotID
	enum class EWeaponAttachmentSlotID : uint8_t
{
	EWeaponAttachmentSlotID__None = 0,
	EWeaponAttachmentSlotID__Muzzle = 1,
	EWeaponAttachmentSlotID__LowerRail = 2,
	EWeaponAttachmentSlotID__UpperRail_Scope = 3,
	EWeaponAttachmentSlotID__Magazine = 4,
	EWeaponAttachmentSlotID__Stock = 5,
	EWeaponAttachmentSlotID__Angled = 6,
	EWeaponAttachmentSlotID__EWeaponAttachmentSlotID_MAX = 7,
	};

	// Enum ShadowTrackerExtra.EWeaponReloadMethod
	enum class EWeaponReloadMethod : uint8_t
{
	All = 0,
	Tactical = 1,
	EWeaponReloadMethod_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EScopeType
	enum class EScopeType : uint8_t
{
	EScopeType__Main = 0,
	EScopeType__Right = 1,
	EScopeType__Total = 2,
	EScopeType__None = 3,
	EScopeType__EScopeType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.ESightType
	enum class ESightType : uint8_t
{
	SightX1 = 0,
	SightX2 = 1,
	SightX4 = 2,
	SightX8 = 3,
	SightX3 = 4,
	SightX6 = 5,
	SightDefault = 6,
	ESightType_MAX = 7,
	};

	// Enum ShadowTrackerExtra.EWeaponReloadType
	enum class EWeaponReloadType : uint8_t
{
	Magzine = 0,
	OneByOne = 1,
	OneByOneAndClip = 2,
	EWeaponReloadType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EWeaponReloadAnimExec
	enum class EWeaponReloadAnimExec : uint8_t
{
	EWeaponReloadAnimExec__Tactical = 0,
	EWeaponReloadAnimExec__Charge = 1,
	EWeaponReloadAnimExec__Single = 2,
	EWeaponReloadAnimExec__Loop = 3,
	EWeaponReloadAnimExec__EWeaponReloadAnimExec_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EShootWeaponState
	enum class EShootWeaponState : uint8_t
{
	SWS_Idle = 0,
	SWS_NoneIdle = 1,
	SWS_Shooting = 2,
	SWS_Reloading = 3,
	SWS_ReloadDone = 4,
	SWS_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EShootWeaponShootMode
	enum class EShootWeaponShootMode : uint8_t
{
	SWST_MuzzleDirection = 0,
	SWST_TargetDirection = 1,
	SWST_TraceTarget = 2,
	SWST_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ESTEPoseState
	enum class ESTEPoseState : uint8_t
{
	ESTEPoseState__Stand = 0,
	ESTEPoseState__Crouch = 1,
	ESTEPoseState__Prone = 2,
	ESTEPoseState__Sprint = 3,
	ESTEPoseState__CrouchSprint = 4,
	ESTEPoseState__Crawl = 5,
	ESTEPoseState__Swim = 6,
	ESTEPoseState__SwimSprint = 7,
	ESTEPoseState__Dying = 8,
	ESTEPoseState__Vehicle_Passengers = 9,
	ESTEPoseState__Skydive = 10,
	ESTEPoseState__ESTEPoseState_MAX = 11,
	};

	// Enum ShadowTrackerExtra.EPlayerCameraMode
	enum class EPlayerCameraMode : uint8_t
{
	PCM_Normal = 0,
	PCM_Near = 1,
	PCM_AimIn = 2,
	PCM_AimOut = 3,
	PCM_Plane = 4,
	PCM_FPP = 5,
	PCM_NormalInVehicle = 6,
	PCM_FPPInVehicle = 7,
	PCM_MAX = 8,
	};

	// Enum ShadowTrackerExtra.ESTExtraVehicleSeatType
	enum class ESTExtraVehicleSeatType : uint8_t
{
	ESTExtraVehicleSeatType__ESeatType_DriversSeat = 0,
	ESTExtraVehicleSeatType__ESeatType_PassengersSeat = 1,
	ESTExtraVehicleSeatType__ESeatType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.ESTExtraVehicleHealthState
	enum class ESTExtraVehicleHealthState : uint8_t
{
	ESTExtraVehicleHealthState__VHS_Good = 0,
	ESTExtraVehicleHealthState__VHS_Smoking = 1,
	ESTExtraVehicleHealthState__VHS_Burning = 2,
	ESTExtraVehicleHealthState__VHS_Destroyed = 3,
	ESTExtraVehicleHealthState__VHS_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EPawnState
	enum class EPawnState : uint8_t
{
	EPawnState__Move = 0,
	EPawnState__Sprint = 1,
	EPawnState__ProneMove = 2,
	EPawnState__Stand = 3,
	EPawnState__Crouch = 4,
	EPawnState__Prone = 5,
	EPawnState__Jump = 6,
	EPawnState__GunFire = 7,
	EPawnState__GunReload = 8,
	EPawnState__GunADS = 9,
	EPawnState__Picth = 10,
	EPawnState__SwitchWeapon = 11,
	EPawnState__Pick = 12,
	EPawnState__MeleeAttack = 13,
	EPawnState__HoldGrenade = 14,
	EPawnState__Save = 15,
	EPawnState__UseConsumables = 16,
	EPawnState__Dying = 17,
	EPawnState__Dead = 18,
	EPawnState__DriveVehicle = 19,
	EPawnState__InVehicle = 20,
	EPawnState__LeanOutVehicle = 21,
	EPawnState__Swim = 22,
	EPawnState__InParachute = 23,
	EPawnState__Vault = 24,
	EPawnState__VaultCancel = 25,
	EPawnState__InPlane = 26,
	EPawnState__GunOBOReload = 27,
	EPawnState__SwitchPP = 28,
	EPawnState__GunShoulderFiring = 29,
	EPawnState__Walk = 30,
	EPawnState__PlayEmote = 31,
	EPawnState____MAX = 32,
	EPawnState__EPawnState_MAX = 33,
	};

	// Enum ShadowTrackerExtra.EInviteResponceType
	enum class EInviteResponceType : uint8_t
{
	EInviteResponceType__ETimeout = 0,
	EInviteResponceType__EAgree = 1,
	EInviteResponceType__ERefuse = 2,
	EInviteResponceType__EBeInviting = 3,
	EInviteResponceType__EInviteResponceType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.ESurviveWeaponPropSlot
	enum class ESurviveWeaponPropSlot : uint8_t
{
	ESurviveWeaponPropSlot__SWPS_None = 0,
	ESurviveWeaponPropSlot__SWPS_MainShootWeapon1 = 1,
	ESurviveWeaponPropSlot__SWPS_MainShootWeapon2 = 2,
	ESurviveWeaponPropSlot__SWPS_SubShootWeapon = 3,
	ESurviveWeaponPropSlot__SWPS_MeleeWeapon = 4,
	ESurviveWeaponPropSlot__SWPS_HandProp = 5,
	ESurviveWeaponPropSlot__SWPS_Max = 6,
	};

	// Enum ShadowTrackerExtra.EHitPartJugementType
	enum class EHitPartJugementType : uint8_t
{
	HitPos = 0,
	HitBone = 1,
	EHitPartJugementType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EGrenadeType
	enum class EGrenadeType : uint8_t
{
	EGrenadeType__UnknownGrenade = 0,
	EGrenadeType__StunGrenade = 1,
	EGrenadeType__FireGrenade = 2,
	EGrenadeType__SmokeGrenade = 3,
	EGrenadeType__FragGrenade = 4,
	EGrenadeType__GrenadeMax = 5,
	EGrenadeType__EGrenadeType_MAX = 6,
	};

	// Enum ShadowTrackerExtra.EAvatarDamagePosition
	enum class EAvatarDamagePosition : uint8_t
{
	EAvatarDamagePosition__Non = 0,
	EAvatarDamagePosition__BigHead = 1,
	EAvatarDamagePosition__BigLimbs = 2,
	EAvatarDamagePosition__BigBody = 3,
	EAvatarDamagePosition__BigHand = 4,
	EAvatarDamagePosition__BigFoot = 5,
	EAvatarDamagePosition__Wheel0 = 6,
	EAvatarDamagePosition__Wheel1 = 7,
	EAvatarDamagePosition__Wheel2 = 8,
	EAvatarDamagePosition__Wheel3 = 9,
	EAvatarDamagePosition__Arms = 10,
	EAvatarDamagePosition__Legs = 11,
	EAvatarDamagePosition__UpperBody = 12,
	EAvatarDamagePosition__LowerBody = 13,
	EAvatarDamagePosition__NonSpecific = 14,
	EAvatarDamagePosition__EAvatarDamagePosition_MAX = 15,
	};

	// Enum ShadowTrackerExtra.EParachuteState
	enum class EParachuteState : uint8_t
{
	PS_None = 0,
	PS_FreeFall = 1,
	PS_Opening = 2,
	PS_Landing = 3,
	PS_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EWeaponType
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

	// Enum ShadowTrackerExtra.EWeaponHoldType
	enum class EWeaponHoldType : uint8_t
{
	EWHT_None = 0,
	EWHT_SingleHand = 1,
	EWHT_TwoHand = 2,
	EWHT_Max = 3,
	};

	// Enum ShadowTrackerExtra.ESTExtraVehicleType
	enum class ESTExtraVehicleType : uint8_t
{
	ESTExtraVehicleType__VT_Unknown = 0,
	ESTExtraVehicleType__VT_Motorbike = 1,
	ESTExtraVehicleType__VT_Motorbike01 = 2,
	ESTExtraVehicleType__VT_Motorbike_SideCart = 3,
	ESTExtraVehicleType__VT_Motorbike_SideCart01 = 4,
	ESTExtraVehicleType__VT_Dacia = 5,
	ESTExtraVehicleType__VT_Dacia01 = 6,
	ESTExtraVehicleType__VT_Dacia02 = 7,
	ESTExtraVehicleType__VT_Dacia03 = 8,
	ESTExtraVehicleType__VT_UAZ = 9,
	ESTExtraVehicleType__VT_UAZ01 = 10,
	ESTExtraVehicleType__VT_UAZ02 = 11,
	ESTExtraVehicleType__VT_Buggy = 12,
	ESTExtraVehicleType__VT_Buggy01 = 13,
	ESTExtraVehicleType__VT_Buggy02 = 14,
	ESTExtraVehicleType__VT_PG117 = 15,
	ESTExtraVehicleType__VT_Aquarail = 16,
	ESTExtraVehicleType__VT_Minibus = 17,
	ESTExtraVehicleType__VT_Mirado_close = 18,
	ESTExtraVehicleType__VT_Mirado_close01 = 19,
	ESTExtraVehicleType__VT_Mirado_close02 = 20,
	ESTExtraVehicleType__VT_Mirado_close03 = 21,
	ESTExtraVehicleType__VT_Mirado_open = 22,
	ESTExtraVehicleType__VT_Mirado_open01 = 23,
	ESTExtraVehicleType__VT_Mirado_open02 = 24,
	ESTExtraVehicleType__VT_Mirado_open03 = 25,
	ESTExtraVehicleType__VT_Rony = 26,
	ESTExtraVehicleType__VT_Scooter = 27,
	ESTExtraVehicleType__VT_TukTuk = 28,
	ESTExtraVehicleType__VT_MAX = 29,
	};

	// Enum ShadowTrackerExtra.EVHSeatSpecialType
	enum class EVHSeatSpecialType : uint8_t
{
	EVHSeatSpecialType__EVHSeatSpecial_Common = 0,
	EVHSeatSpecialType__EVHSeatSpecial_Narrow = 1,
	EVHSeatSpecialType__EVHSeatSpecial_Max = 2,
	};

	// Enum ShadowTrackerExtra.EVHSeatWeaponHoldType
	enum class EVHSeatWeaponHoldType : uint8_t
{
	EVHSeatWeaponHoldType__ESeatWeapon_None = 0,
	EVHSeatWeaponHoldType__ESeatWeapon_ShortOnly = 1,
	EVHSeatWeaponHoldType__ESeatWeapon_ShortIgnoreMelee = 2,
	EVHSeatWeaponHoldType__ESeatWeapon_All = 3,
	EVHSeatWeaponHoldType__ESeatWeapon_BlockLean = 4,
	EVHSeatWeaponHoldType__ESeatWeapon_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EThrowGrenadeMode
	enum class EThrowGrenadeMode : uint8_t
{
	HighThrowMode = 0,
	LowThrowMode = 1,
	EThrowGrenadeMode_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EVaultAnimType
	enum class EVaultAnimType : uint8_t
{
	EVaultAnimType__VaultNone = 0,
	EVaultAnimType__Vault200_Stationary = 1,
	EVaultAnimType__Vault200_Mobile = 2,
	EVaultAnimType__Vault200_Narrow = 3,
	EVaultAnimType__Vault160_Stationary = 4,
	EVaultAnimType__Vault160_Mobile = 5,
	EVaultAnimType__Vault160_Narrow = 6,
	EVaultAnimType__Vault120_Stationary = 7,
	EVaultAnimType__Vault120_Mobile = 8,
	EVaultAnimType__Vault120_Slide = 9,
	EVaultAnimType__Vault120_Narrow = 10,
	EVaultAnimType__Vault90_Stationary = 11,
	EVaultAnimType__Vault90_Mobile = 12,
	EVaultAnimType__Vault90_Slide = 13,
	EVaultAnimType__Vault90_Narrow = 14,
	EVaultAnimType__Climb200_Stationary = 15,
	EVaultAnimType__Climb200_Mobile = 16,
	EVaultAnimType__Climb200_Slide = 17,
	EVaultAnimType__Climb200_Narrow = 18,
	EVaultAnimType__Climb160_Stationary = 19,
	EVaultAnimType__Climb160_Mobile = 20,
	EVaultAnimType__Climb160_Slide = 21,
	EVaultAnimType__Climb160_Narrow = 22,
	EVaultAnimType__Climb120_Stationary = 23,
	EVaultAnimType__Climb120_Mobile = 24,
	EVaultAnimType__Climb120_Slide = 25,
	EVaultAnimType__Climb120_Narrow = 26,
	EVaultAnimType__Climb90_Stationary = 27,
	EVaultAnimType__Climb90_Mobile = 28,
	EVaultAnimType__Climb90_Slide = 29,
	EVaultAnimType__Climb90_Narrow = 30,
	EVaultAnimType__Vault90Roll = 31,
	EVaultAnimType__Vault120Window = 32,
	EVaultAnimType__Vault60_Stationary = 33,
	EVaultAnimType__Vault60_Mobile = 34,
	EVaultAnimType__Vault60_Slide = 35,
	EVaultAnimType__Vault60_Narrow = 36,
	EVaultAnimType__Climb60_Stationary = 37,
	EVaultAnimType__Climb60_Mobile = 38,
	EVaultAnimType__Climb60_Narrow = 39,
	EVaultAnimType__LedgeGrab_Up_Climb = 40,
	EVaultAnimType__LedgeGrab_Up_Climb_Swing = 41,
	EVaultAnimType__LedgeGrab_Up_Climb_HalfSwing = 42,
	EVaultAnimType__LedgeGrab_Up_Vault = 43,
	EVaultAnimType__LedgeGrab_Up_Vault_Swing = 44,
	EVaultAnimType__LedgeGrab_Up_Vault_HalfSwing = 45,
	EVaultAnimType__LedgeGrab_High_Climb = 46,
	EVaultAnimType__LedgeGrab_High_Climb_Swing = 47,
	EVaultAnimType__LedgeGrab_High_Climb_HalfSwing = 48,
	EVaultAnimType__LedgeGrab_High_Vault = 49,
	EVaultAnimType__LedgeGrab_High_Vault_Swing = 50,
	EVaultAnimType__LedgeGrab_High_Vault_HalfSwing = 51,
	EVaultAnimType__LedgeGrab_Low_Climb = 52,
	EVaultAnimType__LedgeGrab_Low_Climb_Swing = 53,
	EVaultAnimType__LedgeGrab_Low_Climb_HalfSwing = 54,
	EVaultAnimType__LedgeGrab_Low_Vault = 55,
	EVaultAnimType__LedgeGrab_Low_Vault_Swing = 56,
	EVaultAnimType__LedgeGrab_Low_Vault_HalfSwing = 57,
	EVaultAnimType__LedgeGrab_Low_Vault_Narrow = 58,
	EVaultAnimType__LedgeGrab_Low_Vault_HalfSwing_Narrow = 59,
	EVaultAnimType__LedgeGrab_Low_Vault_Swing_Narrow = 60,
	EVaultAnimType__LedgeGrab_High_Vault_Narrow = 61,
	EVaultAnimType__LedgeGrab_High_Vault_HalfSwing_Narrow = 62,
	EVaultAnimType__LedgeGrab_High_Vault_Swing_Narrow = 63,
	EVaultAnimType__LedgeGrab_Up_Vault_Narrow = 64,
	EVaultAnimType__LedgeGrab_Up_Vault_HalfSwing_Narrow = 65,
	EVaultAnimType__LedgeGrab_Up_Vault_Swing_Narrow = 66,
	EVaultAnimType__EVaultAnimType_MAX = 67,
	};

	// Enum ShadowTrackerExtra.EWeaponSlotType
	enum class EWeaponSlotType : uint8_t
{
	WST_None = 0,
	WST_Main = 1,
	WST_Sub = 2,
	WST_Melee = 3,
	WST_Throw = 4,
	WST_Max = 5,
	};

	// Enum ShadowTrackerExtra.EAimingType
	enum class EAimingType : uint8_t
{
	EAimingType__Aiming_None = 0,
	EAimingType__Aiming_ShoulderFiring = 1,
	EAimingType__Aiming_AimingDownSight = 2,
	EAimingType__Aiming_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ECharacterHealthStatus
	enum class ECharacterHealthStatus : uint8_t
{
	HealthyAlive = 0,
	HasLastBreath = 1,
	FinishedLastBreath = 2,
	Max = 3,
	};

	// Enum ShadowTrackerExtra.EShootVertifyRes
	enum class EShootVertifyRes : uint8_t
{
	OK = 0,
	ShootBigHead = 1,
	ShootPointBigDeviation = 2,
	ShootBigBoxNull = 3,
	ShootOtherBlock = 4,
	NoLagCompensation = 5,
	ShootTimeTooDelay = 6,
	MuzzleBigDeviation = 7,
	ShootHitHeadError = 8,
	ShootHitRotationError = 9,
	ShootRangeError = 10,
	ShootHitInVehicle = 11,
	ShootHitAITarget = 12,
	ShootHitVehicleTarget = 13,
	BulletFlyTimeError = 14,
	BulletDirError = 15,
	BulletImpactOffsetError = 16,
	CharacterImpactOffsetError = 17,
	Non = 18,
	EShootVertifyRes_MAX = 19,
	};

	// Enum ShadowTrackerExtra.ERecoveryReasonType
	enum class ERecoveryReasonType : uint8_t
{
	ERecoveryReason_Medicine = 0,
	ERecoveryReason_Energy = 1,
	ERecoveryReason_RescueByTeammate = 2,
	ERecoveryReason_Max = 3,
	};

	// Enum ShadowTrackerExtra.EUAESkillEvent
	enum class EUAESkillEvent : uint8_t
{
	UAESkillEvent_None = 0,
	GrenadeModeChange = 1,
	ThrowGrenade = 2,
	SkillCancel = 3,
	GrenadeTimeOut = 4,
	SwitchWeapon = 5,
	SwitchWeaponInterrupt = 6,
	SwitchWeaponFinish = 7,
	UnequipWeapon = 8,
	UnequipWeaponFinish = 9,
	SkillInterrupt = 10,
	EUAESkillEvent_MAX = 11,
	};

	// Enum ShadowTrackerExtra.EUTSkillEntry
	enum class EUTSkillEntry : uint8_t
{
	EUTSkillEntry__SkillEntry_None = 0,
	EUTSkillEntry__SkillEntry_Grenade_Down = 1,
	EUTSkillEntry__SkillEntry_Grenade_Up = 2,
	EUTSkillEntry__SkillEntry_Flash_Down = 3,
	EUTSkillEntry__SkillEntry_Flash_Up = 4,
	EUTSkillEntry__SkillEntry_Smoke_Down = 5,
	EUTSkillEntry__SkillEntry_Smoke_Up = 6,
	EUTSkillEntry__SkillEntry_Molotov_Down = 7,
	EUTSkillEntry__SkillEntry_Molotov_Up = 8,
	EUTSkillEntry__SkillEntry_Melee_Fist_Down = 9,
	EUTSkillEntry__SkillEntry_Melee_Fist_Up = 10,
	EUTSkillEntry__SkillEntry_Melee_Weapon_1_Down = 11,
	EUTSkillEntry__SkillEntry_Melee_Weapon_1_Up = 12,
	EUTSkillEntry__SkillEntry_Melee_Weapon_2_Down = 13,
	EUTSkillEntry__SkillEntry_Melee_Weapon_2_Up = 14,
	EUTSkillEntry__SkillEntry_Melee_Weapon_3_Down = 15,
	EUTSkillEntry__SkillEntry_Melee_Weapon_3_Up = 16,
	EUTSkillEntry__SkillEntry_Melee_Weapon_4_Down = 17,
	EUTSkillEntry__SkillEntry_Melee_Weapon_4_Up = 18,
	EUTSkillEntry__SkillEntry_Bandage_Down = 19,
	EUTSkillEntry__SkillEntry_EnergyDrink_Down = 20,
	EUTSkillEntry__SkillEntry_Painkiller_Down = 21,
	EUTSkillEntry__SkillEntry_AdrenalineSyringe_Down = 22,
	EUTSkillEntry__SkillEntry_FirstAidKit_Down = 23,
	EUTSkillEntry__SkillEntry_MedKit_Down = 24,
	EUTSkillEntry__SkillEntry_GasCan_Down = 25,
	EUTSkillEntry__SkillEntry_Max = 26,
	};

	// Enum ShadowTrackerExtra.EFollowState
	enum class EFollowState : uint8_t
{
	EFollowState__None = 0,
	EFollowState__Leader = 1,
	EFollowState__Follower = 2,
	EFollowState__EFollowState_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EHealthPredictShowType
	enum class EHealthPredictShowType : uint8_t
{
	EHealthPredict_Add = 0,
	EHealthPredict_Set = 1,
	EHealthPredict_Max = 2,
	};

	// Enum ShadowTrackerExtra.ETeamNumber
	enum class ETeamNumber : uint8_t
{
	ETeamNumber__POLICE = 0,
	ETeamNumber__TERRORIST = 1,
	ETeamNumber__CIVILIAN = 2,
	ETeamNumber__UNKNOWN = 3,
	ETeamNumber__ETeamNumber_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EDamageType
	enum class EDamageType : uint8_t
{
	EDamageType__ShootDamage = 0,
	EDamageType__PoisonDamage = 1,
	EDamageType__DrowningDamage = 2,
	EDamageType__FallingDamage = 3,
	EDamageType__MeleeDamage = 4,
	EDamageType__GrenadeRadiusDamage = 5,
	EDamageType__BurningDamage = 6,
	EDamageType__AirAttackDamage = 7,
	EDamageType__VehicleDamage = 8,
	EDamageType__VehicleExplodeRadiusDamage = 9,
	EDamageType__LastBreathWithoutRescue = 10,
	EDamageType__WinnerFakeDeath = 11,
	EDamageType__VehicleCrashDamage = 12,
	EDamageType__InvalidDamageType = 13,
	EDamageType__EDamageType_MAX = 14,
	};

	// Enum ShadowTrackerExtra.EInvincibleType
	enum class EInvincibleType : uint8_t
{
	EInvincibleType__None = 0,
	EInvincibleType__DamageImmune = 1,
	EInvincibleType__NeverDie = 2,
	EInvincibleType__EInvincibleType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EEquipableItemSoundType
	enum class EEquipableItemSoundType : uint8_t
{
	EEquipableItemSoundType__None = 0,
	EEquipableItemSoundType__Vest = 1,
	EEquipableItemSoundType__LongCoat = 2,
	EEquipableItemSoundType__HipSack = 3,
	EEquipableItemSoundType__Cloth = 4,
	EEquipableItemSoundType__BackPack = 5,
	EEquipableItemSoundType__MilitaryShoes = 6,
	EEquipableItemSoundType__Sneakers = 7,
	EEquipableItemSoundType__EEquipableItemSoundType_MAX = 8,
	};

	// Enum ShadowTrackerExtra.EPlayerEnegyStage
	enum class EPlayerEnegyStage : uint8_t
{
	PES_None = 0,
	PES_Stage1 = 1,
	PES_Stage2 = 2,
	PES_Stage3 = 3,
	PES_Stage4 = 4,
	PES_MAX = 5,
	};

	// Enum ShadowTrackerExtra.ExtraPlayerLiveState
	enum class ExtraPlayerLiveState : uint8_t
{
	ExtraPlayerLiveState__InDefault = 0,
	ExtraPlayerLiveState__InPlane = 1,
	ExtraPlayerLiveState__InParachute = 2,
	ExtraPlayerLiveState__InVehicle = 3,
	ExtraPlayerLiveState__InDying = 4,
	ExtraPlayerLiveState__InDied = 5,
	ExtraPlayerLiveState__Offline = 6,
	ExtraPlayerLiveState__ExtraPlayerLiveState_MAX = 7,
	};

	// Enum ShadowTrackerExtra.EDriveCar
	enum class EDriveCar : uint8_t
{
	EDriveCar__None = 0,
	EDriveCar__Buggy = 1,
	EDriveCar__EDriveCar_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EAirAttackInfo
	enum class EAirAttackInfo : uint8_t
{
	EAirAttackInfo__AttackWarningTips = 0,
	EAirAttackInfo__Attacking = 1,
	EAirAttackInfo__AttackOver = 2,
	EAirAttackInfo__NoAirAttack = 3,
	EAirAttackInfo__EAirAttackInfo_MAX = 4,
	};

	// Enum ShadowTrackerExtra.ECircleInfo
	enum class ECircleInfo : uint8_t
{
	ECircleInfo__SafeZoneTips = 0,
	ECircleInfo__BlueCirclePreWarning = 1,
	ECircleInfo__BlueCircleRun = 2,
	ECircleInfo__NoCircleInfo = 3,
	ECircleInfo__ECircleInfo_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EPopupButtonID
	enum class EPopupButtonID : uint8_t
{
	EPopupButtonID__Cancel_Or_No = 0,
	EPopupButtonID__Yes_Or_OK = 1,
	EPopupButtonID__EPopupButtonID_MAX = 2,
	};

	// Enum ShadowTrackerExtra.ETeammatchPersonalMsgType
	enum class ETeammatchPersonalMsgType : uint8_t
{
	ETeammatchPersonalMsgType__Recovery = 0,
	ETeammatchPersonalMsgType__Invincibility = 1,
	ETeammatchPersonalMsgType__ETeammatchPersonalMsgType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EBulletCategory
	enum class EBulletCategory : uint8_t
{
	EBulletCategory__NONE = 0,
	EBulletCategory__Bullet_5 = 1,
	EBulletCategory__Bullet_7 = 2,
	EBulletCategory__Bullet = 3,
	EBulletCategory__Bullet01 = 4,
	EBulletCategory__Bullet02 = 5,
	EBulletCategory__Bullet03 = 6,
	EBulletCategory__Bullet_Bolt = 7,
	EBulletCategory__EBulletCategory_MAX = 8,
	};

	// Enum ShadowTrackerExtra.EGunCategory
	enum class EGunCategory : uint8_t
{
	EGunCategory__NONE = 0,
	EGunCategory__AR = 1,
	EGunCategory__SMG = 2,
	EGunCategory__SR = 3,
	EGunCategory__SG = 4,
	EGunCategory__LMG = 5,
	EGunCategory__HG = 6,
	EGunCategory__DMR = 7,
	EGunCategory__BOW = 8,
	EGunCategory__EGunCategory_MAX = 9,
	};

	// Enum ShadowTrackerExtra.ESubjectToReport
	enum class ESubjectToReport : uint8_t
{
	ESubjectToReport__None = 0,
	ESubjectToReport__Killer = 1,
	ESubjectToReport__Spectating_Player = 2,
	ESubjectToReport__Replay_Player = 3,
	ESubjectToReport__Team_Member = 4,
	ESubjectToReport__TDM_Member = 5,
	ESubjectToReport__ESubjectToReport_MAX = 6,
	};

	// Enum ShadowTrackerExtra.ERadioMessageInteractionType
	enum class ERadioMessageInteractionType : uint8_t
{
	ERadioMessageInteractionType__DroppedItem = 0,
	ERadioMessageInteractionType__Vehicle = 1,
	ERadioMessageInteractionType__CarepackageOrDeadbox = 2,
	ERadioMessageInteractionType__ERadioMessageInteractionType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EObserverAuthorityType
	enum class EObserverAuthorityType : uint8_t
{
	EObserverAuthorityType__None = 0,
	EObserverAuthorityType__FromBeginning = 1,
	EObserverAuthorityType__AfterDeath = 2,
	EObserverAuthorityType__AfterExtermination = 3,
	EObserverAuthorityType__EagleEye = 4,
	EObserverAuthorityType__EObserverAuthorityType_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EReportDetailCauseType
	enum class EReportDetailCauseType : uint8_t
{
	EReportDetailCauseType__AutoAim = 0,
	EReportDetailCauseType__NoRecoil = 1,
	EReportDetailCauseType__EspOrPenetration = 2,
	EReportDetailCauseType__Speedhack = 3,
	EReportDetailCauseType__EReportDetailCauseType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EReportCause
	enum class EReportCause : uint8_t
{
	EReportCause__Default = 0,
	EReportCause__Cheat = 1,
	EReportCause__TeamKill = 2,
	EReportCause__Teaming = 3,
	EReportCause__InappropriateID = 4,
	EReportCause__VerbalHarassment = 5,
	EReportCause__Griefing = 6,
	EReportCause__EReportCause_MAX = 7,
	};

	// Enum ShadowTrackerExtra.ETopMostUIPanelType
	enum class ETopMostUIPanelType : uint8_t
{
	ETopUIPanelType_MainInputPanel = 0,
	ETopUIPanelType_BackpackPanel = 1,
	ETopUIPanelType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EWarScoreChangeReason
	enum class EWarScoreChangeReason : uint8_t
{
	EWarScoreChangeReason__WarScoreChangeReason_NONE = 0,
	EWarScoreChangeReason__WarScoreChangeReason_WHOLETEAMKILLED = 1,
	EWarScoreChangeReason__WarScoreChangeReason_SAVETEAMMATE = 2,
	EWarScoreChangeReason__WarScoreChangeReason_KNOCKDOWNENEMY = 3,
	EWarScoreChangeReason__WarScoreChangeReason_KILLENEMY = 4,
	EWarScoreChangeReason__WarScoreChangeReason_MAX = 5,
	};

	// Enum ShadowTrackerExtra.ESystemMessageType
	enum class ESystemMessageType : uint8_t
{
	ESystemMessageType__Debug = 0,
	ESystemMessageType__Notify = 1,
	ESystemMessageType__Warning = 2,
	ESystemMessageType__Error = 3,
	ESystemMessageType__Important = 4,
	ESystemMessageType__ESystemMessageType_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EServerStatType
	enum class EServerStatType : uint8_t
{
	UE = 0,
	NET = 1,
	EServerStatType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EFatalDamageRelationShip
	enum class EFatalDamageRelationShip : uint8_t
{
	MyTeamateIsCauser = 0,
	NotRelated = 1,
	MyTeammateIsVictim = 2,
	MyTeammateIsCauserAndVictim = 3,
	EFatalDamageRelationShip_MAX = 4,
	};

	// Enum ShadowTrackerExtra.ETouchFireType
	enum class ETouchFireType : uint8_t
{
	NotFire = 0,
	ButtonFire = 1,
	TouchForceFire = 2,
	DoubleClickFire = 3,
	ETouchFireType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EKillOrPutDownMessageType
	enum class EKillOrPutDownMessageType : uint8_t
{
	EKillOrPutDownMessageType_YouPutDownPlayer = 0,
	EKillOrPutDownMessageType_YouKilledPlayer = 1,
	EKillOrPutDownMessageType_YouHaveBeenPutDown = 2,
	EKillOrPutDownMessageType_YouHaveBeenKilled = 3,
	EKillOrPutDownMessageType_YourTeammatePutDownPlayer = 4,
	EKillOrPutDownMessageType_YourTeammateKilledPlayer = 5,
	EKillOrPutDownMessageType_YourTeammateHaveBeenPutDown = 6,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilled = 7,
	EKillOrPutDownMessageType_YouHaveBeenKilledByPoison = 8,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilledByPoison = 9,
	EKillOrPutDownMessageType_YouHaveBeenPutDownByPoison = 10,
	EKillOrPutDownMessageType_YourTeammateHaveBeenPutDownByPoison = 11,
	EKillOrPutDownMessageType_YouHaveBeenPutDownByFallingDown = 12,
	EKillOrPutDownMessageType_YourTeammateHaveBeenPutDownByFallingDown = 13,
	EKillOrPutDownMessageType_YouHaveBeenKilledByFallingDown = 14,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilledByFallingDown = 15,
	EKillOrPutDownMessageType_YouHaveBeenPutDownByDrowing = 16,
	EKillOrPutDownMessageType_YourTeammateHaveBeenPutDownByDrowing = 17,
	EKillOrPutDownMessageType_YouHaveBeenKilledByDrowing = 18,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilledByDrowing = 19,
	EKillOrPutDownMessageType_YouHaveBeenKilledFinally = 20,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilledFinally = 21,
	EKillOrPutDownMessageType_YouHaveBeenPutDownByAirAttack = 22,
	EKillOrPutDownMessageType_YourTeammateHaveBeenPutDownByAirAttack = 23,
	EKillOrPutDownMessageType_YouHaveBeenKilledByAirAttack = 24,
	EKillOrPutDownMessageType_YourTeammateHaveBeenKilledByAirAttack = 25,
	EKillOrPutDownMessageType_MAX = 26,
	};

	// Enum ShadowTrackerExtra.EnmSprintOptType
	enum class EnmSprintOptType : uint8_t
{
	NoneOpt = 0,
	TimeToSprint = 1,
	DistToSprint = 2,
	EnmSprintOptType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EAutoAimType
	enum class EAutoAimType : uint8_t
{
	EAutoAimType__FullTime = 0,
	EAutoAimType__OnlyFire = 1,
	EAutoAimType__OnlyTouch = 2,
	EAutoAimType__OnlyNotTouch = 3,
	EAutoAimType__TouchOrFire = 4,
	EAutoAimType__EAutoAimType_MAX = 5,
	};

	// Enum ShadowTrackerExtra.SwitchWeaponProgress
	enum class ESwitchWeaponProgress : uint8_t
{
	SwitchWeaponProgress__None = 0,
	SwitchWeaponProgress__Unequiping = 1,
	SwitchWeaponProgress__Equiping = 2,
	SwitchWeaponProgress__SwitchWeaponProgress_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EGamePawnEvent
	enum class EGamePawnEvent : uint8_t
{
	EGamePawnEvent__Birth = 0,
	EGamePawnEvent__Plane = 1,
	EGamePawnEvent__Jump = 2,
	EGamePawnEvent__Parachute = 3,
	EGamePawnEvent__Land = 4,
	EGamePawnEvent__Die = 5,
	EGamePawnEvent__ReBirth = 6,
	EGamePawnEvent__HeightCheck_High = 7,
	EGamePawnEvent__HeightCheck_Mid = 8,
	EGamePawnEvent__HeightCheck_Low = 9,
	EGamePawnEvent__Fighting = 10,
	EGamePawnEvent__EGamePawnEvent_MAX = 11,
	};

	// Enum ShadowTrackerExtra.ObjectMovingType
	enum class EObjectMovingType : uint8_t
{
	OMT_Uniform = 0,
	OMT_Acceleration = 1,
	OMT_Deceleration = 2,
	OMT_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ERatingRankType
	enum class ERatingRankType : uint8_t
{
	ERatingRankType__None = 0,
	ERatingRankType__Bronze = 1,
	ERatingRankType__Silver = 2,
	ERatingRankType__Gold = 3,
	ERatingRankType__Platinum = 4,
	ERatingRankType__Diamond = 5,
	ERatingRankType__Elite = 6,
	ERatingRankType__Master = 7,
	ERatingRankType__GrandMaster = 8,
	ERatingRankType__ERatingRankType_MAX = 9,
	};

	// Enum ShadowTrackerExtra.EObserverCameraMode
	enum class EObserverCameraMode : uint8_t
{
	EObserverCameraMode__FixedCamera = 0,
	EObserverCameraMode__FreeCamera = 1,
	EObserverCameraMode__PlayerCamera = 2,
	EObserverCameraMode__FollowCamera = 3,
	EObserverCameraMode__EObserverCameraMode_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EPromotionMsg
	enum class EPromotionMsg : uint8_t
{
	EPromotionMsg__None = 0,
	EPromotionMsg__Veteran = 1,
	EPromotionMsg__Ace = 2,
	EPromotionMsg__Slaughterer = 3,
	EPromotionMsg__EPromotionMsg_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EPersonalMedalType
	enum class EPersonalMedalType : uint8_t
{
	EPersonalMedalType__None = 0,
	EPersonalMedalType__FirstKill = 1,
	EPersonalMedalType__LastKill = 2,
	EPersonalMedalType__Kill_Veteran = 3,
	EPersonalMedalType__Kill_Ace = 4,
	EPersonalMedalType__Kill_Slaughterer = 5,
	EPersonalMedalType__ContinuousKill = 6,
	EPersonalMedalType__ContinuousKill01 = 7,
	EPersonalMedalType__ContinuousKill02 = 8,
	EPersonalMedalType__ContinuousKill03 = 9,
	EPersonalMedalType__ContinuousKill04 = 10,
	EPersonalMedalType__ContinuousKill_Max = 11,
	EPersonalMedalType__Veteran = 12,
	EPersonalMedalType__Ace = 13,
	EPersonalMedalType__Slaughterer = 14,
	EPersonalMedalType__HeadShot = 15,
	EPersonalMedalType__BombDeath = 16,
	EPersonalMedalType__DestroyArmor = 17,
	EPersonalMedalType__DestroyHelmet = 18,
	EPersonalMedalType__KillWithMeleeWeapon = 19,
	EPersonalMedalType__Assist = 20,
	EPersonalMedalType__EPersonalMedalType_MAX = 21,
	};

	// Enum ShadowTrackerExtra.EAllNotifyEventType
	enum class EAllNotifyEventType : uint8_t
{
	EAllNotifyEventType__None = 0,
	EAllNotifyEventType__FirstKill = 1,
	EAllNotifyEventType__LastKill = 2,
	EAllNotifyEventType__Promotion_Slaughterer = 3,
	EAllNotifyEventType__EAllNotifyEventType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.ERenderStyle
	enum class ERenderStyle : uint8_t
{
	ERenderStyle__Default = 0,
	ERenderStyle__CLASSIC = 1,
	ERenderStyle__COLOURFUL = 2,
	ERenderStyle__REALISTIC = 3,
	ERenderStyle__SOFT = 4,
	ERenderStyle__ERenderStyle_MAX = 5,
	};

	// Enum ShadowTrackerExtra.ERenderQuality
	enum class ERenderQuality : uint8_t
{
	ERenderQuality__Default = 0,
	ERenderQuality__SMOOTH = 1,
	ERenderQuality__BALANCE = 2,
	ERenderQuality__HIGHDEFINITION = 3,
	ERenderQuality__HIGHDEFINITIONPLUS = 4,
	ERenderQuality__ERenderQuality_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EQualityType
	enum class EQualityType : uint8_t
{
	EQualityType__EMainQuality = 0,
	EQualityType__EViewDistanceQuality = 1,
	EQualityType__EShadowQuality = 2,
	EQualityType__EAntiAliasingQuality = 3,
	EQualityType__ETextureQuality = 4,
	EQualityType__EVisualEffectQuality = 5,
	EQualityType__EPostProcessingQuality = 6,
	EQualityType__EFoliageQuality = 7,
	EQualityType__EQualityType_MAX = 8,
	};

	// Enum ShadowTrackerExtra.ESkydiveState
	enum class ESkydiveState : uint8_t
{
	ESkydiveState__Skydive_None = 0,
	ESkydiveState__Skydive_Freefall = 1,
	ESkydiveState__Skydive_ParachuteDeploying = 2,
	ESkydiveState__Skydive_ParachuteDeployed = 3,
	ESkydiveState__Skydive_ParachuteCollapsing = 4,
	ESkydiveState__Skydive_MAX = 5,
	};

	// Enum ShadowTrackerExtra.ChatFlagType
	enum class EChatFlagType : uint8_t
{
	ChatFlagType__DanagerForward = 0,
	ChatFlagType__SaveMe = 1,
	ChatFlagType__Congregation = 2,
	ChatFlagType__SuppliesHere = 3,
	ChatFlagType__GetOnCar = 4,
	ChatFlagType__NeedSupplies = 5,
	ChatFlagType__ChatFlagType_MAX = 6,
	};

	// Enum ShadowTrackerExtra.ECustomCarepackageState
	enum class ECustomCarepackageState : uint8_t
{
	ECustomCarepackageState__Transporting = 0,
	ECustomCarepackageState__Falling = 1,
	ECustomCarepackageState__Landing = 2,
	ECustomCarepackageState__ECustomCarepackageState_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ETslControllerType
	enum class ETslControllerType : uint8_t
{
	ETslControllerType__Mouse = 0,
	ETslControllerType__GamePad = 1,
	ETslControllerType__Total = 2,
	ETslControllerType__ETslControllerType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EParachuteLandingSurfaceType
	enum class EParachuteLandingSurfaceType : uint8_t
{
	EParachuteLandingSurfaceType__Surface_None = 0,
	EParachuteLandingSurfaceType__Surface_Vertical = 1,
	EParachuteLandingSurfaceType__Surface_Horizontal = 2,
	EParachuteLandingSurfaceType__Surface_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ERecoveryType
	enum class ERecoveryType : uint8_t
{
	ERecovery_AddDirectly = 0,
	ERecovery_AddTo = 1,
	ERecovery_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EValueType
	enum class EValueType : uint8_t
{
	EValueType_Percentage = 0,
	EValueType_Absolute = 1,
	EValueType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EOperatorType
	enum class EOperatorType : uint8_t
{
	EOperator_Equal = 0,
	EOperator_Greater = 1,
	EOperator_Less = 2,
	EOperator_GreaterEqual = 3,
	EOperator_LessEqual = 4,
	EOperator_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EModifyBlackboardDataValueType
	enum class EModifyBlackboardDataValueType : uint8_t
{
	EModifyBlackboardDataValueType__Int = 0,
	EModifyBlackboardDataValueType__Float = 1,
	EModifyBlackboardDataValueType__Bool = 2,
	EModifyBlackboardDataValueType__String = 3,
	EModifyBlackboardDataValueType__Object = 4,
	EModifyBlackboardDataValueType__Vector3 = 5,
	EModifyBlackboardDataValueType__EModifyBlackboardDataValueType_MAX = 6,
	};

	// Enum ShadowTrackerExtra.ECheatType
	enum class ECheatType : uint8_t
{
	ECheatType__SpeedHack = 0,
	ECheatType__SpeedHack_UE = 1,
	ECheatType__SpeedHack_V2 = 2,
	ECheatType__MovementModeMismatch = 3,
	ECheatType__IgnoreWall_Hit = 4,
	ECheatType__IgnoreWall_Sight = 5,
	ECheatType__ItemPackage = 6,
	ECheatType__CarePackageMount = 7,
	ECheatType__HitLag = 8,
	ECheatType__Aimbot = 9,
	ECheatType__InvalidPelletBypass = 10,
	ECheatType__InvalidImpact = 11,
	ECheatType__InvalidImpactZ = 12,
	ECheatType__InvalidImpact_Gun_C = 13,
	ECheatType__InvalidOrigin_Gun = 14,
	ECheatType__InvalidOrigin_Melee = 15,
	ECheatType__InvalidOrigin_Punch = 16,
	ECheatType__InvalidOrigin_Throwable = 17,
	ECheatType__InvalidRange = 18,
	ECheatType__InvalidRange2 = 19,
	ECheatType__InvalidSequence = 20,
	ECheatType__InvalidAmmo = 21,
	ECheatType__InvalidReviving = 22,
	ECheatType__InvalidKick = 23,
	ECheatType__InvalidA0 = 24,
	ECheatType__InvalidB0 = 25,
	ECheatType__InvalidB1 = 26,
	ECheatType__InvalidB101 = 27,
	ECheatType__InvalidH0 = 28,
	ECheatType__InvalidOrigin_Gun_C = 29,
	ECheatType__InvalidD0 = 30,
	ECheatType__InvalidS0 = 31,
	ECheatType__InvalidS1 = 32,
	ECheatType__InvalidH1 = 33,
	ECheatType__InvalidC0 = 34,
	ECheatType__InvalidC1 = 35,
	ECheatType__InvalidC2 = 36,
	ECheatType__InvalidC3 = 37,
	ECheatType__InvalidC4 = 38,
	ECheatType__InvalidC5 = 39,
	ECheatType__InvalidC6 = 40,
	ECheatType__InvalidT0 = 41,
	ECheatType__InvalidT1 = 42,
	ECheatType__InvalidBulletRadius = 43,
	ECheatType__CHKSUM_GUN = 44,
	ECheatType__CHKSUM_PUNCH = 45,
	ECheatType__CHKSUM_MELEE = 46,
	ECheatType__CHKSUM_VEHICLE = 47,
	ECheatType__CHKSUM_A0 = 48,
	ECheatType__CHKSUM_T0 = 49,
	ECheatType__CHKSUM_S0 = 50,
	ECheatType__CHKSUM_D0 = 51,
	ECheatType__CHKSUM_V0 = 52,
	ECheatType__CHKSUM_W0 = 53,
	ECheatType__CHKSUM_T1 = 54,
	ECheatType__CHKSUM_D1 = 55,
	ECheatType__CHKSUM_CD = 56,
	ECheatType__CHKSUM_LC = 57,
	ECheatType__CHKSUM_V1 = 58,
	ECheatType__CHKSUM_P0 = 59,
	ECheatType__CHKSUM_BP = 60,
	ECheatType__CHKSUM_G0 = 61,
	ECheatType__CHKSUM_G1 = 62,
	ECheatType__VHC_RI = 63,
	ECheatType__VHC_SC = 64,
	ECheatType__VHC_MG = 65,
	ECheatType__VHC_MG_FF = 66,
	ECheatType__VHC_MG_FC = 67,
	ECheatType__VHC_MG_SW = 68,
	ECheatType__VHC_MG_OS = 69,
	ECheatType__VHC_MG_BC = 70,
	ECheatType__VHC_MGB = 71,
	ECheatType__VHC_MGB_FF = 72,
	ECheatType__VHC_MGB_FC = 73,
	ECheatType__VHC_MGB_OS = 74,
	ECheatType__VHC_MGB_BC = 75,
	ECheatType__VHC_KILL = 76,
	ECheatType__VHC_ED = 77,
	ECheatType__CP_RZ = 78,
	ECheatType__CP_RZD = 79,
	ECheatType__KGB_FP = 80,
	ECheatType__KGB_AF = 81,
	ECheatType__KGB_AH = 82,
	ECheatType__KGB_AH_NA = 83,
	ECheatType__ESP1 = 84,
	ECheatType__ESP2 = 85,
	ECheatType__ESP3 = 86,
	ECheatType__SimilarHit = 87,
	ECheatType__DoubleKill = 88,
	ECheatType__B0Log = 89,
	ECheatType__ECheatType_MAX = 90,
	};

	// Enum ShadowTrackerExtra.ELobbyLinkState
	enum class ELobbyLinkState : uint8_t
{
	ELobbyLinkState__Disconnect = 0,
	ELobbyLinkState__WaitInitialize = 1,
	ELobbyLinkState__WaitStart = 2,
	ELobbyLinkState__Gaming = 3,
	ELobbyLinkState__Finished = 4,
	ELobbyLinkState__ELobbyLinkState_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EActorCacheID
	enum class EActorCacheID : uint8_t
{
	ACID_Bullet = 0,
	ACID_BulletImpactEffect = 1,
	ACID_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EAimingPose
	enum class EAimingPose : uint8_t
{
	EAimingPose__NotAiming = 0,
	EAimingPose__ShoulderFiring = 1,
	EAimingPose__AimingDownSight = 2,
	EAimingPose__EAimingPose_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EMovement
	enum class EMovement : uint8_t
{
	EMovement__Walk = 0,
	EMovement__Run = 1,
	EMovement__Sprint = 2,
	EMovement__EMovement_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EStanceMode
	enum class EStanceMode : uint8_t
{
	STANCE_None = 0,
	STANCE_Stand = 1,
	STANCE_Crouch = 2,
	STANCE_Prone = 3,
	STANCE_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EStance
	enum class EStance : uint8_t
{
	EStance__Stand = 0,
	EStance__Prone = 1,
	EStance__Crouch = 2,
	EStance__DBNO = 3,
	EStance__EStance_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EMovementDirection
	enum class EMovementDirection : uint8_t
{
	EMovementDirection__F_Direction = 0,
	EMovementDirection__L_Direction = 1,
	EMovementDirection__R_Direction = 2,
	EMovementDirection__B_Direction = 3,
	EMovementDirection__FL_Direction = 4,
	EMovementDirection__FR_Direction = 5,
	EMovementDirection__BL_Direction = 6,
	EMovementDirection__BR_Direction = 7,
	EMovementDirection__EMovementDirection_MAX = 8,
	};

	// Enum ShadowTrackerExtra.ECustomMovementMode
	enum class ECustomMovementMode : uint8_t
{
	ECustomMovementMode__Vault = 0,
	ECustomMovementMode__ECustomMovementMode_MAX = 1,
	};

	// Enum ShadowTrackerExtra.ETextVertPos
	enum class ETextVertPos : uint8_t
{
	ETextVertPos__Top = 0,
	ETextVertPos__Center = 1,
	ETextVertPos__Bottom = 2,
	ETextVertPos__MAX = 3,
	};

	// Enum ShadowTrackerExtra.ETextHorzPos
	enum class ETextHorzPos : uint8_t
{
	ETextHorzPos__Left = 0,
	ETextHorzPos__Center = 1,
	ETextHorzPos__Right = 2,
	ETextHorzPos__MAX = 3,
	};

	// Enum ShadowTrackerExtra.ECharOperationType
	enum class ECharOperationType : uint8_t
{
	OpMove = 0,
	OpSprint = 1,
	OpJump = 2,
	OpInvalidEnum = 3,
	ECharOperationType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EOperationRunResult
	enum class EOperationRunResult : uint8_t
{
	OpRunning = 0,
	OpSuccess = 1,
	OpAutoFinish = 2,
	OpFail = 3,
	OpNotStarted = 4,
	EOperationRunResult_MAX = 5,
	};

	// Enum ShadowTrackerExtra.ETeamMatchResult
	enum class ETeamMatchResult : uint8_t
{
	ETeamMatchResult__None = 0,
	ETeamMatchResult__Win = 1,
	ETeamMatchResult__Lose = 2,
	ETeamMatchResult__Draw = 3,
	ETeamMatchResult__AbortGame_Win = 4,
	ETeamMatchResult__ETeamMatchResult_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EBattleMsg
	enum class EBattleMsg : uint8_t
{
	EBattleMsg__None = 0,
	EBattleMsg__HeadShot = 1,
	EBattleMsg__BombDeath = 2,
	EBattleMsg__DestroyArmor = 3,
	EBattleMsg__DestroyHelmet = 4,
	EBattleMsg__KillWithMeleeWeapon = 5,
	EBattleMsg__Assist = 6,
	EBattleMsg__EBattleMsg_MAX = 7,
	};

	// Enum ShadowTrackerExtra.EShutDownMsg
	enum class EShutDownMsg : uint8_t
{
	EShutDownMsg__None = 0,
	EShutDownMsg__Kill_Veteran = 1,
	EShutDownMsg__Kill_Ace = 2,
	EShutDownMsg__Kill_Slaughterer = 3,
	EShutDownMsg__EShutDownMsg_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EEventsMsg
	enum class EEventsMsg : uint8_t
{
	EEventsMsg__None = 0,
	EEventsMsg__FirstKill = 1,
	EEventsMsg__LastKill = 2,
	EEventsMsg__EEventsMsg_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ENewbieGuidePlayerCategory
	enum class ENewbieGuidePlayerCategory : uint8_t
{
	Low = 0,
	Middle = 1,
	High = 2,
	ENewbieGuidePlayerCategory_MAX = 3,
	};

	// Enum ShadowTrackerExtra.ENewbieGuideType
	enum class ENewbieGuideType : uint8_t
{
	Op = 0,
	Rule = 1,
	ENewbieGuideType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EWeaponTypeNew
	enum class EWeaponTypeNew : uint8_t
{
	EWeaponTypeNew__EWeaponTypeNew_Other = 0,
	EWeaponTypeNew__EWeaponTypeNew_Rifle = 1,
	EWeaponTypeNew__EWeaponTypeNew_SingleShotSniper = 2,
	EWeaponTypeNew__EWeaponTypeNew_BurstShotSniper = 3,
	EWeaponTypeNew__EWeaponTypeNew_Submachine = 4,
	EWeaponTypeNew__EWeaponTypeNew_ShotGun = 5,
	EWeaponTypeNew__EWeaponTypeNew_MachineGun = 6,
	EWeaponTypeNew__EWeaponTypeNew_Pistol = 7,
	EWeaponTypeNew__EWeaponTypeNew_Melee = 8,
	EWeaponTypeNew__EWeaponTypeNew_Crossbow = 9,
	EWeaponTypeNew__EWeaponTypeNew_MAX = 10,
	};

	// Enum ShadowTrackerExtra.EBulletImpactDir
	enum class EBulletImpactDir : uint8_t
{
	ImpactNormal = 0,
	ImpactShootDir = 1,
	EBulletImpactDir_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EEmoteAnimType
	enum class EEmoteAnimType : uint8_t
{
	EEmoteAnimType__EmoteFullBody = 0,
	EEmoteAnimType__EmoteUpperBody = 1,
	EEmoteAnimType__EmoteArm = 2,
	EEmoteAnimType__EEmoteAnimType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EGameMap
	enum class EGameMap : uint8_t
{
	NoMap = 0,
	SurviveRoot = 1,
	SurviveTestRoot = 2,
	SurviveRCity = 3,
	EGameMap_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EPlayerOperation
	enum class EPlayerOperation : uint8_t
{
	None = 0,
	Parachute = 1,
	shooting = 2,
	Driving = 3,
	EPlayerOperation_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EMapType
	enum class EMapType : uint8_t
{
	ENTIREMAP = 0,
	MINIMAP = 1,
	EMapType_MAX = 2,
	};

	// Enum ShadowTrackerExtra.EMeleeDamageSubType
	enum class EMeleeDamageSubType : uint8_t
{
	Fist = 0,
	Cowbar = 1,
	Pan = 2,
	Machete = 3,
	Sickle = 4,
	EMeleeDamageSubType_MAX = 5,
	};

	// Enum ShadowTrackerExtra.EDamageTypeCategory
	enum class EDamageTypeCategory : uint8_t
{
	EDamageTypeCategory__Damage_None = 0,
	EDamageTypeCategory__Damage_Instant = 1,
	EDamageTypeCategory__Damage_Gun = 2,
	EDamageTypeCategory__Damage_Melee = 3,
	EDamageTypeCategory__Damage_Punch = 4,
	EDamageTypeCategory__Damage_ZombiePunch = 5,
	EDamageTypeCategory__Damage_Groggy = 6,
	EDamageTypeCategory__Damage_BlueZone = 7,
	EDamageTypeCategory__Damage_VehicleHit = 8,
	EDamageTypeCategory__Damage_VehicleCrashHit = 9,
	EDamageTypeCategory__Damage_Molotov = 10,
	EDamageTypeCategory__Damage_Explosion = 11,
	EDamageTypeCategory__Damage_Explosion_Grenade = 12,
	EDamageTypeCategory__Damage_Explosion_RedZone = 13,
	EDamageTypeCategory__Damage_Explosion_Vehicle = 14,
	EDamageTypeCategory__Damage_Instant_Fall = 15,
	EDamageTypeCategory__Damage_Drown = 16,
	EDamageTypeCategory__Damage_BleedOut = 17,
	EDamageTypeCategory__Damage_Explosion_JerryCan = 18,
	EDamageTypeCategory__Damage_ZombieBuff = 19,
	EDamageTypeCategory__Damage_MAX = 20,
	};

	// Enum ShadowTrackerExtra.EPlayerEquipmentLevel
	enum class EPlayerEquipmentLevel : uint8_t
{
	PEL = 0,
	PEL01 = 1,
	PEL02 = 2,
	PEL_MAX = 3,
	};

	// Enum ShadowTrackerExtra.FSoundType
	enum class EFSoundType : uint8_t
{
	FSoundType__ESoundMove = 0,
	FSoundType__ESoundFire = 1,
	FSoundType__ESoundVehicle = 2,
	FSoundType__FSoundType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EScopeMeshAnimType
	enum class EScopeMeshAnimType : uint8_t
{
	EScopeMeshAnimType__ScopeMeshAnimType_Normal = 0,
	EScopeMeshAnimType__ScopeMeshAnimType_Translate = 1,
	EScopeMeshAnimType__ScopeMeshAnimType_Scope = 2,
	EScopeMeshAnimType__ScopeMeshAnimType_MAX = 3,
	};

	// Enum ShadowTrackerExtra.EBattleTextType
	enum class EBattleTextType : uint8_t
{
	EBattleTextType__EBattleTextType_Fist = 0,
	EBattleTextType__EBattleTextType_BurningBomb = 1,
	EBattleTextType__EBattleTextType_Use = 2,
	EBattleTextType__EBattleTextType_ShotAndExplode = 3,
	EBattleTextType__EBattleTextType_Vehicle = 4,
	EBattleTextType__EBattleTextType_You = 5,
	EBattleTextType__EBattleTextType_YourTeammate = 6,
	EBattleTextType__EBattleTextType_By = 7,
	EBattleTextType__EBattleTextType_HeadShot = 8,
	EBattleTextType__EBattleTextType_PutDown = 9,
	EBattleTextType__EBattleTextType_Kill = 10,
	EBattleTextType__EBattleTextType_Killed = 11,
	EBattleTextType__EBattleTextType_Le = 12,
	EBattleTextType__EBattleTextType_Because = 13,
	EBattleTextType__EBattleTextType_CriticalWounded = 14,
	EBattleTextType__EBattleTextType_HighFallingDown = 15,
	EBattleTextType__EBattleTextType_FallToGround = 16,
	EBattleTextType__EBattleTextType_InPosionArea = 17,
	EBattleTextType__EBattleTextType_TooMuchTime = 18,
	EBattleTextType__EBattleTextType_UnderWeater = 19,
	EBattleTextType__EBattleTextType_Finally = 20,
	EBattleTextType__EBattleTextType_AirAttackHit = 21,
	EBattleTextType__EBattleTextType_AccidentalDamage = 22,
	EBattleTextType__EBattleTextType_Myself = 23,
	EBattleTextType__EBattleTextType_Explosion = 24,
	EBattleTextType__EBattleTextType_MAX = 25,
	};

	// Enum ShadowTrackerExtra.EHandlePickUpActionReplicatedDataActionType
	enum class EHandlePickUpActionReplicatedDataActionType : uint8_t
{
	EHandlePickUpActionReplicatedDataActionType_None = 0,
	EHandlePickUpActionReplicatedDataActionType_PickUpWeapon = 1,
	EHandlePickUpActionReplicatedDataActionType_PickUpPlayerEquipment = 2,
	EHandlePickUpActionReplicatedDataActionType_PutDownlayerEquipment = 3,
	EHandlePickUpActionReplicatedDataActionType_MAX = 4,
	};

	// Enum ShadowTrackerExtra.EConsumeItemCategory
	enum class EConsumeItemCategory : uint8_t
	{
		EConsumeItemCategory_None = 0,
		EConsumeItemCategory_RecoverHealth = 1,
		EConsumeItemCategory_RecoverEnegy = 2,
		EConsumeItemCategory_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EConsumeItemType
	enum class EConsumeItemType : uint8_t
{
	EConsumeItemType_None = 0,
	EConsumeItemType_Bandage = 1,
	EConsumeItemType_MedicalBag = 2,
	EConsumeItemType_MedicalBox = 3,
	EConsumeItemType_EnegyDrink = 4,
	EConsumeItemType_PainKillerPills = 5,
	EConsumeItemType_Adrenaline = 6,
	EConsumeItemType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EPlayerEquipmentSlotType
	enum class EPlayerEquipmentSlotType : uint8_t
{
	EPlayerEquipmentSlotType_None = 0,
	EPlayerEquipmentSlotType_HeadEquipemtSlot = 1,
	EPlayerEquipmentSlotType_ChestEquipemtSlot = 2,
	EPlayerEquipmentSlotType_JacketEquipemtSlot = 3,
	EPlayerEquipmentSlotType_BackEquipemtSlot = 4,
	EPlayerEquipmentSlotType_LegsEquipemtSlot = 5,
	EPlayerEquipmentSlotType_FeetEquipemtSlot = 6,
	EPlayerEquipmentSlotType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EDataTableType
	enum class EDataTableType : uint8_t
{
	EDataTableType_None = 0,
	EDataTableType_PickUpGlobalDataTable = 1,
	EDataTableType_PickUpGlobalIDAndWrapperDataTable = 2,
	EDataTableType_WeaponDataTable = 3,
	EDataTableType_PlayerEquipmentDataTable = 4,
	EDataTableType_WeaponComponentDataTable = 5,
	EDataTableType_ConsumeItemDataTable = 6,
	EDataTableType_AkEventDataTable = 7,
	EDataTableType_MAX = 8,
	};
	// Enum ShadowTrackerExtra.ESurvivePickUpType
	enum class ESurvivePickUpType : uint8_t
{
	SPUT_RifileGun = 0,
	SPUT_SubmachineGun = 1,
	SPUT_SniperGun = 2,
	SPUT_Shotgun = 3,
	SPUT_Pistol = 4,
	SPUT_Helmet = 5,
	SPUT_Chest = 6,
	SPUT_Scop = 7,
	SPUT_Bandage = 8,
	SPUT_MedicalBag = 9,
	SPUT_MedicalBox = 10,
	SPUT_EnegyDrink = 11,
	SPUT_PainKillerPills = 12,
	SPUT_Adrenaline = 13,
	SPUT_MAX = 14,
	};
	// Enum ShadowTrackerExtra.ESurvivePickUpCategory
	enum class ESurvivePickUpCategory : uint8_t
{
	SPUC_MainShootWeapon = 0,
	SPUC_SubShootWeapon = 1,
	SPUC_MeleWeapon = 2,
	SPUC_Prop = 3,
	SPUC_PlayerEquipment = 4,
	SPUC_WeaponComponent = 5,
	SPUC_ConsumeItem = 6,
	SPUC_Other = 7,
	SPUC_MAX = 8,
	};
	// Enum ShadowTrackerExtra.EPostEffectBlendType
	enum class EPostEffectBlendType : uint8_t
{
	PEBT_ScanBomb = 0,
	PEBT_DeadGray = 1,
	PEBT_PropOutline = 2,
	PEBT_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EPlayerBodyPartType
	enum class EPlayerBodyPartType : uint8_t
{
	PBPT_Head = 0,
	PBPT_LeftArm = 1,
	PBPT_RightArm = 2,
	PBPT_LeftLeg = 3,
	PBPT_RightLeg = 4,
	PBPT_Body = 5,
	PBPT_MAX = 6,
	};
	// Enum ShadowTrackerExtra.EWeaponSlot
	enum class EWeaponSlot : uint8_t
{
	Primary = 0,
	Secondary = 1,
	Pistol = 2,
	EWeaponSlot_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EDrivingCheckPointState
	enum class EDrivingCheckPointState : uint8_t
{
	DCPS_Invalid = 0,
	DCPS_Unpass = 1,
	DCPS_Pass = 2,
	DCPS_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EKillcamDisplayCode
	enum class EKillcamDisplayCode : uint8_t
{
	EKillcamDisplayCode__NotVisible = 0,
	EKillcamDisplayCode__OptionDisabled = 1,
	EKillcamDisplayCode__Recording = 2,
	EKillcamDisplayCode__Playable = 3,
	EKillcamDisplayCode__Replay = 4,
	EKillcamDisplayCode__FailToLoad = 5,
	EKillcamDisplayCode__DemoFailure = 6,
	EKillcamDisplayCode__DetectedUnusualMovement = 7,
	EKillcamDisplayCode__EKillcamDisplayCode_MAX = 8,
	};
	// Enum ShadowTrackerExtra.EWidgetShowType
	enum class EWidgetShowType : uint8_t
{
	EWidgetShowType__Show = 0,
	EWidgetShowType__Hide = 1,
	EWidgetShowType__Toggle = 2,
	EWidgetShowType__EWidgetShowType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EReleaseToFireType
	enum class EReleaseToFireType : uint8_t
{
	EReleaseToFireType__RELEASEFIRE_NONE = 0,
	EReleaseToFireType__RELEASEFIRE_SHOTGUN = 1,
	EReleaseToFireType__RELEASEFIRE_SNIPER = 2,
	EReleaseToFireType__RELEASEFIRE_BRUST = 3,
	EReleaseToFireType__RELEASEFIRE_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EWeaponFireMode
	enum class EWeaponFireMode : uint8_t
{
	WeaponFireMode_Single = 0,
	WeaponFireMode_Burst = 1,
	WeaponFireMode_Auto = 2,
	WeaponFireMode_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ShootWeaponAnimType
	enum class EShootWeaponAnimType : uint8_t
{
	SWAT_Shoot = 0,
	SWAT_NoneShoot = 1,
	SWAT_Reload = 2,
	SWAT_IdleToNoneIdle = 3,
	SWAT_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ESTEWeaponHoldType
	enum class ESTEWeaponHoldType : uint8_t
{
	ESTEWeaponHoldType__Hand = 0,
	ESTEWeaponHoldType__Rifle = 1,
	ESTEWeaponHoldType__Pistol = 2,
	ESTEWeaponHoldType__Melee = 3,
	ESTEWeaponHoldType__ESTEWeaponHoldType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EAirborne2
	enum class EAirborne2 : uint8_t
{
	Airborne = 0,
	Freefall = 1,
	Opening = 2,
	Landing = 3,
	EAirborne2_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EFlareDeploymentType
	enum class EFlareDeploymentType : uint8_t
{
	EFlareDeploymentType__Deploy_None = 0,
	EFlareDeploymentType__Deploy_InWhite = 1,
	EFlareDeploymentType__Deploy_InBlue = 2,
	EFlareDeploymentType__Deploy_Outside = 3,
	EFlareDeploymentType__Deploy_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EWeaponGripLeftHand
	enum class EWeaponGripLeftHand : uint8_t
{
	EWeaponGripLeftHand__NormalRifle = 0,
	EWeaponGripLeftHand__Foregrip1 = 1,
	EWeaponGripLeftHand__Foregrip2 = 2,
	EWeaponGripLeftHand__Thompson = 3,
	EWeaponGripLeftHand__EWeaponGripLeftHand_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EWonderfulCutOutputType
	enum class EWonderfulCutOutputType : uint8_t
{
	WonderfulCutOutputType_None = 0,
	WonderfulCutOutputType_ChickenDinner = 1,
	WonderfulCutOutputType_ShootKill = 2,
	WonderfulCutOutputType_ShootLastBreath = 3,
	WonderfulCutOutputType_ShootDamage = 4,
	WonderfulCutOutputType_MeleeKill = 5,
	WonderfulCutOutputType_MeleeLastBreath = 6,
	WonderfulCutOutputType_GrenadeKill = 7,
	WonderfulCutOutputType_GrenadeLastBreath = 8,
	WonderfulCutOutputType_VehicleKill = 9,
	WonderfulCutOutputType_VehicleLastBreath = 10,
	WonderfulCutOutputType_MAX = 11,
	};
	// Enum ShadowTrackerExtra.EWonderfulCutShootDamageType
	enum class EWonderfulCutShootDamageType : uint8_t
{
	WonderfulCutHurtType_None = 0,
	WonderfulCutHurtType_Kill = 1,
	WonderfulCutHurtType_LastBreath = 2,
	WonderfulCutHurtType_Hurt = 3,
	WonderfulCutHurtType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EWonderfulCutCaptureType
	enum class EWonderfulCutCaptureType : uint8_t
{
	WonderfulCutCaptureType_None = 0,
	WonderfulCutCaptureType_ChickenDinner = 1,
	WonderfulCutCaptureType_Circle = 2,
	WonderfulCutCaptureType_Vehicle = 3,
	WonderfulCutCaptureType_Grenade = 4,
	WonderfulCutCaptureType_Melee = 5,
	WonderfulCutCaptureType_ShootDamage = 6,
	WonderfulCutCaptureType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.ECameraDataType
	enum class ECameraDataType : uint8_t
{
	ECameraDataType_Stand = 0,
	ECameraDataType_Crouch = 1,
	ECameraDataType_Prone = 2,
	ECameraDataType_Indoor = 3,
	ECameraDataType_LeanLeft = 4,
	ECameraDataType_LeanRight = 5,
	ECameraDataType_Vehicle = 6,
	ECameraDataType_NearDeath = 7,
	ECameraDataType_PeekLeft = 8,
	ECameraDataType_PeekRight = 9,
	ECameraDataType_IndoorLowerCameraStand = 10,
	ECameraDataType_IndoorLowerCameraCrouch = 11,
	ECameraDataType_IndoorLowerCameraProne = 12,
	ECameraDataType_ShoulderFiring = 13,
	ECameraDataType_PeekLeftAndShoulderFiring = 14,
	ECameraDataType_PeekRightAndShoulderFiring = 15,
	ECameraDataType_Max = 16,
	};
	// Enum ShadowTrackerExtra.EDoorType
	enum class EDoorType : uint8_t
{
	EDoorType__EDoorType_NormalDoor = 0,
	EDoorType__EDoorType_DoubleDoor = 1,
	EDoorType__EDoorType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EFlashBangDebuffCurveValueTypes
	enum class EFlashBangDebuffCurveValueTypes : uint8_t
{
	EFlashBangDebuffCurveValueTypes__Blindness_Duration_Front = 0,
	EFlashBangDebuffCurveValueTypes__Blindness_Duration_Back = 1,
	EFlashBangDebuffCurveValueTypes__Tinnitus_Level = 2,
	EFlashBangDebuffCurveValueTypes__EFlashBangDebuffCurveValueTypes_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EPlayerAuthState
	enum class EPlayerAuthState : uint8_t
{
	EPlayerAuthState__None = 0,
	EPlayerAuthState__Login = 1,
	EPlayerAuthState__Logout = 2,
	EPlayerAuthState__EPlayerAuthState_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EPlayerHurtAnimType
	enum class EPlayerHurtAnimType : uint8_t
{
	EPlayerHurtAnim_None = 0,
	EPlayerHurtAnim_Point = 1,
	EPlayerHurtAnim_Melee = 2,
	EPlayerHurtAnim_Max = 3,
	};
	// Enum ShadowTrackerExtra.ELoadingScreenType
	enum class ELoadingScreenType : uint8_t
{
	ELoadingScreenType__NONE = 0,
	ELoadingScreenType__ICE_BRAKE = 1,
	ELoadingScreenType__RULE_SET = 2,
	ELoadingScreenType__WEAPON = 3,
	ELoadingScreenType__ATTACHMENT = 4,
	ELoadingScreenType__EQUIPMENT = 5,
	ELoadingScreenType__ITEM = 6,
	ELoadingScreenType__VEHICLE = 7,
	ELoadingScreenType__SYSTEM = 8,
	ELoadingScreenType__DEFAULT = 9,
	ELoadingScreenType__EXPOSE_WITH_HIGHEST_PRIORITY = 10,
	ELoadingScreenType__ELoadingScreenType_MAX = 11,
	};
	// Enum ShadowTrackerExtra.ERaycastDirection
	enum class ERaycastDirection : uint8_t
{
	ERaycastDirection__Forward = 0,
	ERaycastDirection__Down_45_Degrees = 1,
	ERaycastDirection__Down = 2,
	ERaycastDirection__ERaycastDirection_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAvatarAttachmentSlot
	enum class EAvatarAttachmentSlot : uint8_t
{
	EAvatarAttachmentSlot__NONE = 0,
	EAvatarAttachmentSlot__Magazine = 1,
	EAvatarAttachmentSlot__MAX = 2,
	};
	// Enum ShadowTrackerExtra.EReplaceSlot
	enum class EReplaceSlot : uint8_t
{
	EReplaceSlot__EReplaceType_NONE = 0,
	EReplaceSlot__EReplaceType_HeadEquipemtSlot = 1,
	EReplaceSlot__EReplaceType_HairEquipemtSlot = 2,
	EReplaceSlot__EReplaceType_HatEquipemtSlot = 3,
	EReplaceSlot__EReplaceType_FaceEquipemtSlot = 4,
	EReplaceSlot__EReplaceType_ClothesEquipemtSlot = 5,
	EReplaceSlot__EReplaceType_PantsEquipemtSlot = 6,
	EReplaceSlot__EReplaceType_ShoesEquipemtSlot = 7,
	EReplaceSlot__EReplaceType_BackpackEquipemtSlot = 8,
	EReplaceSlot__EReplaceType_HelmetEquipemtSlot = 9,
	EReplaceSlot__EReplaceType_ArmorEquipemtSlot = 10,
	EReplaceSlot__EReplaceType_ParachuteEquipemtSlot = 11,
	EReplaceSlot__EReplaceType_VeilSlot = 12,
	EReplaceSlot__EReplaceType_HoodSlot = 13,
	EReplaceSlot__EReplaceType_StockingSlot = 14,
	EReplaceSlot__EReplaceType_BootsSlot = 15,
	EReplaceSlot__EReplaceType_MAX = 16,
	};
	// Enum ShadowTrackerExtra.ETslParticleCullType
	enum class ETslParticleCullType : uint8_t
{
	ETslParticleCullType__None = 0,
	ETslParticleCullType__Distance = 1,
	ETslParticleCullType__Frustum = 2,
	ETslParticleCullType__LastRenderedTime = 3,
	ETslParticleCullType__SameTransform = 4,
	ETslParticleCullType__NearbyTransform = 5,
	ETslParticleCullType__DistAndFrustumAndNear = 6,
	ETslParticleCullType__All = 7,
	ETslParticleCullType__ETslParticleCullType_MAX = 8,
	};
	// Enum ShadowTrackerExtra.ETslParticleGroupPriority
	enum class ETslParticleGroupPriority : uint8_t
{
	ETslParticleGroupPriority__High = 0,
	ETslParticleGroupPriority__Low = 1,
	ETslParticleGroupPriority__ETslParticleGroupPriority_MAX = 2,
	};
	// Enum ShadowTrackerExtra.ECustomDamageZoneType
	enum class ECustomDamageZoneType : uint8_t
{
	ECustomDamageZoneType__Head = 0,
	ECustomDamageZoneType__Arms = 1,
	ECustomDamageZoneType__Legs = 2,
	ECustomDamageZoneType__UpperBody = 3,
	ECustomDamageZoneType__LowerBody = 4,
	ECustomDamageZoneType__ECustomDamageZoneType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.ECustomDamageWeaponClass
	enum class ECustomDamageWeaponClass : uint8_t
{
	ECustomDamageWeaponClass__Bullet = 0,
	ECustomDamageWeaponClass__Melee = 1,
	ECustomDamageWeaponClass__ECustomDamageWeaponClass_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EItemSpotType
	enum class EItemSpotType : uint8_t
{
	EItemSpotType__TypeA = 0,
	EItemSpotType__TypeB = 1,
	EItemSpotType__TypeC = 2,
	EItemSpotType__TypeD = 3,
	EItemSpotType__TypeE = 4,
	EItemSpotType__TypeF = 5,
	EItemSpotType__EItemSpotType_MAX = 6,
	};
	// Enum ShadowTrackerExtra.EEquipSlotID
	enum class EEquipSlotID : uint8_t
{
	EEquipSlotID__Head = 0,
	EEquipSlotID__Eyes = 1,
	EEquipSlotID__Mask = 2,
	EEquipSlotID__Torso = 3,
	EEquipSlotID__TorsoArmor = 4,
	EEquipSlotID__Outer = 5,
	EEquipSlotID__Backpack = 6,
	EEquipSlotID__Hands = 7,
	EEquipSlotID__Legs = 8,
	EEquipSlotID__Feet = 9,
	EEquipSlotID__Belt = 10,
	EEquipSlotID__WeaponPrimary = 11,
	EEquipSlotID__WeaponSecondary = 12,
	EEquipSlotID__WeaponMelee = 13,
	EEquipSlotID__WeaponThrowable = 14,
	EEquipSlotID__MaxOrNone = 15,
	EEquipSlotID__EEquipSlotID_MAX = 16,
	};
	// Enum ShadowTrackerExtra.EAttackType
	enum class EAttackType : uint8_t
{
	EAttackType__None = 0,
	EAttackType__Weapon = 1,
	EAttackType__VehicleCrash = 2,
	EAttackType__VehicleExplosion = 3,
	EAttackType__Fall = 4,
	EAttackType__BlueZone = 5,
	EAttackType__RedZone = 6,
	EAttackType__EAttackType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EPlayerMoveType
	enum class EPlayerMoveType : uint8_t
{
	EPlayerMoveType__OnFoot = 0,
	EPlayerMoveType__OnSwim = 1,
	EPlayerMoveType__OnVehicle = 2,
	EPlayerMoveType__OnParachute = 3,
	EPlayerMoveType__OnFreefall = 4,
	EPlayerMoveType__EPlayerMoveType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.EPopupStyle
	enum class EPopupStyle : uint8_t
{
	EPopupStyle__Ok_Cancel = 0,
	EPopupStyle__Ok = 1,
	EPopupStyle__Yes_No = 2,
	EPopupStyle__EPopupStyle_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EVHSeatGUIType
	enum class EVHSeatGUIType : uint8_t
{
	EVHSeatGUIType_NoSeat = 0,
	EVHSeatGUIType_Empty = 1,
	EVHSeatGUIType_Other = 2,
	EVHSeatGUIType_Self = 3,
	EVHSeatGUIType_Max = 4,
	};
	// Enum ShadowTrackerExtra.EVehicleAnimType
	enum class EVehicleAnimType : uint8_t
{
	EVehicleAnimType__DefaultDriver = 0,
	EVehicleAnimType__DefaultPassenger = 1,
	EVehicleAnimType__BuggyDriver = 2,
	EVehicleAnimType__BuggyPassenger = 3,
	EVehicleAnimType__DaciaDriver = 4,
	EVehicleAnimType__DaciaPassengerFR = 5,
	EVehicleAnimType__DaciaPassengerBL = 6,
	EVehicleAnimType__DaciaPassengerBC = 7,
	EVehicleAnimType__DaciaPassengerBR = 8,
	EVehicleAnimType__UazDriver = 9,
	EVehicleAnimType__UazPassengerFR = 10,
	EVehicleAnimType__UazPassengerBL = 11,
	EVehicleAnimType__UazPassengerBC = 12,
	EVehicleAnimType__UazPassengerBR = 13,
	EVehicleAnimType__BoatDriver = 14,
	EVehicleAnimType__BoatPassengerFR = 15,
	EVehicleAnimType__BoatPassengerBL = 16,
	EVehicleAnimType__BoatPassengerBC = 17,
	EVehicleAnimType__BoatPassengerBR = 18,
	EVehicleAnimType__MotoDriver = 19,
	EVehicleAnimType__MotoPassenger = 20,
	EVehicleAnimType__MotoSidecar = 21,
	EVehicleAnimType__MotoDriverSidecar = 22,
	EVehicleAnimType__MotoPassengerSidecar = 23,
	EVehicleAnimType__AircraftPassenger = 24,
	EVehicleAnimType__JetskiDriver = 25,
	EVehicleAnimType__JetskiPassenger = 26,
	EVehicleAnimType__PickupTruckDriver = 27,
	EVehicleAnimType__PickupTruckPassengerFR = 28,
	EVehicleAnimType__PickupTruckPassengerBL_Open = 29,
	EVehicleAnimType__PickupTruckPassengerBR_Open = 30,
	EVehicleAnimType__PickupTruckPassengerBL_Closed = 31,
	EVehicleAnimType__PickupTruckPassengerBR_Closed = 32,
	EVehicleAnimType__MinibusDriver = 33,
	EVehicleAnimType__MinibusPassengerFR = 34,
	EVehicleAnimType__MinibusPassengerML = 35,
	EVehicleAnimType__MinibusPassengerMR = 36,
	EVehicleAnimType__MinibusPassengerBL = 37,
	EVehicleAnimType__MinibusPassengerBR = 38,
	EVehicleAnimType__MiradoDriver = 39,
	EVehicleAnimType__MiradoFR = 40,
	EVehicleAnimType__MiradoRL = 41,
	EVehicleAnimType__MiradoRR = 42,
	EVehicleAnimType__ScooterPassenger = 43,
	EVehicleAnimType__TukDriver = 44,
	EVehicleAnimType__RonyDriver = 45,
	EVehicleAnimType__Snowmobile_Passenger = 46,
	EVehicleAnimType__YetiDriver = 47,
	EVehicleAnimType__YetiPassenger = 48,
	EVehicleAnimType__LadaNivaDriver = 49,
	EVehicleAnimType__BRDM_Driver = 50,
	EVehicleAnimType__BRDM_Passenger = 51,
	EVehicleAnimType__EVehicleAnimType_MAX = 52,
	};
	// Enum ShadowTrackerExtra.ETracerDisplayMode
	enum class ETracerDisplayMode : uint8_t
{
	ETracerDisplayMode__TracerDM_None = 0,
	ETracerDisplayMode__TracerDM_Particle = 1,
	ETracerDisplayMode__TracerDM_Mesh = 2,
	ETracerDisplayMode__TracerDM_Billboard = 3,
	ETracerDisplayMode__TracerDM_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ERadioMessageCategory
	enum class ERadioMessageCategory : uint8_t
{
	ERadioMessageCategory__Affirmative = 0,
	ERadioMessageCategory__ThankYou = 1,
	ERadioMessageCategory__NeedMed = 2,
	ERadioMessageCategory__Negative = 3,
	ERadioMessageCategory__Sorry = 4,
	ERadioMessageCategory__NeedAmmo = 5,
	ERadioMessageCategory__EnemySpotted = 6,
	ERadioMessageCategory__ItemSpotted = 7,
	ERadioMessageCategory__Ping = 8,
	ERadioMessageCategory__HelpMe = 9,
	ERadioMessageCategory__Max = 10,
	};
	// Enum ShadowTrackerExtra.EEventLogCategory
	enum class EEventLogCategory : uint8_t
{
	EEventLogCategory__FirstBlood = 0,
	EEventLogCategory__LastBlood = 1,
	EEventLogCategory__ShutDown_Level1 = 2,
	EEventLogCategory__ShutDown_Level2 = 3,
	EEventLogCategory__ShutDown_Level3 = 4,
	EEventLogCategory__KillingSpree_01 = 5,
	EEventLogCategory__KillingSpree_02 = 6,
	EEventLogCategory__KillingSpree_03 = 7,
	EEventLogCategory__KillingSpree_04 = 8,
	EEventLogCategory__KillingSpree_05 = 9,
	EEventLogCategory__KillingSpree_06 = 10,
	EEventLogCategory__KillingSpree_07 = 11,
	EEventLogCategory__KillingSpree_08 = 12,
	EEventLogCategory__KillingSpree_09 = 13,
	EEventLogCategory__KillingSpree = 14,
	EEventLogCategory__LevelUp = 15,
	EEventLogCategory__LevelUp01 = 16,
	EEventLogCategory__LevelUp02 = 17,
	EEventLogCategory__HelmetBreak = 18,
	EEventLogCategory__ArmorBreak = 19,
	EEventLogCategory__EEventLogCategory_MAX = 20,
	};
	// Enum ShadowTrackerExtra.EForceRefreshDummy
	enum class EForceRefreshDummy : uint8_t
{
	EForceRefreshDummy__Refresh1 = 0,
	EForceRefreshDummy__Refresh2 = 1,
	EForceRefreshDummy__EForceRefreshDummy_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EViewModeCategory
	enum class EViewModeCategory : uint8_t
{
	EViewModeCategory__None = 0,
	EViewModeCategory__Weapon = 1,
	EViewModeCategory__Parachute = 2,
	EViewModeCategory__Character = 3,
	EViewModeCategory__Vehicle = 4,
	EViewModeCategory__EViewModeCategory_MAX = 5,
	};
	// Enum ShadowTrackerExtra.ESystemMenuButtonType
	enum class ESystemMenuButtonType : uint8_t
{
	ESystemMenuButtonType__RESUME = 0,
	ESystemMenuButtonType__SETTINGS = 1,
	ESystemMenuButtonType__TEAM_MANAGEMENT = 2,
	ESystemMenuButtonType__KEY_GUIDE = 3,
	ESystemMenuButtonType__RESTART_LOBBY = 4,
	ESystemMenuButtonType__LEAVE_MATCH = 5,
	ESystemMenuButtonType__EXIT_TO_DESKTOP = 6,
	ESystemMenuButtonType__ESystemMenuButtonType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.ERankGuideType
	enum class ERankGuideType : uint8_t
{
	ERankGuideType__ForElementaryRank = 0,
	ERankGuideType__ForExpertRank = 1,
	ERankGuideType__ERankGuideType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EUserRank
	enum class EUserRank : uint8_t
{
	EUserRank__ElementaryRank = 0,
	EUserRank__IntermediateRank = 1,
	EUserRank__HighRank = 2,
	EUserRank__ExpertRank = 3,
	EUserRank__EUserRank_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EProjectileParticleClass
	enum class EProjectileParticleClass : uint8_t
{
	EProjectileParticleClass__PPC_None = 0,
	EProjectileParticleClass__PPC_Frag = 1,
	EProjectileParticleClass__PPC_Flash = 2,
	EProjectileParticleClass__PPC_Smoke = 3,
	EProjectileParticleClass__PPC_Molotov = 4,
	EProjectileParticleClass__PPC_Other = 5,
	EProjectileParticleClass__PPC_MAX = 6,
	};
	// Enum ShadowTrackerExtra.EReticleType
	enum class EReticleType : uint8_t
{
	EReticleType__RedDot = 0,
	EReticleType__HoloSight = 1,
	EReticleType__Scope2x = 2,
	EReticleType__Scope3x = 3,
	EReticleType__Scope4x = 4,
	EReticleType__Scope6x = 5,
	EReticleType__Scope8x = 6,
	EReticleType__EReticleType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EKeyHintType
	enum class EKeyHintType : uint8_t
{
	EKeyHintType__Menu = 0,
	EKeyHintType__Parachuting = 1,
	EKeyHintType__Character = 2,
	EKeyHintType__Driver = 3,
	EKeyHintType__Driver_NoBoost = 4,
	EKeyHintType__Driver_Bike = 5,
	EKeyHintType__Rider = 6,
	EKeyHintType__WeaponUse = 7,
	EKeyHintType__WeaponChange = 8,
	EKeyHintType__ADS = 9,
	EKeyHintType__Aim = 10,
	EKeyHintType__ADS_8x15x = 11,
	EKeyHintType__ADS_6x = 12,
	EKeyHintType__ADS_1x2x3x = 13,
	EKeyHintType__ADS_IronSight = 14,
	EKeyHintType__Throwing = 15,
	EKeyHintType__Heal = 16,
	EKeyHintType__Swimming = 17,
	EKeyHintType__TeamSpectating = 18,
	EKeyHintType__KillerSpectating = 19,
	EKeyHintType__WorldMap = 20,
	EKeyHintType__None = 21,
	EKeyHintType__FreefallNew = 22,
	EKeyHintType__ParachuteNew = 23,
	EKeyHintType__EKeyHintType_MAX = 24,
	};
	// Enum ShadowTrackerExtra.EObserverOutlineType
	enum class EObserverOutlineType : uint8_t
{
	SpectatedCharacter = 0,
	SpectatedCharacterTeam = 1,
	SpectatedCharacterEnemy = 2,
	WithoutSpectatedCharacter = 3,
	WithoutSpectatedTeamCharacter = 4,
	InteractionFocusingColor = 5,
	EObserverOutlineType_MAX = 6,
	};
	// Enum ShadowTrackerExtra.EOptionExposeType
	enum class EOptionExposeType : uint8_t
{
	EOptionExposeType__All = 0,
	EOptionExposeType__PcOnly = 1,
	EOptionExposeType__XBoxOnly = 2,
	EOptionExposeType__PS4Only = 3,
	EOptionExposeType__PcAndXBox = 4,
	EOptionExposeType__PcAndPS4 = 5,
	EOptionExposeType__XBoxAndPS4 = 6,
	EOptionExposeType__None = 7,
	EOptionExposeType__EOptionExposeType_MAX = 8,
	};
	// Enum ShadowTrackerExtra.EWeatherChange
	enum class EWeatherChange : uint8_t
{
	EWeatherChange__NoChange = 0,
	EWeatherChange__Rainy = 1,
	EWeatherChange__Foggy = 2,
	EWeatherChange__EWeatherChange_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EMinimapColorType
	enum class EMinimapColorType : uint8_t
{
	EMinimapColorType__DESATURATED = 0,
	EMinimapColorType__SATURATED = 1,
	EMinimapColorType__EMinimapColorType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EDamageZoneType
	enum class EDamageZoneType : uint8_t
{
	EDamageZoneType__Head = 0,
	EDamageZoneType__Torso = 1,
	EDamageZoneType__Arm = 2,
	EDamageZoneType__Pelvis = 3,
	EDamageZoneType__Leg = 4,
	EDamageZoneType__EDamageZoneType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.ETslWidgetCreationMethod
	enum class ETslWidgetCreationMethod : uint8_t
{
	ETslWidgetCreationMethod__CreateOnInit = 0,
	ETslWidgetCreationMethod__OnDemand = 1,
	ETslWidgetCreationMethod__OnDemandOnOnlyPC = 2,
	ETslWidgetCreationMethod__OnDemandOnOnlyConsole = 3,
	ETslWidgetCreationMethod__ETslWidgetCreationMethod_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ERedZoneGenerateType
	enum class ERedZoneGenerateType : uint8_t
{
	ERedZoneGenerateType__None = 0,
	ERedZoneGenerateType__Uniform_Distribution = 1,
	ERedZoneGenerateType__Ringtaw = 2,
	ERedZoneGenerateType__Outsider = 3,
	ERedZoneGenerateType__RingtawOrOutsider = 4,
	ERedZoneGenerateType__ERedZoneGenerateType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.ETslHudType
	enum class ETslHudType : uint8_t
{
	ETslHudType__None = 0,
	ETslHudType__CharacterHud = 1,
	ETslHudType__SpectatorHud = 2,
	ETslHudType__ObserverHud = 3,
	ETslHudType__ReplayHud = 4,
	ETslHudType__ETslHudType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.EAnimatableCustomizableTypes
	enum class EAnimatableCustomizableTypes : uint8_t
{
	EAnimatableCustomizableTypes__Hair = 0,
	EAnimatableCustomizableTypes__Outer = 1,
	EAnimatableCustomizableTypes__Legs = 2,
	EAnimatableCustomizableTypes__EAnimatableCustomizableTypes_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EGameEndState
	enum class EGameEndState : uint8_t
{
	EGameEndState__None = 0,
	EGameEndState__CereMony = 1,
	EGameEndState__Cinematic = 2,
	EGameEndState__MatchFinish = 3,
	EGameEndState__EGameEndState_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ELobbyBlurChangingStates
	enum class ELobbyBlurChangingStates : uint8_t
{
	ELobbyBlurChangingStates__AlwaysOff = 0,
	ELobbyBlurChangingStates__AlwaysOn = 1,
	ELobbyBlurChangingStates__ELobbyBlurChangingStates_MAX = 2,
	};
	// Enum ShadowTrackerExtra.ELobbyCameraStates
	enum class ELobbyCameraStates : uint8_t
{
	ELobbyCameraStates__XBox_Home = 0,
	ELobbyCameraStates__Main = 1,
	ELobbyCameraStates__Main01 = 2,
	ELobbyCameraStates__Menu = 3,
	ELobbyCameraStates__Custom = 4,
	ELobbyCameraStates__Custom01 = 5,
	ELobbyCameraStates__EventPass_Milestone = 6,
	ELobbyCameraStates__EventPass_Milestone01 = 7,
	ELobbyCameraStates__EventPass_Missions = 8,
	ELobbyCameraStates__ViewMode_Character = 9,
	ELobbyCameraStates__ViewMode_Weapon = 10,
	ELobbyCameraStates__ViewMode_Parachute = 11,
	ELobbyCameraStates__EventPass_Milestone_0_Particle = 12,
	ELobbyCameraStates__None = 13,
	ELobbyCameraStates__ELobbyCameraStates_MAX = 14,
	};
	// Enum ShadowTrackerExtra.EUiShowType
	enum class EUiShowType : uint8_t
{
	EUiShowType__AlwaysShow = 0,
	EUiShowType__TpsOnlyShow = 1,
	EUiShowType__FpsOnlyShow = 2,
	EUiShowType__AlwaysHide = 3,
	EUiShowType__EUiShowType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EParachuteCutoffState
	enum class EParachuteCutoffState : uint8_t
{
	EParachuteCutoffState__Cutoff_None = 0,
	EParachuteCutoffState__Cutoff_Manual = 1,
	EParachuteCutoffState__Cutoff_Automatic = 2,
	EParachuteCutoffState__Cutoff_Ready = 3,
	EParachuteCutoffState__Cutoff_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EGamepadInputResponseTypes
	enum class EGamepadInputResponseTypes : uint8_t
{
	EGamepadInputResponseTypes__Pressed = 0,
	EGamepadInputResponseTypes__Released = 1,
	EGamepadInputResponseTypes__Tap = 2,
	EGamepadInputResponseTypes__Hold = 3,
	EGamepadInputResponseTypes__DoubleTap = 4,
	EGamepadInputResponseTypes__EGamepadInputResponseTypes_MAX = 5,
	};
	// Enum ShadowTrackerExtra.EGamepadPresets
	enum class EGamepadPresets : uint8_t
{
	EGamepadPresets__Preset = 0,
	EGamepadPresets__Preset01 = 1,
	EGamepadPresets__Preset_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EKeyGuideShowCases
	enum class EKeyGuideShowCases : uint8_t
{
	EKeyGuideShowCases__Reload = 0,
	EKeyGuideShowCases__ExitVehicle = 1,
	EKeyGuideShowCases__EKeyGuideShowCases_MAX = 2,
	};
	// Enum ShadowTrackerExtra.ETslInputModes
	enum class ETslInputModes : uint8_t
{
	ETslInputModes__Toggle = 0,
	ETslInputModes__Hold = 1,
	ETslInputModes__DoubleTap = 2,
	ETslInputModes__ETslInputModes_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EGameplayClientReplay
	enum class EGameplayClientReplay : uint8_t
{
	EGameplayClientReplay__Replay = 0,
	EGameplayClientReplay__Killcam = 1,
	EGameplayClientReplay__EGameplayClientReplay_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EGameplayFunctionalities
	enum class EGameplayFunctionalities : uint8_t
{
	EGameplayFunctionalities__FreeLookInterp = 0,
	EGameplayFunctionalities__EGameplayFunctionalities_MAX = 1,
	};
	// Enum ShadowTrackerExtra.EInputModeSettingActions
	enum class EInputModeSettingActions : uint8_t
{
	EInputModeSettingActions__Crouch = 0,
	EInputModeSettingActions__Prone = 1,
	EInputModeSettingActions__Walk = 2,
	EInputModeSettingActions__Sprint = 3,
	EInputModeSettingActions__HoldRotation = 4,
	EInputModeSettingActions__HoldBreath = 5,
	EInputModeSettingActions__Peek = 6,
	EInputModeSettingActions__Map = 7,
	EInputModeSettingActions__ADS = 8,
	EInputModeSettingActions__Aim = 9,
	EInputModeSettingActions__HoldAngled = 10,
	EInputModeSettingActions__EInputModeSettingActions_MAX = 11,
	};
	// Enum ShadowTrackerExtra.EKeyBindingSlot
	enum class EKeyBindingSlot : uint8_t
{
	EKeyBindingSlot__FirstKey = 0,
	EKeyBindingSlot__SecondKey = 1,
	EKeyBindingSlot__EKeyBindingSlot_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EReportedSessionType
	enum class EReportedSessionType : uint8_t
{
	EReportedSessionType__PublicOrCustomGame = 0,
	EReportedSessionType__Killcam = 1,
	EReportedSessionType__Replay = 2,
	EReportedSessionType__EReportedSessionType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ECarePackageIconType
	enum class ECarePackageIconType : uint8_t
{
	ECarePackageIconType__Normal = 0,
	ECarePackageIconType__Flying = 1,
	ECarePackageIconType__Opened = 2,
	ECarePackageIconType__ECarePackageIconType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ECharacterIconType
	enum class ECharacterIconType : uint8_t
{
	ECharacterIconType__Normal = 0,
	ECharacterIconType__Vehicle = 1,
	ECharacterIconType__Parachute = 2,
	ECharacterIconType__Die = 3,
	ECharacterIconType__Groggy = 4,
	ECharacterIconType__Quitter = 5,
	ECharacterIconType__Observer = 6,
	ECharacterIconType__ECharacterIconType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EReportUiType
	enum class EReportUiType : uint8_t
{
	EReportUiType__Normal = 0,
	EReportUiType__Respawn = 1,
	EReportUiType__EReportUiType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.ECharacterNegativeEffects
	enum class ECharacterNegativeEffects : uint8_t
{
	ECharacterNegativeEffects__Blind = 0,
	ECharacterNegativeEffects__Burning = 1,
	ECharacterNegativeEffects__Total = 2,
	ECharacterNegativeEffects__ECharacterNegativeEffects_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EZombieModePlayerState
	enum class EZombieModePlayerState : uint8_t
{
	EZombieModePlayerState__None = 0,
	EZombieModePlayerState__Human = 1,
	EZombieModePlayerState__ReadyToRevive = 2,
	EZombieModePlayerState__Zombie = 3,
	EZombieModePlayerState__EZombieModePlayerState_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ETeamChangeZombieMode
	enum class ETeamChangeZombieMode : uint8_t
{
	ETeamChangeZombieMode__None = 0,
	ETeamChangeZombieMode__LeaveTeam = 1,
	ETeamChangeZombieMode__JoinTeam = 2,
	ETeamChangeZombieMode__ETeamChangeZombieMode_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ETSLValueType
	enum class ETSLValueType : uint8_t
{
	ETSLValueType__Float = 0,
	ETSLValueType__Int = 1,
	ETSLValueType__String = 2,
	ETSLValueType__Bool = 3,
	ETSLValueType__ETSLValueType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ENearClippingLevel
	enum class ENearClippingLevel : uint8_t
{
	ENearClippingLevel__Default = 0,
	ENearClippingLevel__Low = 1,
	ENearClippingLevel__Middle = 2,
	ENearClippingLevel__High = 3,
	ENearClippingLevel__ENearClippingLevel_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EThingSpotGroupType
	enum class EThingSpotGroupType : uint8_t
{
	EThingSpotGroupType__GroupA = 0,
	EThingSpotGroupType__GroupB = 1,
	EThingSpotGroupType__GroupC = 2,
	EThingSpotGroupType__GroupD = 3,
	EThingSpotGroupType__GroupE = 4,
	EThingSpotGroupType__GroupF = 5,
	EThingSpotGroupType__GroupG = 6,
	EThingSpotGroupType__GroupH = 7,
	EThingSpotGroupType__GroupI = 8,
	EThingSpotGroupType__GroupJ = 9,
	EThingSpotGroupType__GroupK = 10,
	EThingSpotGroupType__GroupL = 11,
	EThingSpotGroupType__GroupM = 12,
	EThingSpotGroupType__GroupN = 13,
	EThingSpotGroupType__EThingSpotGroupType_MAX = 14,
	};
	// Enum ShadowTrackerExtra.EPhysMaterialType
	enum class EPhysMaterialType : uint8_t
{
	EPhysMaterialType__Unknown = 0,
	EPhysMaterialType__Asphalt = 1,
	EPhysMaterialType__Dirt = 2,
	EPhysMaterialType__Water = 3,
	EPhysMaterialType__Wood = 4,
	EPhysMaterialType__Stone = 5,
	EPhysMaterialType__Metal = 6,
	EPhysMaterialType__EPhysMaterialType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EMarkerType
	enum class EMarkerType : uint8_t
{
	EMarkerType__Normal = 0,
	EMarkerType__Attack = 1,
	EMarkerType__Danger = 2,
	EMarkerType__Defend = 3,
	EMarkerType__Loot = 4,
	EMarkerType__Regroup = 5,
	EMarkerType__Vehicle = 6,
	EMarkerType__EMarkerType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EEquipableItemSoundGroup
	enum class EEquipableItemSoundGroup : uint8_t
{
	EEquipableItemSoundGroup__Default = 0,
	EEquipableItemSoundGroup__Shoes = 1,
	EEquipableItemSoundGroup__EEquipableItemSoundGroup_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EColorBlindType
	enum class EColorBlindType : uint8_t
{
	EColorBlindType__Normal = 0,
	EColorBlindType__Deuteranopia = 1,
	EColorBlindType__Protanopia = 2,
	EColorBlindType__Tritanopia = 3,
	EColorBlindType__EColorBlindType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EFrameRateLimitType
	enum class EFrameRateLimitType : uint8_t
{
	EFrameRateLimitType__Unlimited = 0,
	EFrameRateLimitType__Fixed = 1,
	EFrameRateLimitType__Fixed01 = 2,
	EFrameRateLimitType__Customizable = 3,
	EFrameRateLimitType__DisplayBased = 4,
	EFrameRateLimitType__EFrameRateLimitType_MAX = 5,
	};
	// Enum ShadowTrackerExtra.ETslPhysMaterialType
	enum class ETslPhysMaterialType : uint8_t
{
	ETslPhysMaterialType__Unknown = 0,
	ETslPhysMaterialType__Concrete = 1,
	ETslPhysMaterialType__Dirt = 2,
	ETslPhysMaterialType__Water = 3,
	ETslPhysMaterialType__Metal = 4,
	ETslPhysMaterialType__Wood = 5,
	ETslPhysMaterialType__Grass = 6,
	ETslPhysMaterialType__Glass = 7,
	ETslPhysMaterialType__Flesh = 8,
	ETslPhysMaterialType__ETslPhysMaterialType_MAX = 9,
	};
	// Enum ShadowTrackerExtra.EDamageReason
	enum class EDamageReason : uint8_t
{
	EDamageReason__None = 0,
	EDamageReason__HeadShot = 1,
	EDamageReason__TorsoShot = 2,
	EDamageReason__PelvisShot = 3,
	EDamageReason__ArmShot = 4,
	EDamageReason__LegShot = 5,
	EDamageReason__LimbsShot = 6,
	EDamageReason__NonSpecific = 7,
	EDamageReason__EDamageReason_MAX = 8,
	};
	// Enum ShadowTrackerExtra.ETppAimCameraPosition
	enum class ETppAimCameraPosition : uint8_t
{
	ETppAimCameraPosition__LatestAimPosition = 0,
	ETppAimCameraPosition__LastPeekingPosition = 1,
	ETppAimCameraPosition__ResetToRightShoulderPosition = 2,
	ETppAimCameraPosition__ResetToLeftShoulderPosition = 3,
	ETppAimCameraPosition__ETppAimCameraPosition_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ETargetingType
	enum class ETargetingType : uint8_t
{
	ETargetingType__Targeting_None = 0,
	ETargetingType__Targeting_Aiming = 1,
	ETargetingType__Targeting_Scoping = 2,
	ETargetingType__Targeting_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAccessorySlot
	enum class EAccessorySlot : uint8_t
{
	EAccessorySlot__Slot_Primary = 0,
	EAccessorySlot__Slot_Secondary = 1,
	EAccessorySlot__Slot_SideArm = 2,
	EAccessorySlot__Slot_Melee = 3,
	EAccessorySlot__Slot_Thrown = 4,
	EAccessorySlot__Slot_None = 5,
	EAccessorySlot__Slot_MAX = 6,
	};
	// Enum ShadowTrackerExtra.ELobbyCharacterCameraType
	enum class ELobbyCharacterCameraType : uint8_t
{
	ELobbyCharacterCameraType__None = 0,
	ELobbyCharacterCameraType__WholeBodyCamera = 1,
	ELobbyCharacterCameraType__HeadCamera = 2,
	ELobbyCharacterCameraType__BodyCamera = 3,
	ELobbyCharacterCameraType__LegCamera = 4,
	ELobbyCharacterCameraType__FootCamera = 5,
	ELobbyCharacterCameraType__Max = 6,
	};
	// Enum ShadowTrackerExtra.EWeaponClass
	enum class EWeaponClass : uint8_t
{
	EWeaponClass__Class_None = 0,
	EWeaponClass__Class_Pistol = 1,
	EWeaponClass__Class_SMG = 2,
	EWeaponClass__Class_Rifle = 3,
	EWeaponClass__Class_Carbine = 4,
	EWeaponClass__Class_Shotgun = 5,
	EWeaponClass__Class_Sniper = 6,
	EWeaponClass__Class_DMR = 7,
	EWeaponClass__Class_LMG = 8,
	EWeaponClass__Class_Melee = 9,
	EWeaponClass__Class_Throwable = 10,
	EWeaponClass__Class_Shield = 11,
	EWeaponClass__Class_Crossbow = 12,
	EWeaponClass__Class_MAX = 13,
	};
	// Enum ShadowTrackerExtra.EThrownWeaponType
	enum class EThrownWeaponType : uint8_t
{
	EThrownWeaponType__Thrown_Grenade = 0,
	EThrownWeaponType__Thrown_Molotov = 1,
	EThrownWeaponType__Thrown_Other = 2,
	EThrownWeaponType__Thrown_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAttachmentCalculateType
	enum class EAttachmentCalculateType : uint8_t
{
	EAttachmentCalculateType__Addition = 0,
	EAttachmentCalculateType__Multiply = 1,
	EAttachmentCalculateType__EAttachmentCalculateType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EFiringMode
	enum class EFiringMode : uint8_t
{
	EFiringMode__Normal = 0,
	EFiringMode__Burst = 1,
	EFiringMode__FullAuto = 2,
	EFiringMode__EFiringMode_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EWeaponHand
	enum class EWeaponHand : uint8_t
{
	EWeaponHand__Left = 0,
	EWeaponHand__Right = 1,
	EWeaponHand__Total = 2,
	EWeaponHand__EWeaponHand_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ECameraViewBehaviour
	enum class ECameraViewBehaviour : uint8_t
{
	ECameraViewBehaviour__FpsAndTps = 0,
	ECameraViewBehaviour__FpsOnly = 1,
	ECameraViewBehaviour__TpsOnly = 2,
	ECameraViewBehaviour__ECameraViewBehaviour_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EPlayerStartType
	enum class EPlayerStartType : uint8_t
{
	EPlayerStartType__OnePlace = 0,
	EPlayerStartType__SeveralPlace = 1,
	EPlayerStartType__EPlayerStartType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EMatchStartType
	enum class EMatchStartType : uint8_t
{
	EMatchStartType__Normal = 0,
	EMatchStartType__Airborne = 1,
	EMatchStartType__EMatchStartType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EGender
	enum class EGender : uint8_t
{
	EGender__Male = 0,
	EGender__Female = 1,
	EGender__EGender_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EWeatherStatusType
	enum class EWeatherStatusType : uint8_t
{
	EWeatherStatusType__EWeatherStatusType_None = 0,
	EWeatherStatusType__EWeatherStatusType_SunnyDay = 1,
	EWeatherStatusType__EWeatherStatusType_Night = 2,
	EWeatherStatusType__EWeatherStatusType_Fog = 3,
	EWeatherStatusType__EWeatherStatusType_Rain = 4,
	EWeatherStatusType__EWeatherStatusType_Snow = 5,
	EWeatherStatusType__EWeatherStatusType_Blizzard = 6,
	EWeatherStatusType__EWeatherStatusType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.ESTEAIState
	enum class ESTEAIState : uint8_t
{
	ESTEAIState__ZS_Spawn = 0,
	ESTEAIState__ZS_Idle = 1,
	ESTEAIState__ZS_Battle = 2,
	ESTEAIState__ZS_Move = 3,
	ESTEAIState__ZS_Run = 4,
	ESTEAIState__ZS_Inspect = 5,
	ESTEAIState__ZS_Jump = 6,
	ESTEAIState__ZS_Land_Light = 7,
	ESTEAIState__ZS_Land_Hard = 8,
	ESTEAIState__ZS_Suffer = 9,
	ESTEAIState__ZS_SufferFreez = 10,
	ESTEAIState__ZS_Fall = 11,
	ESTEAIState__ZS_ClimbingWall = 12,
	ESTEAIState__ZS_CrossingWindow = 13,
	ESTEAIState__ZS_Dead = 14,
	ESTEAIState__ZS_LockTarget = 15,
	ESTEAIState__ZS_SpawnOnCeiling = 16,
	ESTEAIState__ZS_NearDeath = 17,
	ESTEAIState__ZS_MAX = 18,
	};
	// Enum ShadowTrackerExtra.EBPAIState
	enum class EBPAIState : uint8_t
{
	EBPAIState__ZS_Spawn = 0,
	EBPAIState__ZS_Idle = 1,
	EBPAIState__ZS_Battle = 2,
	EBPAIState__ZS_Move = 3,
	EBPAIState__ZS_Run = 4,
	EBPAIState__ZS_Inspect = 5,
	EBPAIState__ZS_Jump = 6,
	EBPAIState__ZS_Land_Light = 7,
	EBPAIState__ZS_Land_Hard = 8,
	EBPAIState__ZS_Suffer = 9,
	EBPAIState__ZS_SufferFreez = 10,
	EBPAIState__ZS_Fall = 11,
	EBPAIState__ZS_ClimbingWall = 12,
	EBPAIState__ZS_CrossingWindow = 13,
	EBPAIState__ZS_Dead = 14,
	EBPAIState__ZS_LockTarget = 15,
	EBPAIState__ZS_SpawnOnCeiling = 16,
	EBPAIState__ZS_NearDeath = 17,
	EBPAIState__ZS_Max = 18,
	};
	// Enum ShadowTrackerExtra.EMobWalkType
	enum class EMobWalkType : uint8_t
{
	EMobWalkType__Normal = 0,
	EMobWalkType__IdleWalk = 1,
	EMobWalkType__AttackWalk = 2,
	EMobWalkType__EMobWalkType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EMonsterFuncType
	enum class EMonsterFuncType : uint8_t
{
	EMonsterFuncType__AutoExit = 0,
	EMonsterFuncType__EMonsterFuncType_MAX = 1,
	};
	// Enum ShadowTrackerExtra.EMonsterType
	enum class EMonsterType : uint8_t
{
	EMonsterType__EMonsterType_Normal = 0,
	EMonsterType__EMonsterType_Elite = 1,
	EMonsterType__EMonsterType_Boss = 2,
	EMonsterType__EMonsterType_BigBoss = 3,
	EMonsterType__EMonsterType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EMonsterAnimGroupMask
	enum class EMonsterAnimGroupMask : uint8_t
{
	EMonsterAnimGroupMask__EMonsterAnimGroupMask_Null = 0,
	EMonsterAnimGroupMask__EMonsterAnimGroupMask_Base = 1,
	EMonsterAnimGroupMask__EMonsterAnimGroupMask_Child = 2,
	EMonsterAnimGroupMask__EMonsterAnimGroupMask_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAIMoveType
	enum class EAIMoveType : uint8_t
{
	EAIMoveType__StraightMove = 0,
	EAIMoveType__CurveMove = 1,
	EAIMoveType__EAIMoveType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EAIWeaponShootType
	enum class EAIWeaponShootType : uint8_t
{
	EAIWeaponShootType__SingleShot = 0,
	EAIWeaponShootType__Auto = 1,
	EAIWeaponShootType__EAIWeaponShootType_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EAINewFocusPriority
	enum class EAINewFocusPriority : uint8_t
{
	EAINewFocusPriority__Default = 0,
	EAINewFocusPriority__Move = 1,
	EAINewFocusPriority__Gameplay = 2,
	EAINewFocusPriority__EAINewFocusPriority_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAIMovePose
	enum class EAIMovePose : uint8_t
{
	EAIMovePose__Walk = 0,
	EAIMovePose__Run = 1,
	EAIMovePose__CrouchSprint = 2,
	EAIMovePose__KeepCurrentPose = 3,
	EAIMovePose__EAIMovePose_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EAIPoseState
	enum class EAIPoseState : uint8_t
{
	EAIPoseState__Stand = 0,
	EAIPoseState__Crouch = 1,
	EAIPoseState__Prone = 2,
	EAIPoseState__Jump = 3,
	EAIPoseState__EAIPoseState_MAX = 4,
	};
	// Enum ShadowTrackerExtra.EAITriggerAttrType
	enum class EAITriggerAttrType : uint8_t
{
	EAITriggerAttrType__None = 0,
	EAITriggerAttrType__Health = 1,
	EAITriggerAttrType__Energy = 2,
	EAITriggerAttrType__EAITriggerAttrType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAIAttrCompareType
	enum class EAIAttrCompareType : uint8_t
{
	EAIAttrCompareType__None = 0,
	EAIAttrCompareType__Great = 1,
	EAIAttrCompareType__Less = 2,
	EAIAttrCompareType__EAIAttrCompareType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EAIEquipSpawnItemType
	enum class EAIEquipSpawnItemType : uint8_t
{
	EAIEquipSpawnItemType__Shoot_Weap = 0,
	EAIEquipSpawnItemType__Backpack = 1,
	EAIEquipSpawnItemType__other = 2,
	EAIEquipSpawnItemType__EAIEquipSpawnItemType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EBoltActionWeaponProgressType
	enum class EBoltActionWeaponProgressType : uint8_t
{
	EBoltActionWeaponProgressType__NoState = 0,
	EBoltActionWeaponProgressType__Weapon_Fired = 1,
	EBoltActionWeaponProgressType__BoltActionAnim_InProgress = 2,
	EBoltActionWeaponProgressType__EBoltActionWeaponProgressType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EExecuteAirDropOrderResult
	enum class EExecuteAirDropOrderResult : uint8_t
{
	MakeAirDropOrderDone = 0,
	UndefinedADFReason = 1,
	RandomDropFailure = 2,
	NothingToDrop = 3,
	GameNotStart = 4,
	GameEnded = 5,
	GameStateInvalid = 6,
	DroppingLocationOutSideLandscape = 7,
	LandscapeExtentInvalid = 8,
	FlyingDirectionInValid = 9,
	AirPlaneClassInvalid = 10,
	EExecuteAirDropOrderResult_MAX = 11,
	};
	// Enum ShadowTrackerExtra.ESTExtraVehicleShapeType
	enum class ESTExtraVehicleShapeType : uint8_t
{
	ESTExtraVehicleShapeType__VST_Unknown = 0,
	ESTExtraVehicleShapeType__VST_Motorbike = 1,
	ESTExtraVehicleShapeType__VST_Motorbike_SideCart = 2,
	ESTExtraVehicleShapeType__VST_Dacia = 3,
	ESTExtraVehicleShapeType__VST_MiniBus = 4,
	ESTExtraVehicleShapeType__VST_PickUp = 5,
	ESTExtraVehicleShapeType__VST_PickUp01 = 6,
	ESTExtraVehicleShapeType__VST_Buggy = 7,
	ESTExtraVehicleShapeType__VST_UAZ = 8,
	ESTExtraVehicleShapeType__VST_UAZ01 = 9,
	ESTExtraVehicleShapeType__VST_UAZ02 = 10,
	ESTExtraVehicleShapeType__VST_PG117 = 11,
	ESTExtraVehicleShapeType__VST_Aquarail = 12,
	ESTExtraVehicleShapeType__VST_UAZ03 = 13,
	ESTExtraVehicleShapeType__VST_Mirado = 14,
	ESTExtraVehicleShapeType__VST_Mirado01 = 15,
	ESTExtraVehicleShapeType__VST_Rony = 16,
	ESTExtraVehicleShapeType__VST_Scooter = 17,
	ESTExtraVehicleShapeType__VST_TukTukTuk = 18,
	ESTExtraVehicleShapeType__VST_MAX = 19,
	};
	// Enum ShadowTrackerExtra.EBuffApplierCondition
	enum class EBuffApplierCondition : uint8_t
{
	BuffAppCondition_InSight = 0,
	BuffAppConditio_Default = 1,
	EBuffApplierCondition_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EApplyStatus
	enum class EApplyStatus : uint8_t
{
	REVERT = 0,
	NO_APPLY = 1,
	APPLY = 2,
	EApplyStatus_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ELoadMode
	enum class ELoadMode : uint8_t
{
	LOW_LOAD = 0,
	MEDIUM_LOAD = 1,
	HIGH_LOAD = 2,
	ELoadMode_MAX = 3,
	};
	// Enum ShadowTrackerExtra.UTSkill_SoundCue_ListenType
	enum class EUTSkill_SoundCue_ListenType : uint8_t
{
	UTSkill_SoundCue_ListenType__Listen_SelfOnly = 0,
	UTSkill_SoundCue_ListenType__Listen_Teammate = 1,
	UTSkill_SoundCue_ListenType__Listen_Target = 2,
	UTSkill_SoundCue_ListenType__Listen_AllTarget = 3,
	UTSkill_SoundCue_ListenType__Listen_All = 4,
	UTSkill_SoundCue_ListenType__Listen_MAX = 5,
	};
	// Enum ShadowTrackerExtra.EVaultRequirementType
	enum class EVaultRequirementType : uint8_t
{
	EVaultRequirementType__VaultReqType_False = 0,
	EVaultRequirementType__VaultReqType_True = 1,
	EVaultRequirementType__VaultReqType_Any = 2,
	EVaultRequirementType__VaultReqType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EBackpackItemType
	enum class EBackpackItemType : uint8_t
{
	UnknownBackpackItemType = 0,
	BackpackItemType_Weapon = 1,
	BackpackItemType_WeaponAttachment = 2,
	BackpackItemType_Ammo = 3,
	BackpackItemType_Clothing = 4,
	BackpackItemType_Armor = 5,
	BackpackItemType_Consumable = 6,
	EBackpackItemType_MAX = 7,
	};
	// Enum ShadowTrackerExtra.EGameModeType
	enum class EGameModeType : uint8_t
{
	EGameModeType__EGameModeSingle = 0,
	EGameModeType__ETypicalGameMode = 1,
	EGameModeType__EEntertainmentGameMode = 2,
	EGameModeType__EGameModeGroup = 3,
	EGameModeType__EWarGameMode = 4,
	EGameModeType__ETeamDeathMatchGameMode = 5,
	EGameModeType__EGameModeType_MAX = 6,
	};
	// Enum ShadowTrackerExtra.ELobbyCharacterAnimationType
	enum class ELobbyCharacterAnimationType : uint8_t
{
	ELobbyCharacterAnimationType__Default = 0,
	ELobbyCharacterAnimationType__Wardrobe = 1,
	ELobbyCharacterAnimationType__Appearance = 2,
	ELobbyCharacterAnimationType__ELobbyCharacterAnimationType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ERandomItemType
	enum class ERandomItemType : uint8_t
{
	ERandomItemType__Random_Standard = 0,
	ERandomItemType__Random_NoDuplication = 1,
	ERandomItemType__Random_MAX = 2,
	};
	// Enum ShadowTrackerExtra.ESceneTeamType
	enum class ESceneTeamType : uint8_t
{
	ESceneTeamType__None = 0,
	ESceneTeamType__TeamType_A = 1,
	ESceneTeamType__TeamType_B = 2,
	ESceneTeamType__ESceneTeamType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ESceneStep
	enum class ESceneStep : uint8_t
{
	ESceneStep__None = 0,
	ESceneStep__Prepare = 1,
	ESceneStep__BeforeEmote = 2,
	ESceneStep__PlayEmote = 3,
	ESceneStep__AfterEmote = 4,
	ESceneStep__Finish = 5,
	ESceneStep__Max = 6,
	};
	// Enum ShadowTrackerExtra.ESceneType
	enum class ESceneType : uint8_t
{
	ESceneType__None = 0,
	ESceneType__StartScene = 1,
	ESceneType__EndScene = 2,
	ESceneType__ESceneType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ETslWheelWidgetMouseCursorDirectionType
	enum class ETslWheelWidgetMouseCursorDirectionType : uint8_t
{
	ETslWheelWidgetMouseCursorDirectionType__ABSOLUTE_COORD = 0,
	ETslWheelWidgetMouseCursorDirectionType__AREA_RESTRICTED_COORD = 1,
	ETslWheelWidgetMouseCursorDirectionType__CIRCULAR_RESTRICTED_COORD = 2,
	ETslWheelWidgetMouseCursorDirectionType__ETslWheelWidgetMouseCursorDirectionType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ETslWheelWidgetSelectType
	enum class ETslWheelWidgetSelectType : uint8_t
{
	ETslWheelWidgetSelectType__BY_CLICK = 0,
	ETslWheelWidgetSelectType__BY_RELEASE = 1,
	ETslWheelWidgetSelectType__BY_MAX = 2,
	};
	// Enum ShadowTrackerExtra.EHMDType
	enum class EHMDType : uint8_t
{
	EHMDType__None = 0,
	EHMDType__Oculus = 1,
	EHMDType__Vive = 2,
	EHMDType__Morpheus = 3,
	EHMDType__EHMDType_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ELoopMoveMode
	enum class ELoopMoveMode : uint8_t
{
	ELoopMoveMode__ELoopMoveMode_None = 0,
	ELoopMoveMode__ELoopMoveMode_NoLoop = 1,
	ELoopMoveMode__ELoopMoveMode_Forward = 2,
	ELoopMoveMode__ELoopMoveMode_Back = 3,
	ELoopMoveMode__ELoopMoveMode_MAX = 4,
	};
	// Enum ShadowTrackerExtra.ESTAINoiseType
	enum class ESTAINoiseType : uint8_t
{
	ESTAINoiseType__PlayerShootSound = 0,
	ESTAINoiseType__VehicleRunSound = 1,
	ESTAINoiseType__VehicleHornSound = 2,
	ESTAINoiseType__ESTAINoiseType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ESTExtraVehicleUserState
	enum class ESTExtraVehicleUserState : uint8_t
{
	ESTExtraVehicleUserState__EVUS_OutOfVehicle = 0,
	ESTExtraVehicleUserState__EVUS_AsDriver = 1,
	ESTExtraVehicleUserState__EVUS_ASPassenger = 2,
	ESTExtraVehicleUserState__EVUS_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EFollowCameraMode
	enum class EFollowCameraMode : uint8_t
{
	EFollowCameraMode__CharacterCamera = 0,
	EFollowCameraMode__VehicleCamera = 1,
	EFollowCameraMode__AircraftCamera = 2,
	EFollowCameraMode__ParachutingCamera = 3,
	EFollowCameraMode__FallingWithParachuteCamera = 4,
	EFollowCameraMode__EFollowCameraMode_MAX = 5,
	};
	// Enum ShadowTrackerExtra.EObserverMovementSpeedType
	enum class EObserverMovementSpeedType : uint8_t
{
	EObserverMovementSpeedType__NormalSpeed = 0,
	EObserverMovementSpeedType__SlowSpeed = 1,
	EObserverMovementSpeedType__FastSpeed = 2,
	EObserverMovementSpeedType__EObserverMovementSpeedType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EObserverCameraZoomSpeedType
	enum class EObserverCameraZoomSpeedType : uint8_t
{
	EObserverCameraZoomSpeedType__NormalSpeed = 0,
	EObserverCameraZoomSpeedType__SlowSpeed = 1,
	EObserverCameraZoomSpeedType__FastSpeed = 2,
	EObserverCameraZoomSpeedType__EObserverCameraZoomSpeedType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.EObserverPlayerListType
	enum class EObserverPlayerListType : uint8_t
{
	EObserverPlayerListType__Kill = 0,
	EObserverPlayerListType__Survivor = 1,
	EObserverPlayerListType__Score = 2,
	EObserverPlayerListType__Max = 3,
	};
	// Enum ShadowTrackerExtra.EObserverHudAnimType
	enum class EObserverHudAnimType : uint8_t
{
	EObserverHudAnimType__TeamWipeOutAnim = 0,
	EObserverHudAnimType__PersonalKillingSpreeAnim = 1,
	EObserverHudAnimType__TeamTotalKillingSpreeAnim = 2,
	EObserverHudAnimType__EObserverHudAnimType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ETslGameOptionKeyBindingType
	enum class ETslGameOptionKeyBindingType : uint8_t
{
	ETslGameOptionKeyBindingType__None = 0,
	ETslGameOptionKeyBindingType__Action = 1,
	ETslGameOptionKeyBindingType__Axis = 2,
	ETslGameOptionKeyBindingType__ETslGameOptionKeyBindingType_MAX = 3,
	};
	// Enum ShadowTrackerExtra.ETslGameOptionSupplementaryType
	enum class ETslGameOptionSupplementaryType : uint8_t
{
	ETslGameOptionSupplementaryType__None = 0,
	ETslGameOptionSupplementaryType__KeyboardLayout = 1,
	ETslGameOptionSupplementaryType__PreviewImage = 2,
	ETslGameOptionSupplementaryType__PreviewCrosshair = 3,
	ETslGameOptionSupplementaryType__VolumeUnitMeter = 4,
	ETslGameOptionSupplementaryType__ETslGameOptionSupplementaryType_MAX = 5,
	};
//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct Engine.RepMovement
// 0x0034
struct FRepMovement
{
	struct FVector                                     LinearVelocity;                                           // 0x0000(0x000C)
	struct FVector                                     AngularVelocity;                                          // 0x000C(0x000C)
	struct FVector                                     Location;                                                 // 0x0018(0x000C)
	struct FRotator                                    Rotation;                                                 // 0x0024(0x000C)
	unsigned char                                      bSimulatedPhysicSleep : 1;                                // 0x0030(0x0001)
	unsigned char                                      bRepPhysics : 1;                                          // 0x0030(0x0001)
	EVectorQuantization                                LocationQuantizationLevel;                                // 0x0031(0x0001)
	EVectorQuantization                                VelocityQuantizationLevel;                                // 0x0032(0x0001)
	ERotatorQuantization                               RotationQuantizationLevel;                                // 0x0033(0x0001)
};
// ScriptStruct Engine.Vector_NetQuantize100
// 0x0000 (0x000C - 0x000C)
struct FVector_NetQuantize100 : public FVector
{
};

// ScriptStruct Engine.RepAttachment
// 0x0040
struct FRepAttachment
{
	class AActor* AttachParent;                                             // 0x0000(0x0008)
	struct FVector_NetQuantize100                      LocationOffset;                                           // 0x0008(0x000C)
	struct FVector_NetQuantize100                      RelativeScale3D;                                          // 0x0014(0x000C)
	struct FRotator                                    RotationOffset;                                           // 0x0020(0x000C)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	struct FName                                       AttachSocket;                                             // 0x0030(0x0008)
	class USceneComponent* AttachComponent;                                          // 0x0038(0x0008)
};

// ScriptStruct Engine.TickFunction
// 0x0050
struct FTickFunction
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	TEnumAsByte<ETickingGroup>                         TickGroup;                                                // 0x0008(0x0001)
	TEnumAsByte<ETickingGroup>                         EndTickGroup;                                             // 0x0009(0x0001)
	unsigned char                                      UnknownData01[0x2];                                       // 0x000A(0x0002) MISSED OFFSET
	unsigned char                                      bTickEvenWhenPaused : 1;                                  // 0x000C(0x0001)
	unsigned char                                      bCanEverTick : 1;                                         // 0x000C(0x0001)
	unsigned char                                      bStartWithTickEnabled : 1;                                // 0x000C(0x0001)
	unsigned char                                      bAllowTickOnDedicatedServer : 1;                          // 0x000C(0x0001)
	unsigned char                                      UnknownData02[0x33];                                      // 0x000D(0x0033) MISSED OFFSET
	float                                              TickInterval;                                             // 0x0040(0x0004)
	unsigned char                                      UnknownData03[0xC];                                       // 0x0044(0x000C) MISSED OFFSET
};

// ScriptStruct Engine.ActorTickFunction
// 0x0008 (0x0058 - 0x0050)
struct FActorTickFunction : public FTickFunction
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0050(0x0008) MISSED OFFSET
};

// ScriptStruct Engine.BasedMovementInfo
// 0x0030
struct FBasedMovementInfo
{
	class UPrimitiveComponent* MovementBase;                                             // 0x0000(0x0008)
	struct FName                                       BoneName;                                                 // 0x0008(0x0008)
	struct FVector_NetQuantize100                      Location;                                                 // 0x0010(0x000C)
	struct FRotator                                    Rotation;                                                 // 0x001C(0x000C)
	bool                                               bServerHasBaseComponent;                                  // 0x0028(0x0001)
	bool                                               bRelativeRotation;                                        // 0x0029(0x0001)
	bool                                               bServerHasVelocity;                                       // 0x002A(0x0001)
	unsigned char                                      UnknownData00[0x5];                                       // 0x002B(0x0005) MISSED OFFSET
};

// ScriptStruct Engine.Vector_NetQuantize10
// 0x0000 (0x000C - 0x000C)
struct FVector_NetQuantize10 : public FVector
{
};

// ScriptStruct Engine.RootMotionSourceSettings
// 0x0001
struct FRootMotionSourceSettings
{
	unsigned char                                      Flags;                                                    // 0x0000(0x0001)
};

// ScriptStruct Engine.RootMotionSourceGroup
// 0x0100
struct FRootMotionSourceGroup
{
	unsigned char                                      UnknownData00[0xE8];                                      // 0x0000(0x00E8) MISSED OFFSET
	bool                                               bHasAdditiveSources;                                      // 0x00E8(0x0001)
	bool                                               bHasOverrideSources;                                      // 0x00E9(0x0001)
	unsigned char                                      UnknownData01[0x2];                                       // 0x00EA(0x0002) MISSED OFFSET
	struct FVector_NetQuantize10                       LastPreAdditiveVelocity;                                  // 0x00EC(0x000C)
	bool                                               bIsAdditiveVelocityApplied;                               // 0x00F8(0x0001)
	struct FRootMotionSourceSettings                   LastAccumulatedSettings;                                  // 0x00F9(0x0001)
	unsigned char                                      UnknownData02[0x6];                                       // 0x00FA(0x0006) MISSED OFFSET
};

// ScriptStruct Engine.RootMotionMovementParams
// 0x0040
struct FRootMotionMovementParams
{
	bool                                               bHasRootMotion;                                           // 0x0000(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              BlendWeight;                                              // 0x0004(0x0004)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0008(0x0008) MISSED OFFSET
	struct FTransform                                  RootMotionTransform;                                      // 0x0010(0x0030)
};

// ScriptStruct Engine.RepRootMotionMontage
// 0x0160
struct FRepRootMotionMontage
{
	bool                                               bIsActive;                                                // 0x0000(0x0001)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	class UAnimMontage* AnimMontage;                                              // 0x0008(0x0008)
	float                                              Position;                                                 // 0x0010(0x0004)
	struct FVector_NetQuantize100                      Location;                                                 // 0x0014(0x000C)
	struct FRotator                                    Rotation;                                                 // 0x0020(0x000C)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	class UPrimitiveComponent* MovementBase;                                             // 0x0030(0x0008)
	struct FName                                       MovementBaseBoneName;                                     // 0x0038(0x0008)
	bool                                               bRelativePosition;                                        // 0x0040(0x0001)
	bool                                               bRelativeRotation;                                        // 0x0041(0x0001)
	unsigned char                                      UnknownData02[0x6];                                       // 0x0042(0x0006) MISSED OFFSET
	struct FRootMotionSourceGroup                      AuthoritativeRootMotion;                                  // 0x0048(0x0100)
	struct FVector_NetQuantize10                       Acceleration;                                             // 0x0148(0x000C)
	struct FVector_NetQuantize10                       LinearVelocity;                                           // 0x0154(0x000C)
};
// Enum Gameplay.ECharacterGender
enum class ECharacterGender : uint8_t
{
	ECharacterGender__Male = 0,
	ECharacterGender__Female = 1,
	ECharacterGender__ECharacterGender_MAX = 2,
};
//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct ShadowTrackerExtra.BodyTypeDef
// 0x0008
struct FBodyTypeDef
{
	int                                                UpThreshold;                                              // 0x0000(0x0004)
	int                                                DownThreshold;                                            // 0x0004(0x0004)
};

// ScriptStruct ShadowTrackerExtra.CharacterEnergyData
// 0x0038
struct FCharacterEnergyData
{
	TArray<struct FCharacterEnergyPhase>               EnergyEffactPhase;                                        // 0x0000(0x0010)
	float                                              EnergyMax;                                                // 0x0010(0x0004)
	float                                              EnergyCurrent;                                            // 0x0014(0x0004)
	float                                              AttenuationPeriod;                                        // 0x0018(0x0004)
	float                                              AttenuationAmount;                                        // 0x001C(0x0004)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0020(0x0018) MISSED OFFSET
};

// ScriptStruct ShadowTrackerExtra.PoseChangeTime
// 0x0018
struct FPoseChangeTime
{
	float                                              PoseChange_Prone_Stand;                                   // 0x0000(0x0004)
	float                                              PoseChange_Prone_Move;                                    // 0x0004(0x0004)
	float                                              PoseChange_UnProne_Stand;                                 // 0x0008(0x0004)
	float                                              PoseChange_UnProne_Move;                                  // 0x000C(0x0004)
	float                                              PoseChange_Stand_Crouch;                                  // 0x0010(0x0004)
	float                                              PoseChange_Crouch_Stand;                                  // 0x0014(0x0004)
};

// ScriptStruct ShadowTrackerExtra.AnimStatusKeyList
// 0x0020
struct FAnimStatusKeyList
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
	class ASTExtraWeapon* EquipWeapon;                                              // 0x0010(0x0008)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0018(0x0008) MISSED OFFSET
};

// ScriptStruct ShadowTrackerExtra.KilledTipsBlock
// 0x0038
struct FKilledTipsBlock
{
	EDamageType                                        DamageType;                                               // 0x0000(0x0001)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FString                                     attackerName;                                             // 0x0008(0x0010)
	struct FString                                     WeaponName;                                               // 0x0018(0x0010)
	struct FString                                     DeadName;                                                 // 0x0028(0x0010)
};

// ScriptStruct ShadowTrackerExtra.AnimParamList
// 0x00E8
struct FAnimParamList
{
	float                                              RecoilKickADS;                                            // 0x0000(0x0004)
	float                                              CharacterYawRotateRate;                                   // 0x0004(0x0004)
	bool                                               IsNearDeathStatus;                                        // 0x0008(0x0001)
	bool                                               IsJumping;                                                // 0x0009(0x0001)
	unsigned char                                      UnknownData00[0x2];                                       // 0x000A(0x0002) MISSED OFFSET
	float                                              RecoilKick_MovementSpeedMax;                              // 0x000C(0x0004)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0010(0x0004) MISSED OFFSET
	TEnumAsByte<EFreshWeaponStateType>                 WeaponState;                                              // 0x0014(0x0001)
	bool                                               IsRescueing;                                              // 0x0015(0x0001)
	unsigned char                                      UnknownData02[0x1];                                       // 0x0016(0x0001) MISSED OFFSET
	bool                                               IsDisableAim;                                             // 0x0017(0x0001)
	ECharacterPoseType                                 PoseType;                                                 // 0x0018(0x0001)
	TEnumAsByte<EWeaponHoldType>                       WeaponHoldType;                                           // 0x0019(0x0001)
	bool                                               IsHurting;                                                // 0x001A(0x0001)
	bool                                               IsTurning;                                                // 0x001B(0x0001)
	struct FVector                                     MoveDir;                                                  // 0x001C(0x000C)
	struct FRotator                                    OffsetFPPProneRotation;                                   // 0x0028(0x000C)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
	struct FVector                                     OffsetFPPCrouchLocation;                                  // 0x0038(0x000C)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	bool                                               ShouldPauseAnim;                                          // 0x0048(0x0001)
	unsigned char                                      UnknownData05[0x3];                                       // 0x0049(0x0003) MISSED OFFSET
	struct FRotator                                    ViewRotation;                                             // 0x004C(0x000C)
	TEnumAsByte<EWeaponReloadMethod>                   WeaponReloadMethod;                                       // 0x0058(0x0001)
	unsigned char                                      UnknownData06[0x3];                                       // 0x0059(0x0003) MISSED OFFSET
	float                                              HandleFolderFactor;                                       // 0x005C(0x0004)
	struct FRotator                                    ControlRotation;                                          // 0x0060(0x000C)
	struct FVector                                     HurtDir;                                                  // 0x006C(0x000C)
	struct FRotator                                    OffsetFPPRotation;                                        // 0x0078(0x000C)
	float                                              ForegripParam;                                            // 0x0084(0x0004)
	float                                              RecoilKick_MovementMaxMultiplier;                         // 0x0088(0x0004)
	struct FVector                                     OffsetFPPLocation;                                        // 0x008C(0x000C)
	unsigned char                                      UnknownData07[0x4];                                       // 0x0098(0x0004) MISSED OFFSET
	TEnumAsByte<EMovementMode>                         MovementMode;                                             // 0x009C(0x0001)
	bool                                               IsDying;                                                  // 0x009D(0x0001)
	bool                                               IsOnVehicle;                                              // 0x009E(0x0001)
	bool                                               IsCastingGenerate;                                        // 0x009F(0x0001)
	struct FVector                                     Velocity;                                                 // 0x00A0(0x000C)
	bool                                               UsingBoltAction;                                          // 0x00AC(0x0001)
	EWeaponType                                        WeaponType;                                               // 0x00AD(0x0001)
	unsigned char                                      UnknownData08[0x2];                                       // 0x00AE(0x0002) MISSED OFFSET
	struct FVector                                     OffsetFPPProneLocation;                                   // 0x00B0(0x000C)
	bool                                               IsSprinting;                                              // 0x00BC(0x0001)
	unsigned char                                      UnknownData09[0x7];                                       // 0x00BD(0x0007) MISSED OFFSET
	TEnumAsByte<ESightType>                            SightType;                                                // 0x00C4(0x0001)
	TEnumAsByte<EParachuteState>                       ParachuteState;                                           // 0x00C5(0x0001)
	unsigned char                                      UnknownData10[0x2];                                       // 0x00C6(0x0002) MISSED OFFSET
	struct FRotator                                    OffsetFPPCrouchRotation;                                  // 0x00C8(0x000C)
	struct FVector                                     OffsetMagLocation;                                        // 0x00D4(0x000C)
	float                                              AnimationKick;                                            // 0x00E0(0x0004)
	TEnumAsByte<ECharacterJumpType>                    JumpType;                                                 // 0x00E4(0x0001)
	unsigned char                                      UnknownData11[0x3];                                       // 0x00E5(0x0003) MISSED OFFSET
};

// ScriptStruct ShadowTrackerExtra.SyncAKEvent
// 0x0010
struct FSyncAKEvent
{
	struct FVector                                     AkLocation;                                               // 0x0000(0x000C)
	int                                                AkEventID;                                                // 0x000C(0x0004)
};

// ScriptStruct ShadowTrackerExtra.AnimVehParamList
// 0x0018
struct FAnimVehParamList
{
	struct FRotator                                    VehViewRotation;                                          // 0x0000(0x000C)
	float                                              LeanOutPercentage;                                        // 0x000C(0x0004)
	bool                                               IsDriver;                                                 // 0x0010(0x0001)
	EVHSeatWeaponHoldType                              SeatWeaponHoldType;                                       // 0x0011(0x0001)
	EVHSeatSpecialType                                 SeatSpecialType;                                          // 0x0012(0x0001)
	bool                                               DriverExist;                                              // 0x0013(0x0001)
	bool                                               IsLeanOut;                                                // 0x0014(0x0001)
	ESTExtraVehicleType                                VehicleType;                                              // 0x0015(0x0001)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0016(0x0002) MISSED OFFSET
};

// ScriptStruct ShadowTrackerExtra.BodyPartCfg
// 0x0020
struct FBodyPartCfg
{
	float                                              DamageScale;                                              // 0x0000(0x0004)
	float                                              Durability;                                               // 0x0004(0x0004)
	float                                              DamageReduceScale;                                        // 0x0008(0x0004)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FString                                     BodyDurabilityIndexName;                                  // 0x0010(0x0010)
};

// ScriptStruct ShadowTrackerExtra.STParachuteState
// 0x000C
struct FSTParachuteState
{
	float                                              ThrottleInput;                                            // 0x0000(0x0004)
	float                                              SteerInput;                                               // 0x0004(0x0004)
	int8_t                                             State;                                                    // 0x0008(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0009(0x0003) MISSED OFFSET
};

// ScriptStruct ShadowTrackerExtra.STReplicatedMoveState
// 0x0024
struct FSTReplicatedMoveState
{
	struct FVector                                     Location;                                                 // 0x0000(0x000C)
	struct FRotator                                    Rotation;                                                 // 0x000C(0x000C)
	struct FVector                                     Velocity;                                                 // 0x0018(0x000C)
};

// ScriptStruct ShadowTrackerExtra.CameraSettings
// 0x0014
struct FCameraSettings
{
	float                                              TargetArmLength;                                          // 0x0000(0x0004)
	float                                              LagSpeed;                                                 // 0x0004(0x0004)
	struct FVector                                     SocketOffset;                                             // 0x0008(0x000C)
};

// ScriptStruct ShadowTrackerExtra.ParachuteStateParams
// 0x0034
struct FParachuteStateParams
{
	float                                              MinDownSpeed;                                             // 0x0000(0x0004)
	float                                              MaxForwardSpeed;                                          // 0x0004(0x0004)
	float                                              MinPitchAngle;                                            // 0x0008(0x0004)
	float                                              MinForwardSpeed;                                          // 0x000C(0x0004)
	float                                              MaxForwardForce;                                          // 0x0010(0x0004)
	float                                              MaxPitchAngle;                                            // 0x0014(0x0004)
	float                                              MinRightSpeed;                                            // 0x0018(0x0004)
	float                                              MinRollAngle;                                             // 0x001C(0x0004)
	float                                              DragForceFractor;                                         // 0x0020(0x0004)
	float                                              MinForwardForce;                                          // 0x0024(0x0004)
	float                                              MaxRollAngle;                                             // 0x0028(0x0004)
	float                                              MaxRightSpeed;                                            // 0x002C(0x0004)
	float                                              MaxDownSpeed;                                             // 0x0030(0x0004)
};

// ScriptStruct ShadowTrackerExtra.BulletFlySoundReplicatedData
// 0x0018
struct FBulletFlySoundReplicatedData
{
	class ASTExtraShootWeapon* InstigateWeapon;                                          // 0x0000(0x0008)
	struct FVector                                     FlySoundPos;                                              // 0x0008(0x000C)
	int                                                TriggerEarSoundIndex;                                     // 0x0014(0x0004)
};
class AActor : public UObject
{
public:
	float                                              NetCullDistanceSquared;                                   // 0x0030(0x0004)
	unsigned char                                      bReplicates : 1;                                          // 0x0034(0x0001)
	TEnumAsByte<ENetRole>                              RemoteRole;                                               // 0x0035(0x0001)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0036(0x0002) MISSED OFFSET
	class AActor* Owner;                                                    // 0x0038(0x0008)
	unsigned char                                      WorldParallelismID;                                       // 0x0040(0x0001)
	unsigned char                                      UnknownData01[0xF];                                       // 0x0041(0x000F) MISSED OFFSET
	struct FName                                       NetDriverName;                                            // 0x0050(0x0008)
	struct FRepMovement                                ReplicatedMovement;                                       // 0x0058(0x0034)
	float                                              InitialLifeSpan;                                          // 0x008C(0x0004)
	struct FRepAttachment                              AttachmentReplication;                                    // 0x0090(0x0040)
	struct FScriptMulticastDelegate                    OnActorBeginOverlap;                                      // 0x00D0(0x0010)
	TArray<class AActor*>                              Children;                                                 // 0x00E0(0x0010)
	TArray<struct FName>                               Layers;                                                   // 0x00F0(0x0010)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0100(0x0004) MISSED OFFSET
	unsigned char                                      bAutoDestroyWhenFinished : 1;                             // 0x0104(0x0001)
	unsigned char                                      bCanBeDamaged : 1;                                        // 0x0104(0x0001)
	unsigned char                                      bActorIsBeingDestroyed : 1;                               // 0x0104(0x0001)
	unsigned char                                      bCollideWhenPlacing : 1;                                  // 0x0104(0x0001)
	unsigned char                                      bFindCameraComponentWhenViewTarget : 1;                   // 0x0104(0x0001)
	unsigned char                                      bRelevantForNetworkReplays : 1;                           // 0x0104(0x0001)
	unsigned char                                      bGenerateOverlapEventsDuringLevelStreaming : 1;           // 0x0104(0x0001)
	unsigned char                                      bCanBeInCluster : 1;                                      // 0x0104(0x0001)
	unsigned char                                      bAllowReceiveTickEventOnDedicatedServer : 1;              // 0x0105(0x0001)
	unsigned char                                      UnknownData03 : 3;                                        // 0x0105(0x0001)
	unsigned char                                      bActorSeamlessTraveled : 1;                               // 0x0105(0x0001)
	unsigned char                                      bIgnoresOriginShifting : 1;                               // 0x0105(0x0001)
	unsigned char                                      bEnableAutoLODGeneration : 1;                             // 0x0105(0x0001)
	unsigned char                                      UnknownData04[0x2];                                       // 0x0106(0x0002) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnInputTouchBegin;                                        // 0x0108(0x0010)
	class USceneComponent* RootComponent;                                            // 0x0118(0x0008)
	struct FScriptMulticastDelegate                    OnInputTouchEnter;                                        // 0x0120(0x0010)
	struct FScriptMulticastDelegate                    OnTakeAnyDamage;                                          // 0x0130(0x0010)
	unsigned char                                      bHidden : 1;                                              // 0x0140(0x0001)
	unsigned char                                      bNetTemporary : 1;                                        // 0x0140(0x0001)
	unsigned char                                      bNetStartup : 1;                                          // 0x0140(0x0001)
	unsigned char                                      bOnlyRelevantToOwner : 1;                                 // 0x0140(0x0001)
	unsigned char                                      bOnlyRelevantToConnection : 1;                            // 0x0140(0x0001)
	unsigned char                                      bAlwaysRelevant : 1;                                      // 0x0140(0x0001)
	unsigned char                                      bReplicateMovement : 1;                                   // 0x0140(0x0001)
	unsigned char                                      bTearOff : 1;                                             // 0x0140(0x0001)
	unsigned char                                      bExchangedRoles : 1;                                      // 0x0141(0x0001)
	unsigned char                                      UnknownData05 : 1;                                        // 0x0141(0x0001)
	unsigned char                                      bNetLoadOnClient : 1;                                     // 0x0141(0x0001)
	unsigned char                                      bNetUseOwnerRelevancy : 1;                                // 0x0141(0x0001)
	unsigned char                                      bBlockInput : 1;                                          // 0x0141(0x0001)
	unsigned char                                      UnknownData06 : 1;                                        // 0x0141(0x0001)
	unsigned char                                      bAllowTickBeforeBeginPlay : 1;                            // 0x0141(0x0001)
	unsigned char                                      UnknownData07 : 1;                                        // 0x0141(0x0001)
	unsigned char                                      UnknownData08 : 2;                                        // 0x0142(0x0001)
	unsigned char                                      bActorEnableCollision : 1;                                // 0x0142(0x0001)
	TEnumAsByte<EAutoReceiveInput>                     AutoReceiveInput;                                         // 0x0143(0x0001)
	unsigned char                                      UnknownData09[0x4];                                       // 0x0144(0x0004) MISSED OFFSET
	TArray<struct FName>                               Tags;                                                     // 0x0148(0x0010)
	bool                                               bSupportSuspendTick;                                      // 0x0158(0x0001)
	unsigned char                                      UnknownData10[0x7];                                       // 0x0159(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnActorHit;                                               // 0x0160(0x0010)
	unsigned char                                      UnknownData11[0x8];                                       // 0x0170(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnInputTouchEnd;                                          // 0x0178(0x0010)
	unsigned char                                      UnknownData12[0x8];                                       // 0x0188(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnClicked;                                                // 0x0190(0x0010)
	struct FScriptMulticastDelegate                    OnActorEndOverlap;                                        // 0x01A0(0x0010)
	int                                                InputPriority;                                            // 0x01B0(0x0004)
	unsigned char                                      UnknownData13[0x4];                                       // 0x01B4(0x0004) MISSED OFFSET
	TArray<class UActorComponent*>                     InstanceComponents;                                       // 0x01B8(0x0010)
	struct FScriptMulticastDelegate                    OnTakePointDamage;                                        // 0x01C8(0x0010)
	TEnumAsByte<ENetRole>                              Role;                                                     // 0x01D8(0x0001)
	unsigned char                                      UnknownData14[0xF];                                       // 0x01D9(0x000F) MISSED OFFSET
	float                                              NetPriority;                                              // 0x01E8(0x0004)
	float                                              MinNetUpdateFrequency;                                    // 0x01EC(0x0004)
	float                                              NetUpdateFrequency;                                       // 0x01F0(0x0004)
	unsigned char                                      UnknownData15[0x4];                                       // 0x01F4(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnReleased;                                               // 0x01F8(0x0010)
	float                                              CustomTimeDilation;                                       // 0x0208(0x0004)
	unsigned char                                      UnknownData16[0x4];                                       // 0x020C(0x0004) MISSED OFFSET
	uint64_t                                           HiddenEditorViews;                                        // 0x0210(0x0008)
	TArray<class AMatineeActor*>                       ControllingMatineeActors;                                 // 0x0218(0x0010)
	struct FActorTickFunction                          PrimaryActorTick;                                         // 0x0228(0x0058)
	struct FScriptMulticastDelegate                    OnBeginCursorOver;                                        // 0x0280(0x0010)
	TEnumAsByte<ENetDormancy>                          NetDormancy;                                              // 0x0290(0x0001)
	unsigned char                                      UnknownData17[0x57];                                      // 0x0291(0x0057) MISSED OFFSET
	ESpawnActorCollisionHandlingMethod                 SpawnCollisionHandlingMethod;                             // 0x02E8(0x0001)
	unsigned char                                      UnknownData18[0x57];                                      // 0x02E9(0x0057) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnEndCursorOver;                                          // 0x0340(0x0010)
	TArray<class UActorComponent*>                     BlueprintCreatedComponents;                               // 0x0350(0x0010)
	class UInputComponent* InputComponent;                                           // 0x0360(0x0008)
	TWeakObjectPtr<class UChildActorComponent>         ParentComponent;                                          // 0x0368(0x0008)
	struct FScriptMulticastDelegate                    OnInputTouchLeave;                                        // 0x0370(0x0010)
	float                                              ForceReplicateInterleavingFreq;                           // 0x0380(0x0004)
	unsigned char                                      UnknownData19[0x4];                                       // 0x0384(0x0004) MISSED OFFSET
	class APawn* Instigator;                                               // 0x0388(0x0008)
	int                                                NetTag;                                                   // 0x0390(0x0004)
	unsigned char                                      UnknownData20[0x4];                                       // 0x0394(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDestroyed;                                              // 0x0398(0x0010)
	struct FScriptMulticastDelegate                    OnEndPlay;                                                // 0x03A8(0x0010)
	unsigned char                                      UnknownData21[0x8];                                       // 0x03B8(0x0008) MISSED OFFSET
};

class APawn : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x03C0(0x0008) MISSED OFFSET
	unsigned char                                      bUseControllerRotationPitch : 1;                          // 0x03C8(0x0001)
	unsigned char                                      bUseControllerRotationYaw : 1;                            // 0x03C8(0x0001)
	unsigned char                                      bUseControllerRotationRoll : 1;                           // 0x03C8(0x0001)
	unsigned char                                      bCanAffectNavigationGeneration : 1;                       // 0x03C8(0x0001)
	unsigned char                                      UnknownData01[0x3];                                       // 0x03C9(0x0003) MISSED OFFSET
	float                                              BaseEyeHeight;                                            // 0x03CC(0x0004)
	TEnumAsByte<EAutoReceiveInput>                     AutoPossessPlayer;                                        // 0x03D0(0x0001)
	EAutoPossessAI                                     AutoPossessAI;                                            // 0x03D1(0x0001)
	unsigned char                                      UnknownData02[0x6];                                       // 0x03D2(0x0006) MISSED OFFSET
	class UClass* AIControllerClass;                                        // 0x03D8(0x0008)
	unsigned char                                      RemoteViewPitch;                                          // 0x03E0(0x0001)
	unsigned char                                      UnknownData03[0x7];                                       // 0x03E1(0x0007) MISSED OFFSET
	class AController* LastHitBy;                                                // 0x03E8(0x0008)
	class AController* Controller;                                               // 0x03F0(0x0008)
	class APlayerState* PlayerState;                                              // 0x03F8(0x0008)
	unsigned char                                      UnknownData04[0x8];                                       // 0x0400(0x0008) MISSED OFFSET
	struct FVector                                     ControlInputVector;                                       // 0x0408(0x000C)
	struct FVector                                     LastControlInputVector;                                   // 0x0414(0x000C)
};

class ACharacter : public APawn
{
public:
	unsigned char                                      ReplicatedMovementMode;                                   // 0x0420(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0421(0x0003) MISSED OFFSET
	unsigned char                                      bPressedJump : 1;                                         // 0x0424(0x0001)
	unsigned char                                      bClientUpdating : 1;                                      // 0x0424(0x0001)
	unsigned char                                      bClientWasFalling : 1;                                    // 0x0424(0x0001)
	unsigned char                                      bClientResimulateRootMotion : 1;                          // 0x0424(0x0001)
	unsigned char                                      bClientResimulateRootMotionSources : 1;                   // 0x0424(0x0001)
	unsigned char                                      bSimGravityDisabled : 1;                                  // 0x0424(0x0001)
	unsigned char                                      bClientCheckEncroachmentOnNetUpdate : 1;                  // 0x0424(0x0001)
	unsigned char                                      bServerMoveIgnoreRootMotion : 1;                          // 0x0424(0x0001)
	unsigned char                                      UnknownData01[0xB];                                       // 0x0425(0x000B) MISSED OFFSET
	struct FQuat                                       BaseRotationOffset;                                       // 0x0430(0x0010)
	class UCapsuleComponent* CapsuleComponent;                                         // 0x0440(0x0008)
	struct FVector                                     BaseTranslationOffset;                                    // 0x0448(0x000C)
	unsigned char                                      UnknownData02 : 1;                                        // 0x0454(0x0001)
	unsigned char                                      bWasJumping : 1;                                          // 0x0454(0x0001)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0455(0x0003) MISSED OFFSET
	struct FBasedMovementInfo                          BasedMovement;                                            // 0x0458(0x0030)
	struct FBasedMovementInfo                          ReplicatedBasedMovement;                                  // 0x0488(0x0030)
	int                                                JumpCurrentCount;                                         // 0x04B8(0x0004)
	float                                              JumpMaxHoldTime;                                          // 0x04BC(0x0004)
	float                                              JumpKeyHoldTime;                                          // 0x04C0(0x0004)
	float                                              CrouchedEyeHeight;                                        // 0x04C4(0x0004)
	unsigned char                                      bIsCrouched : 1;                                          // 0x04C8(0x0001)
	unsigned char                                      UnknownData04[0x3];                                       // 0x04C9(0x0003) MISSED OFFSET
	int                                                JumpMaxCount;                                             // 0x04CC(0x0004)
	class UCharacterMovementComponent* CharacterMovement;                                        // 0x04D0(0x0008)
	class USkeletalMeshComponent* Mesh;                                                     // 0x04D8(0x0008)
	float                                              AnimRootMotionTranslationScale;                           // 0x04E0(0x0004)
	float                                              ReplicatedServerLastTransformUpdateTimeStamp;             // 0x04E4(0x0004)
	bool                                               bInBaseReplication;                                       // 0x04E8(0x0001)
	unsigned char                                      UnknownData05[0x7];                                       // 0x04E9(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnReachedJumpApex;                                        // 0x04F0(0x0010)
	unsigned char                                      UnknownData06[0x10];                                      // 0x0500(0x0010) MISSED OFFSET
	struct FScriptMulticastDelegate                    MovementModeChangedDelegate;                              // 0x0510(0x0010)
	struct FScriptMulticastDelegate                    OnCharacterMovementUpdated;                               // 0x0520(0x0010)
	struct FRootMotionSourceGroup                      SavedRootMotion;                                          // 0x0530(0x0100)
	struct FRootMotionMovementParams                   ClientRootMotionParams;                                   // 0x0630(0x0040)
	TArray<struct FSimulatedRootMotionReplicatedMove>  RootMotionRepMoves;                                       // 0x0670(0x0010)
	struct FRepRootMotionMontage                       RepRootMotion;                                            // 0x0680(0x0160)
};
class AUAECharacter : public ACharacter
{
public:
	bool                                               bIsAI;                                                    // 0x07E0(0x0001)
	unsigned char                                      UnknownData00[0x7];                                       // 0x07E1(0x0007) MISSED OFFSET
	TArray<struct FGameModePlayerItem>                 InitialItemList;                                          // 0x07E8(0x0010)
	uint32_t                                           PlayerKey;                                                // 0x07F8(0x0004)
	ECharacterGender                                   DefaultCharacterGender;                                   // 0x07FC(0x0001)
	unsigned char                                      UnknownData01[0x7];                                       // 0x07FD(0x0007) MISSED OFFSET
	int                                                TeamID;                                                   // 0x0804(0x0004)
	unsigned char                                      UnknownData02[0x10];                                      // 0x0808(0x0010) MISSED OFFSET
	struct FString                                     PlayerName;                                               // 0x0818(0x0010)
	unsigned char                                      UnknownData03[0x18];                                      // 0x0828(0x0018) MISSED OFFSET
};
class ASTExtraBaseCharacter : public AUAECharacter
{
public:
	unsigned char                                      UnknownData00[0x28];                                      // 0x0840(0x0028) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerWeaponChangeState;                                // 0x0868(0x0010)
	struct FVector                                     ScopeNewAimLoc;                                           // 0x0878(0x000C)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0884(0x0004) MISSED OFFSET
	class USTCharacterMovementComponent* STCharacterMovement;                                      // 0x0888(0x0008)
	float                                              HeavyFallVerticalVelocityThreshold;                       // 0x0890(0x0004)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0894(0x0004) MISSED OFFSET
	TArray<struct FDamageCauserRecordData>             DamageCauserRecords;                                      // 0x0898(0x0010)
	struct FScriptMulticastDelegate                    StateInterruptedHandlerBP;                                // 0x08A8(0x0010)
	struct FScriptMulticastDelegate                    FFailSkillPromptConditionEvent;                           // 0x08B8(0x0010)
	class USTCharacterRescueOtherComp* RescueOtherComponent;                                     // 0x08C8(0x0008)
	class UNavigationInvokerComponent* NavigationInvokerComponent;                               // 0x08D0(0x0008)
	float                                              SpeedDynamicScale;                                        // 0x08D8(0x0004)
	float                                              Money;                                                    // 0x08DC(0x0004)
	class UCustomSpringArmComponent* SpringArmComp;                                            // 0x08E0(0x0008)
	int                                                HandFolderRatio;                                          // 0x08E8(0x0004)
	unsigned char                                      UnknownData03[0x4];                                       // 0x08EC(0x0004) MISSED OFFSET
	class ASTExtraPlayerState* STExtraPlayerState;                                       // 0x08F0(0x0008)
	struct FBodyTypeDef                                StandBodyDef;                                             // 0x08F8(0x0008)
	float                                              FarDistanceAimFOV;                                        // 0x0900(0x0004)
	unsigned char                                      UnknownData04[0x8C];                                      // 0x0904(0x008C) MISSED OFFSET
	float                                              EnterNearDeathCDTimeInitValue;                            // 0x0990(0x0004)
	unsigned char                                      UnknownData05[0xC];                                       // 0x0994(0x000C) MISSED OFFSET
	class UBaseCharacterPickupProxy* PickupProxy;                                              // 0x09A0(0x0008)
	class UAkAudioEvent* VariableZoomStepAk;                                       // 0x09A8(0x0008)
	unsigned char                                      UnknownData06[0x8];                                       // 0x09B0(0x0008) MISSED OFFSET
	class UAttrModifyComponent* AttrModifyComp;                                           // 0x09B8(0x0008)
	float                                              LeanOffset_Prone;                                         // 0x09C0(0x0004)
	unsigned char                                      UnknownData07[0xC];                                       // 0x09C4(0x000C) MISSED OFFSET
	class UAkAudioEvent* PickupSound;                                              // 0x09D0(0x0008)
	bool                                               bShouldDrowningHurt;                                      // 0x09D8(0x0001)
	unsigned char                                      UnknownData08[0x3];                                       // 0x09D9(0x0003) MISSED OFFSET
	float                                              StandHalfHeight;                                          // 0x09DC(0x0004)
	unsigned char                                      UnknownData09[0x8];                                       // 0x09E0(0x0008) MISSED OFFSET
	TArray<class AActor*>                              InventoryData;                                            // 0x09E8(0x0010)
	int                                                LocalSimulateStates;                                      // 0x09F8(0x0004)
	struct FVector_NetQuantizeNormal                   LastAimOffsets;                                           // 0x09FC(0x000C)
	unsigned char                                      UnknownData10[0x10];                                      // 0x0A08(0x0010) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnHideUIAfterPlayerDeadDelegate;                          // 0x0A18(0x0010)
	unsigned char                                      UnknownData11[0x8];                                       // 0x0A28(0x0008) MISSED OFFSET
	struct FCharacterEnergyData                        Energy;                                                   // 0x0A30(0x0038)
	unsigned char                                      UnknownData12[0x8];                                       // 0x0A68(0x0008) MISSED OFFSET
	struct FTransform                                  HitBoxLeanTransL;                                         // 0x0A70(0x0030)
	float                                              AnimDeathLifeSpan;                                        // 0x0AA0(0x0004)
	unsigned char                                      UnknownData13[0x4];                                       // 0x0AA4(0x0004) MISSED OFFSET
	bool                                               IsInWater;                                                // 0x0AA8(0x0001)
	bool                                               IsWaterCanProne;                                          // 0x0AA9(0x0001)
	unsigned char                                      UnknownData14[0x2];                                       // 0x0AAA(0x0002) MISSED OFFSET
	float                                              AutoScopeDelayTimeWhenPeek;                               // 0x0AAC(0x0004)
	bool                                               bUseRagdoll;                                              // 0x0AB0(0x0001)
	unsigned char                                      UnknownData15[0x3];                                       // 0x0AB1(0x0003) MISSED OFFSET
	float                                              VehicleMaxShowDis;                                        // 0x0AB4(0x0004)
	bool                                               IsBeingRescued;                                           // 0x0AB8(0x0001)
	bool                                               FriendThread;                                             // 0x0AB9(0x0001)
	unsigned char                                      UnknownData16[0xE];                                       // 0x0ABA(0x000E) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerPickUp_Server;                                    // 0x0AC8(0x0010)
	unsigned char                                      UnknownData17[0x18];                                      // 0x0AD8(0x0018) MISSED OFFSET
	int                                                IsEnableReportRoute;                                      // 0x0AF0(0x0004)
	float                                              MaxSwimSprintSpeed;                                       // 0x0AF4(0x0004)
	unsigned char                                      UnknownData18[0xC];                                       // 0x0AF8(0x000C) MISSED OFFSET
	EInvincibleType                                    InvincibleType;                                           // 0x0B04(0x0001)
	unsigned char                                      UnknownData19[0x3];                                       // 0x0B05(0x0003) MISSED OFFSET
	unsigned char                                      bShowName : 1;                                            // 0x0B08(0x0001)
	unsigned char                                      bShowDamageToOther : 1;                                   // 0x0B08(0x0001)
	unsigned char                                      UnknownData20[0x7];                                       // 0x0B09(0x0007) MISSED OFFSET
	class UBaseCharacterEffectCom* EffectComponent;                                          // 0x0B10(0x0008)
	class UCameraComponent* ThirdPersonCameraComponent;                               // 0x0B18(0x0008)
	unsigned char                                      UnknownData21[0x4];                                       // 0x0B20(0x0004) MISSED OFFSET
	struct FPoseChangeTime                             SwitchPoseTime;                                           // 0x0B24(0x0018)
	unsigned char                                      UnknownData22[0x4];                                       // 0x0B3C(0x0004) MISSED OFFSET
	bool                                               IsHiddenUI;                                               // 0x0B40(0x0001)
	bool                                               bWeaponCollision;                                         // 0x0B41(0x0001)
	unsigned char                                      UnknownData23[0x2];                                       // 0x0B42(0x0002) MISSED OFFSET
	int                                                ServerSimulateStates;                                     // 0x0B44(0x0004)
	float                                              FPPFreeCameraRotationYawMax;                              // 0x0B48(0x0004)
	unsigned char                                      UnknownData24[0x4];                                       // 0x0B4C(0x0004) MISSED OFFSET
	bool                                               bSwitchingToGrenade;                                      // 0x0B50(0x0001)
	unsigned char                                      UnknownData25[0x3];                                       // 0x0B51(0x0003) MISSED OFFSET
	float                                              voiceCheckShowCD;                                         // 0x0B54(0x0004)
	unsigned char                                      UnknownData26[0x8];                                       // 0x0B58(0x0008) MISSED OFFSET
	float                                              LeanOffset_Crouch;                                        // 0x0B60(0x0004)
	unsigned char                                      UnknownData27[0x4];                                       // 0x0B64(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnAttachedToVehicle;                                      // 0x0B68(0x0010)
	bool                                               IsFPP;                                                    // 0x0B78(0x0001)
	unsigned char                                      UnknownData28[0x7];                                       // 0x0B79(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDoorInteraction_Server;                                 // 0x0B80(0x0010)
	struct FScriptMulticastDelegate                    OnBulletChange;                                           // 0x0B90(0x0010)
	float                                              UnderwaterSwimGapFromSurface;                             // 0x0BA0(0x0004)
	unsigned char                                      UnknownData29[0x4];                                       // 0x0BA4(0x0004) MISSED OFFSET
	struct FVector                                     NewProneHitBodyBoxScale;                                  // 0x0BA8(0x000C)
	bool                                               IsPeekRight;                                              // 0x0BB4(0x0001)
	unsigned char                                      UnknownData30[0x13];                                      // 0x0BB5(0x0013) MISSED OFFSET
	class UCapsuleComponent* ProneBoxComponent;                                        // 0x0BC8(0x0008)
	struct FScriptMulticastDelegate                    OnPlayerPickUp;                                           // 0x0BD0(0x0010)
	bool                                               IsPeekLeft;                                               // 0x0BE0(0x0001)
	unsigned char                                      UnknownData31[0x3];                                       // 0x0BE1(0x0003) MISSED OFFSET
	float                                              TurnNonLinearEndThreshold;                                // 0x0BE4(0x0004)
	unsigned char                                      UnknownData32[0x7C];                                      // 0x0BE8(0x007C) MISSED OFFSET
	float                                              FPPProneRotationYawMax;                                   // 0x0C64(0x0004)
	struct FScriptMulticastDelegate                    OnDetachedFromVehicle;                                    // 0x0C68(0x0010)
	struct FAnimStatusKeyList                          CurUpdateStatusKeyList;                                   // 0x0C78(0x0020)
	class USTCharacterFollowComp* AutoFollowComponent;                                      // 0x0C98(0x0008)
	float                                              FPPSwimRotationPitchMax;                                  // 0x0CA0(0x0004)
	unsigned char                                      UnknownData33[0x4];                                       // 0x0CA4(0x0004) MISSED OFFSET
	TMap<struct FString, EAvatarDamagePosition>        NewHitBodyPosMap;                                         // 0x0CA8(0x0050)
	struct FVector                                     MoveInputState;                                           // 0x0CF8(0x000C)
	bool                                               bIsLastTwoCircle;                                         // 0x0D04(0x0001)
	unsigned char                                      UnknownData34[0x3];                                       // 0x0D05(0x0003) MISSED OFFSET
	int                                                PrevServerSimulateStates;                                 // 0x0D08(0x0004)
	unsigned char                                      UnknownData35[0x4];                                       // 0x0D0C(0x0004) MISSED OFFSET
	TMap<int, float>                                   CachedReticleBrightnessMap;                               // 0x0D10(0x0050)
	struct FSoftClassPath                              AdaptiveCrosshairWidgetClass;                             // 0x0D60(0x0018)
	bool                                               IsEnablePeek;                                             // 0x0D78(0x0001)
	unsigned char                                      UnknownData36[0xF];                                       // 0x0D79(0x000F) MISSED OFFSET
	bool                                               bNonLinearTurn;                                           // 0x0D88(0x0001)
	unsigned char                                      UnknownData37[0x7];                                       // 0x0D89(0x0007) MISSED OFFSET
	struct FTransform                                  HitBoxLeanTransR;                                         // 0x0D90(0x0030)
	float                                              PointDamageForce_MapMax;                                  // 0x0DC0(0x0004)
	bool                                               UseShootVerifyEx;                                         // 0x0DC4(0x0001)
	unsigned char                                      UnknownData38[0x3];                                       // 0x0DC5(0x0003) MISSED OFFSET
	class UAkAudioEvent* SwitchSightSound;                                         // 0x0DC8(0x0008)
	unsigned char                                      UnknownData39[0x8];                                       // 0x0DD0(0x0008) MISSED OFFSET
	bool                                               bCollisionDebug;                                          // 0x0DD8(0x0001)
	unsigned char                                      UnknownData40[0x7];                                       // 0x0DD9(0x0007) MISSED OFFSET
	class ASTExtraVehicleBase* LatestVehicle;                                            // 0x0DE0(0x0008)
	unsigned char                                      UnknownData41[0x10];                                      // 0x0DE8(0x0010) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDoorInteractionDelegate;                                // 0x0DF8(0x0010)
	bool                                               bWasOnVehicle;                                            // 0x0E08(0x0001)
	unsigned char                                      UnknownData42[0x7];                                       // 0x0E09(0x0007) MISSED OFFSET
	class UAkComponent* FootstepSound_Comp;                                       // 0x0E10(0x0008)
	unsigned char                                      UnknownData43[0x50];                                      // 0x0E18(0x0050) MISSED OFFSET
	class UAdaptiveCrosshairWidget* AdaptiveCrosshairWidget;                                  // 0x0E68(0x0008)
	float                                              RelevantPlayerAIPolicyDecisionLogInterval;                // 0x0E70(0x0004)
	unsigned char                                      UnknownData44[0x4];                                       // 0x0E74(0x0004) MISSED OFFSET
	bool                                               bIsDelayingMove;                                          // 0x0E78(0x0001)
	unsigned char                                      UnknownData45[0x7];                                       // 0x0E79(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDeath;                                                  // 0x0E80(0x0010)
	unsigned char                                      UnknownData46[0x20];                                      // 0x0E90(0x0020) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerAttrChangeDelegate;                               // 0x0EB0(0x0010)
	unsigned char                                      UnknownData47[0x14];                                      // 0x0EC0(0x0014) MISSED OFFSET
	int                                                IsEnableReportPlayerBehavior;                             // 0x0ED4(0x0004)
	float                                              ScopeAimShootSpreadRotValMax;                             // 0x0ED8(0x0004)
	unsigned char                                      UnknownData48[0x4];                                       // 0x0EDC(0x0004) MISSED OFFSET
	class UMoveAntiCheatComponent* MoveAntiCheatComponent;                                   // 0x0EE0(0x0008)
	unsigned char                                      UnknownData49[0x4];                                       // 0x0EE8(0x0004) MISSED OFFSET
	int                                                CurrentReticleShapeIndex;                                 // 0x0EEC(0x0004)
	struct FName                                       HeadSocketName;                                           // 0x0EF0(0x0008)
	float                                              AimStateDrawTime;                                         // 0x0EF8(0x0004)
	unsigned char                                      UnknownData50[0x4];                                       // 0x0EFC(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    StateLeaveHandler;                                        // 0x0F00(0x0010)
	float                                              FPPPutDownWeaponCoolingEnd;                               // 0x0F10(0x0004)
	unsigned char                                      UnknownData51[0x1];                                       // 0x0F14(0x0001) MISSED OFFSET
	bool                                               bIsDrawLocation;                                          // 0x0F15(0x0001)
	TEnumAsByte<EHitPartJugementType>                  ClientHitPartJudgment;                                    // 0x0F16(0x0001)
	unsigned char                                      UnknownData52[0x5];                                       // 0x0F17(0x0005) MISSED OFFSET
	float                                              LeanOffset_Stand;                                         // 0x0F1C(0x0004)
	float                                              SwimableCharacterLengthOnSurface;                         // 0x0F20(0x0004)
	unsigned char                                      UnknownData53[0x8];                                       // 0x0F24(0x0008) MISSED OFFSET
	float                                              CrouchHalfHeight;                                         // 0x0F2C(0x0004)
	float                                              ScopeAimShootSpreadDecDirValSpeed;                        // 0x0F30(0x0004)
	unsigned char                                      UnknownData54[0x4];                                       // 0x0F34(0x0004) MISSED OFFSET
	class UEffectComponent* NewEffectComponent;                                       // 0x0F38(0x0008)
	float                                              TurnLinearEndThreshold;                                   // 0x0F40(0x0004)
	unsigned char                                      UnknownData55[0x8];                                       // 0x0F44(0x0008) MISSED OFFSET
	bool                                               bPeekLeftToggled;                                         // 0x0F4C(0x0001)
	bool                                               bPeekRightToggled;                                        // 0x0F4D(0x0001)
	unsigned char                                      UnknownData56[0x2];                                       // 0x0F4E(0x0002) MISSED OFFSET
	struct FVector_NetQuantizeNormal                   AimOffsets;                                               // 0x0F50(0x000C)
	unsigned char                                      UnknownData57[0x4];                                       // 0x0F5C(0x0004) MISSED OFFSET
	class UTslBreatheComp* BreatheComp;                                              // 0x0F60(0x0008)
	struct FKilledTipsBlock                            BlockData;                                                // 0x0F68(0x0038)
	class UClass* FPPAnimClass;                                             // 0x0FA0(0x0008)
	unsigned char                                      UnknownData58[0x10];                                      // 0x0FA8(0x0010) MISSED OFFSET
	class AController* NetOwnerController;                                       // 0x0FB8(0x0008)
	class UInteractorComponent* InteractorComponent;                                      // 0x0FC0(0x0008)
	class UCharacterInteractionComponent* InteractionComponent;                                     // 0x0FC8(0x0008)
	bool                                               bIsHoldingAngled;                                         // 0x0FD0(0x0001)
	unsigned char                                      UnknownData59[0x17];                                      // 0x0FD1(0x0017) MISSED OFFSET
	struct FScriptMulticastDelegate                    CharacterAnimEventDelegate;                               // 0x0FE8(0x0010)
	unsigned char                                      UnknownData60[0x8];                                       // 0x0FF8(0x0008) MISSED OFFSET
	struct FAnimParamList                              CurAnimParamList;                                         // 0x1000(0x00E8)
	bool                                               bMarkScopeLocDirty;                                       // 0x10E8(0x0001)
	unsigned char                                      UnknownData61[0x3];                                       // 0x10E9(0x0003) MISSED OFFSET
	float                                              HealthPredict;                                            // 0x10EC(0x0004)
	unsigned char                                      UnknownData62[0x8];                                       // 0x10F0(0x0008) MISSED OFFSET
	class ASTExtraBaseCharacter* WhoFollowMe;                                              // 0x10F8(0x0008)
	TArray<class ASTExtraPlayerController*>            MySpectators;                                             // 0x1100(0x0010)
	struct FBodyTypeDef                                DyingBodyDef;                                             // 0x1110(0x0008)
	unsigned char                                      UnknownData63[0x8];                                       // 0x1118(0x0008) MISSED OFFSET
	float                                              ScopeAimShootSpreadAddDirValSpeed;                        // 0x1120(0x0004)
	bool                                               IsAutoFollow;                                             // 0x1124(0x0001)
	unsigned char                                      UnknownData64[0x3];                                       // 0x1125(0x0003) MISSED OFFSET
	class ASTExtraWeapon* CurrentReloadWeapon;                                      // 0x1128(0x0008)
	TArray<struct FWeaponSlotSwitchTimeData>           SwitchSlotTimeDataList;                                   // 0x1130(0x0010)
	unsigned char                                      UnknownData65[0xC];                                       // 0x1140(0x000C) MISSED OFFSET
	float                                              CapsuleTurnInterpSpeedLocomotion;                         // 0x114C(0x0004)
	unsigned char                                      UnknownData66[0x20];                                      // 0x1150(0x0020) MISSED OFFSET
	bool                                               bUseSameTeamDamage;                                       // 0x1170(0x0001)
	TEnumAsByte<ESTEPoseState>                         PoseState;                                                // 0x1171(0x0001)
	unsigned char                                      UnknownData67[0x6];                                       // 0x1172(0x0006) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnReconnectNotifyDelegate;                                // 0x1178(0x0010)
	float                                              HeavyFallMovementStopTime;                                // 0x1188(0x0004)
	float                                              UpWaterHeight;                                            // 0x118C(0x0004)
	float                                              MiddleDistanceAimFOV;                                     // 0x1190(0x0004)
	struct FVector                                     LeanLeftTraceOffset;                                      // 0x1194(0x000C)
	float                                              ScopeMoveInOutSpeed;                                      // 0x11A0(0x0004)
	float                                              SprintingSmallGunMOdifier;                                // 0x11A4(0x0004)
	float                                              SprintingBigGunModifier;                                  // 0x11A8(0x0004)
	float                                              SprintingRifleModifier;                                   // 0x11AC(0x0004)
	float                                              BoostPhase3BuffSpeedModifier;                             // 0x11B0(0x0004)
	float                                              BoostPhase4BuffSpeedModifier;                             // 0x11B4(0x0004)
	unsigned char                                      UnknownData68[0x1];                                       // 0x11B8(0x0001) MISSED OFFSET
	bool                                               IsSwimUpWater;                                            // 0x11B9(0x0001)
	unsigned char                                      UnknownData69[0x6];                                       // 0x11BA(0x0006) MISSED OFFSET
	float                                              HealthMax;                                                // 0x11C0(0x0004)
	bool                                               hHasCallGameModeKill;                                     // 0x11C4(0x0001)
	unsigned char                                      UnknownData70[0x13];                                      // 0x11C5(0x0013) MISSED OFFSET
	struct FRotator                                    ServerControlRotation;                                    // 0x11D8(0x000C)
	unsigned char                                      UnknownData71[0xC];                                       // 0x11E4(0x000C) MISSED OFFSET
	unsigned char                                      bIgnoreInput : 1;                                         // 0x11F0(0x0001)
	unsigned char                                      UnknownData72[0x3];                                       // 0x11F1(0x0003) MISSED OFFSET
	float                                              FPPSkillPromptRotationYawMax;                             // 0x11F4(0x0004)
	class UClass* DeadInventoryBoxTemplate;                                 // 0x11F8(0x0008)
	float                                              BreathAmount;                                             // 0x1200(0x0004)
	unsigned char                                      UnknownData73[0x4];                                       // 0x1204(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    StateEnterHandler;                                        // 0x1208(0x0010)
	bool                                               bPressedSprint;                                           // 0x1218(0x0001)
	unsigned char                                      UnknownData74[0x3];                                       // 0x1219(0x0003) MISSED OFFSET
	struct FSyncAKEvent                                SyncAKEvent;                                              // 0x121C(0x0010)
	struct FBodyTypeDef                                VechicleBodyDef;                                          // 0x122C(0x0008)
	unsigned char                                      UnknownData75[0x4];                                       // 0x1234(0x0004) MISSED OFFSET
	unsigned char                                      bDead : 1;                                                // 0x1238(0x0001)
	unsigned char                                      UnknownData76[0x3];                                       // 0x1239(0x0003) MISSED OFFSET
	struct FAnimVehParamList                           CurAnimVehParamList;                                      // 0x123C(0x0018)
	float                                              FarRelevantDistanceSqured;                                // 0x1254(0x0004)
	int                                                VehicleSeatIdx;                                           // 0x1258(0x0004)
	float                                              PreviousValueToSetForHealthPredict;                       // 0x125C(0x0004)
	class UPlayerGunCollosionComp* PlayerGunCollosionComp;                                   // 0x1260(0x0008)
	unsigned char                                      UnknownData77[0xC];                                       // 0x1268(0x000C) MISSED OFFSET
	float                                              SwimUpRate;                                               // 0x1274(0x0004)
	struct FVector                                     NewStandHitBodyBoxScale;                                  // 0x1278(0x000C)
	unsigned char                                      UnknownData78[0x4];                                       // 0x1284(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnReloadEnd;                                              // 0x1288(0x0010)
	struct FScriptMulticastDelegate                    OnPreVaultServer;                                         // 0x1298(0x0010)
	unsigned char                                      UnknownData79[0x4];                                       // 0x12A8(0x0004) MISSED OFFSET
	struct FVector                                     CurInputVector;                                           // 0x12AC(0x000C)
	unsigned char                                      UnknownData80[0x4];                                       // 0x12B8(0x0004) MISSED OFFSET
	float                                              PeekCheckCollisionTimer_Local;                            // 0x12BC(0x0004)
	struct FPlayerVehAnimList                          CurPlayerVehAnimList;                                     // 0x12C0(0x0040)
	float                                              InteractAngleThreshold;                                   // 0x1300(0x0004)
	float                                              CapsuleTurnInterpSpeedLocomotionProne;                    // 0x1304(0x0004)
	class ULagCompensationComponent* LagCompensationComponent;                                 // 0x1308(0x0008)
	unsigned char                                      UnknownData81[0x8];                                       // 0x1310(0x0008) MISSED OFFSET
	float                                              TargetPlayerAIPolicyDecisionLogInterval;                  // 0x1318(0x0004)
	unsigned char                                      UnknownData82[0x4];                                       // 0x131C(0x0004) MISSED OFFSET
	TMap<int, int>                                     CachedReticleShapeIndexMap;                               // 0x1320(0x0050)
	unsigned char                                      UnknownData83[0x4];                                       // 0x1370(0x0004) MISSED OFFSET
	struct FVector                                     LeanRightTraceOffset;                                     // 0x1374(0x000C)
	unsigned char                                      UnknownData84[0x8];                                       // 0x1380(0x0008) MISSED OFFSET
	float                                              ScopeAimShootSpreadAddRotValSpeed;                        // 0x1388(0x0004)
	unsigned char                                      UnknownData85[0x4];                                       // 0x138C(0x0004) MISSED OFFSET
	TArray<class AActor*>                              PlayerSlotData;                                           // 0x1390(0x0010)
	struct FRotator                                    BlendTargetViewRotation;                                  // 0x13A0(0x000C)
	unsigned char                                      UnknownData86[0x4];                                       // 0x13AC(0x0004) MISSED OFFSET
	class UWeaponOwnerProxy* WeaponOwnerProxy;                                         // 0x13B0(0x0008)
	struct FScriptMulticastDelegate                    OnCharacterAttrChangedWithDetail;                         // 0x13B8(0x0010)
	unsigned char                                      UnknownData87[0xC];                                       // 0x13C8(0x000C) MISSED OFFSET
	unsigned char                                      CurrentWeaponZoomLevel;                                   // 0x13D4(0x0001)
	unsigned char                                      UnknownData88[0x13];                                      // 0x13D5(0x0013) MISSED OFFSET
	class UStaticMeshComponent* ScopComp;                                                 // 0x13E8(0x0008)
	float                                              voiceCheckCD;                                             // 0x13F0(0x0004)
	float                                              NetDelayMinAniCompensate;                                 // 0x13F4(0x0004)
	bool                                               bShowSkillPrompt;                                         // 0x13F8(0x0001)
	unsigned char                                      UnknownData89[0xF];                                       // 0x13F9(0x000F) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerPoseChange;                                       // 0x1408(0x0010)
	struct FScriptMulticastDelegate                    OnCharacterShootDelegate;                                 // 0x1418(0x0010)
	class USTCharacterNearDeathComp* NearDeatchComponent;                                      // 0x1428(0x0008)
	unsigned char                                      UnknownData90[0x8];                                       // 0x1430(0x0008) MISSED OFFSET
	float                                              FPPSkillPromptRotationPitchMax;                           // 0x1438(0x0004)
	unsigned char                                      UnknownData91[0x4];                                       // 0x143C(0x0004) MISSED OFFSET
	float                                              LeaveVehicleVelocityKeepTime;                             // 0x1440(0x0004)
	unsigned char                                      UnknownData92[0x4];                                       // 0x1444(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDoSomethingDelaySomeFrames;                             // 0x1448(0x0010)
	struct FVector2D                                   DesiredInput;                                             // 0x1458(0x0008)
	float                                              DelayHideDuration;                                        // 0x1460(0x0004)
	unsigned char                                      UnknownData93[0x18];                                      // 0x1464(0x0018) MISSED OFFSET
	bool                                               bHasStuckOperation;                                       // 0x147C(0x0001)
	unsigned char                                      UnknownData94[0x7];                                       // 0x147D(0x0007) MISSED OFFSET
	float                                              MinTurnAngleHip;                                          // 0x1484(0x0004)
	bool                                               bWeaponObstruct;                                          // 0x1488(0x0001)
	unsigned char                                      UnknownData95[0x7];                                       // 0x1489(0x0007) MISSED OFFSET
	TMap<EAvatarDamagePosition, struct FBodyPartCfg>   BodyPartConfigMap;                                        // 0x1490(0x0050)
	float                                              PointDamageForceMultiplier;                               // 0x14E0(0x0004)
	float                                              FPPSprintWeaponSmoothTime;                                // 0x14E4(0x0004)
	int                                                Head;                                                     // 0x14E8(0x0004)
	unsigned char                                      UnknownData96[0x4];                                       // 0x14EC(0x0004) MISSED OFFSET
	class UPlayerSwimComponent* swimComponet;                                             // 0x14F0(0x0008)
	unsigned char                                      UnknownData97[0x40];                                      // 0x14F8(0x0040) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnJoyStickInteruptDelegate;                               // 0x1538(0x0010)
	float                                              CapsuleTurnInterpSpeedLocomotionSprint;                   // 0x1548(0x0004)
	unsigned char                                      UnknownData98[0x4];                                       // 0x154C(0x0004) MISSED OFFSET
	bool                                               bIsWeaponFiring;                                          // 0x1550(0x0001)
	unsigned char                                      UnknownData99[0xF];                                       // 0x1551(0x000F) MISSED OFFSET
	struct FScriptMulticastDelegate                    IsEnterNearDeathDelegate;                                 // 0x1560(0x0010)
	unsigned char                                      UnknownData100[0x4];                                      // 0x1570(0x0004) MISSED OFFSET
	float                                              RefreshUITimeAfterSpawn;                                  // 0x1574(0x0004)
	float                                              WaterHeightOffset;                                        // 0x1578(0x0004)
	unsigned char                                      UnknownData101[0x40];                                     // 0x157C(0x0040) MISSED OFFSET
	float                                              HitStateOffDelayTime;                                     // 0x15BC(0x0004)
	struct FName                                       EmoteSlots;                                               // 0x15C0(0x0008)
	class UCurveFloat* Curve_TurningLerp;                                        // 0x15C8(0x0008)
	bool                                               bIsGunADS;                                                // 0x15D0(0x0001)
	unsigned char                                      UnknownData102[0x3];                                      // 0x15D1(0x0003) MISSED OFFSET
	float                                              PawnBackpackCapacity;                                     // 0x15D4(0x0004)
	struct FScriptMulticastDelegate                    OnPlayerHandFoldedChanged;                                // 0x15D8(0x0010)
	struct FScriptMulticastDelegate                    OnCharacterAimModeChanged;                                // 0x15E8(0x0010)
	float                                              maxShowAlpha;                                             // 0x15F8(0x0004)
	float                                              WataerSurfaceZOffset;                                     // 0x15FC(0x0004)
	unsigned char                                      UnknownData103[0x8];                                      // 0x1600(0x0008) MISSED OFFSET
	class ASTExtraVehicleBase* CurrentVehicle;                                           // 0x1608(0x0008)
	TEnumAsByte<ETeamNumber>                           TeamNum;                                                  // 0x1610(0x0001)
	unsigned char                                      UnknownData104[0x7];                                      // 0x1611(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerPawnHPChange;                                     // 0x1618(0x0010)
	unsigned char                                      UnknownData105[0x8];                                      // 0x1628(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnChangedVehicleSeat;                                     // 0x1630(0x0010)
	TEnumAsByte<EMovementMode>                         MovementModeBeforeNearDeath;                              // 0x1640(0x0001)
	unsigned char                                      UnknownData106[0x3];                                      // 0x1641(0x0003) MISSED OFFSET
	float                                              AimStateDefaultTime;                                      // 0x1644(0x0004)
	class UAkAudioEvent* DeathSound;                                               // 0x1648(0x0008)
	float                                              TurnInPlaceAngel;                                         // 0x1650(0x0004)
	unsigned char                                      UnknownData107[0x4];                                      // 0x1654(0x0004) MISSED OFFSET
	float                                              AimoffsetsLastRepTime;                                    // 0x1658(0x0004)
	unsigned char                                      UnknownData108[0x4];                                      // 0x165C(0x0004) MISSED OFFSET
	struct FAnimStatusKeyList                          LastUpdateStatusKeyList;                                  // 0x1660(0x0020)
	unsigned char                                      UnknownData109[0xC];                                      // 0x1680(0x000C) MISSED OFFSET
	float                                              SwimableWaterDepth;                                       // 0x168C(0x0004)
	float                                              FPPPutDownWeaponCoolingStart;                             // 0x1690(0x0004)
	unsigned char                                      UnknownData110[0x4];                                      // 0x1694(0x0004) MISSED OFFSET
	class UAkAudioEvent* MountAccessoriesSound;                                    // 0x1698(0x0008)
	unsigned char                                      UnknownData111[0x4];                                      // 0x16A0(0x0004) MISSED OFFSET
	float                                              RefreshUITimeAfterSpawnInterval;                          // 0x16A4(0x0004)
	struct FScriptMulticastDelegate                    OnCharacterStopFireDelegate;                              // 0x16A8(0x0010)
	bool                                               EnableStatesInterruptRPC;                                 // 0x16B8(0x0001)
	unsigned char                                      UnknownData112[0x7];                                      // 0x16B9(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerTeleport;                                         // 0x16C0(0x0010)
	unsigned char                                      UnknownData113[0x8];                                      // 0x16D0(0x0008) MISSED OFFSET
	class UAkComponent* WeaponSound_Comp;                                         // 0x16D8(0x0008)
	bool                                               bHasHandleDead;                                           // 0x16E0(0x0001)
	unsigned char                                      UnknownData114[0x7];                                      // 0x16E1(0x0007) MISSED OFFSET
	class UTslPlayerDamageConfig* DamageConfig;                                             // 0x16E8(0x0008)
	float                                              RadialDamageForceMultiplier;                              // 0x16F0(0x0004)
	bool                                               IsPressedWalk;                                            // 0x16F4(0x0001)
	unsigned char                                      UnknownData115[0x3];                                      // 0x16F5(0x0003) MISSED OFFSET
	float                                              ScopeLagScale;                                            // 0x16F8(0x0004)
	int                                                SkillPromptItemID;                                        // 0x16FC(0x0004)
	float                                              Health;                                                   // 0x1700(0x0004)
	unsigned char                                      UnknownData116[0x4];                                      // 0x1704(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnPlayerEnterRescueingStatus;                             // 0x1708(0x0010)
	unsigned char                                      UnknownData117[0x8];                                      // 0x1718(0x0008) MISSED OFFSET
	class UClass* AutoEquipWeaponTemplate;                                  // 0x1720(0x0008)
	class UCharacterAvatarComponent* AvatarComponent;                                          // 0x1728(0x0008)
	unsigned char                                      UnknownData118[0xC];                                      // 0x1730(0x000C) MISSED OFFSET
	float                                              ValueLimitForHealthPredict;                               // 0x173C(0x0004)
	struct FScriptMulticastDelegate                    OnHit;                                                    // 0x1740(0x0010)
	struct FBodyTypeDef                                ProneBodyDef;                                             // 0x1750(0x0008)
	float                                              ScopeAimShootSpreadDecRotValSpeed;                        // 0x1758(0x0004)
	float                                              MiddleRelevantDistanceSqured;                             // 0x175C(0x0004)
	float                                              CorpseLifeSpan;                                           // 0x1760(0x0004)
	unsigned char                                      UnknownData119[0x4];                                      // 0x1764(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnCharacterStartFireDelegate;                             // 0x1768(0x0010)
	unsigned char                                      UnknownData120[0x8];                                      // 0x1778(0x0008) MISSED OFFSET
	float                                              TurnSpeedHip;                                             // 0x1780(0x0004)
	float                                              ScopeAimShootSpreadDirValMax;                             // 0x1784(0x0004)
	unsigned char                                      UnknownData121[0xC];                                      // 0x1788(0x000C) MISSED OFFSET
	float                                              WaterFloorDetectionLength;                                // 0x1794(0x0004)
	class UAkAudioEvent* AmbientSound;                                             // 0x1798(0x0008)
	float                                              ProneHalfHeight;                                          // 0x17A0(0x0004)
	float                                              ExtremeFallMovementStopTime;                              // 0x17A4(0x0004)
	unsigned char                                      UnknownData122[0x4];                                      // 0x17A8(0x0004) MISSED OFFSET
	bool                                               bVaultIsOpen;                                             // 0x17AC(0x0001)
	unsigned char                                      UnknownData123[0x3];                                      // 0x17AD(0x0003) MISSED OFFSET
	float                                              NetCullingDistanceOnVeryLowDevice;                        // 0x17B0(0x0004)
	unsigned char                                      UnknownData124[0x4];                                      // 0x17B4(0x0004) MISSED OFFSET
	class ASTExtraPlayerState* WhoKillMeRecord;                                          // 0x17B8(0x0008)
	unsigned char                                      bDying : 1;                                               // 0x17C0(0x0001)
	unsigned char                                      UnknownData125[0xB];                                      // 0x17C1(0x000B) MISSED OFFSET
	struct FSTParachuteState                           STReplicateParchuteState;                                 // 0x17CC(0x000C)
	struct FSTReplicatedMoveState                      STReplicatedParachuteMoveState;                           // 0x17D8(0x0024)
	bool                                               bReplicatedIsStartParachute;                              // 0x17FC(0x0001)
	unsigned char                                      UnknownData126[0x3];                                      // 0x17FD(0x0003) MISSED OFFSET
	float                                              MoveForwardInputValue;                                    // 0x1800(0x0004)
	float                                              MoveRightInputValue;                                      // 0x1804(0x0004)
	unsigned char                                      UnknownData127[0x4];                                      // 0x1808(0x0004) MISSED OFFSET
	float                                              ExtremeFallVerticalVelocityThreshold;                     // 0x180C(0x0004)
	struct FRotator                                    ScopeAimShootSpreadRot;                                   // 0x1810(0x000C)
	float                                              PickUpRadius;                                             // 0x181C(0x0004)
	struct FName                                       TPPCameraBoneName;                                        // 0x1820(0x0008)
	unsigned char                                      UnknownData128[0x1];                                      // 0x1828(0x0001) MISSED OFFSET
	TEnumAsByte<EHitPartJugementType>                  DSHitPartJudgment;                                        // 0x1829(0x0001)
	unsigned char                                      UnknownData129[0xA];                                      // 0x182A(0x000A) MISSED OFFSET
	float                                              VoiceCheckDis;                                            // 0x1834(0x0004)
	struct FVector                                     LandPredictedLocation_CP;                                 // 0x1838(0x000C)
	unsigned char                                      UnknownData130[0x4];                                      // 0x1844(0x0004) MISSED OFFSET
	float                                              DeadInventoryBoxOverrideFindPutDownPointZThreshold;       // 0x1848(0x0004)
	unsigned char                                      UnknownData131[0x4];                                      // 0x184C(0x0004) MISSED OFFSET
	float                                              AttackStateOffDelayTime;                                  // 0x1850(0x0004)
	unsigned char                                      UnknownData132[0x4];                                      // 0x1854(0x0004) MISSED OFFSET
	struct FPlayerAnimList                             CurPlayerAnimList;                                        // 0x1858(0x00F0)
	class UCharacterParachuteComponent* ParachuteComponent;                                       // 0x1948(0x0008)
	struct FBodyTypeDef                                CrouchBodyDef;                                            // 0x1950(0x0008)
	float                                              WeaponMaxShowDis;                                         // 0x1958(0x0004)
	unsigned char                                      UnknownData133[0x1];                                      // 0x195C(0x0001) MISSED OFFSET
	bool                                               bCheckRelevantWithFOV;                                    // 0x195D(0x0001)
	unsigned char                                      UnknownData134[0x6];                                      // 0x195E(0x0006) MISSED OFFSET
	float                                              MoveMaxShowDis;                                           // 0x1964(0x0004)
	unsigned char                                      UnknownData135[0x10];                                     // 0x1968(0x0010) MISSED OFFSET
	class UAkComponent* AmbientSound_Comp;                                        // 0x1978(0x0008)
	struct FScriptMulticastDelegate                    OnPreVaultClient;                                         // 0x1980(0x0010)
	unsigned char                                      UnknownData136[0x4];                                      // 0x1990(0x0004) MISSED OFFSET
	bool                                               PeekHasCollision;                                         // 0x1994(0x0001)
	unsigned char                                      UnknownData137[0x3];                                      // 0x1995(0x0003) MISSED OFFSET
	TArray<struct FHealthPredictShowData>              HealthPredictShowDataList;                                // 0x1998(0x0010)
	TEnumAsByte<ESTEPoseState>                         LastPoseState;                                            // 0x19A8(0x0001)
	unsigned char                                      UnknownData138[0xF];                                      // 0x19A9(0x000F) MISSED OFFSET
	float                                              CurrentReticleBrightness;                                 // 0x19B8(0x0004)
	unsigned char                                      UnknownData139[0xC];                                      // 0x19BC(0x000C) MISSED OFFSET
	class USecuryInfoComponent* SecuryComponent;                                          // 0x19C8(0x0008)
	float                                              SwimableCharacterLengthOnSurfaceWhenSwimming;             // 0x19D0(0x0004)
	struct FVector                                     ScopeNewTargetLoc;                                        // 0x19D4(0x000C)
	unsigned char                                      UnknownData140[0x8];                                      // 0x19E0(0x0008) MISSED OFFSET
	class UParachuteFollowComponent* ParachuteFollowComp;                                      // 0x19E8(0x0008)
	TArray<class ASTExtraBaseCharacter*>               FlyingTeam;                                               // 0x19F0(0x0010)
	class ASTExtraBaseCharacter* Leader;                                                   // 0x1A00(0x0008)
	EFollowState                                       FollowState;                                              // 0x1A08(0x0001)
	unsigned char                                      UnknownData141[0x7];                                      // 0x1A09(0x0007) MISSED OFFSET
	TArray<struct FParachuteFollowState>               TeammateParachuteFollowState;                             // 0x1A10(0x0010)
	TArray<class ASTExtraBaseCharacter*>               Inviters;                                                 // 0x1A20(0x0010)
	class UAkAudioEvent* SwitchFireModeSound;                                      // 0x1A30(0x0008)
	unsigned char                                      UnknownData142[0x1];                                      // 0x1A38(0x0001) MISSED OFFSET
	TEnumAsByte<EThrowGrenadeMode>                     ThrowGrenadeMode;                                         // 0x1A39(0x0001)
	bool                                               bSimulatePressedSprint;                                   // 0x1A3A(0x0001)
	unsigned char                                      UnknownData143[0x5];                                      // 0x1A3B(0x0005) MISSED OFFSET
	struct FVector                                     ScopeNewIdleLoc;                                          // 0x1A40(0x000C)
	unsigned char                                      IsFiveTimesWalkSpeed : 1;                                 // 0x1A4C(0x0001)
	unsigned char                                      UnknownData144[0x3];                                      // 0x1A4D(0x0003) MISSED OFFSET
	float                                              AimStateReturnTime;                                       // 0x1A50(0x0004)
	float                                              PointDamageForce_MapMin;                                  // 0x1A54(0x0004)
	bool                                               bUsingFreeCamera;                                         // 0x1A58(0x0001)
	unsigned char                                      UnknownData145[0x3];                                      // 0x1A59(0x0003) MISSED OFFSET
	float                                              ScopeAimCrosshairUIScale;                                 // 0x1A5C(0x0004)
	unsigned char                                      UnknownData146[0x8];                                      // 0x1A60(0x0008) MISSED OFFSET
	bool                                               EnableSprintSync;                                         // 0x1A68(0x0001)
	unsigned char                                      UnknownData147[0x7];                                      // 0x1A69(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnStartInitDelegate;                                      // 0x1A70(0x0010)
	unsigned char                                      UnknownData148[0x80];                                     // 0x1A80(0x0080) MISSED OFFSET
	bool                                               IsRescueingOther;                                         // 0x1B00(0x0001)
	unsigned char                                      UnknownData149[0x3];                                      // 0x1B01(0x0003) MISSED OFFSET
	struct FVector                                     ScopeAimShootSpreadDir;                                   // 0x1B04(0x000C)
	class UCurveFloat* Curve_TurningLerpLocomotion;                              // 0x1B10(0x0008)
	float                                              FreeCameraRestoreTime;                                    // 0x1B18(0x0004)
	unsigned char                                      UnknownData150[0xDC];                                     // 0x1B1C(0x00DC) MISSED OFFSET
	float                                              FOV_OnScopingEaseExp;                                     // 0x1BF8(0x0004)
	unsigned char                                      UnknownData151[0x4];                                      // 0x1BFC(0x0004) MISSED OFFSET
	class UCurveFloat* CameraFovRatioCurve;                                      // 0x1C00(0x0008)
	class UCurveVector* Curve_FPPCameraOffsetByFOV;                               // 0x1C08(0x0008)
	class UCurveFloat* AngledCurve;                                              // 0x1C10(0x0008)
	struct FScriptMulticastDelegate                    OnWeaponFireModeChangeDelegate;                           // 0x1C18(0x0010)
	unsigned char                                      UnknownData152[0x8];                                      // 0x1C28(0x0008) MISSED OFFSET
	TEnumAsByte<ECharacterHealthStatus>                HealthStatus;                                             // 0x1C30(0x0001)
	unsigned char                                      UnknownData153[0x67];                                     // 0x1C31(0x0067) MISSED OFFSET
	class UCharacterWeaponManagerComponent* WeaponManagerComponent;                                   // 0x1C98(0x0008)
	unsigned char                                      UnknownData154[0x60];                                     // 0x1CA0(0x0060) MISSED OFFSET
	class UAkAudioEvent* ThrowawayWeaponSound;                                     // 0x1D00(0x0008)
	class UTslEmoteComponent* EmoteComponent;                                           // 0x1D08(0x0008)
	int                                                FirstDamageTypeSpesificID;                                // 0x1D10(0x0004)
	unsigned char                                      UnknownData155[0x4];                                      // 0x1D14(0x0004) MISSED OFFSET
	class USTBaseBuffSystemComponent* BuffSystemComponent;                                      // 0x1D18(0x0008)
	unsigned char                                      UnknownData156[0x4];                                      // 0x1D20(0x0004) MISSED OFFSET
	int                                                CurrentEmoteIndex;                                        // 0x1D24(0x0004)
	int                                                CurrentEmoteID;                                           // 0x1D28(0x0004)
	unsigned char                                      UnknownData157[0x4];                                      // 0x1D2C(0x0004) MISSED OFFSET
	struct FScriptMulticastDelegate                    EmoteMontageFinishedEvent;                                // 0x1D30(0x0010)
	unsigned char                                      UnknownData158[0x28];                                     // 0x1D40(0x0028) UNKNOWN PROPERTY: SoftObjectProperty ShadowTrackerExtra.STExtraBaseCharacter.TempEmoteResource|TempEmoteResource
	unsigned char                                      UnknownData159[0x40];                                     // 0x1D68(0x0040) MISSED OFFSET
	struct FVector                                     EmoteColBox;                                              // 0x1DA8(0x000C)
	unsigned char                                      UnknownData160[0x4];                                      // 0x1DB4(0x0004) MISSED OFFSET
	class UHackReporterComponent* HackReporterComponent;                                    // 0x1DB8(0x0008)
	struct FScriptMulticastDelegate                    OnPlayerRespawnInvincible;                                // 0x1DC0(0x0010)
	struct FScriptMulticastDelegate                    OnPlayerHealStart;                                        // 0x1DD0(0x0010)
	struct FScriptMulticastDelegate                    OnPlayerHealEnd;                                          // 0x1DE0(0x0010)
	unsigned char                                      UnknownData161[0x20];                                     // 0x1DF0(0x0020) MISSED OFFSET
	int                                                SpectatedCount;                                           // 0x1E10(0x0004)
	bool                                               bSprintingAuto;                                           // 0x1E14(0x0001)
	unsigned char                                      UnknownData162[0x3];                                      // 0x1E15(0x0003) MISSED OFFSET
	struct FVector                                     JumpStartLocation_CP;                                     // 0x1E18(0x000C)
	float                                              FallHeight_CP;                                            // 0x1E24(0x0004)
	bool                                               bServerFinishedVault;                                     // 0x1E28(0x0001)
	unsigned char                                      UnknownData163[0x3];                                      // 0x1E29(0x0003) MISSED OFFSET
	struct FVector                                     VaultEndVelocity_CP;                                      // 0x1E2C(0x000C)
	struct FVector                                     VaultLastLocation_CP;                                     // 0x1E38(0x000C)
	unsigned char                                      UnknownData164[0xC];                                      // 0x1E44(0x000C) MISSED OFFSET
};


// Class ShadowTrackerExtra.STExtraPlayerCharacter
// 0x0250 (0x20A0 - 0x1E50)
class ASTExtraPlayerCharacter : public ASTExtraBaseCharacter
{
public:
	struct FCameraSettings                             FreefallCameraSetting;                                    // 0x1E50(0x0014)
	unsigned char                                      UnknownData00[0x4];                                       // 0x1E64(0x0004) MISSED OFFSET
	float                                              VehicleForwardInputRate;                                  // 0x1E68(0x0004)
	float                                              IndoorCheckDistance;                                      // 0x1E6C(0x0004)
	bool                                               bDrawBoxEarBulletOverlapRay;                              // 0x1E70(0x0001)
	unsigned char                                      UnknownData01[0x3];                                       // 0x1E71(0x0003) MISSED OFFSET
	struct FParachuteStateParams                       ParachuteOpeningParams;                                   // 0x1E74(0x0034)
	unsigned char                                      UnknownData02[0x8];                                       // 0x1EA8(0x0008) MISSED OFFSET
	class UAimingComp* AimingComponent;                                          // 0x1EB0(0x0008)
	struct FScriptMulticastDelegate                    OnSkillFinishedDelegate;                                  // 0x1EB8(0x0010)
	class UCharacterInterpRotationComp* InterpRotationComp;                                       // 0x1EC8(0x0008)
	unsigned char                                      UnknownData03[0x4];                                       // 0x1ED0(0x0004) MISSED OFFSET
	bool                                               bInputMoveRight;                                          // 0x1ED4(0x0001)
	unsigned char                                      UnknownData04[0x3];                                       // 0x1ED5(0x0003) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnHasPickupPropsAvailableChanged;                         // 0x1ED8(0x0010)
	unsigned char                                      UnknownData05[0x14];                                      // 0x1EE8(0x0014) MISSED OFFSET
	float                                              FootSoundObstructionCheckInterval;                        // 0x1EFC(0x0004)
	float                                              VehicleRightInputRate;                                    // 0x1F00(0x0004)
	unsigned char                                      UnknownData06[0xC];                                       // 0x1F04(0x000C) MISSED OFFSET
	float                                              SwimRotateX_Ex;                                           // 0x1F10(0x0004)
	float                                              HaveToLandHeightToGround;                                 // 0x1F14(0x0004)
	unsigned char                                      UnknownData07[0x10];                                      // 0x1F18(0x0010) MISSED OFFSET
	class UWeaponAutoAimingComponent* AutoAimComp;                                              // 0x1F28(0x0008)
	float                                              IndoorCheckTime;                                          // 0x1F30(0x0004)
	unsigned char                                      UnknownData08[0x4];                                       // 0x1F34(0x0004) MISSED OFFSET
	class USTScreenAppearanceComponent* ScreenAppearaceComp;                                      // 0x1F38(0x0008)
	TEnumAsByte<EParachuteState>                       ParachuteState;                                           // 0x1F40(0x0001)
	unsigned char                                      UnknownData09[0x3];                                       // 0x1F41(0x0003) MISSED OFFSET
	int                                                IndoorCheckAccuracyMultiplier;                            // 0x1F44(0x0004)
	float                                              IndoorCheckSuccessRate;                                   // 0x1F48(0x0004)
	unsigned char                                      UnknownData10[0x4];                                       // 0x1F4C(0x0004) MISSED OFFSET
	float                                              IndoorCheckHalfConeAngle;                                 // 0x1F50(0x0004)
	int                                                IndoorCheckSamplingQueueSize;                             // 0x1F54(0x0004)
	class UParticleSystemComponent* SwimWaveEffectComponent;                                  // 0x1F58(0x0008)
	struct FScriptMulticastDelegate                    OnHasTombBoxesAvailableChanged;                           // 0x1F60(0x0010)
	TEnumAsByte<EParachuteState>                       LastParachuteState;                                       // 0x1F70(0x0001)
	unsigned char                                      UnknownData11[0x3];                                       // 0x1F71(0x0003) MISSED OFFSET
	struct FParachuteStateParams                       ParachuteFreeFallingParams;                               // 0x1F74(0x0034)
	unsigned char                                      UnknownData12[0x28];                                      // 0x1FA8(0x0028) UNKNOWN PROPERTY: SoftClassProperty ShadowTrackerExtra.STExtraPlayerCharacter.SettleAccountUI|SettleAccountUI
	float                                              SwimZDir;                                                 // 0x1FD0(0x0004)
	unsigned char                                      UnknownData13[0x4];                                       // 0x1FD4(0x0004) MISSED OFFSET
	class UBoxComponent* BoxEar;                                                   // 0x1FD8(0x0008)
	unsigned char                                      UnknownData14[0x8];                                       // 0x1FE0(0x0008) MISSED OFFSET
	class ASTExtraPlayerController* STPlayerController;                                       // 0x1FE8(0x0008)
	bool                                               bIsStillParachuting;                                      // 0x1FF0(0x0001)
	bool                                               Indoor;                                                   // 0x1FF1(0x0001)
	unsigned char                                      UnknownData15[0x2];                                       // 0x1FF2(0x0002) MISSED OFFSET
	float                                              IndoorLowerCameraHeight;                                  // 0x1FF4(0x0004)
	bool                                               bInputMoveForward;                                        // 0x1FF8(0x0001)
	unsigned char                                      UnknownData16[0x7];                                       // 0x1FF9(0x0007) MISSED OFFSET
	struct FBulletFlySoundReplicatedData               BulletFlySoundReplicatedData;                             // 0x2000(0x0018)
	unsigned char                                      UnknownData17[0x10];                                      // 0x2018(0x0010) MISSED OFFSET
	float                                              FootSoundObstructionCheckMaxDistance;                     // 0x2028(0x0004)
	unsigned char                                      UnknownData18[0x14];                                      // 0x202C(0x0014) MISSED OFFSET
	struct FCameraSettings                             OpeningCameraSetting;                                     // 0x2040(0x0014)
	unsigned char                                      UnknownData19[0x4];                                       // 0x2054(0x0004) MISSED OFFSET
	TArray<struct FString>                             CurrentVisitingLocationNames;                             // 0x2058(0x0010)
	struct FSoftClassPath                              SkydivingComponentClass;                                  // 0x2068(0x0018)
	class UTslSkydiveComponent* SkydivingComponent;                                       // 0x2080(0x0008)
	unsigned char                                      UnknownData20[0x8];                                       // 0x2088(0x0008) MISSED OFFSET
	ESurviveWeaponPropSlot                             LastEquipedWeaponIndex;                                   // 0x2090(0x0001)
	unsigned char                                      UnknownData21[0xF];                                       // 0x2091(0x000F) MISSED OFFSET
};
