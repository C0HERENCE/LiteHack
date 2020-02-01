#include "../Global.h"
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "d3d11.lib")

RECT GameRect;
MARGINS Margin = { -1 };
RECT old_rc;


int Overlay::Init()
{
	wClass =
	{
		sizeof(WNDCLASSEX),
		0,
		WndProc,
		0,
		0,
		nullptr,
		LoadIcon(nullptr, IDI_APPLICATION),
		LoadCursor(nullptr, IDC_ARROW),
		nullptr,
		nullptr,
		LiteHack.M_Name,
		LoadIcon(nullptr, IDI_APPLICATION)
	};
	::RegisterClassEx(&wClass);
	GameWnd = FindWindow(LiteHack.WindowsClass, LiteHack.WindowsCaption);
	if (GameWnd)
	{
		POINT xy;
		ZeroMemory(&GameRect, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &GameRect);
		ClientToScreen(GameWnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
	{
		return FALSE;
	}
	MyWnd = CreateWindowEx(NULL, LiteHack.M_Name, LiteHack.M_Name, WS_POPUP | WS_VISIBLE, GameRect.left, GameRect.top, Width, Height, NULL, NULL, 0, NULL);
	DwmExtendFrameIntoClientArea(MyWnd, &Margin);
	SetWindowLong(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	ShowWindow(MyWnd, SW_SHOW);
	UpdateWindow(MyWnd);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();(void)io;
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 18.f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	ImGui::StyleColorsDark();
	if (!CreateDeviceD3D(MyWnd))
	{
		::UnregisterClass(wClass.lpszClassName, wClass.hInstance);
		return FALSE;
	}
	ImGui_ImplWin32_Init(MyWnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
	return 1;
}
void Overlay::SetWindowToTarget()
{
	HWND hwnd_active = GetForegroundWindow();
	if (hwnd_active == GameWnd) {
		HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
		SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}

	RECT rc;
	POINT xy;

	ZeroMemory(&rc, sizeof(RECT));	ZeroMemory(&xy, sizeof(POINT));
	GetClientRect(GameWnd, &rc);
	ClientToScreen(GameWnd, &xy);
	rc.left = xy.x;
	rc.top = xy.y;
	if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
	{
		old_rc = rc;
		LiteHack.Canvas->Width = rc.right;
		LiteHack.Canvas->Height = rc.bottom;
		LiteHack.Canvas->ScreenCenterX = LiteHack.Canvas->Width / 2.0f;
		LiteHack.Canvas->ScreenCenterY = LiteHack.Canvas->Height / 2.0f;
		SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, LiteHack.Canvas->Width, LiteHack.Canvas->Height, SWP_NOREDRAW);
	}
	
}
void Overlay::NewFrame()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void Overlay::RefreshAndSleep(int sleep)
{
	ImGui::Render();
	ImVec4 clear_color = ImVec4(0., 0., 0., 0.);
	g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
	g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	g_pSwapChain->Present(1, 0);
	SetWindowToTarget();
	Sleep(sleep);
}
void Overlay::Cleanup()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	LiteHack.Canvas->CleanupDeviceD3D();
	::DestroyWindow(MyWnd);
	::UnregisterClass(wClass.lpszClassName, wClass.hInstance);
}

bool Overlay::CreateDeviceD3D(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = Width;
	sd.BufferDesc.Height = Height;
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
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
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
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
	pBackBuffer->Release();
}

void Overlay::CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}
#define STB_IMAGE_IMPLEMENTATION

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (LiteHack.Canvas->g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			LiteHack.Canvas->CleanupRenderTarget();
			LiteHack.Canvas->g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			LiteHack.Canvas->CreateRenderTarget();
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
