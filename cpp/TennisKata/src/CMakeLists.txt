file(GLOB SOURCE_FILES *.cpp *.h)

add_library(libtennis STATIC ${SOURCE_FILES})
set_target_properties(libtennis PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(libtennis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(tenniskata-bin ${SOURCE_FILES})