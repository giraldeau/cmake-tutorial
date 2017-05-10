set(NS_MKL_PREFIX intel/compilers_and_libraries/linux/mkl)
if(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  set(NS_MKL_PATH lib/intel64)
  set(NS_MKL_NAME mkl_intel_lp64)
else(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  set(NS_MKL_PATH lib/ia32)
  set(NS_MKL_NAME mkl_intel)
endif()

find_library(MKL_LIBRARIES mkl_rt
    PATHS
    $ENV{MKLROOT}/${NS_MKL_PATH}
    $ENV{HOME}/${NS_MKL_PREFIX}/${NS_MKL_PATH}
    /opt/${NS_MKL_PREFIX}/${NS_MKL_PATH}
)

find_path(MKL_INCLUDES mkl.h
    PATHS
    $ENV{MKLROOT}/${NS_MKL_PATH}/include
    $ENV{HOME}/${NS_MKL_PREFIX}/include
    /opt/${NS_MKL_PREFIX}/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MKL DEFAULT_MSG MKL_LIBRARIES)
