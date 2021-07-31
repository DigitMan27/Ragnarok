#include "Heimdall.h"


void windows_heimdall() {
	DWORD dwSize = 0;
	DWORD dwReturnValue = 0;

	unsigned int index = 0;

	/*flags*/
	ULONG flags = 0x0010;

	ULONG family = AF_UNSPEC;

	LPVOID lpMsgBuff = NULL;
	PIP_ADAPTER_ADDRESSES pAddresses = NULL;
	ULONG out_buffer_len = 0;
	ULONG iter = 0;

	PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
	PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
	PIP_ADAPTER_ANYCAST_ADDRESS pAnycast = NULL;
	PIP_ADAPTER_MULTICAST_ADDRESS pMulticast = NULL;
	IP_ADAPTER_DNS_SERVER_ADDRESS* pDnServer = NULL;
	IP_ADAPTER_PREFIX* pPrefix = NULL;

	out_buffer_len = INIT_BUFFER_SIZE;

	while ((dwReturnValue == ERROR_BUFFER_OVERFLOW) or (iter < MAX)) {
		pAddresses = (IP_ADAPTER_ADDRESSES*)malloc(out_buffer_len);
		dwReturnValue = GetAdaptersAddresses(family, flags, NULL, pAddresses, &out_buffer_len);
		if (dwReturnValue == ERROR_BUFFER_OVERFLOW) {
			free(pAddresses);
			pAddresses = NULL;
		}
		else {
			break;
		}

		iter++;
	}
	PIP_ADAPTER_ADDRESSES active = NULL;
	if (dwReturnValue == NO_ERROR) {
		pCurrAddresses = pAddresses;
		while (pCurrAddresses) {
			if (((pCurrAddresses->IfType == IF_TYPE_ETHERNET_CSMACD) or (pCurrAddresses->IfType == IF_TYPE_IEEE80211)) and (pCurrAddresses->IfType!= IF_TYPE_SOFTWARE_LOOPBACK) and ((pCurrAddresses->OperStatus==IfOperStatusUp) and (wcslen(pCurrAddresses->DnsSuffix)>0))) {
				//printf("Adapter Name: %s\n", pCurrAddresses->DnsSuffix);
				std::cout << "Adapter name:"<< pCurrAddresses->AdapterName << std::endl;
				std::wcout << "Adapter desc:" << pCurrAddresses->DnsSuffix << std::endl;
				active = pCurrAddresses;
			}
			pCurrAddresses = pCurrAddresses->Next;
		}

		DWORD clientVer = 2;
		PDWORD negotiatedVer = &clientVer;
		PHANDLE handle;
		DWORD session = WlanOpenHandle(clientVer,NULL,negotiatedVer,handle);
		if (session == ERROR_SUCCESS) {
			LPCOLESTR GG = active->AdapterName;
			const GUID guid;
			BOOL d = IIDFromString()
		}
	}
}


