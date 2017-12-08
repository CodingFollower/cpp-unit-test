#include "CoreTest/CoreTestCase.hpp"

namespace CoreTest {
	static std::list<TestCaseInfo *> _allTests;

	TestCaseInfo * TestCaseInfo::MakeTestInfo(const char *casename, const char *testname, TestCaseBase *testCase) {
		auto info = new TestCaseInfo();
		info->casename = casename;
		info->testname = testname;
		info->testCase = testCase;

		_allTests.push_back(info);
		return info;
	}

	TestCaseInfo::TestCaseList & TestCaseInfo::getAllTestCase() {
		return _allTests;
	}
}