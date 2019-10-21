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
	_ObjObjects = GameMemory.Read<FUObjectArray>(address);
	_ObjObjects.ObjObjects.Objects = updates::dec::objobjects(_ObjObjects.ObjObjects.Objects);
	return true;
}

UEObject ObjectsStore::GetById(size_t id) const
{
	return UEObject(_ObjObjects.ObjObjects.GetById(id).Object);
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
	return _ObjObjects.ObjObjects.NumElements;
}

void ObjectsStore::Dump(std::string p)
{
	std::ofstream o;
	std::string path = p +  "\\ObjectsEasyDump.txt";
	o.open(path);
	tfm::format(o, "%s\n", "By COHERENCE");
	tfm::format(o, "Base Address: 0x%x\n\n", GetById(0).GetAddress());
	tfm::format(o, "%s\t%s\t%s\n", "Address","InternalIndex","Class&FullName");
	tfm::format(o, "");
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