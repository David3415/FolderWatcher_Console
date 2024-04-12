#pragma once
#include <iostream>
#include <fstream>
#include "Windows.h"
#include "Wininet.h"
#pragma comment(lib, "wininet.lib")
class GetLocalFileSizeClass
{
public:
	static unsigned long GetLocalFileSizeVoid(std::wstring file_to_update);
		char str[100];
		unsigned long FileSize;
		HANDLE hF;
		
};

