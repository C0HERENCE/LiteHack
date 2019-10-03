#pragma once
#include "..//..//Utils/ida_defs.h"
#include "FVector.h"
#include "Rotator.h"

template<class TEnum>
class TEnumAsByte
{
private:
	uint8  Value;
};

enum class EVectorQuantization : uint8
{
	/** Each vector component will be rounded to the nearest whole number. */
	RoundWholeNumber,
	/** Each vector component will be rounded, preserving one decimal place. */
	RoundOneDecimal,
	/** Each vector component will be rounded, preserving two decimal places. */
	RoundTwoDecimals
};
enum class ERotatorQuantization : uint8
{
	/** The rotator will be compressed to 8 bits per component. */
	ByteComponents,
	/** The rotator will be compressed to 16 bits per component. */
	ShortComponents
};
enum class ESpawnActorCollisionHandlingMethod : uint8
{
	/** Fall back to default settings. */
	Undefined,
	/** Actor will spawn in desired location, regardless of collisions. */
	AlwaysSpawn,
	/** Actor will try to find a nearby non-colliding location (based on shape components), but will always spawn even if one cannot be found. */
	AdjustIfPossibleButAlwaysSpawn,
	/** Actor will try to find a nearby non-colliding location (based on shape components), but will NOT spawn unless one is found. */
	AdjustIfPossibleButDontSpawnIfColliding,
	/** Actor will fail to spawn. */
	DontSpawnIfColliding,
};
enum ENetDormancy
{
	/** This actor can never go network dormant. */
	DORM_Never,
	/** This actor can go dormant, but is not currently dormant. Game code will tell it when it go dormant. */
	DORM_Awake,
	/** This actor wants to go fully dormant for all connections. */
	DORM_DormantAll,
	/** This actor may want to go dormant for some connections, GetNetDormancy() will be called to find out which. */
	DORM_DormantPartial,
	/** This actor is initially dormant for all connection if it was placed in map. */
	DORM_Initial,
	DORN_MAX,
};
enum ENetRole
{
	/** No role at all. */
	ROLE_None,
	/** Locally simulated proxy of this actor. */
	ROLE_SimulatedProxy,
	/** Locally autonomous proxy of this actor. */
	ROLE_AutonomousProxy,
	/** Authoritative control over the actor. */
	ROLE_Authority,
	ROLE_MAX,
};
enum ETickingGroup
{
	/** Any item that needs to be executed before physics simulation starts. */
	TG_PrePhysics,

	/** Special tick group that starts physics simulation. */
	TG_StartPhysics,

	/** Any item that can be run in parallel with our physics simulation work. */
	TG_DuringPhysics,

	/** Special tick group that ends physics simulation. */
	TG_EndPhysics,

	/** Any item that needs rigid body and cloth simulation to be complete before being executed. */
	TG_PostPhysics,

	/** Any item that needs the update work to be done before being ticked. */
	TG_PostUpdateWork,

	/** Catchall for anything demoted to the end. */
	TG_LastDemotable,

	/** Special tick group that is not actually a tick group. After every tick group this is repeatedly re-run until there are no more newly spawned items to run. */
	TG_NewlySpawned,

	TG_MAX,
};
enum class EAutoPossessAI : uint8
{
	/** Feature is disabled (do not automatically possess AI). */
	Disabled,
	/** Only possess by an AI Controller if Pawn is placed in the world. */
	PlacedInWorld,
	/** Only possess by an AI Controller if Pawn is spawned after the world has loaded. */
	Spawned,
	/** Pawn is automatically possessed by an AI Controller whenever it is created. */
	PlacedInWorldOrSpawned,
};
struct FQuat
{
public:

	/** The quaternion's X-component. */
	float X;

	/** The quaternion's Y-component. */
	float Y;

	/** The quaternion's Z-component. */
	float Z;

	/** The quaternion's W-component. */
	float W;
};
struct FTransform
{
protected:
	/** Rotation of this transformation, as a quaternion. */
	FQuat	Rotation;
	/** Translation of this transformation, as a vector. */
	FVector	Translation;
	/** 3D scale (always applied in local space) as a vector. */
	FVector	Scale3D;
};
struct FThreadSafeCounter
{
	int32 Counter;
};
struct FSoftObjectPath
{
private:
	/** Asset path, patch to a top level object in a package. This is /package/path.assetname */
	FName AssetPathName;

	/** Optional FString for subobject within an asset. This is the sub path after the : */
	FString SubPathString;

	/** Global counter that determines when we need to re-search based on path because more objects have been loaded **/
	static FThreadSafeCounter CurrentTag;

	/** Package names currently being duplicated, needed by FixupForPIE */
	char pad[4];
};
template<typename a,typename b>
struct TMap
{
	char pad[50];
};