#include <iostream>
#include <fstream>
#include <mutex>
#include <ctime>

enum class LogLevel { DEBUG, INFO, WARNING, ERROR, FATAL };

class Logger {
public:
    Logger() : logLevel(LogLevel::INFO) {}

    void setLogLevel(LogLevel level) {
        logLevel = level;
    }

    void addConsoleOutput() {
        outputDestinations.push_back(&std::cout);
    }

    void addFileOutput(const std::string& filename) {
        std::ofstream* fileStream = new std::ofstream(filename);
        outputDestinations.push_back(fileStream);
    }

    void log(LogLevel level, const std::string& message) {
        if (level >= logLevel) {
            std::lock_guard<std::mutex> lock(mutex);
            for (auto dest : outputDestinations) {
                *dest << getCurrentTime() << " " << logLevelToString(level) << ": " << message << std::endl;
            }
        }
    }

    ~Logger() {
        for (auto dest : outputDestinations) {
            if (dest != &std::cout) {
                std::ofstream* fileStream = static_cast<std::ofstream*>(dest);
                fileStream->close();
                delete fileStream;
            }
        }
    }

private:
    LogLevel logLevel;
    std::vector<std::ostream*> outputDestinations;
    std::mutex mutex;

    std::string getCurrentTime() {
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
            default: return "UNKNOWN";
        }
    }
};

int main() {
    Logger logger;
    logger.addConsoleOutput();
    logger.addFileOutput("log.txt");
    logger.setLogLevel(LogLevel::DEBUG);

    logger.log(LogLevel::INFO, "This is an informational message");
    logger.log(LogLevel::WARNING, "This is a warning message");
    logger.log(LogLevel::ERROR, "This is an error message");
    logger.log(LogLevel::DEBUG, "This is a debug message");

    return 0;
}
