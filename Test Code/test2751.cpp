#include <iostream>
#include <string>
#include <sstream>

// Log levels
enum LogLevel {
    CRITICAL,
    ERROR,
    WARNING,
    INFO,
    DEBUG
};

// Log message template
struct LogMessage {
    LogLevel level;
    std::string message;
};

// Logging function
void log(const LogMessage& message) {
    // Print log message to standard output
    std::cout << message.level << ": " << message.message << std::endl;
}

// Macro for logging at CRITICAL level
#define LOG_CRITICAL(message, ...) log(LogMessage{CRITICAL, message})

int main() {
    // Log a CRITICAL message with a variable argument
    LOG_CRITICAL("Critical error occurred: %s", "Invalid input");

    return 0;
}
