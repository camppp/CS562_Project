#include <json/json.h>

bool validateJSONFile(Json::Value jRoot) {
    // Check if the JSON data is valid
    if (!jRoot.isValid()) {
        return false;
    }

    // Check if the JSON data is an object
    if (!jRoot.isObject()) {
        return false;
    }

    // Check if the JSON data has the required fields
    if (!jRoot.has("name") || !jRoot.has("age")) {
        return false;
    }

    // Check if the JSON data has the correct data types
    if (!jRoot["name"].isString() || !jRoot["age"].isInt()) {
        return false;
    }

    // Check if the JSON data has the correct values
    if (jRoot["name"].asString() != "John Doe" || jRoot["age"].asInt() != 30) {
        return false;
    }

    return true;
}
