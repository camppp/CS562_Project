#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Define the macro LAYOUT
#define LAYOUT(layout) std::string getLayout() { return layout; }

// Define the separator
#define SX_SEPARATOR "--------------------"

// Define the namespace for data types
namespace sx {
    class String {};
    class Int {};
}

class EventDataParser {
private:
    std::vector<std::string> data;
    std::vector<std::string>::iterator it;

public:
    EventDataParser(const std::string& eventData) {
        std::istringstream iss(eventData);
        std::string token;
        while (iss >> token) {
            data.push_back(token);
        }
        it = data.begin();
    }

    // Implement the LAYOUT macro
    LAYOUT(std::string)

    // Method to extract string based on layout
    std::string shiftString() {
        if (it != data.end()) {
            std::string value = *it;
            it++;
            return value;
        }
        return "";
    }

    // Method to extract integer based on layout
    int shiftInt() {
        if (it != data.end()) {
            int value = std::stoi(*it);
            it++;
            return value;
        }
        return 0;
    }
};

int main() {
    EventDataParser ev("Name: John Age: 25 City: New York");
    std::cout << "Layout: " << ev.getLayout() << std::endl;
    LAYOUT(sx::String << sx::Int << sx::String << sx::Int << sx::String << sx::Int);
    std::cout << ev.shiftString() << std::endl;
    std::cout << ev.shiftInt() << std::endl;
    std::cout << ev.shiftString() << std::endl;
    std::cout << ev.shiftInt() << std::endl;
    std::cout << ev.shiftString() << std::endl;
    std::cout << ev.shiftInt() << std::endl;
    std::cout << SX_SEPARATOR << std::endl;
    return 0;
}
