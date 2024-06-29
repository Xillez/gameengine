# Game engine

## Introduction

Basic game engine. WIP.

### Installation / Usage (Linux)

1. Install the following dependencies:
    1. OpenGL
    2. GLEW
    3. GLM
    4. SDL2
    5. Assimp
    6. UUID
    7. {fmt}
    8. spdlog
    9. SOIL
    10. CMake
    11. Make
    12. Doxygen
    13. Dot

    Command for installing all:

    ./scripts/linux/setup_dependencies.sh

    **OR**

    ```bash
    sudo apt-get update
    sudo apt-get install -y \
        libglew-dev \
        libglm-dev \
        libsdl2-dev \
        libassimp-dev \
        uuid-dev \
        libfmt-dev \
        libspdlog-dev \
        libsoil-dev \
        cmake \
        make \
        doxygen \
        graphviz
    ```

2. Run the build script:

    ```bash
    ./buildlinux.sh -r
    ```

    Code should build and the application should show (-r runs the built app
    as well), if not, check the log for errors or other issues.

### Installation / Usage (Windows)

1. Install these:

    - Visual Studio (for MSBUILD) - Comes with [Visual Studio Community](https://visualstudio.microsoft.com/downloads/)
    - VCPKG - [Download](https://github.com/microsoft/vcpkg/releases)
    - CMake - [Download](https://cmake.org/download/)
    - Doxygen - [Download](http://www.doxygen.nl/download.html)
    - Graphviz - [Download](https://graphviz.org/download/)
    - jq - [Download](https://jqlang.github.io/jq/download/)

2. Setup VCPKG as it says [here](https://github.com/microsoft/vcpkg?tab=readme-ov-file#quick-start-windows)

    If VCPKG isn't installed directly on C:/ open up the buildwin.sh file and
    correct the CMAKE_TOOLCHAIN_FILE envvar. NOTE! DO **NOT** push it if changed.

3. Run the build script:

    ```bash
    ./buildwin.sh -r
    ```

    If VCPKG is in your path or available the build script will run it to
    install and compile any dependencies, then Run CMake and build the project.
    Eventually the Project should come up. If it doesn't look for any errors or
    issues in the log and go through them.