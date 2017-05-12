cmake_minimum_required(VERSION 3.5)

project(foo)
include(GNUInstallDirs)

add_library(foo1 SHARED foo1.c)
target_compile_definitions(foo1 PRIVATE FOO1_LIBRARY)

target_include_directories(foo1 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE src
)

install(TARGETS foo1 EXPORT fooExport
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT fooExport DESTINATION share/foo/cmake)

export(EXPORT fooExport FILE FooConfig.cmake)
export(PACKAGE fooExport)
