#pragma once
#include "CoreTest/CoreTestDefs.hpp"

namespace CoreTest {
	void PrintMessage(FILE *target, const char *msg);
	void PrintMessageFormat(FILE *target, const char *fmt, ...);

	WORD SetTextColor(WORD color);

	WORD SetErrorColor();
	WORD SetSuccessColor();
}