#include "Bragi.h"

#ifdef __linux__
	/*++++++++++++++Comming Soon++++++++++++++*/
	/* Code for Libs for Linux Platform */

#elif _WIN32
	/*++++++++++++++Comming Soon++++++++++++++*/
	
	/*Error on getUser function*/
	const char* getUser()
	{
		TCHAR username[LEN + 1];
		DWORD size = LEN + 1;
		GetUserName((TCHAR*)username, &size);
		char buff[PATH];
		snprintf(buff, sizeof(buff), "%s", username);
		const char* name = buff;
		return name;
	}

	const char* Path()
	{
		const char* user = getUser();
		char buff1[PATH];
		snprintf(buff1, sizeof(buff1), "C:\\Users\\%s\\Documents\\*", user); /*A fixed path just for testing*/
		const char* path = buff1;
		return path;
	}

	std::vector<std::string> ListDir(char* dir) // dir not used yet.
	{
		std::vector<std::string> contents;
		const char* path = Path();
		WIN32_FIND_DATA data;
		HANDLE hFind = FindFirstFile("C:\\Users\\Hive\\Documents\\*", &data);      // DIRECTORY

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
