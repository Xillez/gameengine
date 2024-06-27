#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>

#include <fmt/core.h>
#include <fmt/chrono.h>

#include "Logging.hpp"
#include "Config.hpp"
#include "TermColors.hpp"

const std::string Log::LOG_INFO = TermColor::WHITE + "INFO" + TermColor::RESET;
const std::string Log::LOG_WARN = TermColor::YELLOW + "WARN" + TermColor::RESET;
const std::string Log::LOG_ERROR = TermColor::RED + "ERROR" + TermColor::RESET;
const std::string Log::LOG_DEBUG = TermColor::BLUE + "DEBUG" + TermColor::RESET;

//static
void Log::Info(const std::string& format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format.c_str());
        Log::printLog(Log::LOG_INFO, format, args);
        va_end(args);
    #endif
}

//static
void Log::Warn(const std::string& format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format.c_str());
        Log::printLog(Log::LOG_WARN, format, args);
        va_end(args);
    #endif
}

//static
void Log::Error(const std::string& format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format.c_str());
        Log::printLog(Log::LOG_ERROR, format, args);
        va_end(args);
    #endif
}

//static
void Log::Debug(const std::string& format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format.c_str());
        Log::printLog(Log::LOG_DEBUG, format, args);
        va_end(args);
    #endif
}

//static
void Log::printLog(const std::string& tag, const std::string& format, va_list args)
{
    #if (LOGGING)
        // Print the log message
        fmt::print(
            "{} | {}: {}\n",
            // Get current time
            std::chrono::system_clock::now(),
            tag,
            // Format the message using fmt
            fmt::vformat(format, fmt::make_format_args(args))
        );
    #endif
}