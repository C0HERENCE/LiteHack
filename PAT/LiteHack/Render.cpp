#include "Render.h"
#include "WindowHijack.h"
#include "..//GWorld/Core/FTransform.h"
#include <list>


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

int Render::Initialize()
{
	hwnd = HiJackNotepadWindow();
	Width = GetSystemMetrics(SM_CXSCREEN);
	Height = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, 0, 0, 0, Width, Height, 0);
	CreateDeviceD3D(hwnd);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, Width, Height, SWP_SHOWWINDOW);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 15.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
	return 1;
}

void Render::CleanUp()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	CleanupDeviceD3D();
	::DestroyWindow(hwnd);
}

void Render::Refresh()
{
	ImGui::Render();
	g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
	g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)& clear_color);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	g_pSwapChain->Present(1, 0);
	Sleep(16);
}

void Render::NewFrame()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void Render::DrawLine(FVector from, FVector end, FColor color, float thickness)
{
	ImVec2 _from = ImVec2(from.X, from.Y);
	ImVec2 _end = ImVec2(end.X, end.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddLine(_from, _end, _color, thickness);
}
void Render::DrawString(FVector pos, FColor color, char* string, int length)
{
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, string, string + length);
}
void Render::DrawString(FVector pos, FColor color, std::string string)
{
	char* _string;
	_string = (char*)string.data();
	ImVec2 _pos = ImVec2(pos.X, pos.Y);
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddText(_pos, _color, _string, _string + string.length());
}
void Render::DrawCircle(FVector center, float radius, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(center.X, center.Y), radius, _color);
}
void Render::DrawRectangle(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,color.A / 255.f });
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color);
}
void Render::DrawRectangleFilled(FVector a, float h, float w, FColor color)
{
	ImU32 _color = ImGui::GetColorU32({ color.R / 255.f ,color.G / 255.f ,color.B / 255.f ,1 });
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(a.X, a.Y), ImVec2(a.X + w, a.Y + h), _color);
}

FVector Render::WorldToScreen(FVector WorldLocation, FMinimalViewInfo POV)
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
	float ScreenCenterX = Width / 2.0f;
	float ScreenCenterY = Height / 2.0f;
	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)3.14159265358979323846 / 360.f)) / vTransformed.Z;
	return Screenlocation;
}

void Render::DrawWorldToScreenScreenText(FVector WorldLocation, FMinimalViewInfo POV,FColor color,std::string string)
{
	FVector ScreenPos = WorldToScreen(WorldLocation,POV);
	DrawString(ScreenPos, color, string);
}

bool Render::CreateDeviceD3D(HWND hWnd)
{
	// Setup swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
		return false;

	CreateRenderTarget();
	return true;
}

void Render::CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void Render::CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
	pBackBuffer->Release();
}

void Render::CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Win32 message handler
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI Render::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
