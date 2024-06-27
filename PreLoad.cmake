# Set policy CMP0054 to NEW
if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

# Determine Platform
if(UNIX AND NOT APPLE)
    set(OS_NAME "LINUX")
elseif(WIN32)
    set(OS_NAME "WIN32")
elseif(APPLE)
    set(OS_NAME "MACOS")
endif()

# Define project config directory
set(CMAKE_CONFIG_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# OS specific before executable addition
if(OS_NAME STREQUAL LINUX)
  include(${CMAKE_CONFIG_DIRECTORY}/linux/PreLoad.cmake)
endif()

if(OS_NAME STREQUAL WIN32)
  include(${CMAKE_CONFIG_DIRECTORY}/windows/PreLoad.cmake)
endif()

if(OS_NAME STREQUAL MACOS)
  include(${CMAKE_CONFIG_DIRECTORY}/macos/PreLoad.cmake)
endif()