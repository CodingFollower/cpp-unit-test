#pragma once
#include "CoreTest/CoreTestCase.hpp"
#include "CoreTest/CoreTestOutput.hpp"
#include "CoreTest/CoreTestUtils.hpp"

namespace CoreTest {
	void init();
	int run();
}

#define CT_TEST(case, test) __CT_TEST(case, test, #case, #test)

#define __CT_TEST_COND(cond) do {\
	strncpy(__ct_test_file, __FILE__, MAX_PATH);\
	__ct_test_line = __LINE__;\
	if (!(cond)) {\
		CoreTest::PrintMessageFormat(stderr, "FAILED AT %s:%d\r\n", __FILE__, __LINE__);\
		__ct_test_result = false;\
	}\
}while(0)

#define CT_EXPECT_EQ(actual, expect) __CT_TEST_COND((actual) == (expect))
#define CT_EXPECT_NE(actual, ne) __CT_TEST_COND((actual) != (ne))

#define CT_EXPECT_FLOAT_EQ(actual, expect) __CT_TEST_COND(CoreTest::FloatEqual((actual), (expect)))
#define CT_EXPECT_FLOAT_NE(actual, ne) __CT_TEST_COND(!CoreTest::FloatEqual((actual), (ne)))

#define CT_EXPECT_STRING_EQ(actual, expect) __CT_TEST_COND(CoreTest::StringEqual((actual), (expect)))
#define CT_EXPECT_STRING_NE(actual, ne) __CT_TEST_COND(!CoreTest::StringEqual((actual), (ne)))

#define CT_EXPECT_TRUE(cond) __CT_TEST_COND((cond))
#define CT_EXPECT_FALSE(cond) __CT_TEST_COND(!(cond))