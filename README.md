# Game engine

### Author(s):

- Xillez - kent.wincent46@gmail.com

### Introduction

Basic game engine.

### Tools used:

- CMake - https://cmake.org/download/
- Make - http://gnuwin32.sourceforge.net/packages/make.htm
- Doxygen - http://www.doxygen.nl/download.html

### Installation / Usage (Linux only so far)

1. Install the following dependencies:
   1. Assimp
   2. UUID
   3. SDL2
   4. GLFW3
   5. GLM
   6. Glew
   7. Format
   8. OpenGL
   9. Doxygen
   10. Dot
   11. CMake
   12. Make
2. Run the build script (linux):

```
./buildlinux.sh
```

3. Go into the "build" folder.
4. Run executable:

```
./bin/gameengine
```

### Features so far:

- Entity component lifecycle (start, update, destroy)
