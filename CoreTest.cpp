#include "CoreTest.hpp"

namespace CoreTest {
	static int RunAll(const TestCaseInfo::TestCaseList &tests) {
		bool __ct_test_result = true;
		WORD backup = 0;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			TestCaseInfo *info = *iter;
			if (info->testCase->RunTestCase()) {
				backup = SetSuccessColor();
				PrintMessageFormat(stderr, "%s.%s: PASSED\r\n", info->casename.c_str(), info->testname.c_str());
			}
			else {
				backup = SetErrorColor();
				PrintMessageFormat(stderr, "%s.%s: FAILED\r\n", info->casename.c_str(), info->testname.c_str());
			}
			SetTextColor(backup);
		}

		return 0;
	}

	void init() {
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	}

	int run() {
		TestCaseInfo::TestCaseList &tests = TestCaseInfo::getAllTestCase();
		int ret = RunAll(tests);
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			TestCaseInfo *info = *iter;
			delete info;
		}

		tests.clear();
		return ret;
	}
}