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

/**
 * @brief MACRO to make a default formatter for custom types for fmt library.
 *
 * @example Define a formatter for a custom type Point:
 * struct Point {
 *     double x, y;
 * };
 *
 * // Use the macro to define the formatter for Point
 * DEFINE_FORMATTER(Point, {
 *     switch (this->presentation_) {
 *         case 'e': return fmt::format_to(ctx.out(), "({:e}, {:e})", value.x, value.y);
 *         case 'f':
 *         default: return fmt::format_to(ctx.out(), "({:f}, {:f})", value.x, value.y);
 *     }
 * })
 */
#define DEFINE_FORMATTER(T, format_code)                                    \
    template <>                                                             \
    struct fmt::formatter<T> {                                              \
        char presentation_ = 'f';                                           \
                                                                            \
        constexpr auto parse(fmt::format_parse_context& ctx) {              \
            auto it = ctx.begin(), end = ctx.end();                         \
            if (it != end && (*it == 'f' || *it == 'e')) {                  \
                presentation_ = *it++;                                      \
            }                                                               \
            if (it != end && *it != '}') {                                  \
                throw fmt::format_error("invalid format");                  \
            }                                                               \
            return it;                                                      \
        }                                                                   \
                                                                            \
        template <typename FormatContext>                                   \
        auto format(const T& value, FormatContext& ctx) const {             \
            format_code                                                     \
        }                                                                   \
    };
