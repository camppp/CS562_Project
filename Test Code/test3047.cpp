#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <cassert>

using json = nlohmann::json;

class JSONParser {
private:
    json parsedJson;

public:
    JSONParser(const std::string& jsonString) : parsedJson(json::parse(jsonString)) {}

    bool getBoolean(const std::string& key) {
        return parsedJson[key];
    }

    double getFloat(const std::string& key) {
        return parsedJson[key];
    }
};

int main() {
    std::string jsonString = R"(
    {
        "happy": true,
        "pi": 3.141
    }
    )";

    JSONParser parser(jsonString);

    assert(parser.getBoolean("happy") == true);
    assert(parser.getFloat("pi") > 3.14);

    std::cout << "All assertions passed successfully." << std::endl;

    return 0;
}
