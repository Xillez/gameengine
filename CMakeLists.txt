# Set cmake minimum
cmake_minimum_required(VERSION 3.10)

# Set project name
set(PROJECT_NAME "SkyForgeEngine")
set(VERSION "v0.1")
set(VERSION_NAME "Sponge")

# "true" to build for debug or "false" to build for release.
set(DEBUG_BUILD "true")

# "true" to enable logging or "false" to disable.
set(LOGGING "true")

# Automatic setup of release and debug build setting
if(DEBUG_BUILD STREQUAL "true")
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
    set(LOGGING "false")
endif()

# Set project name
project(${PROJECT_NAME})

# Set cmake options + custom compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output to the bin folder
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OUTPUT_PATH ${PROJECT_PATH}/build)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATH}/bin)
set(SOURCE_DIR ${PROJECT_PATH}/source)

set(LIBS_INCLUDE_DIRS)
set(LIBS_BINARIES)

# Determine platform, set generator, find library includes and binary directories
if(APPLE)
    message("MacOS build")
    include(${PROJECT_PATH}/MacOSConfig.cmake)
    set(OS_NAME "MACOS")
elseif(UNIX AND NOT APPLE)
    message("Linux build")
    set(OS_NAME "LINUX")
    include(${PROJECT_PATH}/LinuxConfig.cmake)
elseif(WIN32)
    message("Windows build")
    set(OS_NAME "WIN32")
    include(${PROJECT_PATH}/WindowsConfig.cmake)
endif()

# ----------------------------------- IMGUI ------------------------------------
# Add the ImGui library
set(IMGUI_DIR ${PROJECT_PATH}/imgui)
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp ${IMGUI_DIR}/*.h)
add_library(imgui ${IMGUI_SOURCES})
# Assuming you're using OpenGL3 and glfw3 for imgui's backends
add_library(imgui-sdl2-opengl3 
    ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp 
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Folders to include
include_directories(
    ${LIBS_INCLUDE_DIRS}
    imgui PUBLIC ${IMGUI_DIR}
    imgui-sdl2-opengl3 PUBLIC ${IMGUI_DIR}/backends 
)

# Pass CMake settings to source header
configure_file(
    "${SOURCE_DIR}/config/Config.hpp.in"
    "${SOURCE_DIR}/config/Config.hpp"
    @ONLY
)

# -- -- -- -- -- -- -- -- -- -- -- -- -- -- Source file inclusion -- -- -- -- -- -- -- -- -- -- -- -- -- -
# Define a list of extensions of header files
set(SOURCE_EXTENSIONS ".c" ".cpp")

# Define a list of root directories to search
set(SOURCE_SEARCH_DIRS ${SOURCE_DIR})

# Use a loop to search for header files in each directory with each extension
foreach(SOURCE_SEARCH_DIR ${SOURCE_SEARCH_DIRS})
    foreach(SOURCE_EXTENSION ${SOURCE_EXTENSIONS})
        file(GLOB_RECURSE SOURCEFILES_TEMP "${SOURCE_SEARCH_DIR}/**/*${SOURCE_EXTENSION}")
        list(APPEND SOURCE_FILES ${SOURCEFILES_TEMP})
    endforeach()
endforeach()

# Remove duplicates from the list of directories
list(REMOVE_DUPLICATES SOURCE_FILES)

# Print the list of directories
message("Source files:")

foreach(SOURCE_FILE ${SOURCE_FILES})
    message("- ${SOURCE_FILE}")
endforeach()

# Give files for building application
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SOURCE_DIR}/main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    ${LIBS_BINARIES}
    imgui-sdl2-opengl3
    imgui
)

# Include doxygen lists file
include(${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLists.txt)

execDoxygen()

# File copy example
# file(COPY ${SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})
