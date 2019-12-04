#include "Overlay.h"
#include "WindowHijack.h"
#pragma unmanaged
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#pragma managed
#include "Header.h"
#include "Global.h"

int Overlay::Init()
{
	Width = GetSystemMetrics(SM_CXSCREEN);
	Height = GetSystemMetrics(SM_CYSCREEN);

	if (Global::Option->UseHijackOverlay)
	{
		hwnd = HiJackNotepadWindow();
	}
	else
	{
		WNDCLASSEX wClass =
		{
			sizeof(WNDCLASSEX), 0, WndProc, 0, 0, nullptr, LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr, " ", LoadIcon(nullptr, IDI_APPLICATION)
		};
		::RegisterClassEx(&wClass);
		hwnd = CreateWindowEx(NULL, " ", " ", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, NULL, NULL, 0, NULL);
		ShowWindow(hwnd, SW_SHOW);
		UpdateWindow(hwnd);
	}

	SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE);
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT /*| WS_EX_TOOLWINDOW*/);
	//SetLayeredWindowAttributes(hwnd, 0, 0, LWA_ALPHA);
	//SetLayeredWindowAttributes(hwnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
	//SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 255, ULW_COLORKEY | LWA_ALPHA);
	MARGINS margins = { -1 };
	DwmExtendFrameIntoClientArea(hwnd, &margins);

	SetWindowPos(hwnd, 0, 0, 0, Width, Height, 0);
	CreateDeviceD3D(hwnd);
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, Width, Height, SWP_SHOWWINDOW);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 18.f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	int my_image_width = 0;
	int my_image_height = 0;
	bool ret = LoadTextureFromFile("Images/Ammunition/Item_Ammo_9mm_C.png", &my_texture, &my_image_width, &my_image_height);
	IM_ASSERT(ret);
	
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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
bool Overlay::LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
	// Load from disk into a raw RGBA buffer
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	// Create texture
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = image_width;
	desc.Height = image_height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;

	ID3D11Texture2D* pTexture = NULL;
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = image_data;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;
	g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

	// Create texture view
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;
	g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
	pTexture->Release();

	*out_width = image_width;
	*out_height = image_height;
	stbi_image_free(image_data);

	return true;
}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (Global::Canvas->g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			Global::Canvas->CleanupRenderTarget();
			Global::Canvas->g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			Global::Canvas->CreateRenderTarget();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		//::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
