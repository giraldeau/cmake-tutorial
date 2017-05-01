cmake_minimum_required(VERSION 2.8.11)

# Specify the Qt library on the command line:
# Linux: cmake -DCMAKE_PREFIX_PATH=/qt/qt-5.7.0/ ..
# Windows: cmake -DCMAKE_PREFIX_PATH=C:\Qt\Qt5.8\5.8\msvc2015_64 ..
# Compile: cmake --build

project(foo)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tell CMake to create the helloworld executable
add_executable(foo WIN32 main.cpp mainwindow.cpp)

# Use the Widgets module from Qt 5.
target_link_libraries(foo Qt5::Widgets)
