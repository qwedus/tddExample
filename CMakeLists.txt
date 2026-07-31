cmake_minimum_required(VERSION 3.16)
project(tddExample LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_COVERAGE "Enable gcov coverage instrumentation" ON)

if(ENABLE_COVERAGE)
  if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O0 -g --coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
  endif()
endif()

enable_testing()

add_library(tdd_example STATIC
  src/example.cpp
)
target_include_directories(tdd_example PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(c_example STATIC
  src/c_example.c
)
target_include_directories(c_example PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(tdd_example_app src/main.cpp)
target_link_libraries(tdd_example_app PRIVATE tdd_example)

if(EXISTS "/usr/src/googletest")
  add_subdirectory("/usr/src/googletest" "${CMAKE_BINARY_DIR}/googletest")
  add_executable(tdd_example_tests tests/test_example.cpp tests/test_c_example.cpp)
  target_link_libraries(tdd_example_tests PRIVATE gtest_main tdd_example c_example)
  add_test(NAME tdd_example_tests COMMAND tdd_example_tests)
else()
  find_package(GTest REQUIRED)
  add_executable(tdd_example_tests tests/test_example.cpp tests/test_c_example.cpp)
  target_link_libraries(tdd_example_tests PRIVATE GTest::gtest_main tdd_example c_example)
  add_test(NAME tdd_example_tests COMMAND tdd_example_tests)
endif()
