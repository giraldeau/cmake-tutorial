cmake_minimum_required(VERSION 3.5)
project(hello)

find_package(Foo CONFIG REQUIRED)

add_executable(hello hello.c)

target_link_libraries(hello foo1)

