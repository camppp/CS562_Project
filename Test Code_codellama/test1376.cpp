#include <iostream>
#include <string>

// Macro for logging messages
#define LOG_MESSAGE(funcName, data) std::cout << "[" << funcName << "] " << data << std::endl;

// Generic logging function
template <typename T>
void logData(const T& data, const std::string& funcName) {
    LOG_MESSAGE(funcName, data);
}

// Example usage of the logging function
class MyClass {
public:
    void myFunction() {
        int data = 10;
        logData(data, "myFunction");
    }
};

int main() {
    MyClass myClass;
    myClass.myFunction();
    return 0;
}
