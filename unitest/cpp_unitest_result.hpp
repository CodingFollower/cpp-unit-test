#pragma once
#include "cpp_unitest_def.hpp"

namespace cpp_unitest {
	class TestFailedInfo {
	public:
		TestFailedInfo(const std::string &file, size_t line) {
			this->file = file;
			this->line = line;
		}

		void addDescription(const char *fmt, ...);

		std::string file;
		size_t line;

		std::list<std::string> desciption;
	};

	class TestResult : public nocopyable {
	public:
		std::string testname;
		std::string casename;

		std::list<TestFailedInfo> faileds;

		void addFailed(TestFailedInfo f) {
			faileds.push_back(f);
		}

		bool success() const {
			return faileds.empty();
		}

		void print() const;

	private:
		std::string message() const;
	};
}