#pragma once

#include <string>
#include <stdarg.h>

#include <fmt/core.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/sinks/basic_file_sink.h> // Support for logging to file

/**
 * @brief Logger class. Logs is logging is enabled.
 */
class Log
{
public:
    /**
     * @brief Logs a message using the info tag.
     *
     * @param msg - string - The format string to print.
     */
    static void Info(const std::string format, ...);

    /**
     * @brief Logs a message using the warn tag.
     *
     * @param msg - string - The format string to print.
     */
    static void Warn(const std::string format, ...);

    /**
     * @brief Logs a message using the error tag.
     *
     * @param msg - string - The format string to print.
     */
    static void Error(const std::string format, ...);

    /**
     * @brief Logs a message using the debug tag.
     *
     * @param msg - string - The format string to print.
     */
    static void Debug(const std::string format, ...);

protected:
    static const std::string LOG_INFO;  //!< Info logging tag
    static const std::string LOG_WARN;  //!< Warning logging tag
    static const std::string LOG_ERROR; //!< Error logging tag
    static const std::string LOG_DEBUG; //!< Debug logging tag

    static std::shared_ptr<spdlog::logger> makeLogger(const std::string& name);
    static std::string formatMessage(const std::string& tag, const std::string& format, va_list args);

    static std::shared_ptr<spdlog::logger> logger;
};

