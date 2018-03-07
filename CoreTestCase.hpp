#pragma once
#include "CoreTest/CoreTestDefs.hpp"
#include "CoreTest/CoreTestResult.hpp"

namespace CoreTest {
	class TestCaseBase : public Nocopyable {
	public:
		virtual void RunTestCase(TestResult &) const = 0;
	};

	class TestCaseInfo : public Nocopyable {
	public:
		~TestCaseInfo() {
			delete testCase;
		}

		std::string casename;
		std::string testname;
		TestCaseBase *testCase;

		static TestCaseInfo *MakeTestInfo(const char *casename, const char *testname, 
			TestCaseBase *testCase);

		typedef std::list<TestCaseInfo *> TestCaseList;
		static TestCaseList & getAllTestCase();
	};
}

#define __CT_TEST_CASE_CLASS_NAME(casename, testname) casename##_##testname##_Test
#define __CT_VAR_TEST_RESULT __ct_test_result
#define __CT_VAR_TEST_FILE __ct_test_file
#define __CT_VAR_TEST_FILE_SIZE (MAX_PATH + 1)
#define __CT_VAR_TEST_LINE __ct_test_line
#define __CT_VAR_TEST_FAILED_INFO __ct_test_failed_info

#define __CT_TEST(case, test, casename, testname) \
class __CT_TEST_CASE_CLASS_NAME(case, test) : public CoreTest::TestCaseBase {\
public:\
	__CT_TEST_CASE_CLASS_NAME(case, test)() {}\
	\
	static CoreTest::TestCaseInfo *_testInfo; \
	\
	void __TestCaseBody(CoreTest::TestResult &result, char file[__CT_VAR_TEST_FILE_SIZE], int &line) const {\
		__try {\
			TestCaseBody(result, file, line);\
		}\
		__except(CoreTest::TestExceptionHandle(GetExceptionInformation(), result, file, line)) {\
		}\
	}\
	\
	void TestCaseBody(CoreTest::TestResult &__CT_VAR_TEST_RESULT, char __CT_VAR_TEST_FILE[__CT_VAR_TEST_FILE_SIZE], int &__CT_VAR_TEST_LINE) const;\
	\
	void RunTestCase(CoreTest::TestResult &result) const override {\
		char file[__CT_VAR_TEST_FILE_SIZE] = {0};\
		int line = 0;\
		__TestCaseBody(result, file, line);\
	}\
};\
\
CoreTest::TestCaseInfo *__CT_TEST_CASE_CLASS_NAME(case, test)::_testInfo = \
	CoreTest::TestCaseInfo::MakeTestInfo(casename, testname, new __CT_TEST_CASE_CLASS_NAME(case, test));\
\
void __CT_TEST_CASE_CLASS_NAME(case, test)::TestCaseBody(CoreTest::TestResult &__CT_VAR_TEST_RESULT, char __CT_VAR_TEST_FILE[__CT_VAR_TEST_FILE_SIZE], int &__CT_VAR_TEST_LINE) const

#define __CT_EXPECT_BODY_HEADER(file, line) \
	CoreTest::StringCopy(__CT_VAR_TEST_FILE, file, __CT_VAR_TEST_FILE_SIZE - 1);\
	__CT_VAR_TEST_LINE = line;\
	CoreTest::TestFailedInfo __CT_VAR_TEST_FAILED_INFO(__CT_VAR_TEST_FILE, __CT_VAR_TEST_LINE)\

#define __CT_TEST_FAILED __CT_VAR_TEST_RESULT.addFailed(__CT_VAR_TEST_FAILED_INFO)