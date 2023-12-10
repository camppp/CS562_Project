#include <iostream>

// Define the LOG_MESSAGE macro for logging
#define LOG_MESSAGE(funcName, data) \
    std::cout << "Logging " << funcName << " - Data: " << data << std::endl;

// Define a generic logging function template
template <typename T>
void logData(const std::string& funcName, const T& data) {
    LOG_MESSAGE(funcName, data);
}

// Sample class with a member function to log data
class SampleClass {
public:
    int getData() const {
        return 42;
    }
};

// Function to log data from SampleClass
void logSampleData(SampleClass& sample) {
    logData("logSampleData", sample.getData());
}

int main() {
    SampleClass sampleObj;
    logSampleData(sampleObj);
    return 0;
}
