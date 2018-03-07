#include "cpp_uintest_case.hpp"
#include "cpp_uintest_utils.hpp"

namespace CPPUnitest {
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