#pragma once
#include "cpp_unitest_def.hpp"

namespace cpp_unitest {
	class TestResult;
	int TestExceptionHandle(EXCEPTION_POINTERS *except, TestResult &result, const char *file, int line);

	template<class TActual, class TExpect>
	bool NormalEqual(const TActual &actual, const TExpect &excpect) {
		return actual == excpect;
	}

	bool FloatEqual(long double v1, long double v2);
	bool StringEqual(const std::string &v1, const std::string &v2);
	bool CStrEqual(const char *p1, const char *p2);

	WORD SetTextColor(WORD color);

	WORD SetErrorColor();
	WORD SetSuccessColor();

	void PrintMessage(FILE *target, const char *msg);
	void PrintMessageFormat(FILE *target, bool err, const char *fmt, ...);

	char *StringCopy(char *dest, const char *src, size_t count);

	template<class T>
	bool IsStringStreamSupportType(const T &v) {
		if (v == nullptr) {
			return true;
		}

		if (std::is_integral<T>::value) {
			return true;
		}

		if (std::is_floating_point<T>::value) {
			return true;
		}

		return false;
	}

	template<class TActual, class TExpect>
	std::string __FormatEqualFailedError(const TActual &actual, const TExpect &excpect) {
		return "";
	}

	template<class TActual, class TExpect>
	void PrintEqualFailedError(const TActual &actual, const TExpect &excpect, const std::string &file, size_t line) {
		std::stringstream stream;
		stream << "FAILED AT " << file << ":" << line;

		auto backup = SetErrorColor();

		auto errmsg = __FormatEqualFailedError(actual, excpect);
		if (!errmsg.empty()) {
			stream << ", " << errmsg;
		}
		stream << ".";
		std::cerr << stream.str() << std::endl;

		SetTextColor(backup);
	}
}