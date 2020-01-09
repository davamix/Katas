add_library(libcalculator STATIC calculator.cpp)

target_include_directories(libcalculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})