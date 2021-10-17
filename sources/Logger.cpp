// Copyright 2021 byteihq <kotov038@gmail.com>

#include <Logger.h>
#include <ios>
#include <chrono>
#include <iomanip>

void Logger::log(const std::string &msg, const std::string &fileName, size_t lineNumber) {
    auto file_ = std::ofstream("log/mainLog.log", std::ios::app);
    if (!file_.is_open()) {
        throw std::runtime_error{"Can't open log file"};
    }
    const char *time_param = "%T";
#ifdef BOOST_OS_WINDOWS
    time_param = "%X";
#endif
    time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    file_ << "[" << std::put_time(std::localtime(&time), "%d.%m.%y") << ' '
          << std::put_time(std::localtime(&time), time_param) << "][LINE: " << lineNumber << "][FILE: " << fileName
          << "][LOG]: " << msg << std::endl;
    file_.close();
}