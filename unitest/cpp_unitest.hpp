#pragma once
#include "cpp_unitest_case.hpp"
#include "cpp_unitest_utils.hpp"

namespace cpp_unitest {
	void init();
	int run();
}

#define CT_TEST(case, test) __CT_TEST(case, test, #case, #test)

//#define __CT_PRINT_FAILED CoreTest::PrintMessageFormat(stderr, true, "FAILED AT %s:%d\r\n", __CT_VAR_TEST_FILE, __CT_VAR_TEST_LINE)

#define __CT_EXPECT_THROW(express, except, file, line) do {\
	__CT_EXPECT_BODY_HEADER(file, line);\
	try {\
		express;\
		__CT_VAR_TEST_FAILED_INFO.addDescription("Expect Throw Exception %s\r\n", #except);\
		__CT_TEST_FAILED;\
	}\
	catch(const except &) {\
	}\
	catch(...) {\
		__CT_VAR_TEST_FAILED_INFO.addDescription("Expect Throw Exception %s\r\n", #except);\
		__CT_TEST_FAILED;\
	}\
} while (0)
#define CT_EXPECT_THROW(express, except) __CT_EXPECT_THROW(express, except, __FILE__, __LINE__)

#define __CT_TEST_COND__(cond, file, line) do {\
	__CT_EXPECT_BODY_HEADER(file, line);\
	if (!(cond)) {\
		__CT_TEST_FAILED;\
	}\
}while(0)
#define __CT_TEST_COND(cond) __CT_TEST_COND__(cond, __FILE__, __LINE__)

//#define __CT_EXPECT_EQ(actual, expect, comp, file, line) do {\
//	__CT_EXPECT_BODY_HEADER(file, line);\
//	auto __ct_actual = (actual);\
//	auto __ct_expect = (expect);\
//	if (!cmp(__ct_actual, __ct_expect)) {\
//		CoreTest::PrintEqualFailedError(__ct_actual, __ct_expect, __CT_VAR_TEST_FILE, __CT_VAR_TEST_LINE);\
//		__CT_SET_TEST_RESULT(false);\
//	}\
//}while(0)

#define CT_EXPECT_EQ(actual, expect) __CT_TEST_COND((actual) == (expect))
#define CT_EXPECT_NE(actual, ne) __CT_TEST_COND((actual) != (ne))

#define CT_EXPECT_FLOAT_EQ(actual, expect) __CT_TEST_COND(cpp_unitest::FloatEqual((actual), (expect)))
#define CT_EXPECT_FLOAT_NE(actual, ne) __CT_TEST_COND(!cpp_unitest::FloatEqual((actual), (ne)))

#define CT_EXPECT_CSTR_EQ(actual, expect) __CT_TEST_COND(cpp_unitest::CStrEqual((actual), (expect)))

#define CT_EXPECT_STRING_EQ(actual, expect) __CT_TEST_COND(cpp_unitest::StringEqual((actual), (expect)))
#define CT_EXPECT_STRING_NE(actual, ne) __CT_TEST_COND(!cpp_unitest::StringEqual((actual), (ne)))

#define CT_EXPECT_TRUE(cond) __CT_TEST_COND((cond))
#define CT_EXPECT_FALSE(cond) __CT_TEST_COND(!(cond))