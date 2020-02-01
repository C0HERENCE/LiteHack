#include "../Global.h"
#include "Renderer.h"

ImU32 Renderer::ConvertColor(FColor color)
{
	if (Alpha)
	{
		return ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,0.4f });
	}
	else
	{
		return ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,0.7f });
	}
}
void Renderer::Line(FVector from, FVector end, FColor color)
{
	ImVec2 _from = ImVec2(from.X, from.Y);
	ImVec2 _end = ImVec2(end.X, end.Y);
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddLine(_from, _end, _color, thickness);
}
void Renderer::Text(FVector pos, FColor color, char* string, int length)
{
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, string, string + length);
}
void Renderer::Text(FVector pos, FColor color, std::string string)
{
	char* _string;
	_string = (char*)string.data();
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, _string, _string + string.length());
}
void Renderer::Circle(FVector center, float radius, FColor color)
{
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(center.X, center.Y), radius, _color, 36, thickness);
}
void Renderer::Rectangle(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color, 0.f, 15, thickness);
}
void Renderer::RectangleFilled(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ConvertColor(color);
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color);
}

void Renderer::Image(ID3D11ShaderResourceView* texture, FVector a, FVector b)
{
	ImGui::GetOverlayDrawList()->AddImage((void*)texture, ImVec2(a.X, a.Y), ImVec2(b.X, b.Y));
}

FVector Renderer::WorldToScreen(FVector WorldLocation, FMinimalViewInfo POV)
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
	Screenlocation.X = LiteHack.Canvas->ScreenCenterX + vTransformed.X * (LiteHack.Canvas->ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	Screenlocation.Y = LiteHack.Canvas->ScreenCenterY - vTransformed.Y * (LiteHack.Canvas->ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	return Screenlocation;
}