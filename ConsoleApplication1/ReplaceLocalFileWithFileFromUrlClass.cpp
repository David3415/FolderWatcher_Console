#include <iostream>
#include <fstream>
#include "Windows.h"
#include "Wininet.h"
#pragma comment(lib, "wininet.lib")
#include "ReplaceLocalFileWithFileFromUrlClass.h"

 int ReplaceLocalFileWithFileFromUrlClass::ReplaceLocalFileWithFileFromUrlVoid(std::wstring fileFromUrl, std::wstring file_to_update) {
	HINTERNET hi = InternetOpenW(L"MyProgram", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hi == NULL)
	{
		std::cout << "error " << GetLastError() << std::endl;
	}
	else
	{
		HINTERNET hiu = InternetOpenUrlW(hi, &fileFromUrl[0], NULL, 0, INTERNET_FLAG_RELOAD, NULL);
		if (hiu == NULL)
		{
			std::cout << "error " << GetLastError() << std::endl;
		}
		else
		{
			char buf[10240];
			DWORD br;
			std::ofstream ofs(file_to_update, std::ofstream::binary);
			while (InternetReadFile(hiu, buf, 10240, &br) && br > 0)
			{
				std::cout << br << std::endl;
				ofs.write(buf, br);
			}
			ofs.close();
			InternetCloseHandle(hiu);
		}
		InternetCloseHandle(hi);
	}
	return 0;
};

