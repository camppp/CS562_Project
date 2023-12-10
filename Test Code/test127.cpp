#include <iostream>
#include <string>
#include <cstdarg>

enum LogLevel {
    LOGGER_INFO,
    LOGGER_WARNING,
    LOGGER_ERROR
};

class Logger {
public:
    void log(LogLevel level, const char* format, ...) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        std::cout << std::endl;
    }
};

int main() {
    Logger logger;

    // Log messages with different log levels and variable arguments
    logger.log(LOGGER_INFO, "is equivalent.");
    logger.log(LOGGER_ERROR, "results in counterexample %s .", "example123");

    return 0;
}
