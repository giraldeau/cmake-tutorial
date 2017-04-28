cmake_minimum_required(VERSION 3.5)

project(solver)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# HACK: force cache refresh by unsetting the variable
unset (MKL_LIBRARIES CACHE)
find_package(MKL REQUIRED)

add_executable(solver solver.cpp)
include_directories(${MKL_INCLUDES})
target_link_libraries(solver ${MKL_LIBRARIES})