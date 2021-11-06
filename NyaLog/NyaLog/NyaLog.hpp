/*
** EPITECH PROJECT, 2021
** NyaLog
** File description:
** NyaLog
*/

/**
 * @file        NyaLog.hpp
 * @brief       NyaLog logger.
 * @details     A simple logger made to be header only.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/11/2021
 */

#ifndef NYALOG_HPP_
#define NYALOG_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <mutex>

/**
 * @namespace nl
 */
namespace nl {
    enum class LogLevel {
        NONE,
        INFO,
        DEBUG,
        WARNING,
        ERROR,
        FATAL
    };

    namespace {
        class NyaLog {
            public:
                /**
                 * @brief Constructor
                 */
                NyaLog();

                /**
                 * @brief Destructor
                 */
                ~NyaLog();

                /**
                 * @brief Enables NyaLog.
                 * @details Opens all output streams.
                 * @param settings Settings to use for NyaLog.
                 * @return true if all streams were opened correctly,
                 * false otherwise.
                 */
                auto init(
                ) -> bool;

                /**
                 * @brief Stops NyaLog.
                 * @details Closes all output streams.
                 */
                auto stop(
                ) -> void;

                /**
                 * @brief Logs a message.
                 * @details Logs a message to the enabled output streams.
                 * @param level Logging level.
                 * @param message Message to log.
                 */
                auto operator()(
                    nl::LogLevel level,
                    std::string message
                ) -> NyaLog&;

                /**
                 * @brief Set the path to the log file.
                 * @details On Windows, defaults to %LocalAppData%/rtouhou/logs
                 * @details On Linux, defaults to ~/.config/rtouhou/logs
                 * @details Can use both relative and fixed paths.
                 * @param path The path.
                 */
                auto setPath(
                    std::string path
                ) -> NyaLog&;

                /**
                 * @brief Set the filename
                 * Sets the name of the log file.
                 * @param filename The filename.
                 */
                auto setFilename(
                    std::string filename
                ) -> NyaLog&;

                /**
                 * @brief Should the output be stored to a log file ?
                 * 
                 * @param enabled
                 */
                auto enableFileLogging(
                    bool enabled
                ) -> NyaLog&;

                /**
                 * @brief Should the file be overwritten ?
                 * If the file is overwritten, it will not prepend the date to the filename.
                 * @param overwrite 
                 */
                auto shouldOverwrite(
                    bool overwrite
                ) -> NyaLog&;

                /**
                 * @brief Should the output be written to stdout ?
                 * 
                 * @param enabled 
                 */
                auto enableStdoutLogging(
                    bool enabled
                ) -> NyaLog&;

                /**
                 * @brief Sets the minimul logging level to be shown.
                 * 
                 * @param level 
                 */
                auto setLogLevel(
                    nl::LogLevel level
                ) -> NyaLog&;

                /**
                 * @brief Sets the date format to use in the logger.
                 * Defaults to ISO-8601.
                 * @param format following the std::put_time (https://en.cppreference.com/w/cpp/io/manip/put_time) format (%Y for year, etc)
                 */
                auto setDateFormat(
                    std::string format
                ) -> NyaLog&;

                /**
                 * @brief Sets the filename format to use in the logger.
                 * Defaults to YYYY-MM-DD_name.log.
                 * Bear in mind that some date characters can be invalid on some platforms.
                 * @param format following the std::put_time (https://en.cppreference.com/w/cpp/io/manip/put_time) format (%Y for year, etc)
                 */
                auto setFilenameFormat(
                    std::string format
                ) -> NyaLog&;

            private:
                std::ofstream _ofs;
                bool _init;
                std::mutex _mutex;
                std::string _path;
                std::string _filename;
                bool _overwrite;
                bool _file;
                bool _stdout;
                std::string _dateFormat;
                std::string _filenameFormat;
                LogLevel _level;
                void printFormattedMessage(std::string message);
        };
    }
#define nyalogTRACE(level, message) nl::nyalog(level, std::string{__FILE__ + ":" + std::to_string(__LINE__) + " " + message})
}

#include "NyaLog.inl"


#endif /* !NYALOG_HPP_ */
