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
        INFO,
        DEBUG,
        WARNING,
        ERROR,
        FATAL
    };

    /**
     * @class NyaLogSettings
     * @brief Class holding NyaLog settings.
     * @details use this class to set NyaLog settings.
     */
    class NyaLogSettings {
        public:
            /**
             * Path to the log file.
             * On Windows, defaults to %LocalAppData%/rtouhou/logs
             * On Linux, defaults to ~/.config/rtouhou/logs
             * Must be a complete path, or it will be relative to the working directory.
             */
            std::string _path;

            // Filename. Defaults to "nya".
            std::string _filename;

            // Should the file be overwritten ?
            bool _overwrite;

            // Enable logging to a file ?
            bool _file;

            // Enable logging to stdout ?
            bool _stdout;

            // Default Logging Level.
            LogLevel _level;

            /**
             * @brief Construct a new Nya Log Settings object.
             */
            NyaLogSettings();
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
                    const NyaLogSettings& settings
                ) -> bool;

                /**
                 * @brief Stops NyaLog.
                 * @details Closes all output streams.
                 */
                auto stop(
                ) -> void;

                auto operator()(
                    nl::LogLevel level,
                    std::string message
                ) -> NyaLog&;

            private:
                NyaLogSettings _settings;
                std::ofstream _ofs;
                bool _init;
                std::mutex _mutex;

                void printFormattedMessage(std::string message);
        };
    }
}

#include "NyaLog.inl"

#endif /* !NYALOG_HPP_ */
