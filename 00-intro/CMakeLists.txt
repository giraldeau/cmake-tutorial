cmake_minimum_required(VERSION 3.5)
project(hello)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(foo1)
add_subdirectory(foo2)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(hello hello.c)

target_link_libraries(hello foo1 foo2)
install(TARGETS hello DESTINATION bin)


IF(UNIX)
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath='$ORIGIN'")
ENDIF()

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My funky project")
set(CPACK_PACKAGE_VENDOR "Me, myself, and I")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "3")
set(CPACK_PACKAGE_VERSION_PATCH "2")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
set(CPACK_PACKAGE_EXECUTABLES hello "hello")
set(CPACK_STRIP_FILES true)
include(CPack)
