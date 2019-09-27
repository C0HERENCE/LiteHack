#pragma once
#include <fstream>
#include "../GNames/GNames.h"
#include "..//Utils/tinyformat.h"
#include "..//Utils/MemoryHelper.h"
#include "EngineClasses.h"

#define off_GObjects																0x43C9C20
#define off_off																			0x4c

extern uint64 GameBaseAddress;
extern Memory GameMemory;
extern GNames NameStore;

class GObjects
{
public:
	GObjects();
	GObjects(uint64);
	void Dump();
	TUObjectArray  ObjObjects;
};