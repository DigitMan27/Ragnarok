#pragma once

#include <stdlib.h>
#include <string.h>

#ifdef __linux__

#include <unistd.h>
void linux_skadi();

#elif _WIN32

#include <Windows.h>

typedef NTSTATUS(NTAPI *pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI *pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

void windows_skadi();

#endif
