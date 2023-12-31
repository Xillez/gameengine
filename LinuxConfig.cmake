set(CMAKE_MODULE_PATH ${PROJECT_PATH})

# Add the path to your CMake modules if CMake can't find them.
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)

# Manually specify the paths to the ASSIMP headers and libraries
set(ASSIMP_INCLUDE_DIRS "/usr/include/")
set(ASSIMP_LIBRARIES "/usr/lib/x86_64-linux-gnu/libassimp.so")
find_package(ASSIMP REQUIRED)
find_library(UUID_LIBRARY NAMES uuid)
find_package(fmt REQUIRED)
find_package(SOIL REQUIRED)

set(LIBS_INCLUDE_DIRS
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
    ${UUID_LIBRARY}
    ${SOIL_INCLUDE_DIRS}
    ${OPENAL_INCLUDE_DIR}
)
set(LIBS_BINARIES
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLM_LIBRARIES}
    ${SDL2_LIBRARIES}
    assimp
    fmt::fmt
    ${UUID_LIBRARY}
    ${SOIL_LIBRARIES}
    ${OPENAL_LIBRARY}
)