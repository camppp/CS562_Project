#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Logger {
public:
    // Constructor
    Logger() : logLevel_(LogLevel::DEBUG), outputToConsole_(true), outputToFile_(false), outputToServer_(false) {}

    // Set the minimum log level to be output
    void setLogLevel(LogLevel level) {
        logLevel_ = level;
    }

    // Log a message with the specified log level
    void log(LogLevel level, const std::string& message) {
        // Check if the message should be logged based on the log level
        if (level >= logLevel_) {
            // Log the message to the console
            if (outputToConsole_) {
                std::cout << message << std::endl;
            }

            // Log the message to a file
            if (outputToFile_) {
                std::ofstream file(filename_);
                file << message << std::endl;
                file.close();
            }

            // Log the message to a remote server
            if (outputToServer_) {
                // Send the message to the remote server
            }
        }
    }

    // Enable or disable logging to the console
    void setOutputToConsole(bool enable) {
        outputToConsole_ = enable;
    }

    // Enable logging to a file
    void setOutputToFile(const std::string& filename) {
        outputToFile_ = true;
        filename_ = filename;
    }

    // Enable logging to a remote server
    void setOutputToServer(const std::string& serverAddress) {
        outputToServer_ = true;
        serverAddress_ = serverAddress;
    }

private:
    // The minimum log level to be output
    LogLevel logLevel_;

    // Whether to output log messages to the console
    bool outputToConsole_;

    // Whether to output log messages to a file
    bool outputToFile_;

    // Whether to output log messages to a remote server
    bool outputToServer_;

    // The filename to output log messages to
    std::string filename_;

    // The address of the remote server to output log messages to
    std::string serverAddress_;

    // A mutex to ensure thread-safe logging
    std::mutex mutex_;
};
