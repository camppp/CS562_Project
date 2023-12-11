#include <iostream>
#include <fstream>
#include <string>

class CustomLog {
public:
    CustomLog(std::ostream& outputStream, const std::string& filePath, const std::string& messageType)
        : outputStream(outputStream), filePath(filePath), messageType(messageType) {
        // Construct the log message prefix based on the file name and message type
        logMessagePrefix = "[" + filePath + "] " + messageType + ": ";
    }

    // Overloaded operator<< for logging various types of data
    template<typename T>
    CustomLog& operator<<(const T& data) {
        outputStream << logMessagePrefix << data << std::endl;
        return *this;
    }

private:
    std::ostream& outputStream; // The output stream to log to
    std::string filePath; // The file path from which the log message originates
    std::string messageType; // The type of message being logged (e.g. "INFO", "WARNING", etc.)
    std::string logMessagePrefix; // The prefix for the log message
};
