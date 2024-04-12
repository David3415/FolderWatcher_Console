
#include <iostream>
#include <fstream>
#include "Windows.h"
#include "Wininet.h"
#pragma comment(lib, "wininet.lib")
#include "GetFileSizeFromUrlClass.h"

DWORD GetFileSizeFromUrlClass::GetFileSizeFromUrlVoid(std::wstring fileFromUrl) {
	HINTERNET hOpen = NULL;
	HINTERNET hFile = NULL;
	HANDLE hOut = NULL;
	char* data = NULL;
	DWORD dataSize = 0;
	DWORD dwBytesRead = 0;
	DWORD dwBytesWritten = 0;

	hOpen = InternetOpenW(L"MyAgent", NULL, NULL, NULL, NULL);
	if (!hOpen) return NULL;

	hFile = InternetOpenUrlW(hOpen, &fileFromUrl[0], NULL, NULL, INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE, NULL);
	if (!hFile) {
		InternetCloseHandle(hOpen);
		return NULL;
	}
	do {
		char buffer[2000];
		InternetReadFile(hFile, (LPVOID)buffer, _countof(buffer), &dwBytesRead);
		char* tempData = new char[dataSize + dwBytesRead];
		memcpy(tempData, data, dataSize);
		memcpy(tempData + dataSize, buffer, dwBytesRead);
		//delete[] data;
		data = tempData;
		dataSize += dwBytesRead;
		//delete[] tempData;//---
	} while (dwBytesRead);
	
	InternetCloseHandle(hFile);
	InternetCloseHandle(hOpen);
	
	return dataSize;
};