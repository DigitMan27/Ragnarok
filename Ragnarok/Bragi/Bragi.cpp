#include "Bragi.h"

#ifdef __linux__
	/*++++++++++++++Comming Soon++++++++++++++*/
	/* Code for Libs for Linux Platform */

#elif _WIN32
	/*++++++++++++++Comming Soon++++++++++++++*/
	
	/*Error on getUser function*/
	std::wstring getUser()
	{
		WCHAR username[LEN + 1];
		DWORD size = LEN + 1;
		GetUserNameW((LPWSTR)username, &size);
		std::wstring name = username;
		return name;
	}

	std::wstring Path()
	{
		std::wstring path = L"C:\\Users\\" + getUser() + L"\\Documents\\*";
		return path;
	}

	std::vector<std::wstring> ListDir(char* dir) // dir not used yet.
	{
		std::vector<std::wstring> contents;
		WIN32_FIND_DATAW data;
		HANDLE hFind = FindFirstFileW((LPCWSTR)Path().c_str(), &data);      // DIRECTORY

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				//std::cout << data.cFileName << std::endl;
				std::wstring word(data.cFileName);
				contents.push_back(word);
			} while (FindNextFileW(hFind, &data));
			FindClose(hFind);
		}
		return contents;
	}
#endif
