#include "Renderer.h"
#include "Global.h"
#include "imgui.h"

void Renderer::Line(FVector from, FVector end, FColor color, float thickness)
{
	ImVec2 _from = ImVec2(from.X, from.Y);
	ImVec2 _end = ImVec2(end.X, end.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddLine(_from, _end, _color, thickness);
}
void Renderer::Text(FVector pos, FColor color, char* string, int length)
{
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, string, string + length);
}
void Renderer::Text(FVector pos, FColor color, std::string string)
{
	char* _string;
	_string = (char*)string.data();
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, _string, _string + string.length());
}
void Renderer::Circle(FVector center, float radius, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,33 });
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(center.X, center.Y), radius, _color);
}
void Renderer::Rectangle(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color);
}
void Renderer::RectangleFilled(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,1 });
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color);
}

FVector Renderer::WorldToScreen(FVector WorldLocation, Off::FMinimalViewInfo POV)
{
	FVector Screenlocation = FVector(0, 0, 0);
	FRotator Rotation = POV.Rotation;
	FVector vAxisX, vAxisY, vAxisZ;
	Rotation.get_axes(vAxisX, vAxisY, vAxisZ);
	FVector vDelta = WorldLocation - POV.Location;
	FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
	if (vTransformed.Z < 1.f)
		vTransformed.Z = 1.f;
	float FovAngle = POV.FOV;
	float ScreenCenterX = Global::Canvas->Width / 2.0f;
	float ScreenCenterY = Global::Canvas->Height / 2.0f;
	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	return Screenlocation;
}

std::string FString::ToString() const
{
	wchar_t* Name;
	if (m_nCount>=60)
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