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
			tfm::format(o, "[%06i] %-100s 0x%x\n", obj.GetIndex(), obj.GetFullName(), obj.GetAddress());
		}
	}
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
	std::cout << "Package Count: " << packageObjects.size() << std::endl;
	std::cout << "Objects Count: " << processedObjects.size() << std::endl;

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
