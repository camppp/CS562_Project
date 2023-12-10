#include <string>

class LoggerConfig {
public:
    LoggerConfig(const std::string& ini, const std::string& loggerType, int verbosity, const std::string& filePath)
        : ini(ini), loggerType(loggerType), verbosity(verbosity), filePath(filePath) {}

    const std::string& getIni() const { return ini; }
    const std::string& getLoggerType() const { return loggerType; }
    int getVerbosity() const { return verbosity; }
    const std::string& getFilePath() const { return filePath; }

private:
    std::string ini;
    std::string loggerType;
    int verbosity;
    std::string filePath;
};
