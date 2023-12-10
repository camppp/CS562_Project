#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// Define log levels
enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

// Abstract base class for log output destinations
class LogOutput {
public:
    virtual void write(const std::string& message) = 0;
    virtual ~LogOutput() {}
};

// Console log output
class ConsoleLogOutput : public LogOutput {
public:
    void write(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

// File log output
class FileLogOutput : public LogOutput {
private:
    std::ofstream file;
public:
    FileLogOutput(const std::string& filename) {
        file.open(filename, std::ios::out | std::ios::app);
    }

    void write(const std::string& message) override {
        file << message << std::endl;
    }

    ~FileLogOutput() {
        file.close();
    }
};

// Logger class
class Logger {
private:
    LogLevel level;
    LogOutput* output;

public:
    Logger(LogLevel logLevel, LogOutput* logOutput) : level(logLevel), output(logOutput) {}

    void log(LogLevel messageLevel, const std::string& message) {
        if (messageLevel >= level) {
            std::time_t now = std::time(nullptr);
            std::string timestamp = std::ctime(&now);
            std::string logMessage = "[" + timestamp.substr(0, timestamp.length() - 1) + "] " + message;
            output->write(logMessage);
        }
    }
};

// Test data generation
class TestDataGenerator {
public:
    static std::string generateTestData() {
        // Generate random test data
        return "Sample test data";
    }
};

int main() {
    // Create log outputs
    ConsoleLogOutput consoleOutput;
    FileLogOutput fileOutput("log.txt");

    // Create loggers
    Logger consoleLogger(LogLevel::INFO, &consoleOutput);
    Logger fileLogger(LogLevel::DEBUG, &fileOutput);

    // Log messages
    consoleLogger.log(LogLevel::INFO, "This is an informational message");
    fileLogger.log(LogLevel::DEBUG, "This is a debug message");

    // Generate test data
    std::string testData = TestDataGenerator::generateTestData();
    consoleLogger.log(LogLevel::INFO, "Generated test data: " + testData);

    return 0;
}
