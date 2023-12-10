#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Log level enumeration
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// Log message structure
struct LogMessage {
    LogLevel level;
    std::string message;
};

// Logger class
class Logger {
public:
    // Constructor
    Logger(LogLevel level = LogLevel::DEBUG) : level_(level) {}

    // Set log level
    void setLevel(LogLevel level) {
        level_ = level;
    }

    // Log message at DEBUG level
    void logDebug(const std::string& message) {
        logMessage(LogLevel::DEBUG, message);
    }

    // Log message at INFO level
    void logInfo(const std::string& message) {
        logMessage(LogLevel::INFO, message);
    }

    // Log message at WARNING level
    void logWarning(const std::string& message) {
        logMessage(LogLevel::WARNING, message);
    }

    // Log message at ERROR level
    void logError(const std::string& message) {
        logMessage(LogLevel::ERROR, message);
    }

    // Add output destination
    void addOutput(std::ostream& output) {
        outputs_.push_back(&output);
    }

    // Remove output destination
    void removeOutput(std::ostream& output) {
        auto it = std::find(outputs_.begin(), outputs_.end(), &output);
        if (it != outputs_.end()) {
            outputs_.erase(it);
        }
    }

private:
    // Log message
    void logMessage(LogLevel level, const std::string& message) {
        if (level >= level_) {
            for (auto& output : outputs_) {
                *output << message << std::endl;
            }
        }
    }

    // Log level
    LogLevel level_;

    // Output destinations
    std::vector<std::ostream*> outputs_;
};

// Sample usage
int main() {
    // Create a logger instance
    Logger logger;

    // Set the log level to INFO
    logger.setLevel(LogLevel::INFO);

    // Log a message at DEBUG level
    logger.logDebug("This is a DEBUG message");

    // Log a message at INFO level
    logger.logInfo("This is an INFO message");

    // Log a message at WARNING level
    logger.logWarning("This is a WARNING message");

    // Log a message at ERROR level
    logger.logError("This is an ERROR message");

    // Add a console output
    logger.addOutput(std::cout);

    // Remove the console output
    logger.removeOutput(std::cout);

    // Add a file output
    std::ofstream file("log.txt");
    logger.addOutput(file);

    // Log a message at DEBUG level
    logger.logDebug("This is a DEBUG message");

    // Log a message at INFO level
    logger.logInfo("This is an INFO message");

    // Log a message at WARNING level
    logger.logWarning("This is a WARNING message");

    // Log a message at ERROR level
    logger.logError("This is an ERROR message");

    // Close the file output
    file.close();

    return 0;
}
