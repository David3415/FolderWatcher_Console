#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <experimental/filesystem>
#include <conio.h>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include <windows.h>
#include <tlhelp32.h>
#include <windowsx.h>
#include <algorithm>
#include <shobjidl.h> 
#include <shlobj.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "DisplayPathInfoClass.h"
#include "LoadDBClass.h"
#include "TgClass.h"
#include "GetLocalFileSizeClass.h"
#include "ReplaceLocalFileWithFileFromUrlClass.h"
#include "GetFileSizeFromUrlClass.h"

#include <map>

#define WMAIN_CLASSNAME L"MyClassName"
#define WMAIN_CAPTION L"Test Window"
vector<HWND>formsVec;
int resPos{};
int G = 400;
using namespace std;
using namespace std::experimental::filesystem;
bool startBool = false;

wstring  my_string[3]{};
wstring  wstringForTg = L"START";
bool wnd_exists = false;
vector<wstring>new_paths = {
	//L"\\\\FILESERVER-2\\Для всех\\ГРУППА ДИЗАЙНА",L"\\\\STOR1\\ingest hr\\ГРУППА ДИЗАЙНА",L"F:\\EFIR"


L"c:\\Users\\dgagi\\Desktop", L"c:\\Users\\dgagi\\Desktop\\000", L"c:\\Users\\dgagi\\Desktop\\111"

};


HWND hwndOwner{};
HINSTANCE hinst;
bool new_wnd = true;
HWND hWnd_child;
HWND hWnd_edit2{};
int wnd_counter{};
int j{};
bool start = false;
vector<pair<wstring, wstring>>DirAndFilesVec;

using namespace std;
using namespace std::experimental::filesystem;

unsigned int WNDSEX_COUNT = 0;

int childsIndsex{};
class WND
{
public:
	class wnd {
	public:
		map<HWND, wnd*> wndlist;
		static LRESULT CALLBACK mainwindowproc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
			PAINTSTRUCT ps;
			HDC hdc;
			/*	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
				SetLayeredWindowAttributes(hWnd, 50, (255 * 70) / 100, LWA_ALPHA);*/
			SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
			switch (message)
			{
			case WM_CREATE:
				/*SetWindowLong(hWnd, GWL_EXSTYLE,
					GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT | WS_EX_LAYERED
				);
				SetLayeredWindowAttributes(hWnd, RGB(100,100,100), 255, LWA_COLORKEY | LWA_ALPHA);
			}*/
				break;
			case WM_LBUTTONDOWN:
			{

				cout << WNDSEX_COUNT << '\n';
				auto pos = find(formsVec.begin(), formsVec.end(), hWnd);
				resPos = pos - formsVec.begin();
				formsVec.erase(pos);
				DestroyWindow(hWnd);
				//for (size_t wnd_count_new = resPos; wnd_count_new < formsVec.size(); wnd_count_new++) {
				//RedrawWindow(formsVec[wnd_count_new], 0, 0, 0);

				for (size_t wnd_count_new = resPos; wnd_count_new < formsVec.size(); wnd_count_new++) {
					MoveWindow(formsVec[wnd_count_new], 1670, 900 - 93 * wnd_count_new, 250, 90, 0);
				}
				if (formsVec.size() > 0) {
					WNDSEX_COUNT = formsVec.size() - 1;
				}
				else {
					WNDSEX_COUNT = 0;
				}
			}
			break;
			case WM_RBUTTONDOWN:
			{

				ShellExecuteW(hWnd, L"Open", &my_string[j][0], 0, 0, 1);


				cout << '\n' << resPos << '\t' << "resPos" << '\n';

				WNDSEX_COUNT = formsVec.size();
			}
			break;
			case WM_SIZE:
				InvalidateRect(hWnd, NULL, true);
				break;
			case WM_PAINT:
				hdc = BeginPaint(hWnd, &ps);
				RECT rect;
				GetClientRect(hWnd, &rect);
				SetBkMode(hdc, OPAQUE);
				wstringForTg = my_string[j];
				DrawText(hdc, &my_string[j][0], -1, &rect, DT_SINGLELINE | DT_VCENTER);
				EndPaint(hWnd, &ps);
				break;
			case WM_CLOSE:
				if (IDYES != MessageBox(hWnd, L"Зыкрыть окно?", L"Question", MB_YESNO | MB_ICONQUESTION))
					break;
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
			return 0;
		}

		HWND hwnd;
		wnd(HINSTANCE hInst, wchar_t* winname, bool _mainwindow = true, int nShowCmd = 0) {//} :mainwindow(_mainwindow) {
			WNDCLASS wc = { 0 };
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
			wc.hInstance = hInst;
			wc.lpfnWndProc = &wnd::mainwindowproc;
			wc.style = CS_HREDRAW | CS_VREDRAW;
			wc.lpszClassName = WMAIN_CLASSNAME;
			wc.lpszMenuName = NULL;
			RegisterClass(&wc);
			cout << WNDSEX_COUNT << '\n';
			hwnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT, WMAIN_CLASSNAME, winname,
				WS_POPUP | WS_VISIBLE | WS_EX_TOPMOST,///*WS_OVERLAPPEDWINDOW*/WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX ,
				1670, 900 - 93 * WNDSEX_COUNT, 250, 90, HWND_DESKTOP, NULL, hInst, 0);

		}

	};

};
int M(HINSTANCE hInst,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	std::wstring ws = L"First";
	wchar_t* ws_t = &ws[0];

	WND::wnd w(hinst, ws_t, true, 0);//, , false
	formsVec.push_back(w.hwnd);

	/*for (auto k : formsVec) {
cout << '\n' << k << " w.hwnd" << '\n';
	}*/


	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
};


int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Russian_Russia.1251");

	//=======================================  INSTALLATION OF CURL   ================================================
	/*system("\git clone https://github.com/Microsoft/vcpkg.git \c:\\vcpkg");
	system("c:\\vcpkg\\bootstrap-vcpkg.bat");
	system("c:\\vcpkg\\vcpkg install curl");
	system("c:\\vcpkg\\vcpkg integrate install");*/


	//=======================================  ПРОВЕРКА НАЛИЧИЯ ОБНОВЛЕНИЙ  ===============================================
	//=================================================================================================================
	std::wstring fileFromUrl = L"https://iwillpouryousomecoffee.ru/files/FolderWatcher.msi";
	DWORD fileFromUrlSize = GetFileSizeFromUrlClass::GetFileSizeFromUrlVoid(fileFromUrl);
	std::wstring file_to_update = L"c:\\Users\\dgagi\\Desktop\\FolderWatcher_Setup\\FolderWatcher.msi";
	unsigned long localFileSize = GetLocalFileSizeClass::GetLocalFileSizeVoid(file_to_update);
	if (fileFromUrlSize != localFileSize) {
		auto res = ReplaceLocalFileWithFileFromUrlClass::ReplaceLocalFileWithFileFromUrlVoid(fileFromUrl, file_to_update);
	}



	//=================================================================================================================
	//=================================================================================================================
		wstring LoadDBPath = L"%Temp%\\LoadDBTemp.txt";
	vector< wstring>LoadDBVec = LoadDBClass::LoadDBFunc(LoadDBPath);// Грузим Базу  данных словаря
	LPCTSTR p_sound = L"c:\\Users\\dgagi\\Desktop";					//грузим звук
	//ESC_Class esc_Class{};											//Класс выхода по нажатию ESC
	//thread my_thread(&ESC_Class::EscVoid, ref(esc_Class));			//выделяем поток для ESC_Class
	//MainDialogClass mainDialogClass{};

	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_HIDE);//Прячем консоль

	wstring directory_path = L"c:\\Users\\dgagi\\Desktop";
	vector<wstring>new_paths = LoadDBVec;// { L"c:\\Users\\dgagi\\Desktop", L"c:\\Users\\dgagi\\Desktop\\000" };//L"\\\\fileserver-2\\Для всех\\группа дизайна",L"\\\\Stor1\\ingest hr\\ГРУППА ДИЗАЙНА",L"F:\EFIR"  

	//----------------------------------количество файлов в папке----------------
	DisplayPathInfoClass displayPathInfoClass{};
	vector<int> oldValVec(3);
	for (int i = 0; i < 3; i++) {
		oldValVec[i] = displayPathInfoClass.DisplayPathVoid(new_paths[i]);
	};
	unsigned int newVal{};// новое количество файлов в папке
	bool yep = false;


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	thread th_TgThread(&TgClass::TgVoid);
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




	while (true)
	{

		for (j = 0; j < 3; j++) {

			this_thread::sleep_for(chrono::milliseconds(500));
			newVal = displayPathInfoClass.DisplayPathVoid(new_paths[j]);
			newVal = displayPathInfoClass.DisplayPathVoid(new_paths[j]);
			if (newVal > oldValVec[j]) {

				HINSTANCE hInst{};
				HINSTANCE hPrevInstance{};
				LPSTR lpCmdLine{};
				int nShowCmd{};

				G = 11024;
				if (start == false) { start = true; };

				//MainDialogVoid();

				DirAndFilesVec.push_back(make_pair(new_paths[j], new_paths[j]));
				childsIndsex += j;
				//new_wnd == true ? new_wnd = false : new_wnd = true;

				oldValVec[j] = newVal;
				my_string[j] = new_paths[j];
				thread th_MainDialog(M, hInst, hPrevInstance, lpCmdLine, nShowCmd);
				th_MainDialog.detach();
				Beep(700, 300);
				Beep(700, 300);
				wnd_counter++; yep = true;
				WNDSEX_COUNT++;
			}
			//else if (newVal < oldValVec[j]) {
			//	if (start == false) { start = true; };
			//	startBool = true;
			//	childsIndsex = j;
			//	oldValVec[j] = newVal;
			//	my_string[j] = new_paths[j];
			//	//PlaySound(TEXT("c:\\Users\\dgagi\\Desktop\\StranitsaWAV.wav"), NULL, SND_FILENAME | SND_ASYNC);
			//	wnd_counter++;
			//	cout << wnd_counter;
			//	cout << wnd_counter;
			//}
		}
	}
	//my_thread.detach();
}
