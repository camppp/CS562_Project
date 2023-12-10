#include <iostream>
#include <fstream>
#include <mutex>
#include <ctime>

enum class LogLevel { DEBUG, INFO, WARNING, ERROR, FATAL };

class Logger {
public:
    Logger() : minLogLevel(LogLevel::INFO), outputToConsole(true) {}

    void setLogLevel(LogLevel level) {
        minLogLevel = level;
    }

    void log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(logMutex);
        if (level >= minLogLevel) {
            std::string logMessage = getTimestamp() + " " + logLevelToString(level) + ": " + message;
            if (outputToConsole) {
                std::cout << logMessage << std::endl;
            }
            if (outputToFile) {
                logToFile(logMessage);
            }
            if (!serverAddress.empty()) {
                logToServer(logMessage);
            }
        }
    }

    void setOutputToConsole(bool enable) {
        outputToConsole = enable;
    }

    void setOutputToFile(const std::string& filename) {
        logFile.open(filename, std::ios::app);
        outputToFile = true;
    }

    void setOutputToServer(const std::string& serverAddress) {
        this->serverAddress = serverAddress;
    }

private:
    LogLevel minLogLevel;
    bool outputToConsole;
    std::ofstream logFile;
    bool outputToFile = false;
    std::string serverAddress;
    std::mutex logMutex;

    std::string getTimestamp() {
        std::time_t now = std::time(nullptr);
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return std::string(buffer);
    }

    std::string logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::FATAL: return "FATAL";
        }
    }

    void logToFile(const std::string& message) {
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }

    void logToServer(const std::string& message) {
        // Implement logic to send log message to remote server
    }
};
