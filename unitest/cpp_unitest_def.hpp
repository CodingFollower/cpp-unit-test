#pragma once

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS

#include <SDKDDKVer.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>
#include <tchar.h>

#ifdef _DEBUG
#define CPP_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)

#else
#define CPP_NEW new
#endif

#endif

#include <list>
#include <iostream>
#include <cstdarg>
#include <string>
#include <type_traits>
#include <sstream>

namespace cpp_unitest {
	class nocopyable {
	public:
		nocopyable() {}
		virtual ~nocopyable() {}

	protected:
		nocopyable(const nocopyable&);
		const nocopyable &operator=(const nocopyable &);
	};
}