#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Log levels
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

// Log destination interface
class LogDestination {
public:
    virtual void log(const LogMessage& message) = 0;
};

// Console log destination
class ConsoleLogDestination : public LogDestination {
public:
    void log(const LogMessage& message) override {
        std::cout << message.level << ": " << message.message << std::endl;
    }
};

// File log destination
class FileLogDestination : public LogDestination {
public:
    FileLogDestination(const std::string& filename) : filename_(filename) {}

    void log(const LogMessage& message) override {
        std::ofstream file(filename_);
        file << message.level << ": " << message.message << std::endl;
    }

private:
    std::string filename_;
};

// Network socket log destination
class NetworkSocketLogDestination : public LogDestination {
public:
    NetworkSocketLogDestination(const std::string& hostname, int port) : hostname_(hostname), port_(port) {}

    void log(const LogMessage& message) override {
        // Send log message to network socket
    }

private:
    std::string hostname_;
    int port_;
};

// Logging system class
class LoggingSystem {
public:
    LoggingSystem(const std::vector<LogDestination*>& destinations) : destinations_(destinations) {}

    void log(const LogMessage& message) {
        for (auto& destination : destinations_) {
            destination->log(message);
        }
    }

private:
    std::vector<LogDestination*> destinations_;
};

// Test data generation
class TestData {
public:
    static std::vector<LogMessage> generateLogMessages() {
        std::vector<LogMessage> messages;
        messages.push_back(LogMessage{LogLevel::DEBUG, "Test message 1"});
        messages.push_back(LogMessage{LogLevel::INFO, "Test message 2"});
        messages.push_back(LogMessage{LogLevel::WARNING, "Test message 3"});
        messages.push_back(LogMessage{LogLevel::ERROR, "Test message 4"});
        return messages;
    }
};

int main() {
    // Create logging system with console and file destinations
    std::vector<LogDestination*> destinations;
    destinations.push_back(new ConsoleLogDestination());
    destinations.push_back(new FileLogDestination("log.txt"));
    LoggingSystem loggingSystem(destinations);

    // Log test messages
    for (auto& message : TestData::generateLogMessages()) {
        loggingSystem.log(message);
    }

    return 0;
}
