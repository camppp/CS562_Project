#include <iostream>
#include <fstream>
#include <filesystem>

class CustomLog {
private:
    std::ostream& output;
    std::string before;

public:
    CustomLog(std::ostream& out, const std::string& filePath, const std::string& messageType) : output(out) {
        before = '[' + std::filesystem::path(filePath).filename().string() + "] " + messageType + '\t';
    }

    template <typename T>
    std::ostream& operator<<(T other) {
        return output << before << other;
    }
};

int main() {
    // Example usage
    std::ofstream fileStream("log.txt");
    CustomLog fileLog(fileStream, "example.cpp", "INFO");
    fileLog << "This is an informational message." << std::endl;

    CustomLog consoleLog(std::cout, "example.cpp", "ERROR");
    consoleLog << "An error occurred!" << std::endl;

    return 0;
}
