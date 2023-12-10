#include <iostream>
#include <string>
#include <map>
#include <cassert>

class JSONParser {
public:
    JSONParser(const std::string& json) {
        // Parse the JSON string and store the result in the internal representation
        // ...
    }

    bool getBoolean(const std::string& key) {
        // Return the boolean value associated with the given key in the parsed JSON object
        // ...
    }

    float getFloat(const std::string& key) {
        // Return the floating-point value associated with the given key in the parsed JSON object
        // ...
    }
};

int main() {
    // Parse the JSON string and create a JSONParser object
    JSONParser parser("{\"happy\": true, \"pi\": 3.14159}");

    // Check that the boolean value associated with the key "happy" is true
    assert(parser.getBoolean("happy"));

    // Check that the floating-point value associated with the key "pi" is greater than 3.14
    assert(parser.getFloat("pi") > 3.14);

    return 0;
}
