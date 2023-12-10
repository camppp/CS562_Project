#include <iostream>
#include <fstream>
#include <string>

class CustomErrorHandler
{
public:
    CustomErrorHandler() {}

    void logError(const std::string& message)
    {
        std::ofstream errorLogFile("error.log", std::ios::app);
        errorLogFile << message << std::endl;
        errorLogFile.close();
    }

    std::string getLastError()
    {
        std::ifstream errorLogFile("error.log");
        std::string lastError;
        std::getline(errorLogFile, lastError);
        errorLogFile.close();
        return lastError;
    }
};
