#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

// Log levels
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

// Log message structure
struct LogMessage {
    LogLevel level;
    std::string message;
    std::string timestamp;
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
        std::cout << message.timestamp << " " << message.level << ": " << message.message << std::endl;
    }
};

// File log destination
class FileLogDestination : public LogDestination {
public:
    FileLogDestination(const std::string& filename) : filename_(filename) {}

    void log(const LogMessage& message) override {
        std::ofstream file(filename_, std::ios::app);
        file << message.timestamp << " " << message.level << ": " << message.message << std::endl;
    }

private:
    std::string filename_;
};

// Remote log destination
class RemoteLogDestination : public LogDestination {
public:
    RemoteLogDestination(const std::string& host, const std::string& port) : host_(host), port_(port) {}

    void log(const LogMessage& message) override {
        // Send log message to remote server
    }

private:
    std::string host_;
    std::string port_;
};

// Logging system
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

int main() {
    // Create logging system with console and file destinations
    LoggingSystem loggingSystem({
        new ConsoleLogDestination(),
        new FileLogDestination("log.txt")
    });

    // Log messages
    loggingSystem.log({LogLevel::INFO, "Hello, world!"});
    loggingSystem.log({LogLevel::WARNING, "Something went wrong!"});

    return 0;
}
