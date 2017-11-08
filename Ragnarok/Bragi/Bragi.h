#ifndef _BRAGI_
#define _BRAGI_

	#include <iostream>
	#include <errno.h>
	#include <vector>
	#include <string>

	#ifdef __linux__

	/*++++++++++++++Comming Soon++++++++++++++*/
	/*Libs for Linux Platform*/

	#elif _WIN32

	/* Libs and prototype Functions for Windows Platform */

	#include <windows.h>
	#include <tchar.h>
	//#include <direct.h>
	//#include <strsafe.h>

	/*#pragma comment(lib, "User32.lib")*/
	#define LEN 64
	#define PATH 128

	std::wstring getUser();
	std::wstring Path();
	std::vector<std::wstring> ListDir(wchar_t* dir);


	#endif
#endif