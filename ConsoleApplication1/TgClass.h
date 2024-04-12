#pragma once
#pragma warning( disable : 4996 )
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <string>

class TgClass
{
public:
	static bool TgVoid();
	const std::string botToken;
	const std::string chatId;
	CURL* curl;
	CURLcode res;
};

