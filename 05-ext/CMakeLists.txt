cmake_minimum_required(VERSION 3.5)

project(main)

include(ExternalProject)
ExternalProject_Add(fooProject
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo1
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/ext
)

ExternalProject_Get_Property(fooProject install_dir)
message("fooProject install_dir=${install_dir}")

ExternalProject_Add(helloProject
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/hello
  CMAKE_ARGS -DCMAKE_MODULE_PATH=${CMAKE_BINARY_DIR}/fooProject-prefix/src/fooProject-build
)
