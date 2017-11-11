#ifndef _BRAGI_
#define _BRAGI_

	#include <iostream>
	#include <errno.h>
	#include <vector>
	#include <stack>
	#include <string>
	#include <fcntl.h>
	#include <io.h>

	#ifdef __linux__

	/*++++++++++++++Comming Soon++++++++++++++*/
	/*Libs for Linux Platform*/

	#elif _WIN32

	/* Libs and prototype Functions for Windows Platform */

	#include <windows.h>
	#include <tchar.h>
	#include <Userenv.h>
	#include <shlobj.h>
	#include <wchar.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <Shlwapi.h>

	#pragma comment(lib, "Shlwapi.lib")
	#define LEN 64
	#define PATH 512
	#define WSTR 1024

	std::wstring Path();
	bool Dot(const wchar_t* str);
	std::vector<std::wstring> ListDir(std::wstring s);
	int Delete(std::wstring s);
	void cd(std::wstring s);


	#endif
#endif