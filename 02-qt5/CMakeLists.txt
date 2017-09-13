cmake_minimum_required(VERSION 2.8.11)

# Specify the Qt library on the command line:
# Linux: cmake -DCMAKE_PREFIX_PATH=/qt/qt-5.7.0/ ..
# Windows: cmake -DCMAKE_PREFIX_PATH=C:\Qt\Qt5.8\5.8\msvc2015_64 ..
# Compile: cmake --build

project(fooProject)

find_package(Qt5 COMPONENTS Widgets)

# Enable C++11
set (CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# have more info on the target properties
#set(CMAKE_DEBUG_TARGET_PROPERTIES
#  INCLUDE_DIRECTORIES
#  COMPILE_DEFINITIONS
#  POSITION_INDEPENDENT_CODE
#  CONTAINER_SIZE_REQUIRED
#  LIB_VERSION
#)


# Find the QtWidgets library
add_subdirectory(form)

# Tell CMake to create the helloworld executable
add_executable(foo main.cpp dummyclass.cpp mainwindow.cpp resources.qrc)
target_link_libraries(foo form)

# Use the Widgets module from Qt 5.
target_link_libraries(foo Qt5::Widgets)
install(TARGETS foo DESTINATION bin)

include(BundleUtilities)

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My funky project")
set(CPACK_PACKAGE_VENDOR "Me, myself, and I")
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 2)
set(CPACK_PACKAGE_VERSION_PATCH 3)
set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}-${CPACK_PACKAGE_VERSION_LABEL})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "foo ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
set(CPACK_PACKAGE_EXECUTABLES foo "foo")
set(CPACK_STRIP_FILES true)
include(CPack)
