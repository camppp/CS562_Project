#include <string>

bool isValidName(const std::string& name) {
    if (name.empty()) {
        return false;
    }

    for (const char& c : name) {
        if (c == '*' || c == '?' || c == ':' || c == '|' || c == '\\' || c == '/' || c == '<' || c == '>' || c == '"' || c == '.') {
            return false;
        }
    }

    if (name.length() > 255) {
        return false;
    }

    return true;
}
