#include <iostream>
#include <string>
#include <cassert>

class Logger {
public:
    // Log levels
    enum class Level {
        Info,
        Warning,
        Error,
        Debug
    };

    // Constructor
    Logger(Level level) : level_(level) {}

    // Log a message at the specified level
    void log(Level level, const std::string& message) {
        if (level_ >= level) {
            std::cout << message << std::endl;
        }
    }

    // Assert that a condition is true
    void assertCondition(bool condition, const std::string& message) {
        if (!condition) {
            log(Level::Error, "Assertion failed: " + message);
            assert(false);
        }
    }

private:
    Level level_;
};

int main() {
    Logger logger(Logger::Level::Info);

    // Log a message at the info level
    logger.log(Logger::Level::Info, "Hello, world!");

    // Log a message at the warning level
    logger.log(Logger::Level::Warning, "This is a warning message");

    // Log a message at the error level
    logger.log(Logger::Level::Error, "This is an error message");

    // Assert that a condition is true
    logger.assertCondition(true, "This condition should be true");

    return 0;
}
