#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Json {
private:
    std::unordered_map<std::string, std::string> values;
    std::unordered_map<std::string, std::vector<std::string>> arrays;

public:
    void parse(std::string json) {
        // Implement JSON parsing logic to populate values and arrays maps
        // Assume valid JSON input for simplicity
    }

    std::string getValue(std::string key) {
        if (values.find(key) != values.end()) {
            return values[key];
        }
        return "";
    }

    std::vector<std::string> getArray(std::string key) {
        if (arrays.find(key) != arrays.end()) {
            return arrays[key];
        }
        return std::vector<std::string>();
    }
};

int main() {
    Json j;
    j.parse(R"({"name": "John", "age": 30, "address": {"city": "New York", "zip": 10001}, "languages": ["C++", "Python", "JavaScript"]})");

    std::string name = j.getValue("name"); // name = "John"
    std::string city = j.getValue("address.city"); // city = "New York"
    std::string language = j.getArray("languages")[1]; // language = "Python"

    std::cout << "Name: " << name << std::endl;
    std::cout << "City: " << city << std::endl;
    std::cout << "Language: " << language << std::endl;

    return 0;
}
