#include "Generator.h"


extern ObjectsStore GlobalObjects;
extern NamesStore GlobalNames;
std::string GetType(UEProperty prop)
{
	std::string className = prop.GetClass().GetName();
	std::string cppType = "";
	if (className == "StructProperty")
	{
		cppType = "struct " + UEScriptStruct(UStructProperty(prop.GetAddress()).Struct()).GetNameCPP();
	}
	else if (className == "ByteProperty")
	{
		auto b = UEByteProperty(prop.GetAddress());
		if (b.IsEnum())
			cppType = "TEnumAsByte<" + b.GetEnum().GetNameCPP() + ">";
		else cppType = "unsigned char";

	}
	else if (className == "ObjectProperty" || className == "EncryptedObjectProperty")
	{
		auto b = UEObjectProperty(prop.GetAddress());
		cppType = "class " + b.GetPropertyClass().GetNameCPP() + "*";
	}
	else if (className == "ClassProperty")
	{
		cppType = "class " + UEClassProperty(prop.GetAddress()).GetMetaClass().GetNameCPP() + "*";
	}
	else if (className == "InterfaceProperty")
	{
		cppType = "TScriptInterface<class " + UEInterfaceProperty(prop.GetAddress()).GetInterfaceClass().GetNameCPP() + ">";
	}
	else if (className == "WeakObjectProperty")
	{
		cppType = "TWeakObjectPtr<class " + UEWeakObjectProperty(prop.GetAddress()).GetPropertyClass().GetNameCPP() + ">";
	}
	else if (className == "LazyObjectProperty")
	{
		cppType = "TLazyObjectPtr<class " + UELazyObjectProperty(prop.GetAddress()).GetPropertyClass().GetNameCPP() + ">";
	}
	else if (className == "BoolProperty")
	{
		auto b = UEBoolProperty(prop.GetAddress());
		if (b.IsNativeBool())
		{
			cppType = "bool";
		}
		cppType = "unsigned char";
	}
	else if (className == "UInt16Property")
	{
		cppType = "uint16_t";
	}
	else if (className == "UInt32Property")
	{
		cppType = "uint32_t";
	}
	else if (className == "UInt64Property")
	{
		cppType = "uint64_t";
	}
	else if (className == "Int8Property")
	{
		cppType = "int8_t";
	}
	else if (className == "Int16Property")
	{
		cppType = "int16_t";
	}
	else if (className == "IntProperty")
	{
		cppType = "int";
	}
	else if (className == "Int64Property")
	{
		cppType = "int64_t";
	}
	else if (className == "FloatProperty")
	{
		cppType = "float";
	}
	else if (className == "DoubleProperty")
	{
		cppType = "double";
	}
	else if (className == "AssetObjectProperty")
	{
		cppType = "TAssetPtr<class >";
	}
	else if (className == "AssetClassProperty")
	{
		cppType = "AssetClassProperty";
	}
	else if (className == "NameProperty")
	{
		cppType = "struct FName";
	}
	else if (className == "StrProperty")
	{
		cppType = "struct FString";
	}
	else if (className == "TextProperty")
	{
		cppType = "struct FText";
	}
	else if (className == "ArrayProperty")
	{
		auto b = UEArrayProperty(prop.GetAddress());
		cppType = "TArray<" + GetType(b.GetInner()) + ">";
	}
	else if (className == "MapProperty")
	{
		auto key = GetType(UEProperty(UMapProperty(prop.GetAddress()).KeyProp()));
		auto value = GetType(UEProperty(UMapProperty(prop.GetAddress()).ValueProp()));
		cppType = "TMap<" + key + ", " + value + ">";
	}
	else if (className == "DelegateProperty")
	{
		cppType = "struct FScriptDelegate";
	}
	else if (className == "MulticastDelegateProperty")
	{
		cppType = "struct FScriptMulticastDelegate";
	}
	else if (className == "EnumProperty")
	{
		cppType = UEEnumProperty(prop.GetAddress()).GetEnum().GetNameCPP();
	}
	else
	{
		cppType = "UnknownProperty";
	}
	return cppType;
}

Generator::Generator()
{

}

void Generator::Dump(const fs::path& path)
{
	std::ofstream o(path / "ObjectsDump.txt");
	tfm::format(o, "Address: 0x%x\n\n", GlobalObjects.GetById(0).GetAddress());

	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		auto obj = GlobalObjects.GetById(i);
		std::cout << i << " " << obj.GetIndex() << " " <<obj.GetName() << std::endl;
		if (obj.IsValid())
		{
			std::string e = obj.GetName();
			if (e.find("Default__") != std::string::npos
				|| e.find("PLACEHOLDER-CLASS") != std::string::npos)
			{
				continue;
			}
			if (obj.IsA<UEFunction>())
			{
				continue;
			}
			else if (obj.IsA<UEEnum>())
			{
				std::cout <<2 << std::endl;
				auto e = UEEnum(obj.GetAddress()).GetNames();
				tfm::format(o, "[0x%x]\t[%06i]\t%-100s\t%d Members: ", obj.GetAddress(), obj.GetIndex(), UEEnum(obj.GetAddress()).GetFullName(), e.size());
				for (int i = 0; i < e.size(); i++)
				{
					tfm::format(o, " %s = %d, ", e[i], i);
				}
				tfm::format(o, "\n");
			}
			else if (obj.IsA<UEScriptStruct>() || obj.IsA<UEClass>())
			{
				std::cout << 3 << std::endl;
				UEStruct s = UEStruct(obj.GetAddress());

				tfm::format(o, "[0x%x]\t[%06i]\t%-100s\t%s %s\n", obj.GetAddress(), obj.GetIndex(), obj.GetFullName(), s.GetNameCPP(), s.GetSuper().IsValid() ? ": " + s.GetSuper().GetNameCPP() : "");
			}
			else if (obj.IsA<UEProperty>())
			{
				std::cout << 4 << std::endl;
				UEProperty p = UEProperty(obj.GetAddress());
				std::string cppType = "";
				if (obj.IsA<UEStructProperty>())
				{
					std::cout << 5 << std::endl;
					cppType = UEScriptStruct(UStructProperty(obj.GetAddress()).Struct()).GetNameCPP();
				}
				else if (obj.IsA<UEEnumProperty>())
				{
					std::cout << 6 << std::endl;
					cppType = UEEnum(UEnumProperty(obj.GetAddress()).Enum()).GetNameCPP();
				}
				tfm::format(o, "[0x%x]\t[%06i]\t[0x%04x]\t%-100s\t%s\n", obj.GetAddress(), obj.GetIndex(), p.GetOffset(), obj.GetFullName(), cppType);
			}
		}
	}

	return;
	std::ofstream p(path / "NamesDump.txt");
	tfm::format(p, "Address: 0x%x\n\n", GlobalNames.GetAddress());
	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		auto name = GlobalNames.GetById(i);
		tfm::format(p, "[%06i] %s\n", i, name);
	}
}

void Generator::DumpSDK(const fs::path& path)
{
	std::ofstream o(path / "ObjectsSDKDump.txt");
	tfm::format(o, "Address: 0x%x\n\n", GlobalObjects.GetById(0).GetAddress());

	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		auto obj = GlobalObjects.GetById(i);
		if (obj.IsValid())
		{
			std::string e = obj.GetName();
			if (e.find("Default__") != std::string::npos
				|| e.find("PLACEHOLDER-CLASS") != std::string::npos)
			{
				continue;
			}
			if (obj.IsA<UEFunction>())
			{
				continue;
			}
			else if (obj.IsA<UEEnum>())
			{
				tfm::format(o, "//%s\n",obj.GetFullName());
				tfm::format(o, "enum class %s : uint8_t\n{", obj.GetNameCPP());
				auto e = UEEnum(obj.GetAddress()).GetNames();
				for (int i = 0; i < e.size(); i++)
				{
					tfm::format(o, "\t%s = %d, \n", e[i], i);
				}
				tfm::format(o, "};\n");
			}
			else if (obj.IsA<UEScriptStruct>() || obj.IsA<UEClass>())
			{
				UEStruct s = UEStruct(obj.GetAddress());
				auto super = s.GetSuper();
				tfm::format(o, "//%s\n", obj.GetFullName());
				tfm::format(o, "class %s %s\n{\n", obj.GetNameCPP(), super.IsValid()?": public " + super.GetNameCPP():"");
				for (auto prop = s.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
				{
					if (prop.GetElementSize() > 0
						&& !prop.IsA<UEScriptStruct>()
						&& !prop.IsA<UEFunction>()
						&& !prop.IsA<UEEnum>()
						&& !prop.IsA<UEConst>()
						&& (!super.IsValid()
							|| (super != s
								&& prop.GetOffset() >= super.GetPropertySize()
								)
							)
						)
					{
						std::cout << prop.GetName() << std::endl;
						tfm::format(o, "\t%s %s; //offset: 0x%x\t\n", GetType(prop), prop.GetName(), prop.GetOffset());
					}
				}
				tfm::format(o, "};\n");
			}
			else if (obj.IsA<UEProperty>())
			{
			}
		}
	}

	return;
	std::ofstream p(path / "NamesDump.txt");
	tfm::format(p, "Address: 0x%x\n\n", GlobalNames.GetAddress());
	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		auto name = GlobalNames.GetById(i);
		tfm::format(p, "[%06i] %s\n", i, name);
	}
}

void Generator::ProcessPackages(const fs::path& path)
{
	std::unordered_map<uint64, bool> processedObjects;
	std::unordered_set<uint64> packageObjects;
	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		if (!GlobalObjects.GetById(i).IsValid()) continue;
		processedObjects.insert({ GlobalObjects.GetById(i).GetAddress(),false });
		auto package = GlobalObjects.GetById(i).GetPackageObject();
		if (!package.IsValid()) continue;
		packageObjects.insert(package.GetAddress());
	}
	std::cout << "Package Count: " << packageObjects.size() << std::endl;
	std::cout << "Objects Count: " << processedObjects.size() << std::endl;

	fs::path outputDirectory(path);
	outputDirectory /= "PUBGLite";
	fs::create_directories(outputDirectory);
	outputDirectory /= "SDK";
	fs::create_directories(outputDirectory);

	std::cout << "OutputDirectory: " << outputDirectory << std::endl;
	for (auto i : packageObjects)
	{
		auto package = Package(UEObject(i));
		package.Process(processedObjects);
		package.Save(outputDirectory);
	}
}

void Generator::ProcessPackages(const fs::path& path, std::string packageName, std::string className)
{
	std::unordered_map<uint64, bool> processedObjects;
	std::unordered_set<uint64> packageObjects;
	for (int i = 0; i < GlobalObjects.GetObjectsNum(); i++)
	{
		if (!GlobalObjects.GetById(i).IsValid()) continue;
		processedObjects.insert({ GlobalObjects.GetById(i).GetAddress(),false });
		auto package = GlobalObjects.GetById(i).GetPackageObject();
		if (!package.IsValid()) continue;
		packageObjects.insert(package.GetAddress());
	}
	fs::path outputDirectory(path);
	outputDirectory /= "PUBGLite";
	fs::create_directories(outputDirectory);

	std::cout << "OutputDirectory: " << outputDirectory << std::endl;
	for (auto i : packageObjects)
	{
		auto package = Package(UEObject(i));
		std::string name = package.GetName();
		if (name == packageName)
		{
			package.Process(processedObjects,className);
			outputDirectory /= className;
			fs::create_directories(outputDirectory);
			package.Save(outputDirectory);
		}
	}
}