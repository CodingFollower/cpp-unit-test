#include "cpp_uintest.hpp"

namespace CPPUnitest {
	static int RunAll(const TestCaseInfo::TestCaseList &tests) {
		bool __ct_test_result = true;
		for (auto iter = tests.begin(); iter != tests.end(); ++iter) {
			TestCaseInfo *info = *iter;

			TestResult result;
			result.casename = info->casename;
			result.testname = info->testname;

			info->testCase->RunTestCase(result);
			result.print();

			//if (result.success()) {
			//	PrintMessageFormat(stderr, true, "%s.%s: PASSED\r\n", info->casename.c_str(), info->testname.c_str());
			//}
			//else {
			//	PrintMessageFormat(stderr, false, "%s.%s: FAILED\r\n", info->casename.c_str(), info->testname.c_str());
			//}
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

		std::cout << "Run All Test Done, Press Enter To Quit!" << std::endl;
		char ch;
		std::cin.get(ch);

		return ret;
	}
}