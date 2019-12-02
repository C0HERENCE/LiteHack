#include "Overlay.h"
#include "WindowHijack.h"
#pragma unmanaged
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#pragma managed


int Overlay::Init()
{
	hwnd = HiJackNotepadWindow();

	Width = GetSystemMetrics(SM_CXSCREEN);
	Height = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(hwnd, 0, 0, 0, Width, Height, 0);
	CreateDeviceD3D(hwnd);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, Width, Height, SWP_SHOWWINDOW);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 18.f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
	return 1;
}

void Overlay::CleanUp()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	CleanupDeviceD3D();
	::DestroyWindow(hwnd);
	TerminateNotepad();
}

void Overlay::RefreshAndSleep(int sleep)
{
	ImGui::Render();
	pin_ptr<ID3D11RenderTargetView*> a = &g_mainRenderTargetView;
	ImVec4 clear_color = ImVec4(0., 0., 0., 0.);
	g_pd3dDeviceContext->OMSetRenderTargets(1, a, NULL);
	g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	g_pSwapChain->Present(1, 0);
	Sleep(sleep);
}

void Overlay::NewFrame()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

bool Overlay::CreateDeviceD3D(HWND hWnd)
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
	pin_ptr<IDXGISwapChain*> a = &g_pSwapChain;
	pin_ptr<ID3D11Device*> b = &g_pd3dDevice;
	pin_ptr<ID3D11DeviceContext*> c = &g_pd3dDeviceContext;
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, a, b, &featureLevel, c) != S_OK)
		return false;

	CreateRenderTarget();
	return true;
}

void Overlay::CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void Overlay::CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	pin_ptr<ID3D11RenderTargetView*> a = &g_mainRenderTargetView;
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, a);
	pBackBuffer->Release();
}

void Overlay::CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}
