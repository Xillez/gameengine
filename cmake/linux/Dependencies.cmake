# Add the path to your CMake modules if CMake can't find them.
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
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
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
endif()

# Manually specify the paths to the ASSIMP headers and libraries
set(ASSIMP_INCLUDE_DIRS "/usr/include/")
set(ASSIMP_LIBRARIES "/usr/lib/x86_64-linux-gnu/libassimp.so")
find_package(ASSIMP REQUIRED)
# Use ASSIMP
if(ASSIMP_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ASSIMP_LIBRARIES})
endif()

find_library(UUID_LIBRARY NAMES uuid)
if(UUID_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${UUID_LIBRARY})
endif()

find_package(fmt CONFIG REQUIRED)
if(fmt_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)
endif()

find_package(spdlog REQUIRED)
if(spdlog_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog spdlog::spdlog_header_only)
endif()

find_package(SOIL REQUIRED)
if(SOIL_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SOIL_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SOIL_LIBRARIES})
else()
    message(FATAL_ERROR "SOIL library not found.")
endif()