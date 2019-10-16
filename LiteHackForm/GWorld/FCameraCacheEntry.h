#pragma once
#include "Core/FRotator.h"
#include "..//Utils/MemoryHelper.h"
#include "Base.h"
extern Memory GameMemory;

struct FMinimalViewInfo
{
	struct FRotator Rotation;// 0x050C sizeof (0x000C)
	char pad2[0xc];
	float FOV;// 0x0524 sizeof (0x0004)
	struct FVector Location;// 0x0528 sizeof (0x000C)
};


struct FCameraCacheEntry
{
	float Timestamp;// 0x0000 sizeof (0x0004)
	unsigned char UnknownData00[0xC];// 0x0004 sizeof (0x000C) MISSED OFFSET
	FMinimalViewInfo POV;// 0x0010 sizeof (0x0550)
};

class APlayerCameraManager : Base
{
public:
	using Base::Base;
	FMinimalViewInfo MinimalViewInfo()
	{
		FMinimalViewInfo cameracache = GameMemory.Read<FMinimalViewInfo>(base + off_CameraCache);
		return cameracache;
	}
private:
	uint64 off_CameraCache = 0x3d0+0x0010+0x50c;
};