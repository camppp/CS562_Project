#include <iostream>

// Enumeration for the different levels of logging
enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

// Class for logging messages
class ToolLogger {
public:
    // Method for logging messages
    void log(LogLevel level, int flag, int color, const char* data, size_t size) {
        // Print the log message based on the level, flag, and color
        switch (level) {
            case LogLevel::INFO:
                std::cout << "INFO: " << data << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "WARNING: " << data << std::endl;
                break;
            case LogLevel::ERROR:
                std::cout << "ERROR: " << data << std::endl;
                break;
        }
    }
};

// Function to suppress warnings about unused parameters
#define MENGINE_UNUSED(x) (void)x

int main() {
    // Create a ToolLogger object
    ToolLogger logger;

    // Log a message with the INFO level
    logger.log(LogLevel::INFO, 0, 0, "This is an INFO message", 20);

    // Log a message with the WARNING level
    logger.log(LogLevel::WARNING, 0, 0, "This is a WARNING message", 20);

    // Log a message with the ERROR level
    logger.log(LogLevel::ERROR, 0, 0, "This is an ERROR message", 20);

    return 0;
}
