#pragma once
#include "MemoryHelper.h"
#include "GNames.h"
#include <iostream>
#define off_GObjectsCount	 	                                                0x43C9C30			//up
#define off_GObjects																0x43C9C20			//up		(ENC)
#define off_off																			0x44

extern MemoryHelper mh;
extern uint64 Base;

class UObject;
class OffsetDumper
{
public:
	void Dump();
};


class FName
{
public:
	FORCEINLINE uint64 GetComparisonIndex() const;
	FORCEINLINE uint64 GetNumber() const;
public:
	uint32_t ComparisonIndex = 0;	// 0x0000
	uint32_t Number = 0;			// 0x0004
};

class UClass;
class UObject
{
public:
	FORCEINLINE int32 GetInternalIndex() const;
	FORCEINLINE UClass GetClass() const;
	FORCEINLINE FName GetFName() const;
	FORCEINLINE UObject GetOuter() const;
	FORCEINLINE uint64 GetNameID() const;
protected:
	uint64 pad1 = 0;	// 0x0000
	uint64 pad2 = 0;	// 0x0008
	uint64 OuterPrivate = 0;		// 0x0010
	FName NamePrivate = { };	// 0x0018
	uint32 InternalIndex = 0;	// 0x0020
	uint32 pad3 = 0;	// 0x0020
	uint64 ClassPrivate = 0;//0x28
};
class UClass : public UObject
{

};
class FUObjectItem
{
public:
	UObject GetUObject();
	uint64 GetBaseAddress();
private:
	uint64 Object; //0x0000			Objects[i] = 0x18 * i + Objects
	__int32 Flags; //0x0008				unkown
	__int32 ClusterIndex; //0x000C	unkown
	__int32 SerialNumber; //0x0010 unkown
};

class TUObjectArray
{
public:
	int32_t GetNumElements();
	uint64 GetBaseAddress();
	FUObjectItem GetObjects();
	FUObjectItem GetObjects(int);
private:
	uint64 Objects;
	int64 unknownMaxElements;
	int32_t NumElements;
};