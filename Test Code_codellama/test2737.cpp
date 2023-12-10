#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& s, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ss(s);
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}
