#include <iostream>
#include <string>
#include <map>
#include <vector>

class ConfigAndLogger {
public:
    ConfigAndLogger(const std::map<std::string, std::string>& config, const std::vector<std::string>& logLevels)
        : config_(config), logLevels_(logLevels) {
    }

    void setConfig(const std::map<std::string, std::string>& config) {
        config_ = config;
    }

    void setLogLevels(const std::vector<std::string>& logLevels) {
        logLevels_ = logLevels;
    }

    void log(const std::string& message, const std::string& logLevel) {
        if (std::find(logLevels_.begin(), logLevels_.end(), logLevel) != logLevels_.end()) {
            std::cout << "[" << logLevel << "] " << message << std::endl;
        }
    }

    void info(const std::string& message) {
        log(message, "info");
    }

    void warning(const std::string& message) {
        log(message, "warning");
    }

    void error(const std::string& message) {
        log(message, "error");
    }

private:
    std::map<std::string, std::string> config_;
    std::vector<std::string> logLevels_;
};

int main() {
    // Create a ConfigAndLogger object with a map of configuration settings and a vector of log levels
    std::map<std::string, std::string> config = {
        {"key1", "value1"},
        {"key2", "value2"}
    };
    std::vector<std::string> logLevels = {"info", "warning", "error"};
    ConfigAndLogger logger(config, logLevels);

    // Set the configuration settings
    logger.setConfig({{"key1", "newValue1"}});

    // Set the log levels
    logger.setLogLevels({"info", "error"});

    // Log messages with different log levels
    logger.info("This is an info message");
    logger.warning("This is a warning message");
    logger.error("This is an error message");

    return 0;
}
