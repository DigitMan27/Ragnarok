#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifdef __linux__

#include <unistd.h>

#elif _WIN32

#include <winsock2.h>
#include <iphlpapi.h>
#include <wlanapi.h>


// Link with Iphlpapi.lib
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(dll, "Shlwapi.dll")

#define INIT_BUFFER_SIZE 15000
#define MAX 3

typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

void windows_heimdall();

#endif