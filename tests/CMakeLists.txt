# Установка минимальной версии CMake для GoogleTest
cmake_minimum_required(VERSION 3.10)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)  # Отключаем автообновление

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Создание тестового исполняемого файла
add_executable(calculator_tests calculator_tests.cpp)
target_link_libraries(calculator_tests gtest_main calculator_lib)

add_test(NAME calculator_tests COMMAND calculator_tests --gtest_output=xml:report.xml)
include(GoogleTest)
gtest_discover_tests(calculator_tests)
