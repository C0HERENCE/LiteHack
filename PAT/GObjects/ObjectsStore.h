#pragma once
#include <iostream>
#include <unordered_map>
#include "GenericTypes.h"
#include "..//GNames/NamesStore.h"

extern uint64 GameBaseAddress;
extern Memory GameMemory;
extern NamesStore GlobalNames;
class UEClass;
class UEObject;
class FUObjectItem
{
public:
	uint64 Object;
	__int32 Flags;
	__int32 ClusterIndex;
	__int32 SerialNumber;
};

class TUObjectArray
{
public:
	uint64 Objects;
	int32_t unknownMaxElements;
	int32_t unknownMaxElements2;
	int32_t NumElements;
public:
	const FUObjectItem& operator[](int i) const
	{
		return GameMemory.Read<FUObjectItem>(Objects + 0x18 * i);
	}
	FUObjectItem GetById(int i) const
	{
		return GameMemory.Read<FUObjectItem>(Objects + 0x18 * i);
	}
};

class FUObjectArray
{
public:
	__int32 ObjFirstGCIndex;
	__int32 ObjLastNonGCIndex;
	__int32 MaxObjectsNotConsideredByGC;
	__int32 OpenForDisregardForGC;
	TUObjectArray ObjObjects;
};

class ObjectsStore
{
public:
	ObjectsStore();

	ObjectsStore(uint64);

	bool Initialize(uint64);

	int GetObjectsNum() const;

	UEObject GetById(size_t id) const;

	UEClass FindClass(const std::string& name) const;

	//template<class T>
	//size_t CountObjects(const std::string& name) const
	//{
	//	static std::unordered_map<std::string, size_t> cache;

	//	auto it = cache.find(name);
	//	if (it != std::end(cache))
	//	{
	//		return it->second;
	//	}

	//	size_t count = 0;
	//	for (auto obj : *this)
	//	{
	//		if (obj.IsA<T>() && obj.GetName() == name)
	//		{
	//			++count;
	//		}
	//	}

	//	cache[name] = count;

	//	return count;
	//}

private:
	FUObjectArray privateGO;
};