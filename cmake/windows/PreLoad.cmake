# Add vcpkg toolchain file
#message(STATUS "Using vcpkg toolchain file: $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
#set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}\\scripts\\buildsystems\\vcpkg.cmake)

set(CMAKE_C_COMPILER " C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER " C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)