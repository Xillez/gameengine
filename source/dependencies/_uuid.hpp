#pragma once

#include "Config.hpp"

#if defined(LINUX)
    #include <uuid/uuid.h>
#elif defined(WINDOWS)
    #include <uuid.h>
#endif
