#include "Logger.h"

Logger::Logger() {

}

Logger::~Logger() {
    if (!Config::Instance()->debug && _file) {
        _file.close();
    }
}

void Logger::init() {
    if (!Config::Instance()->debug) {
        _file.open("log.txt", std::ios::out | std::ios::trunc);
    }
}

void Logger::log(std::string message) {
    if (!Config::Instance()->debug) {
        _file << message << std::endl;
    } else {
        std::cout << message << std::endl;
    }
}
