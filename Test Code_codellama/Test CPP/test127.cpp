#include <iostream>
#include <string>

class Logger {
public:
    void log(LogLevel level, const char* format, ...) {
        va_list args;
        va_start(args, format);
        std::string message = formatMessage(level, format, args);
        va_end(args);
        std::cout << message << std::endl;
    }

private:
    std::string formatMessage(LogLevel level, const char* format, va_list args) {
        std::string message;
        switch (level) {
            case LOGGER_INFO:
                message = "INFO: ";
                break;
            case LOGGER_WARNING:
                message = "WARNING: ";
                break;
            case LOGGER_ERROR:
                message = "ERROR: ";
                break;
        }
        message += format;
        return message;
    }
};

int main() {
    Logger logger;
    logger.log(LOGGER_INFO, "This is an info message.");
    logger.log(LOGGER_WARNING, "This is a warning message.");
    logger.log(LOGGER_ERROR, "This is an error message.");
    logger.log(LOGGER_INFO, "The counterexample is %s.", "123");
    return 0;
}
