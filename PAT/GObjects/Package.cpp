#include "Package.h"
#include "NameValidator.h"

enum class FileContentType
{
	Structs,
	Classes,
	Functions,
	FunctionParameters
};

void PrintFileHeader(std::ostream& os, const std::vector<std::string>& includes, bool isHeaderFile)
{
	if (isHeaderFile)
	{
		os << "#pragma once\n\n";
	}

	os << tfm::format("// %s (%s) SDK\n\n", "PUBG Lite", "1003")
		<< tfm::format("#ifdef _MSC_VER\n\t#pragma pack(push, 0x%X)\n#endif\n\n", 8);

	if (!includes.empty())
	{
		for (auto&& i : includes) { os << "#include " << i << "\n"; }
		os << "\n";
	}
	std::string getnamespace = "SDK";
	if (!getnamespace.empty())
	{
		os << "namespace " << getnamespace << "\n{\n";
	}
}

void PrintFileHeader(std::ostream& os, bool isHeaderFile)
{
	PrintFileHeader(os, std::vector<std::string>(), isHeaderFile);
}

void PrintFileFooter(std::ostream& os)
{
	std::string getnamespace = "SDK";
	if (getnamespace.empty())
	{
		os << "}\n\n";
	}

	os << "#ifdef _MSC_VER\n\t#pragma pack(pop)\n#endif\n";
}

void PrintSectionHeader(std::ostream& os, const char* name)
{
	os << "//---------------------------------------------------------------------------\n"
		<< "//" << name << "\n"
		<< "//---------------------------------------------------------------------------\n\n";
}

std::string GenerateFileName(FileContentType type, const Package& package)
{
	const char* name = "";
	switch (type)
	{
	case FileContentType::Structs:
		name = "%s_%s_structs.h";
		break;
	case FileContentType::Classes:
		name = "%s_%s_classes.h";
		break;
	case FileContentType::Functions:
		name = "%s_%s_functions.cpp";
		break;
	case FileContentType::FunctionParameters:
		name = "%s_%s_parameters.h";
		break;
	default:
		assert(false);
	}

	return tfm::format(name, "Lite", package.GetName());
}

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
	std::cout << "Processing :" << GetName() << "\n";
	int percent = GlobalObjects.GetObjectsNum() / 100;
	int progress = 25;
	for (int i=0;i< GlobalObjects.GetObjectsNum();i++)
	{
		if (i==progress*percent)
		{
			std::cout <<"\t\t\t\tScaned "<< progress << "%\n";
			progress += 25;
		}
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
				GeneratePrerequisites(obj, processedObjects);
			}
			else if (obj.IsA<UEScriptStruct>())
			{
				GeneratePrerequisites(obj, processedObjects);
			}
		}
	}
	std::cout << "Generate " << packageObj.GetName() << "  Finished: ";
	std::cout << dependencies.size() << " dependencies. ";
	std::cout << enums.size() << " enums. ";
	std::cout << constants.size() << " constants. ";
	std::cout << scriptStructs.size() << " scriptStructs. And ";
	std::cout << classes.size() << " classes.\n\n\n\n";
}

bool Package::Save(const fs::path& path) const
{
	bool skip = true;
	for (auto e:enums)
		if (!e.Values.empty())
			skip = false;
	if (skip)
		for (auto s :scriptStructs)
				if (!s.Members.empty())
					skip = false;
	if (skip)
		for (auto c : classes)
				if (!c.Members.empty())
					skip = false;
	if (!skip)
	{
		SaveStructs(path);
		SaveClasses(path);
		std::cout << GetName() + " Save Finished." << std::endl;
		return true;
	}
	return false;
}

void Package::SaveStructs(const fs::path& path) const
{
	std::ofstream os(path / GenerateFileName(FileContentType::Structs, *this));
	PrintFileHeader(os, true);
	if (!constants.empty())
	{
		PrintSectionHeader(os, "Constants");
		for (auto&& c : constants) { PrintConstant(os, c); }

		os << "\n";
	}

	if (!enums.empty())
	{
		PrintSectionHeader(os, "Enums");
		for (auto&& e : enums) { PrintEnum(os, e); os << "\n"; }

		os << "\n";
	}

	if (!scriptStructs.empty())
	{
		PrintSectionHeader(os, "Script Structs");
		for (auto&& s : scriptStructs) { PrintStruct(os, s); os << "\n"; }
	}

	PrintFileFooter(os);
}

void Package::SaveClasses(const fs::path& path) const
{
	std::ofstream os(path / GenerateFileName(FileContentType::Classes, *this));

	PrintFileHeader(os, true);

	if (!classes.empty())
	{
		PrintSectionHeader(os, "Classes");
		for (auto&& c : classes) { PrintClass(os, c); os << "\n"; }
	}

	PrintFileFooter(os);
}

void Package::PrintConstant(std::ostream& os, const std::pair<std::string, std::string>& c) const
{
	tfm::format(os, "#define CONST_%-50s %s\n", c.first, c.second);
}

void Package::PrintEnum(std::ostream& os, const Enum& e) const
{
	os << "// " << e.FullName << "\nenum class " << e.Name << " : uint8_t\n{\n";
	int i = 0;
	for (auto v : e.Values)
	{
		std::string name = v;
		os << tfm::format("\t%-30s = %d,\n", name, i);
		i++;
	}
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
	enums.emplace_back(std::move(e));
	std::cout << "\t\tGenerated " << enums.size() << " Enums in Package "<< GetName() << ".\n";
}

void Package::PrintStruct(std::ostream& os, const ScriptStruct& ss) const
{
	os << "// " << ss.FullName << "\n// ";
	if (ss.InheritedSize)
	{
		os << tfm::format("0x%04X (0x%04X - 0x%04X)\n", ss.Size - ss.InheritedSize, ss.Size, ss.InheritedSize);
	}
	else
	{
		os << tfm::format("0x%04X\n", ss.Size);
	}

	os << ss.NameCppFull << "\n{\n";

	
	for (auto m : ss.Members)
	{
		os << tfm::format("\t%-50s %-58s// 0x%04X(0x%04X)", m.Type, m.Name + ";", m.Offset, m.Size) 
			+(!m.Comment.empty() ? " " + m.Comment : "")
			+ (!m.FlagsString.empty() ? " (" + m.FlagsString + ")" : "");
		os << "\n";
	}
	os << "};\n";
}

void Package::PrintClass(std::ostream& os, const Class& c) const
{
	os << "// " << c.FullName << "\n// ";
	if (c.InheritedSize)
	{
		tfm::format(os, "0x%04X (0x%04X - 0x%04X)\n", c.Size - c.InheritedSize, c.Size, c.InheritedSize);
	}
	else
	{
		tfm::format(os, "0x%04X\n", c.Size);
	}

	os << c.NameCppFull << "\n{\npublic:\n";

	for (auto&& m : c.Members)
	{
		tfm::format(os, "\t%-50s %-58s// 0x%04X(0x%04X)", m.Type, m.Name + ";", m.Offset, m.Size);
		if (!m.Comment.empty())
		{
			os << " " << m.Comment;
		}
		if (!m.FlagsString.empty())
		{
			os << " (" << m.FlagsString << ")";
		}
		os << "\n";
	}
	os << "};\n\n";
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
			members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "UNKNOWN PROPERTY: " + prop.GetFullName()+"|"+prop.GetName()));
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
	ss.Comment = std::move(reason);
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

bool Package::AddDependency(const UEObject& package) const
{
	if (package != packageObj)
	{
		dependencies.insert(package.GetAddress());

		return true;
	}
	return false;
}

void Package::GeneratePrerequisites(const UEObject& obj, std::unordered_map<uint64, bool>& processedObjects)
{
	if (!obj.IsValid())
	{
		return;
	}

	const auto isClass = obj.IsA<UEClass>();
	const auto isScriptStruct = obj.IsA<UEScriptStruct>();
	if (!isClass && !isScriptStruct)
	{
		return;
	}

	const auto name = obj.GetName();
	if (name.find("Default__") != std::string::npos
		|| name.find("<uninitialized>") != std::string::npos
		|| name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}

	processedObjects[obj.GetAddress()] |= false;

	auto classPackage = obj.GetPackageObject();
	if (!classPackage.IsValid())
	{
		return;
	}
	if (AddDependency(classPackage))
	{
		return;
	}
	if (processedObjects[obj.GetAddress()] == false)
	{
		processedObjects[obj.GetAddress()] = true;

		auto outer = obj.GetOuter();
		if (outer.IsValid() && outer != obj)
		{
			GeneratePrerequisites(outer, processedObjects);
		}

		auto structObj = obj.Cast<UEStruct>();

		auto super = structObj.GetSuper();
		if (super.IsValid() && super != obj)
		{
			GeneratePrerequisites(super, processedObjects);
		}

		GenerateMemberPrerequisites(structObj.GetChildren().Cast<UEProperty>(), processedObjects);

		if (isClass)
		{
			GenerateClass(obj.Cast<UEClass>());
		}
		else
		{
			GenerateScriptStruct(obj.Cast<UEScriptStruct>());
		}
	}
}

void Package::GenerateMemberPrerequisites(const UEProperty& first, std::unordered_map<uint64, bool>& processedObjects)
{
	for (auto prop = first; prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
	{
		const auto info = prop.GetInfo();
		if (info.Type == UEProperty::PropertyType::Primitive)
		{
			if (prop.IsA<UEByteProperty>())
			{
				auto byteProperty = prop.Cast<UEByteProperty>();
				if (byteProperty.IsEnum())
				{
					AddDependency(byteProperty.GetEnum().GetPackageObject());
				}
			}
			else if (prop.IsA<UEEnumProperty>())
			{
				auto enumProperty = prop.Cast<UEEnumProperty>();
				AddDependency(enumProperty.GetEnum().GetPackageObject());
			}
		}
		else if (info.Type == UEProperty::PropertyType::CustomStruct)
		{
			GeneratePrerequisites(prop.Cast<UEStructProperty>().GetStruct(), processedObjects);
		}
		else if (info.Type == UEProperty::PropertyType::Container)
		{
			std::vector<UEProperty> innerProperties;
			if (prop.IsA<UEArrayProperty>())
			{
				innerProperties.push_back(prop.Cast<UEArrayProperty>().GetInner());
			}
			else if (prop.IsA<UEMapProperty>())
			{
				auto mapProp = prop.Cast<UEMapProperty>();
				innerProperties.push_back(mapProp.GetKeyProperty());
				innerProperties.push_back(mapProp.GetValueProperty());
				for (auto innerProp : innerProperties)
				{
					if (innerProp.GetInfo().Type == UEProperty::PropertyType::CustomStruct)
					{
						GeneratePrerequisites(innerProp.Cast<UEStructProperty>().GetStruct(), processedObjects);
					}
				}
			}
		}
	}
}

void Package::GenerateScriptStruct(const UEScriptStruct& scriptStructObj)
{
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
	scriptStructs.emplace_back(std::move(ss));
	std::cout << "\t\tGenerated " << scriptStructs.size() << " Struct in Package " << GetName() << ".\n";
}

void Package::GenerateClass(const UEClass& classObj)
{
	Class c;
	c.Name = classObj.GetName();
	c.FullName = classObj.GetFullName();
	c.NameCpp = MakeValidName(classObj.GetNameCPP());
	c.NameCppFull = "class " + c.NameCpp;
	c.Size = classObj.GetPropertySize();
	c.InheritedSize = 0; 
	size_t offset = 0;
	auto super = classObj.GetSuper();
	if (super.IsValid() && super != classObj)
	{
		c.InheritedSize = offset = super.GetPropertySize();

		c.NameCppFull += " : public " + MakeValidName(super.GetNameCPP());
		std::vector<UEProperty> properties;
		for (auto prop = classObj.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
		{
			if (prop.GetElementSize() > 0
				&& !prop.IsA<UEScriptStruct>()
				&& !prop.IsA<UEFunction>()
				&& !prop.IsA<UEEnum>()
				&& !prop.IsA<UEConst>()
				&& (!super.IsValid()
					|| (super != classObj
						&& prop.GetOffset() >= super.GetPropertySize()
						)
					)
				)
			{
				properties.push_back(prop);
			}
		}
		std::sort(std::begin(properties), std::end(properties), ComparePropertyLess);
		GenerateMembers(classObj, offset, properties, c.Members);
		classes.emplace_back(std::move(c));
		std::cout << "\t\tGenerated " << classes.size() << " Classes in Package " << GetName() << ".\n";
	}
}