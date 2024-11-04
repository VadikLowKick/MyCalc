cmake_minimum_required(VERSION 3.10)
project(MyCalc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем библиотеку из исходных файлов калькулятора
add_library(calculator_lib src/calculator.cpp)

# Исполняемый файл для основного приложения
add_executable(MyCalc src/main.cpp)
target_link_libraries(MyCalc calculator_lib)

# Подключение тестов
add_subdirectory(tests)