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
#include "Header.h"
void Renderer::Image()
{
	ImGui::GetOverlayDrawList()->AddImage((void*)my_texture,ImVec2(0,0), ImVec2(100, 100));
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

