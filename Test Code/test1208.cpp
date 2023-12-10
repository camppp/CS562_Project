// Base class for log levels
class LogLevel {
public:
    virtual void log(const std::string& message) = 0;
};

// Derived class for INFO log level
class InfoLogLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        // Implement logging to console or file
    }
};

// Derived class for WARNING log level
class WarningLogLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        // Implement logging to console or file
    }
};

// Derived class for ERROR log level
class ErrorLogLevel : public LogLevel {
public:
    void log(const std::string& message) override {
        // Implement logging to console or file
    }
};

// Base class for log destinations
class LogDestination {
public:
    virtual void log(const std::string& message) = 0;
};

// Derived class for Console log destination
class ConsoleLogDestination : public LogDestination {
public:
    void log(const std::string& message) override {
        // Implement logging to console
    }
};

// Derived class for File log destination
class FileLogDestination : public LogDestination {
public:
    void log(const std::string& message) override {
        // Implement logging to file
    }
};

// Derived class for Network log destination
class NetworkLogDestination : public LogDestination {
public:
    void log(const std::string& message) override {
        // Implement logging to network
    }
};

// Method for logging messages at different levels and to different destinations
void log(const std::string& message, LogLevel* logLevel, LogDestination* logDestination) {
    logLevel->log(message);
    logDestination->log(message);
}

// Sample application demonstrating the usage of the logging system
int main() {
    // Create a logger instance
    Logger logger;

    // Log a message at the INFO level to the console
    logger.log("Hello, world!", new InfoLogLevel(), new ConsoleLogDestination());

    // Log a message at the WARNING level to the file
    logger.log("Warning: something went wrong!", new WarningLogLevel(), new FileLogDestination());

    // Log a message at the ERROR level to the network
    logger.log("Error: something went very wrong!", new ErrorLogLevel(), new NetworkLogDestination());

    return 0;
}
