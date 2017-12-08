#pragma once
#include "CoreTest/CoreTestDefs.hpp"

namespace CoreTest {
	class Nocopyable {
	public:
		Nocopyable() {}
		virtual ~Nocopyable() {}

	protected:
		Nocopyable(const Nocopyable&);
		const Nocopyable &operator=(const Nocopyable &);
	};

	class TestCaseBase : public Nocopyable {
	public:
		virtual bool RunTestCase() const = 0;
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

#define __CT_TEST(case, test, casename, testname) \
class __CT_TEST_CASE_CLASS_NAME(case, test) : public CoreTest::TestCaseBase {\
public:\
	__CT_TEST_CASE_CLASS_NAME(case, test)() {}\
	\
	static CoreTest::TestCaseInfo *_testInfo; \
	\
	void TestCaseBody(bool &__ct_test_result, char *__ct_test_file, int &__ct_test_line);\
	\
	bool RunTestCase() const override {\
		char file[MAX_PATH + 1] = {0};\
		int line = 0;\
		bool ret = true;\
		__try {\
			TestCaseBody(ret, file, line);\
		}\
		__except(CoreTest::TestExceptionHandle(GetExceptionInformation(), file, line)) {\
			ret = false;\
		}\
		return ret;\
	}\
};\
\
CoreTest::TestCaseInfo *__CT_TEST_CASE_CLASS_NAME(case, test)::_testInfo = \
	CoreTest::MakeTestInfo(casename, testname, new __CT_TEST_CASE_CLASS_NAME(case, test));\
\
void __CT_TEST_CASE_CLASS_NAME(case, test)::TestCaseBody(bool &__ct_test_result, char *__ct_test_file, int &__ct_test_line)