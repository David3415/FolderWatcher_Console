#pragma once
class ReplaceLocalFileWithFileFromUrlClass
{
public:
	static int ReplaceLocalFileWithFileFromUrlVoid(std::wstring fileFromUrl, std::wstring file_to_update);
	HINTERNET hi;

	HINTERNET hiu;

	std::ofstream ofs;
};

