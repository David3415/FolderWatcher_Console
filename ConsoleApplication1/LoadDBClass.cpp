#pragma once
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
#include "LoadDBClass.h"
extern wstring my_string[];
using namespace std;
using namespace std::experimental::filesystem;

vector< wstring>LoadDBClass::LoadDBFunc(wstring LoadDBPath) {
	vector< wstring>LoadDBVec{};

	if (L"%userprofile%\\AppData\\Local\\Temp\\LoadDBTemp.txt") {
		LoadDBVec = {
			//L"\\\\FILESERVER-2\\Для всех\\ГРУППА ДИЗАЙНА",L"\\\\STOR1\\ingest hr\\ГРУППА ДИЗАЙНА",L"F:\\EFIR"
			 //L"c:\\Users\\dgagi\\Desktop",L"c:\\Users\\dgagi\\Desktop\\000",L"c:\\Users\\dgagi\\Desktop\\Адаптивная верстка"
			 L"c:\\Users\\dgagi\\Desktop",L"c:\\Users\\dgagi\\Desktop\\000",L"c:\\Users\\dgagi\\Desktop\\111"
		};
		for (int i = 0; i < 3; i++) {
			my_string[i] = LoadDBVec[i];
		}
	}
	else {
		wfstream finout;
		wstring temp;
		finout.open(LoadDBPath, ios::in | ios::out);
		int j = 0;
		while (getline(finout, temp)) {
			LoadDBVec[j] = temp;
		}
	}
	return LoadDBVec;
}

