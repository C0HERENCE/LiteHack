#pragma once
#include <filesystem>
namespace fs = std::experimental::filesystem;
#include <fstream>
#include <unordered_set>
#include "../Utils/tinyformat.h"
#include "GenericTypes.h"


class Package
{
	friend bool operator==(const Package& lhs, const Package& rhs);
public:
	Package(const UEObject& packageObj);
	std::string GetName() const { return packageObj.GetName();}
	void Process(std::unordered_map<uint64, bool>& processedObjects);
	void Process(std::unordered_map<uint64, bool>& processedObjects,std::string className);
	bool Save(const fs::path& path) const; 
private:
	UEObject packageObj;

	struct Enum
	{
		std::string Name;
		std::string FullName;
		std::vector<std::string> Values;
	};
	std::vector<Enum> enums;
	void GenerateEnum(const UEEnum& enumObj);

	std::unordered_map<std::string, std::string> constants;
	void GenerateConst(const UEConst& constObj);

	struct Member
	{
		std::string Name;
		std::string Type;

		size_t Offset;
		size_t Size;

		size_t Flags;
		std::string FlagsString;

		std::string Comment;
	};
	struct ScriptStruct
	{
		std::string Name;
		std::string FullName;
		std::string NameCpp;
		std::string NameCppFull;
		int Size;
		int InheritedSize;
		std::vector<Member> Members;
	};
	struct Class : ScriptStruct
	{
	};
	std::vector<Class> classes;
	std::vector<ScriptStruct> scriptStructs;
	static Member CreatePadding(size_t id, size_t offset, size_t size, std::string reason);
	static Member CreateBitfieldPadding(size_t id, size_t offset, std::string type, size_t bits);
	mutable std::unordered_set<uint64> dependencies;
	bool AddDependency(const UEObject& package) const;
	void GeneratePrerequisites(const UEObject& obj, std::unordered_map<uint64, bool>& processedObjects);
	void GenerateMemberPrerequisites(const UEProperty& first, std::unordered_map<uint64, bool>& processedObjects);
	void GenerateMembers(const UEStruct& structObj, size_t offset, const std::vector<UEProperty>& properties, std::vector<Member>& members) const;
	void GenerateScriptStruct(const UEScriptStruct& scriptStructObj);
	void GenerateClass(const UEClass& classObj);

	void SaveStructs(const fs::path& path) const;
	void SaveClasses(const fs::path& path) const;

	void PrintConstant(std::ostream& os, const std::pair<std::string, std::string>& c) const;
	void PrintStruct(std::ostream& os, const ScriptStruct& ss) const;
	void PrintEnum(std::ostream& os, const Enum& e) const;
	void PrintClass(std::ostream& os, const Class& c) const;

};

inline bool operator==(const Package& lhs, const Package& rhs) { return rhs.packageObj.GetAddress() == lhs.packageObj.GetAddress(); }
inline bool operator!=(const Package& lhs, const Package& rhs) { return !(lhs == rhs); }
