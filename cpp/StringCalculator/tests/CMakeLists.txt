cmake_minimum_required(VERSION 3.5)

find_package(Threads REQUIRED)

#set(CMAKE_C_COMPILER "/usr/bin/x86_64-linux-gnu-gcc-7")
#set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-linux-gnu-g++-7")
#set (CMAKE_CXX_STANDARD 11)

project("CalculatorTest")

set(CMAKE_CXX_STANDARD 11)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

#message("CMAKE_COMMAND: ${CMAKE_COMMAND}")
#message("WORKING_DIRECTORY: ${CMAKE_BINARY_DIR}")
#message("CURRENT: ${CMAKE_CURRENT_BINARY_DIR}")

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                EXCLUDE_FROM_ALL)

add_executable(calculator-test calculator-test.cpp)

target_link_libraries(calculator-test libcalculator gtest_main)

#enable_testing()
add_test(NAME Calculator COMMAND calculator-test)