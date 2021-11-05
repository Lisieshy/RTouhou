/*
** EPITECH PROJECT, 2021
** NyaLog
** File description:
** NyaLog
*/

/**
 * @file        NyaLog.inl
 * @brief       NyaLog logger implementation.
 * @details     A simple logger made to be header only.
 * @author      Aurélien Schulz (@Lisieshy)
 * @date        05/11/2021
 */

#ifdef NYALOG_HPP_
#ifndef NYALOG_INL_
#define NYALOG_INL_

#include "NyaLog.hpp"

#include <sstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <fstream>

inline nl::NyaLogSettings::NyaLogSettings() :
    _filename("nya"),
    _file(true),
    _stdout(true)
{
    std::string log_path;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    _path = getenv("LOCALAPPDATA");
    _path.append("\\rtouhou\\logs\\");
#elif __linux__
    _path = getenv("HOME");
    _path.append("/.config/rtouhou/logs/");
#endif
}

namespace nl {
    NyaLog nyalog{};
}

inline nl::NyaLog::NyaLog() :
    _init(false),
    _mutex()
{
}

inline nl::NyaLog::~NyaLog()
{
    if (_init)
        stop();
}

auto inline nl::NyaLog::init(
    const nl::NyaLogSettings& settings
) -> bool
{
    _settings = settings;

    const auto current_time_point {
        std::chrono::system_clock::now()
    };
    const auto current_time {
        std::chrono::system_clock::to_time_t (current_time_point)
    };
    const auto current_localtime {
        *std::localtime (&current_time)
    };

    std::ostringstream stream;
    stream << std::put_time (&current_localtime, "%F") << "";

    if (!_init) {
        std::filesystem::create_directories(_settings._path);

        if (_settings._file) {
            _ofs.open(
                _settings._path +
                stream.str() +
                "_" +
                _settings._filename,
                std::ios::app
            );
        }
        if (_ofs.is_open()) {
            _init = true;
            return true;
        }
        else
            return false;
    }
    return true;
}

auto inline nl::NyaLog::stop(
) -> void
{
    if (_init) {
        _ofs.close();
        _init = false;
    }
}

auto inline nl::NyaLog::printFormattedMessage(
    std::string message
) -> void
{
    std::scoped_lock<std::mutex> lock {
        _mutex
    };
    if (_settings._file)
        _ofs << message << std::endl;
    if (_settings._stdout)
        std::cout << message << std::endl;
}

auto inline nl::NyaLog::operator()(
    nl::LogLevel level,
    std::string message
) -> NyaLog&
{
    if (_init) {
        if (level <= _settings._level) {
            const auto current_time_point {
                std::chrono::system_clock::now()
            };
            const auto current_time {
                std::chrono::system_clock::to_time_t (current_time_point)
            };
            const auto current_localtime {
                *std::localtime (&current_time)
            };
            const auto current_time_since_epoch {
                current_time_point.time_since_epoch()
            };
            const auto current_milliseconds {
                std::chrono::duration_cast<std::chrono::milliseconds> (current_time_since_epoch).count() % 1000
            };

            std::ostringstream stream;
            stream << std::put_time (&current_localtime, "%FT%T") << "." << std::setw (3) << std::setfill ('0') << current_milliseconds << "Z";

            std::stringstream ss;
            ss << "[" << stream.str() << "] ";
            switch (level) {
                case nl::LogLevel::INFO:
                    ss << "\e[1;36m[INFO]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
                case nl::LogLevel::DEBUG:
                    ss << "\e[1;34m[DEBUG]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
                case nl::LogLevel::WARNING:
                    ss << "\e[1;33m[WARN]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
                case nl::LogLevel::ERROR:
                    ss << "\e[1;31m[ERROR]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
                case nl::LogLevel::FATAL:
                    ss << "\e[1;31m[CRIT]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
                default:
                    ss << "\e[1;36m[INFO]\e[0m " << message;
                    printFormattedMessage(ss.str());
                    break;
            }
        }
    }
    return *this;
}

#endif /* NYALOG_INL_ */
#endif /* NYALOG_HPP_ */