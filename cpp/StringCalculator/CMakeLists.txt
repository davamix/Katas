cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER "/usr/bin/x86_64-linux-gnu-gcc-7")
set(CMAKE_CXX_COMPILER "/usr/bin/x86_64-linux-gnu-g++-7")
set (CMAKE_CXX_STANDARD 11)

project("String Calculator")

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

