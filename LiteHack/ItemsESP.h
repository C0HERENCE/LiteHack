#pragma once
#include "Commons.h"
#include <map>
#include <string>

struct ItemInfo
{
	int id;
	std::string name;
	std::string path;
};
extern std::multimap<int, std::string> importantMap;

void DrawItem();