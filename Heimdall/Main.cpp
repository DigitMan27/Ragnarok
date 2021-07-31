#include "Heimdall.h"

int main()
{
#ifdef __linux__
	// soon TM
#elif _WIN32
	windows_heimdall();
#endif
	return EXIT_SUCCESS;
}