cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(autotools)
# TODO: move to a package file
include(ExternalProject)
ExternalProject_Add(xz
    GIT_REPOSITORY "http://git.tukaani.org/xz.git"
# GIT_SHALLOW supported only for git protocol and not http
#    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_SOURCE_DIR}/gettext.patch
    CONFIGURE_COMMAND <SOURCE_DIR>/configure
        --host=${TARGET_ARCH}
        --prefix=${CMAKE_BINARY_DIR}
        --disable-doc
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    LOG_DOWNLOAD 1 LOG_UPDATE 1 LOG_CONFIGURE 1 LOG_BUILD 1 LOG_INSTALL 1
)

autogen(xz)

ExternalProject_Get_Property(xz install_dir)
set(xz_install_dir ${install_dir})

ExternalProject_Add(foolib
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}
)
ExternalProject_Get_Property(foolib install_dir)
set(foolib_install_dir ${install_dir})
find_library(FOO1_LIBRARY foo1 PATHS ${foolib_install_dir})

project(deps)
add_executable(deps deps.c)
include_directories(${foolib_install_dir} ${xz_install_dir}/include)

# TODO: use find_library instead
add_library(lzma SHARED IMPORTED)
add_dependencies(lzma xz)
set_property(TARGET lzma PROPERTY IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/liblzma.so)

add_dependencies(deps foolib)
target_link_libraries(deps lzma ${FOO1_LIBRARY})
enable_testing()
add_test(depsTest deps)

