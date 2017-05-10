cmake_minimum_required(VERSION 3.5)
project(hello)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(foo)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(hello hello.c)

target_link_libraries(hello foo)

enable_testing()
add_test(NAME helloTest COMMAND $<TARGET_FILE:hello>)
