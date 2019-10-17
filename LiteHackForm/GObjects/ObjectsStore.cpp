#pragma once
#include "ObjectsStore.h"
#include <fstream>
#include "..//Utils/tinyformat.h"

ObjectsStore::ObjectsStore()
{

}

ObjectsStore::ObjectsStore(uint64 address)
{
	Initialize(address);
}

bool ObjectsStore::Initialize(uint64 address)
{
	privateGO = GameMemory.Read<FUObjectArray>(address);
	uint64 v7 = privateGO.ObjObjects.Objects;
	uint64 v417;
	LODWORD(v417) = (v7 + 0x56963ECA) ^ 0x56963ECA;
	HIDWORD(v417) = (HIDWORD(v7) + 0x5589550A) ^ 0xAA76AAF6;
	privateGO.ObjObjects.Objects = v417;
	return true;
}

UEObject ObjectsStore::GetById(size_t id) const
{
	return UEObject(privateGO.ObjObjects.GetById(id).Object);
}

UEClass ObjectsStore::FindClass(const std::string& name) const
{
	for (int i=0;i< GetObjectsNum();i++)
	{
		UEObject obj = UEObject(GetById(i));
		if (obj.GetFullName() == name)
		{
			return obj.Cast<UEClass>();
		}
	}
	return UEClass(0);
}

int ObjectsStore::GetObjectsNum() const
{
	return privateGO.ObjObjects.NumElements;
}

void ObjectsStore::Dump(std::string p)
{
	std::ofstream o;
	std::string path = p +  "\\ObjectsDump.txt";
	o.open(path);
	tfm::format(o, "//%s\n", "By COHERENCE");
	for (int i = 0; i < GetObjectsNum(); i++)
	{
		auto obj = GetById(i);
		if (!obj.IsValid()) continue;
		int id = obj.GetIndex();
		std::string fullname = obj.GetFullName();
		o << tfm::format("[0x%010X]\t%6d\t%s\n", obj.GetAddress(), id, fullname);
	}
	o.close();
	return;
}