#include "Bragi.h"

#ifdef __linux__
	/*++++++++++++++Comming Soon++++++++++++++*/
	/* Code for Libs for Linux Platform */

#elif _WIN32
	/*++++++++++++++Comming Soon++++++++++++++*/
	
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
		std::wstring w = s  + L"\\*";
		WIN32_FIND_DATAW data;
		HANDLE hFind = FindFirstFileW((LPCWSTR)w.c_str(), &data);      // Starts to find the first file inside the directory

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				std::wstring word(data.cFileName);
				if (Dot(word.c_str())) continue;
				contents.push_back(s + L"\\" + word);
			} while (FindNextFileW(hFind, &data));
			FindClose(hFind);
		}
		/*
		else
		{
			std::wcout << "Error in the HANDLE\n";
		}*/
		return contents;
	}

	int Delete(std::wstring s)
	{
				if (_wremove(s.c_str()))
				{
					return 0;
				}
		return -1;
	}

	void cd(std::wstring s) //It will wroks with recursion.I have to split this func into two or more parts in order the recursion works.
	{
		std::vector<std::wstring> v{};
		int e{};
		v = ListDir(s);
		for (int i = 0; i < v.size(); i++)
		{
			e = Delete(v[i]);
		}
		for each(std::wstring i in v)
		{
			std::wcout << i << std::endl;
			cd(i);
		}
	}

	
#endif
