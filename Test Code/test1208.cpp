#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

// Base class for log levels
class LogLevel {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~LogLevel() {}
};

// Derived classes for specific log levels
class InfoLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        std::cout << "[INFO] " << message << std::endl;
    }
};

class WarningLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        std::cout << "[WARNING] " << message << std::endl;
    }
};

class ErrorLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        std::cerr << "[ERROR] " << message << std::endl;
    }
};

// Base class for log destinations
class LogDestination {
public:
    virtual void write(const std::string& message) = 0;
    virtual ~LogDestination() {}
};

// Derived classes for specific log destinations
class ConsoleDestination : public LogDestination {
public:
    void write(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileDestination : public LogDestination {
private:
    std::ofstream file;

public:
    FileDestination(const std::string& filename) {
        file.open(filename, std::ios::app);
    }

    void write(const std::string& message) override {
        file << message << std::endl;
    }

    ~FileDestination() {
        file.close();
    }
};

class NetworkDestination : public LogDestination {
public:
    void write(const std::string& message) override {
        // Implement network logging
    }
};

// Logging system
class Logger {
private:
    std::vector<std::shared_ptr<LogDestination>> destinations;

public:
    void addDestination(std::shared_ptr<LogDestination> destination) {
        destinations.push_back(destination);
    }

    void log(LogLevel& level, const std::string& message) {
        for (const auto& destination : destinations) {
            destination->write(getLevelPrefix(level) + message);
        }
    }

    std::string getLevelPrefix(LogLevel& level) {
        if (dynamic_cast<InfoLevel*>(&level)) {
            return "[INFO] ";
        } else if (dynamic_cast<WarningLevel*>(&level)) {
            return "[WARNING] ";
        } else if (dynamic_cast<ErrorLevel*>(&level)) {
            return "[ERROR] ";
        } else {
            return "";
        }
    }
};

// Sample application
int main() {
    Logger logger;
    logger.addDestination(std::make_shared<ConsoleDestination>());
    logger.addDestination(std::make_shared<FileDestination>("log.txt"));

    InfoLevel info;
    WarningLevel warning;
    ErrorLevel error;

    logger.log(info, "This is an information message");
    logger.log(warning, "This is a warning message");
    logger.log(error, "This is an error message");

    return 0;
}
