#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;

bool validateJSON(const json& jsonObject, const json& schema) {
    // Check if the JSON object is of type "object"
    if (jsonObject.type() != json::object) {
        return false;
    }

    // Check if the JSON object has the required property "property1"
    if (!jsonObject.contains("property1")) {
        return false;
    }

    // Check if the property "property1" is of type "string"
    if (jsonObject["property1"].type() != json::string) {
        return false;
    }

    // Check if the JSON object has any additional properties not specified in the schema
    for (const auto& property : jsonObject.properties()) {
        if (!schema.contains(property.first)) {
            return false;
        }
    }

    // Check if the JSON object has any properties matching the pattern "patternProperty1.*"
    for (const auto& property : jsonObject.properties()) {
        if (regex_match(property.first, regex("patternProperty1.*"))) {
            if (property.second.type() != json::object) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    json jsonObject = {
        {"property1", "value1"},
        {"patternProperty1a", {}},
        {"patternProperty1b", {}}
    };

    json schema = {
        {"type", "object"},
        {"properties", {
            {"property1", {"type", "string"}},
            {"patternProperty1.*", {"type", "object"}}
        }},
        {"additionalProperties", false},
        {"required", {"property1"}}
    };

    if (validateJSON(jsonObject, schema)) {
        cout << "The JSON object is valid according to the schema." << endl;
    } else {
        cout << "The JSON object is not valid according to the schema." << endl;
    }

    return 0;
}
