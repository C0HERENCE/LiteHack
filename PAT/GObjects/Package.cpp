#include "Package.h"
#include "NameValidator.h"
#include "../Utils/tinyformat.h"

bool ComparePropertyLess(const UEProperty& lhs, const UEProperty& rhs)
{
	if (lhs.GetOffset() == rhs.GetOffset()
		&& lhs.IsA<UEBoolProperty>()
		&& rhs.IsA<UEBoolProperty>())
	{
		return lhs.Cast<UEBoolProperty>() < rhs.Cast<UEBoolProperty>();
	}

	return lhs.GetOffset() < rhs.GetOffset();
}

Package::Package(const UEObject& _packageObj)
{
	packageObj = _packageObj;
}

void Package::Process(std::unordered_map<uint64, bool>& processedObjects)
{
	if (packageObj.GetName() != "ShadowTrackerExtra") return;
	for (int i=0;i< GlobalObjects.GetObjectsNum();i++)
	{
		auto obj = GlobalObjects.GetById(i);
		const auto package = GlobalObjects.GetById(i).GetPackageObject();
		if (packageObj == package)
		{
			if (obj.IsA<UEEnum>())
			{
				GenerateEnum(obj.Cast<UEEnum>());
			}
			else if (obj.IsA<UEConst>())
			{
				GenerateConst(obj.Cast<UEConst>());
			}
			else if (obj.IsA<UEClass>())
			{
				//GeneratePrerequisites(obj, processedObjects);
				//GenerateClass(obj.Cast<UEClass>());
			}
			else if (obj.IsA<UEScriptStruct>())
			{
				GenerateScriptStruct(obj.Cast<UEScriptStruct>());
			}
		}
	}
	std::cout << "Generate " <<packageObj.GetName() << "  Finished." << std::endl;
	std::cout << enums.size() << " enums." << std::endl;
	std::cout << constants.size() << " constants." << std::endl;
	std::cout << scriptStructs.size() << " scriptStructs." << std::endl;
}

bool Package::Save() const
{
	return false;
}

void Package::GenerateEnum(const UEEnum& enumObj)
{
	Enum e;
	e.Name = MakeUniqueCppName(enumObj);

	if (e.Name.find("Default__") != std::string::npos
		|| e.Name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}

	e.FullName = enumObj.GetFullName();

	std::unordered_map<std::string, int> conflicts;
	for (auto&& s : enumObj.GetNames())
	{
		const auto clean = MakeValidName(std::move(s));

		const auto it = conflicts.find(clean);
		if (it == std::end(conflicts))
		{
			e.Values.push_back(clean);
			conflicts[clean] = 1;
		}
		else
		{
			e.Values.push_back(clean + tfm::format("%02d", it->second));
			conflicts[clean]++;
		}
	}

	std::cout << e.FullName << std::endl << "{" << std::endl;;
	int i = 0;
	for (auto j : e.Values)
	{
		std::cout << "\t" << j << " = " << i <<  ";" << std::endl;
		i++;
	}
	std::cout << "}" << std::endl;

	enums.emplace_back(std::move(e));
}

void Package::GenerateConst(const UEConst& constObj)
{
	auto name = MakeUniqueCppName(constObj);

	if (name.find("Default__") != std::string::npos
		|| name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}
	constants[name] = constObj.GetValue();
	std::cout << constants[name] << "   " << name << std::endl;
}

void Package::GenerateMembers(const UEStruct& structObj, size_t offset, const std::vector<UEProperty>& properties, std::vector<Member>& members) const
{
	std::unordered_map<std::string, size_t> uniqueMemberNames;
	size_t unknownDataCounter = 0;
	UEBoolProperty previousBitfieldProperty;

	for (auto&& prop : properties)
	{
		if (offset < prop.GetOffset())
		{
			previousBitfieldProperty = UEBoolProperty();

			const auto size = prop.GetOffset() - offset;
			members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "MISSED OFFSET"));
		}

		const auto info = prop.GetInfo();

		if (info.Type != UEProperty::PropertyType::Unknown)
		{
			Member sp;
			sp.Offset = prop.GetOffset();
			sp.Size = info.Size;

			sp.Type = info.CppType;
			sp.Name = MakeValidName(prop.GetName());
			const auto it = uniqueMemberNames.find(sp.Name);
			if (it == std::end(uniqueMemberNames))
			{
				uniqueMemberNames[sp.Name] = 1;
			}
			else
			{
				++uniqueMemberNames[sp.Name];
				sp.Name += tfm::format("%02d", it->second);
			}
			if (prop.GetArrayDim() > 1)
			{
				sp.Name += tfm::format("[0x%X]", prop.GetArrayDim());
			}
			if (prop.IsA<UEBoolProperty>() && prop.Cast<UEBoolProperty>().IsBitfield())
			{
				auto boolProp = prop.Cast<UEBoolProperty>();

				const auto missingBits = boolProp.GetMissingBitsCount(previousBitfieldProperty);
				if (missingBits[1] != -1)
				{
					if (missingBits[0] > 0)
					{
						members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, previousBitfieldProperty.GetOffset(), info.CppType, missingBits[0]));
					}
					if (missingBits[1] > 0)
					{
						members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, sp.Offset, info.CppType, missingBits[1]));
					}
				}
				else if (missingBits[0] > 0)
				{
					members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, sp.Offset, info.CppType, missingBits[0]));
				}

				previousBitfieldProperty = boolProp;

				sp.Name += " : 1";
			}
			else
			{
				previousBitfieldProperty = UEBoolProperty();
			}
			members.emplace_back(std::move(sp));
			const auto sizeMismatch = static_cast<int>(prop.GetElementSize() * prop.GetArrayDim()) - static_cast<int>(info.Size * prop.GetArrayDim());
			if (sizeMismatch > 0)
			{
				members.emplace_back(CreatePadding(unknownDataCounter++, offset, sizeMismatch, "FIX WRONG TYPE SIZE OF PREVIOUS PROPERTY"));
			}
		}
		else
		{
			const auto size = prop.GetElementSize() * prop.GetArrayDim();
			members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "UNKNOWN PROPERTY: " + prop.GetFullName()));
		}
		offset = prop.GetOffset() + prop.GetElementSize() * prop.GetArrayDim();
	}

	if (offset < structObj.GetPropertySize())
	{
		const auto size = structObj.GetPropertySize() - offset;
		members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "MISSED OFFSET"));
	}
}

Package::Member Package::CreatePadding(size_t id, size_t offset, size_t size, std::string reason)
{
	Member ss;
	ss.Name = tfm::format("UnknownData%02d[0x%X]", id, size);
	ss.Type = "unsigned char";
	ss.Offset = offset;
	ss.Size = size;
	return ss;
}

Package::Member Package::CreateBitfieldPadding(size_t id, size_t offset, std::string type, size_t bits)
{
	Member ss;
	ss.Name = tfm::format("UnknownData%02d : %d", id, bits);
	ss.Type = std::move(type);
	ss.Offset = offset;
	ss.Size = 1;
	return ss;
}

void Package::GenerateScriptStruct(const UEScriptStruct& scriptStructObj)
{
	if (!scriptStructObj.IsValid())
	{
		return;
	}
	const auto isClass = scriptStructObj.IsA<UEClass>();
	const auto isScriptStruct = scriptStructObj.IsA<UEScriptStruct>();
	if (!isClass && !isScriptStruct)
	{
		return;
	}
	const auto name = scriptStructObj.GetName();
	if (name.find("Default__") != std::string::npos	|| name.find("<uninitialized>") != std::string::npos	|| name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}
	auto classPackage = scriptStructObj.GetPackageObject();
	if (!classPackage.IsValid())
	{
		return;
	}
	ScriptStruct ss;
	ss.Name = scriptStructObj.GetName();
	ss.FullName = scriptStructObj.GetFullName();
	ss.NameCpp = MakeValidName(scriptStructObj.GetNameCPP());
	ss.NameCppFull = "struct ";
	ss.NameCppFull += MakeUniqueCppName(scriptStructObj);
	ss.Size = scriptStructObj.GetPropertySize();
	ss.InheritedSize = 0;
	size_t offset = 0;
	auto super = scriptStructObj.GetSuper();
	if (super.IsValid() && super != scriptStructObj)
	{
		ss.InheritedSize = offset = super.GetPropertySize();
		ss.NameCppFull += " : public " + MakeUniqueCppName(super.Cast<UEScriptStruct>());
	}
	std::vector<UEProperty> properties;
	for (auto prop = scriptStructObj.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
	{
		if (prop.GetElementSize() > 0)
		{
			if (!prop.IsA<UEScriptStruct>())
			{
				if (!prop.IsA<UEEnum>())
				{
					if (!prop.IsA<UEConst>())
					{
						if (!prop.IsA<UEFunction>())
						{
							properties.push_back(prop);
						}
					}
				}
			}
		}
	}
	std::sort(std::begin(properties), std::end(properties), ComparePropertyLess);

	GenerateMembers(scriptStructObj, offset, properties,ss.Members);

	
	std::cout << ss.NameCppFull << std::endl << "{" << std::endl;;
	for (auto j : ss.Members)
	{
		std::cout <<"\t"<< j.Type << " " << j.Name << ";" << std::endl;
	}
	std::cout << "}" << std::endl;

	scriptStructs.emplace_back(std::move(ss));
}

void Package::GenerateClass(const UEClass& classObj)
{
	
}