#include "CoreTest/CoreTestUtils.hpp"

namespace CoreTest {
	int TestExceptionHandle( EXCEPTION_POINTERS *except, const char *file, int line ) {
		PrintMessageFormat(stderr, "EXCEPTION<0x%x> AT <%s:%d>\r\n", except->ExceptionRecord->ExceptionCode, file, line);
		return EXCEPTION_EXECUTE_HANDLER;
	}

	bool FloatEqual(long double v1, long double v2) {
		return abs(v1 - v2) < 0.000001;
	}

	bool StringEqual(const std::string &v1, const std::string &v2) {
		return v1 == v2;
	}
}