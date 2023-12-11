class Logger {
public:
    void LogError(const std::string& message) {
        // Log the message as an error
        std::cout << "Error: " << message << std::endl;
    }

    void LogWarning(const std::string& message) {
        // Log the message as a warning
        std::cout << "Warning: " << message << std::endl;
    }

    void LogInfo(const std::string& message) {
        // Log the message as informational
        std::cout << "Info: " << message << std::endl;
    }

    std::vector<std::string> GetLogs(LogType type) {
        // Return a list of messages of the specified type
        std::vector<std::string> logs;
        switch (type) {
            case LogType::Error:
                logs = errorLogs;
                break;
            case LogType::Warning:
                logs = warningLogs;
                break;
            case LogType::Info:
                logs = infoLogs;
                break;
        }
        return logs;
    }

private:
    std::vector<std::string> errorLogs;
    std::vector<std::string> warningLogs;
    std::vector<std::string> infoLogs;
};
