#pragma once

#include "Config.hpp"

#ifdef defined(LINUX)
    #include <SOIL/SOIL.h>
#elif defined(WINDOWS)
    #include <SOIL2/SOIL2.h>
#endif