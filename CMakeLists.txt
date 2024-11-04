cmake_minimum_required(VERSION 3.10)

project(MyCalc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Опция для включения или отключения тестов
option(BUILD_TESTS "Build tests" ON)

# Создаем статическую библиотеку из calculator.cpp
add_library(calculator_lib STATIC src/calculator.cpp)

# Подключаем заголовочный файл к библиотеке
target_include_directories(calculator_lib PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Основной исполняемый файл, использующий библиотеку calculator_lib
add_executable(MyCalc src/main.cpp)
target_link_libraries(MyCalc PRIVATE calculator_lib)



if (BUILD_TESTS)
    enable_testing()

    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(CalculatorTests tests/calculator_tests.cpp)
    target_link_libraries(CalculatorTests calculator_lib GTest::GTest GTest::Main)

    add_test(NAME CalculatorTests COMMAND CalculatorTests --gtest_output=xml:report.xml)

    message("Report path: ${CMAKE_BINARY_DIR}/report.xml")
endif()