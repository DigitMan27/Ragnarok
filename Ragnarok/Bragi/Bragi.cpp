#include "Bragi.h"

#ifdef __linux__
	/*++++++++++++++Comming Soon++++++++++++++*/
	/* Code for Libs for Linux Platform */

#elif _WIN32
	/*++++++++++++++Comming Soon++++++++++++++*/
	
	/*Error on getUser function*/
	/*
	std::wstring getUser()
	{
		WCHAR username[LEN + 1];
		DWORD size = LEN + 1;
		GetUserNameW((LPWSTR)username, &size);
		std::wstring name = username;
		return name;
	}
	*/

	/*
	std::wstring Path()
	{
		std::wstring path = L"C:\\Users\\" + getUser() + L"\\Documents\\*";
		return path;
	}
	*/


	/*This Function finds the User path*/
	std::wstring Path()
	{
		wchar_t path[WSTR];
		std::wstring wpath;
		if (SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, path) == S_OK)
		{
			wpath = path;
		}

		return wpath;
	}

	std::vector<std::wstring> ListDir()
	{
		std::vector<std::wstring> contents;
		std::wstring s = Path() + L"\\*";
		WIN32_FIND_DATAW data;
		HANDLE hFind = FindFirstFileW((LPCWSTR)s.c_str(), &data);      // Starts to find the first file inside the directory

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				std::wstring word(data.cFileName);
				contents.push_back(word);
			} while (FindNextFileW(hFind, &data));
			FindClose(hFind);
		}
		else
		{
			std::wcout << "Error in the HANDLE\n";
		}
		return contents;
	}
#endif
