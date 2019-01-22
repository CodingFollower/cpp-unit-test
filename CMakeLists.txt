cmake_minimum_required (VERSION 2.8)
project (cpp_test)

set(UNITEST_SRC_DIR unitest)
include_directories(${UNITEST_SRC_DIR})
add_subdirectory(${UNITEST_SRC_DIR})

add_subdirectory(example)