#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{
	FreeConsole();
	#ifdef _WIN32
		_setmode(_fileno(stdout), _O_U16TEXT);
	#endif
	std::vector<std::wstring> v;
	int i{};
	v = ListDir(Path());
	for (int i = 0; i < v.size(); i++)
	{
		cd(v[i]);
	}
	return EXIT_SUCCESS;
}