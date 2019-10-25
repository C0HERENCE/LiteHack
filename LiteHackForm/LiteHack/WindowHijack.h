#pragma once
#include <Dwmapi.h>
#include <vector>
#include <TlHelp32.h>
#include <string>
#define HJWND_PROGRAM L"notepad.exe"
#define MAX_CLASSNAME 255
#define MAX_WNDNAME 255
#pragma comment(lib, "Dwmapi.lib")
struct WindowsFinderParams {
	DWORD pidOwner = NULL;
	std::wstring wndClassName = L"";
	std::wstring wndName = L"";
	RECT pos = { 0, 0, 0, 0 };
	POINT res = { 0, 0 };
	float percentAllScreens = 0.0f;
	float percentMainScreen = 0.0f;
	DWORD style = NULL;
	DWORD styleEx = NULL;
	bool satisfyAllCriteria = false;
	std::vector<HWND> hwnds;
};
HWND HiJackNotepadWindow();
std::vector<DWORD> GetPIDs(std::wstring targetProcessName);
std::vector<HWND> WindowsFinder(WindowsFinderParams params);
BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam);
void TerminateNotepad();
HWND HiJackNotepadWindow()
{
	HWND hwndHiHjacked = NULL;
	std::vector<DWORD> existingNotepads = GetPIDs(HJWND_PROGRAM);
	if (!existingNotepads.empty()) {
		for (int i(0); i < existingNotepads.size(); ++i) {
			HANDLE hOldProcess = OpenProcess(PROCESS_TERMINATE, FALSE, existingNotepads[i]);
			TerminateProcess(hOldProcess, 0);
			CloseHandle(hOldProcess);
		}
	}
	system("start notepad");

	std::vector<DWORD> notepads = GetPIDs(HJWND_PROGRAM);
	if (notepads.empty() || notepads.size() > 1)
	{
		MessageBox(NULL, (LPCTSTR)L"Finding Nvida Share.exe Error", (LPCTSTR)L"HI", MB_ICONQUESTION);
		return hwndHiHjacked;
	}
	WindowsFinderParams params;
	params.pidOwner = notepads[0];
	params.style = WS_VISIBLE;
	params.satisfyAllCriteria = true;
	std::vector<HWND> hwnds;
	int attempt = 0;
	while (hwndHiHjacked == NULL || attempt > 5000) {
		Sleep(100);
		hwnds = WindowsFinder(params);
		if (hwnds.size() > 1)
			return hwndHiHjacked;
		hwndHiHjacked = hwnds[0];
		++attempt;
	}
	if (!hwndHiHjacked)
		return hwndHiHjacked;

	SetMenu(hwndHiHjacked, NULL);
	SetWindowLongPtr(hwndHiHjacked, GWL_STYLE, WS_VISIBLE);
	SetWindowLongPtr(hwndHiHjacked, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT);
	MARGINS margins = { -1 };
	DwmExtendFrameIntoClientArea(hwndHiHjacked, &margins);
	return hwndHiHjacked;
}

void TerminateNotepad()
{
	std::vector<DWORD> existingNotepads = GetPIDs(HJWND_PROGRAM);
	if (!existingNotepads.empty()) {
		for (int i(0); i < existingNotepads.size(); ++i) {
			HANDLE hOldProcess = OpenProcess(PROCESS_TERMINATE, FALSE, existingNotepads[i]);
			TerminateProcess(hOldProcess, 0);
			CloseHandle(hOldProcess);
		}
	}
}

std::vector<DWORD> GetPIDs(std::wstring targetProcessName) {
	std::vector<DWORD> pids;
	if (targetProcessName == L"")
		return pids;
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W entry;
	entry.dwSize = sizeof entry;
	if (!Process32FirstW(snap, &entry)) {
		CloseHandle(snap);
		return pids;
	}
	do {
		if (std::wstring(entry.szExeFile) == targetProcessName) {
			pids.emplace_back(entry.th32ProcessID);
		}
	} while (Process32NextW(snap, &entry));
	CloseHandle(snap);
	return pids;
}
std::vector<HWND> WindowsFinder(WindowsFinderParams params) {
	EnumWindows(EnumWindowsCallback, (LPARAM)& params);
	return params.hwnds;
}
BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam) {
	WindowsFinderParams& params = *(WindowsFinderParams*)lParam;

	unsigned char satisfiedCriteria = 0, unSatisfiedCriteria = 0;

	// If looking for windows of a specific PID
	DWORD pid = 0;
	GetWindowThreadProcessId(hwnd, &pid);
	if (params.pidOwner != NULL)
		if (params.pidOwner == pid)
			++satisfiedCriteria; // Doesn't belong to the process targeted
		else
			++unSatisfiedCriteria;

	// If looking for windows of a specific class
	wchar_t className[MAX_CLASSNAME] = L"";
	GetClassName(hwnd, (LPSTR)className, MAX_CLASSNAME);
	std::wstring classNameWstr = className;
	if (params.wndClassName != L"")
		if (params.wndClassName == classNameWstr)
			++satisfiedCriteria; // Not the class targeted
		else
			++unSatisfiedCriteria;

	// If looking for windows with a specific name
	wchar_t windowName[MAX_WNDNAME] = L"";
	GetWindowText(hwnd, (LPSTR)windowName, MAX_CLASSNAME);
	std::wstring windowNameWstr = windowName;
	if (params.wndName != L"")
		if (params.wndName == windowNameWstr)
			++satisfiedCriteria; // Not the class targeted
		else
			++unSatisfiedCriteria;

	// If looking for window at a specific position
	RECT pos;
	GetWindowRect(hwnd, &pos);
	if (params.pos.left || params.pos.top || params.pos.right || params.pos.bottom)
		if (params.pos.left == pos.left && params.pos.top == pos.top && params.pos.right == pos.right && params.pos.bottom == pos.bottom)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	// If looking for window of a specific size
	POINT res = { pos.right - pos.left, pos.bottom - pos.top };
	if (params.res.x || params.res.y)
		if (res.x == params.res.x && res.y == params.res.y)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	// If looking for windows taking more than a specific percentage of all the screens
	float ratioAllScreensX = res.x / GetSystemMetrics(SM_CXSCREEN);
	float ratioAllScreensY = res.y / GetSystemMetrics(SM_CYSCREEN);
	float percentAllScreens = ratioAllScreensX * ratioAllScreensY * 100;
	if (params.percentAllScreens != 0.0f)
		if (percentAllScreens >= params.percentAllScreens)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	// If looking for windows taking more than a specific percentage or the main screen
	RECT desktopRect;
	GetWindowRect(GetDesktopWindow(), &desktopRect);
	POINT desktopRes = { desktopRect.right - desktopRect.left, desktopRect.bottom - desktopRect.top };
	float ratioMainScreenX = res.x / desktopRes.x;
	float ratioMainScreenY = res.y / desktopRes.y;
	float percentMainScreen = ratioMainScreenX * ratioMainScreenY * 100;
	if (params.percentMainScreen != 0.0f)
		if (percentAllScreens >= params.percentMainScreen)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	// Looking for windows with specific styles
	LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
	if (params.style)
		if (params.style & style)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	// Looking for windows with specific extended styles
	LONG_PTR styleEx = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	if (params.styleEx)
		if (params.styleEx & styleEx)
			++satisfiedCriteria;
		else
			++unSatisfiedCriteria;

	if (satisfiedCriteria == 0)
	{
		return TRUE;

	}

	if (params.satisfyAllCriteria == 1 && unSatisfiedCriteria > 0) //满足数大于0，但要满足所有条件，继续查找
	{
		return TRUE;
	}

	// If looking for multiple windows
	params.hwnds.push_back(hwnd);
	return TRUE;
}