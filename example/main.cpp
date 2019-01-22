#include "cpp_unitest.hpp"
#include <vector>
using namespace std;

CT_TEST(example, success) {
	vector<int> vec;
	vec.push_back(10);

	CT_EXPECT_THROW(vec.at(1), out_of_range);
	CT_EXPECT_FALSE(vec.empty());

	int i = 10;
	CT_EXPECT_EQ(i, 10);
	CT_EXPECT_NE(i, 2);

	double f = 0.1;
	CT_EXPECT_FLOAT_EQ(f, 0.10);
	CT_EXPECT_FLOAT_NE(f, 0.01);

	char *cstr = "hello";
	std::string str = "hello";

	CT_EXPECT_CSTR_EQ(cstr, str.c_str());
	CT_EXPECT_STRING_EQ(str, "hello");
	CT_EXPECT_STRING_NE(str, "Hello");
}

CT_TEST(example, failed) {
	vector<int> vec;
	vec.push_back(10);

	CT_EXPECT_THROW(vec.at(0), out_of_range);
	CT_EXPECT_TRUE(vec.empty());

	int i = 10;
	CT_EXPECT_NE(i, 10);

	double f = 0.1;
	CT_EXPECT_FLOAT_NE(f, 0.10);

	char *cstr = "hello";
	std::string str = "hello";

	CT_EXPECT_STRING_NE(cstr, "hello");
	CT_EXPECT_STRING_NE(str, "hello");
	CT_EXPECT_STRING_NE(str, "Hello");
}

int main(int argc, char *argv[]) {
	cpp_unitest::init();
    return cpp_unitest::run();
}