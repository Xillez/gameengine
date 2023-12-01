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
   4. GLM
   5. Glew
   6. Format
   7. OpenGL
   8. Doxygen
   9. Dot
   10. CMake
   11. Make
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
