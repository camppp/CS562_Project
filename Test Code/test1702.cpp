#include <iostream>
#include <string>
#include <ctime>

class Logger {
public:
    virtual void log(const std::string& level, const std::string& message) = 0;
};

class CLog4CXX : public Logger {
public:
    void log(const std::string& level, const std::string& message) override {
        std::time_t now = std::time(0);
        std::tm* timeinfo = std::localtime(&now);
        char timestamp[80];
        std::strftime(timestamp, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        std::cout << "[" << timestamp << "] " << level << ": " << message << std::endl;
    }
};

class CustomLogger : public Logger {
public:
    void log(const std::string& level, const std::string& message) override {
        // Custom logging implementation
        std::cout << level << ": " << message << std::endl;
    }
};

class LogManager {
private:
    Logger* logger;

public:
    LogManager(Logger* logger) : logger(logger) {}

    void Warn(const char* format, ...) {
        va_list args;
        va_start(args, format);
        char buffer[256];
        vsnprintf(buffer, 256, format, args);
        va_end(args);
        logger->log("WARN", buffer);
    }
};

int main() {
    CLog4CXX cLog;
    CustomLogger customLog;

    LogManager logManager1(&cLog);
    logManager1.Warn("aaa,%s", "bbb");

    LogManager logManager2(&customLog);
    logManager2.Warn("aaa,%s", "bbb");

    return 0;
}
