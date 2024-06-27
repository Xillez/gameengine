# Build up a list of sources and libraries to link with
set(OpenGL_GL_PREFERENCE "LEGACY")
find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
endif()

find_package(GLEW REQUIRED)
# Use GLEW::GLEW
if(GLEW_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)
endif()

find_package(glm CONFIG REQUIRED)
# Use glm::glm
if(GLM_FOUND)
    list(APPEND LINK_LIBRARIES ${GLM_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
endif()

find_package(SDL2 CONFIG REQUIRED)
# Use
# target_link_libraries(main
#     PRIVATE
#     $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
#     $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
# )
if(SDL2_FOUND)
    list(APPEND LINK_LIBRARIES ${SDL2_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

find_package(assimp CONFIG REQUIRED)
# Use assimp::assimp
get_target_property(assimp_INCLUDE_DIRS assimp::assimp INTERFACE_INCLUDE_DIRECTORIES)
message("assimp Include Directories: ${assimp_INCLUDE_DIRS}")
get_target_property(assimp_LINKED_LIBS assimp::assimp INTERFACE_LINK_LIBRARIES)
message("assimp Linked Libraries: ${assimp_LINKED_LIBS}")
get_target_property(assimp_COMPILE_DEFS assimp::assimp INTERFACE_COMPILE_DEFINITIONS)
message("assimp Compile Definitions: ${assimp_COMPILE_DEFS}")
get_target_property(assimp_COMPILE_OPTS assimp::assimp INTERFACE_COMPILE_OPTIONS)
message("assimp Compile Options: ${assimp_COMPILE_OPTS}")
if(assimp_FOUND)
    #target_link_libraries(${PROJECT_NAME} PRIVATE ${ASSIMP_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE assimp::assimp)
endif()

# Saving this for linux configuration!
# find_library(UUID_LIBRARY CONFIG REQUIRED NAMES uuid)
# if(UUID_FOUND)
#     list(APPEND SOURCE_INCLUDES ${UUID_INCLUDE_DIRS})
#     list(APPEND LINK_LIBRARIES ${UUID_LIBRARIES})
# endif()

find_package(stduuid CONFIG REQUIRED)
# Use stduuid::stduuid
if(stduuid_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE stduuid)
endif()

find_package(fmt CONFIG REQUIRED)
if(fmt_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
endif()

find_package(soil2 CONFIG REQUIRED)
# Use soil2
if(soil2_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE soil2)
endif()

find_package(OpenAL CONFIG REQUIRED)
# Use OpenAL::OpenAL
if(OpenAL_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenAL::OpenAL)
endif()

# set(IMGUI_DIR ${PROJECT_PATH}/imgui)
# find_package(IMGUI REQUIRED)
# #get_target_property(IMGUI_PROPERTIES IMGUI INTERFACE_SOURCES)
# #message("IMGUI Properties: ${IMGUI_PROPERTIES}")
# if(IMGUI_FOUND)
#     target_link_libraries(${PROJECT_NAME} PRIVATE IMGUI::IMGUI)
# endif()

# Add the ImGui library
# set(IMGUI_DIR ${PROJECT_PATH}/imgui)
# file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp ${IMGUI_DIR}/*.h)
# message("IMGUI source files:")
# foreach(SOURCE_FILE ${IMGUI_SOURCES})
#     message("- ${SOURCE_FILE}")
# endforeach()
# message("###################### PROJECT_PATH: " ${IMGUI_SOURCES})
# add_library(imgui ${IMGUI_SOURCES})
# # Assuming you're using OpenGL3 and glfw3 for imgui's backends
# add_library(imgui-sdl2-opengl3
#     ${IMGUI_DIR}/backends/imgui_impl_sdl2.h
#     ${IMGUI_DIR}/backends/imgui_impl_opengl3.h
#     ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
#     ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
# )
# target_include_directories(imgui-sdl2-opengl3 PRIVATE ${IMGUI_DIR} ${IMGUI_DIR}/backends)
# 
# # Link the ImGui library
# target_include_directories(${PROJECT_NAME} PRIVATE imgui)
# target_link_libraries(${PROJECT_NAME} PRIVATE imgui)
# target_include_directories(${PROJECT_NAME} PRIVATE imgui-sdl2-opengl3)
# target_link_libraries(${PROJECT_NAME} PRIVATE imgui-sdl2-opengl3)