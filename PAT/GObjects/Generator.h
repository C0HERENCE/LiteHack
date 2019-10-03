#pragma once
#include "Package.h"

class Generator
{
public:
	Generator();
	void Dump(const fs::path& path);
	void ProcessPackages(const fs::path& outputDirectory);
};