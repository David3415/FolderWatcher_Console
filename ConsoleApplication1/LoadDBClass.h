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

using namespace std;
using namespace std::experimental::filesystem;
static class LoadDBClass
{
public:
	vector<wstring> LoadDBVec;
	static vector<wstring>LoadDBFunc(wstring);
};
