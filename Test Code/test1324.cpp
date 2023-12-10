#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

enum class LogLevel { INFO, WARNING, ERROR, DEBUG };

class Logger {
public:
    void info(const std::string& message) {
        log(LogLevel::INFO, message);
    }

    void warning(const std::string& message) {
        log(LogLevel::WARNING, message);
    }

    void error(const std::string& message) {
        log(LogLevel::ERROR, message);
    }

    void debug(const std::string& message) {
        log(LogLevel::DEBUG, message);
    }

    void assertCondition(bool condition, const std::string& message) {
        if (!condition) {
            error("Assertion failed: " + message);
            terminateProgram();
        }
    }

    void setOutputDestination(std::ostream& output) {
        output_ = &output;
    }

private:
    std::ostream* output_ = &std::cout;

    void log(LogLevel level, const std::string& message) {
        std::string levelStr;
        switch (level) {
            case LogLevel::INFO:
                levelStr = "INFO";
                break;
            case LogLevel::WARNING:
                levelStr = "WARNING";
                break;
            case LogLevel::ERROR:
                levelStr = "ERROR";
                break;
            case LogLevel::DEBUG:
                levelStr = "DEBUG";
                break;
        }

        (*output_) << "[" << levelStr << "] " << message << std::endl;
    }

    void terminateProgram() {
        throw std::runtime_error("Program terminated due to assertion failure");
    }
};

int main() {
    Logger logger;
    logger.error("An error occurred");
    logger.debug("Debugging information");

    logger.setOutputDestination(std::cerr);
    logger.warning("This is a warning");

    logger.assertCondition(2 + 2 == 5, "Math is broken");
    logger.info("This message should not be logged");

    return 0;
}
