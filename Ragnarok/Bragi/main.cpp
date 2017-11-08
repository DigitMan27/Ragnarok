#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{

	#ifdef _WIN32
		_setmode(_fileno(stdout), _O_U16TEXT);
	#endif
	std::vector<std::wstring> v;
	v = ListDir();
	for (std::vector<std::wstring>::const_iterator s = v.begin(); s != v.end(); s++)
	{
		std::wcout << *s << std::endl;
	}
	#ifdef _WIN32
		system("pause"); // recommended just to see the result (Windows Start without Debugging runs very fast)
	#endif
	return EXIT_SUCCESS;
}