#include "Commons.h"

std::map<float, uint64_t> distances;
std::map<uint32_t, float> player_keys;
int warning_count;
std::list<int> rightarm = { 5,15,16,17,18 };
std::list<int> leftarm = { 5,35,36,37,38 };
std::list<int> upper = { 5,4,3,2,1 };
std::list<int> rightleg = { 1,56,57,58 };
std::list<int> leftleg = { 1,60,61,62 };
std::list<std::list<int>> part = { rightarm,leftarm,upper,rightleg,leftleg };

FVector GetBoneWithRotation(ASTExtraPlayerCharacter^ actor, int id)
{
	auto mesh = actor->Mesh();
	auto arrybone = mesh->BoneArray();
	FTransform bone = Global::GMemory->Read<FTransform>(arrybone + (id * 0x30));
	FTransform ComponentToWorld = mesh->ComponentToWorld();
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}

std::string FString::ToString() const
{
	wchar_t* Name;
	if (m_nCount >= 60)
	{
		return "Error";
	}
	Name = (wchar_t*)Global::GMemory->ReadSize(m_Data, m_nCount * sizeof(wchar_t));
	if (Name != NULL)
	{
		char text[60];
		sprintf_s(text, "%ls", Name);
		delete Name;
		return text;
	}
	else
	{
		return "Unkown";
	}
}

D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}