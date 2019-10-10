#pragma once
#include "..//Utils/MemoryHelper.h"

class Base
{
public:
	Base() :base(0) {}

	Base(uint64 _base) :base(_base) {}

	uint64 GetAddress() const
	{
		return base;
	}
protected:
	uint64 base;

};