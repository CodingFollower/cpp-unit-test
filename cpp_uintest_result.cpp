#include "cpp_uintest_result.hpp"
#include "cpp_uintest_utils.hpp"

namespace CPPUnitest {
	void TestFailedInfo::addDescription(const char *fmt, ...){
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
			desciption.push_back(buf);
		}

		delete [] buf;
		va_end(args);
	}

	void TestResult::print() const {
		auto msg = message();
		auto backup = success() ? SetSuccessColor() : SetErrorColor();
		std::cout << message();
		SetTextColor(backup);
	}

	std::string TestResult::message() const {
		std::stringstream stream;
		stream << casename << "." << testname << ": ";
		if (success()) {
			stream << "PASSED" << std::endl;
			return stream.str();
		}

		stream << "FAILED" << std::endl;
		for (auto iter = faileds.begin(); iter != faileds.end(); ++iter) {
			stream << "\tFAILED AT " << iter->file << ":" << iter->line << std::endl;
			for (auto d = iter->desciption.begin(); d != iter->desciption.end(); ++d) {
				stream << "\t\t" << *d << std::endl;
			}
		}
		return stream.str();
	}

}