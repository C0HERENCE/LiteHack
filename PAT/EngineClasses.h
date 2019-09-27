#pragma once
#include "Utils/"

class UObject;

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
	//protected:
	uint64 pad1 = 0;	// 0x0000
	FName NamePrivate = { };	// 0x0008 fname
	uint32 InternalIndex = 0;	// 0x0010 ID
	uint32 pad3 = 0;
	uint64 OuterPrivate;	// 0x0018 outer
	uint64 ClassPrivate = 0;	// 0x0020 class
	char pad4[0x4c - 0x28] = {};
	int32 offset = 0;
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

class GObjects
{
public:
	GObjects();
	GObjects(uint64);
	void Dump();
	TUObjectArray  ObjObjects;
};