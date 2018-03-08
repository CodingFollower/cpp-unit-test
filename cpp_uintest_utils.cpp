#include "cpp_uintest_utils.hpp"
#include "cpp_uintest_result.hpp"

namespace CPPUnitest {
	int TestExceptionHandle(EXCEPTION_POINTERS *except, TestResult &result, const char *file, int line) {
		//PrintMessageFormat(stderr, true, "EXCEPTION<0x%x> AT <%s:%d>\r\n", except->ExceptionRecord->ExceptionCode, file, line);
		CPPUnitest::TestFailedInfo fail(file, line);
		fail.addDescription("Unexpect Exception<0x%x> Catched!", except->ExceptionRecord->ExceptionCode);
		result.addFailed(fail);
		return EXCEPTION_EXECUTE_HANDLER;
	}

	bool FloatEqual(long double v1, long double v2) {
		return abs(v1 - v2) < 0.000001;
	}

	bool StringEqual(const std::string &v1, const std::string &v2) {
		return v1 == v2;
	}

	bool CStrEqual(const char *p1, const char *p2) {
		if (p1 == p2) {
			return true;
		}

		if (p1 == nullptr || p2 == nullptr) {
			return false;
		}

		return StringEqual(p1, p2);
	}

	void PrintMessageFormat(FILE *target, bool err, const char *fmt, ...) {
		if (!fmt || !fmt[0]) {
			return;
		}

		va_list args;
		va_start(args, fmt);
		int len = _vscprintf(fmt, args);
		if(len <= 0) {
			va_end(args);
			return;
		}

		char *buf = new char[len + 1];
		if ((len = vsprintf(buf, fmt, args)) > 0) {
			buf[len] = 0;
			auto backup = err ? SetErrorColor() : SetSuccessColor();
			PrintMessage(target, buf);
			SetTextColor(backup);
		}

		delete [] buf;
		va_end(args);
	}

	void PrintMessage(FILE *target, const char *msg) {
		if (!msg || !msg[0]) {
			return;
		}

		fprintf(target, msg);
#ifdef _WIN32
		OutputDebugStringA(msg);
#endif
	}

	WORD SetTextColor(WORD color) {
		HANDLE handle = GetStdHandle(STD_ERROR_HANDLE);
		if (handle == INVALID_HANDLE_VALUE) {
			return 0;
		}

		CONSOLE_SCREEN_BUFFER_INFO info;
		if (!GetConsoleScreenBufferInfo(handle, &info)) {
			return 0;
		}

		SetConsoleTextAttribute(handle, color);
		return info.wAttributes;
	}

	WORD SetErrorColor() {
		return SetTextColor(FOREGROUND_RED);
	}

	WORD SetSuccessColor() {
		return SetTextColor(FOREGROUND_GREEN);
	}

	char *StringCopy(char *dest, const char *src, size_t count) {
		return strncpy(dest, src, count);
	}
}