#include <iostream>
#include <fstream>
#include <vector>

enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

class Logger {
public:
    void setLogLevel(LogLevel level) {
        logLevel = level;
    }

    void addOutputDestination(std::ostream& output) {
        outputDestinations.push_back(&output);
    }

    void log(LogLevel level, const std::string& message) {
        if (level >= logLevel) {
            for (auto dest : outputDestinations) {
                (*dest) << "[" << logLevelToString(level) << "] " << message << std::endl;
            }
        }
    }

    void logDebug(const std::string& message) {
        log(LogLevel::DEBUG, message);
    }

    void logInfo(const std::string& message) {
        log(LogLevel::INFO, message);
    }

    void logWarning(const std::string& message) {
        log(LogLevel::WARNING, message);
    }

    void logError(const std::string& message) {
        log(LogLevel::ERROR, message);
    }

private:
    LogLevel logLevel = LogLevel::DEBUG;
    std::vector<std::ostream*> outputDestinations;

    std::string logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR: return "ERROR";
        }
    }
};

int main() {
    Logger logger;

    // Add console output destination
    logger.addOutputDestination(std::cout);

    // Add file output destination
    std::ofstream file("log.txt");
    logger.addOutputDestination(file);

    // Set log level to INFO
    logger.setLogLevel(LogLevel::INFO);

    // Log messages at different levels
    logger.logDebug("This is a debug message");
    logger.logInfo("This is an info message");
    logger.logWarning("This is a warning message");
    logger.logError("This is an error message");

    file.close();  // Close the file stream

    return 0;
}
