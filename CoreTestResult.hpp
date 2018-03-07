#pragma once
#include "CoreTest/CoreTestDefs.hpp"

namespace CoreTest {
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

	class TestResult : public Nocopyable {
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