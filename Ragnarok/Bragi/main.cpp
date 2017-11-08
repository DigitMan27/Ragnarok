#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{
	std::vector<std::string> v;
	v = ListDir("dddd");
	for (std::vector<std::string>::const_iterator s = v.begin(); s != v.end(); s++)
	{
		std::cout << *s << std::endl;
	}
	system("pause"); // recommended just to see the result (Windows Start without Debugging runs very fast)
    return EXIT_SUCCESS;
}
