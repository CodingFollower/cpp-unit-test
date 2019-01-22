set (CPP_TEST_SRC 
     cpp_unitest_def.hpp cpp_unitest.hpp cpp_unitest.cpp
     cpp_unitest_utils.hpp cpp_unitest_utils.cpp
     cpp_unitest_result.hpp cpp_unitest_result.cpp
     cpp_unitest_case.hpp cpp_unitest_case.cpp)
add_library(cpp_test_lib STATIC ${CPP_TEST_SRC})