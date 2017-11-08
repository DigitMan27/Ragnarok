#include "Bragi.h"

#ifdef __linux__
	/*++++++++++++++Comming Soon++++++++++++++*/
	/* Code for Libs for Linux Platform */

#elif _WIN32
	/*++++++++++++++Comming Soon++++++++++++++*/
	
	/*Error on getUser function*/
	std::string getUser()
	{
		TCHAR username[LEN + 1];
		DWORD size = LEN + 1;
		GetUserName((TCHAR*)username, &size);
		std::string name = username;
		return name;
	}

	std::string Path()
	{
		std::string path = "C:\\Users\\" + getUser() + "\\Documents\\*";
		return path;
	}

	std::vector<std::string> ListDir(char* dir) // dir not used yet.
	{
		std::vector<std::string> contents;
		WIN32_FIND_DATA data;
		HANDLE hFind = FindFirstFile((LPCSTR)Path().c_str(), &data);      // DIRECTORY

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				//std::cout << data.cFileName << std::endl;
				std::string word(data.cFileName);
				contents.push_back(word);
			} while (FindNextFile(hFind, &data));
			FindClose(hFind);
		}
		return contents;
	}
#endif
