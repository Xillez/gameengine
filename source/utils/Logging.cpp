#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>

#include <fmt/core.h>

#include "Logging.hpp"
#include "Config.hpp"
#include "TermColors.hpp"

const std::string Log::LOG_INFO = TermColor::color(TermColor::Color::LIGHT_GRAY) + "INFO" + TermColor::RESET;
const std::string Log::LOG_WARN = TermColor::color(TermColor::Color::YELLOW) + "WARN" + TermColor::RESET;
const std::string Log::LOG_ERROR = TermColor::color(TermColor::Color::RED) + "ERROR" + TermColor::RESET;
const std::string Log::LOG_DEBUG = TermColor::color(TermColor::Color::BLUE) + "DEBUG" + TermColor::RESET;

std::shared_ptr<spdlog::logger> Log::logger = Log::makeLogger("Logger");

//static
void Log::Info(const std::string format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format);
        Log::logger->info(Log::formatMessage(Log::LOG_INFO, format, args));
        va_end(args);
    #endif
}

//static
void Log::Warn(const std::string format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format);
        Log::logger->warn(Log::formatMessage(Log::LOG_WARN, format, args));
        va_end(args);
    #endif
}

//static
void Log::Error(const std::string format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format);
        Log::logger->error(Log::formatMessage(Log::LOG_ERROR, format, args));
        va_end(args);
    #endif
}

//static
void Log::Debug(const std::string format, ...)
{
    #if (LOGGING)
        va_list args;
        va_start(args, format);
        Log::logger->debug(Log::formatMessage(Log::LOG_DEBUG, format, args));
        va_end(args);
    #endif
}

//statics
std::shared_ptr<spdlog::logger> Log::makeLogger(const std::string& name)
{
    // Create a logger with a name
    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt(
        name,
        spdlog::color_mode::automatic
    );
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] %v");
    logger->set_level(spdlog::level::trace);
    return logger;
}

//static
std::string Log::formatMessage(const std::string& tag, const std::string& format, va_list args)
{
    return fmt::format(
        "{}: {}{}\n",
        tag,
        fmt::vformat(format, fmt::make_format_args(args)),
        TermColor::RESET
    );
}
