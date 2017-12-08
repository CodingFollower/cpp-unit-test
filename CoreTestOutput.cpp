#include "CoreTest/CoreTestOutput.hpp"

namespace CoreTest {
	void PrintMessage(FILE *target, const char *msg) {
		if (!msg || !msg[0]) {
			return;
		}

		fprintf(target, msg);
#ifdef _WIN32
		OutputDebugStringA(msg);
#endif
	}

	void PrintMessageFormat(FILE *target, const char *fmt, ...) {
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
			PrintMessage(target, buf);
		}

		delete [] buf;
		va_end(args);
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
}