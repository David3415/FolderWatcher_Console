#pragma once
#include <iostream>
#include <fstream>
#include "Windows.h"
#include "Wininet.h"
#pragma comment(lib, "wininet.lib")

class GetFileSizeFromUrlClass
{public:
	static DWORD GetFileSizeFromUrlVoid(std::wstring fileFromUrl);
	HINTERNET hOpen;
	HINTERNET hFile;
	HANDLE hOut;
	char* data;
	DWORD dataSize;
	DWORD dwBytesRead;
	DWORD dwBytesWritten;
};

