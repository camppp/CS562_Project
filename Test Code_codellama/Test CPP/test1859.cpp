#include <string>
#include <vector>
#include <unordered_map>

class Json {
public:
    void parse(const std::string& json) {
        // Parse the JSON string and store the parsed data internally
        // ...
    }

    std::string getValue(const std::string& key) {
        // Find the value associated with the given key in the parsed JSON object
        // ...
    }

    std::vector<std::string> getArray(const std::string& key) {
        // Find the array associated with the given key in the parsed JSON object
        // ...
    }

private:
    // Store the parsed data internally
    std::unordered_map<std::string, std::string> values;
    std::unordered_map<std::string, std::vector<std::string>> arrays;
};
