#include "rapidjson/document.h"

bool ValidateEngineNo(const rapidjson::Value& value) {
    if (value.HasMember("EngineNo") && !value["EngineNo"].IsNull() && value["EngineNo"].IsString()) {
        return true;
    }
    return false;
}
