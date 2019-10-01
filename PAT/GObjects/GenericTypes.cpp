#pragma once
#include "GenericTypes.h"

int UEObject::GetIndex() const
{
	return GameMemory.Read<UObject>(object).GetInternalIndex();
}

UEClass UEObject::GetClass() const
{
	return UEClass(GameMemory.Read<UObject>(object).GetClass());
}

UEObject UEObject::GetOuter() const
{
	return UEObject(GameMemory.Read<UObject>(object).GetOuter());
}

std::string UEObject::GetName() const
{
	UObject uobj = GameMemory.Read<UObject>(object);
	auto name = GlobalNames.GetById(uobj.GetFName().GetComparisonIndex());
	if (uobj.GetFName().GetNumber()>0)
	{
		name += '_' + std::to_string(uobj.GetFName().GetNumber());
	}

	auto pos = name.rfind('/');
	if (pos == std::string::npos)
	{
		return name;
	}

	return name.substr(pos + 1);
}

uint64 UEObject::GetAddress() const
{
	return object;
}

UEObject UEObject::GetPackageObject() const
{
	UEObject package(0);

	for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
	{
		package = outer;
	}

	return package;
}

std::string UEObject::GetFullName() const
{
	if (GetClass().IsValid())
	{
		std::string temp;

		for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
		{
			temp = outer.GetName() + "." + temp;
		}

		std::string name = GetClass().GetName();
		name += " ";
		name += temp;
		name += GetName();

		return name;
	}

	return std::string("(null)");
}

UEClass UEObject::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Object");
	return c;
}

UEField UEField::GetNext() const
{
	return UEField(GameMemory.Read<UField>(object).Next);
}

UEClass UEField::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Field");
	return c;
}

std::vector<std::string> UEEnum::GetNames() const
{
	std::vector<std::string> buffer;
	auto names = GameMemory.Read<UEnum>(object).Names;

	for (auto i = 0; i < names.Length(); ++i)
	{
		buffer.push_back(GlobalNames.GetById(names[i].Key.ComparisonIndex));
	}

	return buffer;
}

UEClass UEEnum::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Enum");
	return c;
}

std::string UEConst::GetValue() const
{
	throw;
}

UEClass UEConst::StaticClass()
{
	return 0;
}

UEStruct UEStruct::GetSuper() const
{
	return UEStruct(GameMemory.Read<UStruct>(object).SuperField);
}

UEField UEStruct::GetChildren() const
{
	return UEField(GameMemory.Read<UStruct>(object).Children);
}

size_t UEStruct::GetPropertySize() const
{
	return GameMemory.Read<UStruct>(object).PropertySize;
}

UEClass UEStruct::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Struct");
	return c;
}

UEClass UEScriptStruct::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.ScriptStruct");
	return c;
}

UEClass UEClass::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Class");
	return c;
}

size_t UEProperty::GetArrayDim() const
{
	return GameMemory.Read<UProperty>(object).ArrayDim;
}

size_t UEProperty::GetElementSize() const
{
	return GameMemory.Read<UProperty>(object).ElementSize;
}

size_t UEProperty::GetOffset() const
{
	return GameMemory.Read<UProperty>(object).Offset;
}

UEClass UEProperty::StaticClass()
{
	static auto c = ObjectsStore().FindClass("Class CoreUObject.Property");
	return c;
}