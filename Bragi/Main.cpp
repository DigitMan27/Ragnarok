#include "Bragi.h"
#include <iostream>

int main()
{
#ifdef __linux__

#elif _WIN32
	windows_Bragi();
#endif
	return EXIT_SUCCESS;
}