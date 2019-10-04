#include "Generator.h"


extern ObjectsStore GlobalObjects;
extern NamesStore GlobalNames;

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
				auto e = UEEnum(obj.GetAddress()).GetNames();
				tfm::format(o, "[0x%x]\t[%06i]\t%-100s\t%d Members: ", obj.GetAddress(), obj.GetIndex(), UEEnum(obj.GetAddress()).GetFullName(),e.size());
				for (int i = 0; i < e.size(); i++)
				{
					tfm::format(o, " %s = %d, ", e[i],i);
				}
				tfm::format(o, "\n");
			}
			else if (obj.IsA<UEScriptStruct>()||obj.IsA<UEClass>())
			{
				UEStruct s = UEStruct(obj.GetAddress());
				tfm::format(o, "[0x%x]\t[%06i]\t%-100s\t%s %s\n", obj.GetAddress(), obj.GetIndex(),obj.GetFullName(),s.GetNameCPP(), s.GetSuper().IsValid() ? ": " + s.GetSuper().GetNameCPP() : "" );
			}
			else if (obj.IsA<UEProperty>())
			{
				UEProperty p = UEProperty(obj.GetAddress());
				std::string cppType = "";
				if (obj.IsA<UEStructProperty>())
				{
					cppType = UEScriptStruct(GameMemory.Read<UStructProperty>(obj.GetAddress()).Struct).GetNameCPP();
				}
				else if (obj.IsA<UEEnumProperty>(obj.GetAddress()))
				{
					cppType = UEEnum(GameMemory.Read<UEnumProperty>(obj.GetAddress()).Enum).GetNameCPP();
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
