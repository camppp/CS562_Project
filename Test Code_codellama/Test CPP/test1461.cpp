#include <iostream>
#include <string>

class Logger {
public:
    void logFunctionExit(const std::string& functionName) {
        std::cout << "Function exited: " << functionName << std::endl;
    }

    int getRefCountFile(const std::string& fileName) {
        // Return the reference count of the file
        return 0;
    }
};
