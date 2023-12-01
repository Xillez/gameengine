#pragma once

#include <string>

// ################################################################################################
// #                                                                                              #
// #                                           Logging                                            #
// #                                                                                              #
// ################################################################################################

/**
 * @brief Logger class. Logs is logging is enabled.
 */
class Log
{
public:
    /**
     * @brief Logs a message using the info tag.
     * 
     * @param msg - string - The message to print.
     */
    static void Info(std::string msg);

    /**
     * @brief Logs a message using the warn tag.
     * 
     * @param msg - string - The message to print.
     */
    static void Warn(std::string msg);

    /**
     * @brief Logs a message using the error tag.
     * 
     * @param msg - string - The message to print.
     */
    static void Err(std::string msg);

    /**
     * @brief Logs a message using the debug tag.
     * 
     * @param msg - string - The message to print.
     */
    static void Debug(std::string msg);

protected:
    static const std::string LOG_INFO;  //!< Info tag used by logging
    static const std::string LOG_WARN;  //!< Warning tag used by logging
    static const std::string LOG_ERR;   //!< Error tag used by logging
    static const std::string LOG_DEBUG; //!< Debug tag used by logging
    //
};

#define LOG_INFO(msg) Log::Info(msg);
#define LOG_WARN(msg) Log::Warn(msg);
#define LOG_ERR(msg) Log::Err(msg);
#define LOG_DEBUG(msg) Log::Debug(msg);