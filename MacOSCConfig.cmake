if(UNIX)
  SET(LINUX 1)
  SET(WINDOWS 0)
elseif(WIN32)
  SET(LINUX 0)
  SET(WINDOWS 1)
endif()

# OS specific before executable addition
if(WINDOWS)
  set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
endif(WINDOWS)

if(LINUX)
  set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
endif(LINUX)