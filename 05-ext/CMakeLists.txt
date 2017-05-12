cmake_minimum_required(VERSION 3.5)

project(main)

include(ExternalProject)
ExternalProject_Add(fooProject
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo1
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/ext
)

ExternalProject_Get_Property(fooProject install_dir)
ExternalProject_Get_Property(fooProject source_dir)
ExternalProject_Get_Property(fooProject binary_dir)
message("fooProject install_dir=${install_dir}")
message("fooProject source_dir=${source_dir}")
message("fooProject binary_dir=${binary_dir}")

ExternalProject_Add(helloProject
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/hello
  CMAKE_ARGS -DCMAKE_PREFIX_PATH=${binary_dir}
)
