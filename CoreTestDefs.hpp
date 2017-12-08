#pragma once

#ifdef _WIN32
#include <SDKDDKVer.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#endif

#include <list>
#include <iostream>
#include <cstdarg>
#include <string>