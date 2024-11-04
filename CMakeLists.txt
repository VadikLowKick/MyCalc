cmake_minimum_required(VERSION 3.10)

project(MyCalc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(src)

add_library(Calculator src/calculator.cpp)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CalculatorTests tests/calculator_tests.cpp)
target_link_libraries(CalculatorTests Calculator GTest::GTest GTest::Main)

add_test(NAME CalculatorTests COMMAND CalculatorTests --gtest_output=xml:report.xml)
message("Report path: ${CMAKE_BINARY_DIR}/report.xml")