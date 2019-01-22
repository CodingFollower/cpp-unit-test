#include "cpp_unitest_case.hpp"
#include "cpp_unitest_utils.hpp"

namespace cpp_unitest {
	//static volatile LONG _once_flage = 0;
	static TestCaseInfo::TestCaseList *_allTests = nullptr;

	TestCaseInfo *TestCaseInfo::MakeTestInfo(const char *casename, const char *testname, TestCaseBase *testCase) {
		TestCaseInfo *info = new TestCaseInfo();
		info->casename = casename;
		info->testname = testname;
		info->testCase = testCase;

		if (_allTests == nullptr) {
			_allTests = new TestCaseList();
		}

		_allTests->push_back(info);
		return info;
	}

	TestCaseInfo::TestCaseList & TestCaseInfo::getAllTestCase() {
		return *_allTests;
	}

	void TestCaseInfo::clearTests() {
		if (_allTests != nullptr) {
			for (auto iter = _allTests->begin(); iter != _allTests->end(); ++iter)
			{
				TestCaseInfo *testCase = *iter;
				delete testCase;
			}

			delete _allTests;
			_allTests = nullptr;
		}
	}

}