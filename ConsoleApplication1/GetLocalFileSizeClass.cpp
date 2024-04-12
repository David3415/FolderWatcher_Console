#include <iostream>
#include <fstream>
#include "Windows.h"
#include "Wininet.h"
#pragma comment(lib, "wininet.lib")
#include "GetLocalFileSizeClass.h"


unsigned long GetLocalFileSizeClass::GetLocalFileSizeVoid(std::wstring file_to_update) {//char* par[],
	char str[100]{};
	unsigned long FileSize = 0;
	HANDLE hF = CreateFile(
		&file_to_update[0], // file name
		GENERIC_READ,                // access mode
		0,                           // share mode
		NULL,                        // SD
		OPEN_EXISTING,               // how to create
		0,                           // file attributes
		NULL                         // handle to template file
	);
	FileSize = GetFileSize(hF, NULL);
	CloseHandle(hF);
	return FileSize;
}