#include <string>

std::string modifyString(const std::string& input) {
    std::string result = input;
    size_t pos = result.find("EditorDoubleValue::");
    if (pos != std::string::npos) {
        result.replace(pos, 18, "UpdatedValue::");
    }
    pos = result.find("//");
    if (pos != std::string::npos) {
        result.replace(pos, 2, "##");
    }
    return result;
}
