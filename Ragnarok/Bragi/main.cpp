#include "Bragi.h"
#include <iostream>

/*Comments will be posted later*/

int main()
{

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
	#ifdef _WIN32
		system("pause"); // recommended just to see the result (Windows Start without Debugging runs very fast)
	#endif
	return EXIT_SUCCESS;
}