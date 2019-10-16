#pragma once
#include "Package.h"
#include <unordered_map>

class Generator
{
public:
	Generator();
	void Dump(const fs::path& path);
	void DumpSDK(const fs::path& path);
	void ProcessPackages(const fs::path& path);
	void ProcessPackages(const fs::path& path,std::string packageName,std::string className);
};