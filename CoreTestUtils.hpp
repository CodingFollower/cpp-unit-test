#pragma once
#include "CoreTest/CoreTestDefs.hpp"
#include "CoreTest/CoreTestOutput.hpp"

namespace CoreTest {
	int TestExceptionHandle(EXCEPTION_POINTERS *except, const char *file, int line);

	bool FloatEqual(long double v1, long double v2);
	bool StringEqual(const std::string &v1, const std::string &v2);
}