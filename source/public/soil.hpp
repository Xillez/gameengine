#pragma once

#include "Config.hpp"

#if defined(LINUX)
    #include <SOIL/SOIL.h>
#elif defined(WINDOWS)
    #include <SOIL2/SOIL2.h>
#endif