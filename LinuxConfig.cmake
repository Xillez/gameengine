set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

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