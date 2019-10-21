#pragma once
#include "Core/FRotator.h"
#include "Base.h"
extern Memory GameMemory;

class APlayerCameraManager : Base
{
public:
	using Base::Base;
	updates::off::FMinimalViewInfo MinimalViewInfo()
	{
		updates::off::FMinimalViewInfo cameracache = GameMemory.Read<updates::off::FMinimalViewInfo>(base + updates::off::CameraCache);
		return cameracache;
	}
};