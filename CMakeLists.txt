# Set cmake minimum
cmake_minimum_required(VERSION 3.10)

# Define project config directory
set(CMAKE_CONFIG_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Include utils file
include(${CMAKE_CONFIG_DIRECTORY}/Utils.cmake)

# Set project name
set(PROJECT_NAME $ENV{PROJECT_NAME})
set(VERSION $ENV{VERSION})
set(VERSION_NAME $ENV{VERSION_NAME})
set(ARCHITECTURE $ENV{ARCHITECTURE})

# "true" to build for debug or "false" to build for release.
set(DEBUG_BUILD "true")

# "true" to enable logging or "false" to disable.
set(LOGGING "true")

# Automatic setup of release and debug build setting
if(DEBUG_BUILD STREQUAL "true")
    set(CMAKE_BUILD_TYPE Debug)
                    set(CMAKE_BUILD_TYPE Debug)
                    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
else()
    set(CMAKE_BUILD_TYPE Release)
    set(LOGGING "false")
endif()

# Determine platform
if(UNIX AND NOT APPLE)
    message("Linux build")
    set(OS_NAME "LINUX")
elseif(WIN32)
    message("Windows build")
    set(OS_NAME "WIN32")
elseif(APPLE) # TODO: Implement eventually.
    message("MacOS build")
    message(FATAL_ERROR "TODO: Implement MacOS build.")
    set(OS_NAME "MACOS")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Set project name
project(${PROJECT_NAME} VERSION ${VERSION})

# Set the output to the bin folder
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OUTPUT_PATH ${PROJECT_PATH}/build)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATH}/bin)
set(SOURCE_DIR ${PROJECT_PATH}/source)

# Set cmake options + custom compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_GENERATOR_PLATFORM ${ARCHITECTURE})

# Pass CMake settings to source header
configure_file(
    "${SOURCE_DIR}/config/Config.hpp.in"
    "${SOURCE_DIR}/config/Config.hpp"
    @ONLY
)

# ---------------------------- Source file inclusion ---------------------------

set(SOURCE_EXTENSIONS ".c" ".cpp") # Define a list of extensions of source files
set(SOURCE_SEARCH_DIRS ${SOURCE_DIR}) # Define a list of root directories to search
set(SOURCE_FILES) # Define a list to store source files
find_files_in_directories("${SOURCE_EXTENSIONS}" "${SOURCE_SEARCH_DIRS}" SOURCE_FILES)
print_list("Source files" "${SOURCE_FILES}")

# ---------------------------- Header file inclusion ---------------------------

set(HEADER_EXTENSIONS ".h" ".hpp") # Define a list of extensions of header files
set(HEADER_SEARCH_DIRS ${SOURCE_DIR}) # Define a list of root directories to search
set(HEADER_FILES) # Define a list to store header files
find_files_in_directories("${HEADER_EXTENSIONS}" "${HEADER_SEARCH_DIRS}" HEADER_FILES)

set(HEADER_DIRS) # Define a list to store header directories
get_header_directories("${HEADER_FILES}" HEADER_DIRS)
print_list("Header directories" "${HEADER_DIRS}")
print_list("Header files" "${HEADER_FILES}")

# ----------------------------------- IMGUI ------------------------------------
# Specify where the header files are
set(IMGUI_DIR ${PROJECT_PATH}/imgui)
set(IMGUI_INCLUDE_DIRS ${IMGUI_DIR} ${IMGUI_DIR}/backends)

set(HEADER_EXTENSIONS ".h" ".hpp") # Define a list of extensions of header files
set(IMGUI_HEADER_FILES) # Define a list to store source files
find_files_in_directories("${HEADER_EXTENSIONS}" "${IMGUI_INCLUDE_DIRS}" IMGUI_HEADER_FILES TRUE)
print_list("IMGUI Header files" "${IMGUI_HEADER_FILES}")

set(SOURCE_EXTENSIONS ".c" ".cpp") # Define a list of extensions of source files
set(IMGUI_SOURCE_FILES) # Define a list to store source files
find_files_in_directories("${SOURCE_EXTENSIONS}" "${IMGUI_DIR}" IMGUI_SOURCE_FILES TRUE)
list(APPEND IMGUI_SOURCE_FILES
    "${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp"
)
print_list("IMGUI Source files" "${IMGUI_SOURCE_FILES}")
# ------------------------------------ IMGUI -----------------------------------

include_directories(${HEADER_DIRS} ${IMGUI_INCLUDE_DIRS})

# Give files for building application
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${IMGUI_SOURCE_FILES} ${SOURCE_DIR}/main.cpp)
# Set the project to be a WIN32 executable
if(OS_NAME STREQUAL "WIN32")
    #set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Determine platform, find library includes and binary directories
if(OS_NAME STREQUAL "LINUX")
    include(${CMAKE_CONFIG_DIRECTORY}/linux/Dependencies.cmake)
elseif(OS_NAME STREQUAL "WIN32")
    include(${CMAKE_CONFIG_DIRECTORY}/windows/Dependencies.cmake)
elseif(OS_NAME STREQUAL "MACOS") # TODO: Implement eventually.
    message(FATAL_ERROR "TODO: Implement MacOS build.")
    include(${CMAKE_CONFIG_DIRECTORY}/macos/Dependencies.cmake)
endif()

# Include doxygen lists file
#include(${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLists.txt)
#
#execDoxygen()

# File copy example
# file(COPY ${SOURCE_DIR}/libs/dll/glew32.dll DESTINATION ${PROJECT_BINARY_DIR})