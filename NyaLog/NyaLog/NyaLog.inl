#ifdef NYALOG_HPP_
#ifndef NYALOG_INL_
#define NYALOG_INL_

#include "NyaLog.hpp"

#include <sstream>
#include <chrono>
#include <iomanip>

inline nl::NyaLogSettings::NyaLogSettings() :
    _path(""),
    _filename("nya"),
    _overwrite(false),
    _file(true),
    _stdout(true)
{

}

namespace nl {
    NyaLog nyalog{};
}

inline nl::NyaLog::NyaLog()
{
    _init = false;
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

    // std::chrono::year_month_day today{std::chrono::system_clock::now()};
    // std::chrono::hh_mm_ss hour{std::chrono::system_clock::now()};

    time_t theTime = time(nullptr);
    struct tm* timeInfo = localtime(&theTime);

    std::string format = "%Y%m%dT%H%M%SZ";

    std::stringstream ss;
    ss << std::put_time(timeInfo, format.c_str());

    if (!_init) {
        if (_settings._overwrite)
            _ofs.open(
                _settings._path +
                _settings._filename
            );
        else
            _ofs.open(
                _settings._path +
                ss.str() +
                "_" +
                _settings._filename
            );
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

template<typename T>
auto inline nl::NyaLog::operator<<(
    T value
) -> NyaLog&
{
    if (_init) {
        // std::chrono::year_month_day today{std::chrono::system_clock::now()};
        // std::chrono::hh_mm_ss hour{std::chrono::system_clock::now()};
        // std::chrono::milliseconds ms{std::chrono::system_clock::now()};

        time_t theTime = time(nullptr);
        struct tm* timeInfo = localtime(&theTime);

        std::string format = "%FT%T%z";

        std::stringstream ss;
        ss << std::put_time(timeInfo, format.c_str());

        std::string formatted = "[" + ss.str() + "] ";

        if (_settings._file)
            _ofs << formatted << value;
        if (_settings._stdout)
            std::cout << formatted << value;
    }
    return *this;
}

auto inline nl::NyaLog::operator<<(
    std::ostream& (*f)(std::ostream&)
) -> NyaLog&
{
    if (_init) {
        if (_settings._file)
            _ofs << std::endl;
        if (_settings._stdout)
            std::cout << std::endl;
    }
    return *this;
}

#endif /* NYALOG_INL_ */
#endif /* NYALOG_HPP_ */