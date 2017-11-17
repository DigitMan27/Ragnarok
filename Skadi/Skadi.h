#pragma once

#include <stdlib.h>
#include <string.h>

#ifdef __linux__

#include <unistd.h>
void linux_skadi();

#elif _WIN32

#include <Windows.h>
void windows_skadi();

#endif
