#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{
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
