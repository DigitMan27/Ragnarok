#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{
	std::vector<std::wstring> v;
	v = ListDir("dddd");
	for (std::vector<std::wstring>::const_iterator s = v.begin(); s != v.end(); s++)
	{
		std::wcout << *s << std::endl;
	}
	system("pause"); // recommended just to see the result (Windows Start without Debugging runs very fast)
    return EXIT_SUCCESS;
}
