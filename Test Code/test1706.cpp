#include <string>
#include <vector>

std::string alignNamespaceBraces(const std::string& code) {
    std::vector<std::string> lines = split(code, '\n');
    std::string result;
    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        if (line.find("namespace") != std::string::npos) {
            int start = line.find("{");
            int end = line.find("}");
            if (start != -1 && end != -1) {
                result += line.substr(0, start + 1);
                result += std::string(end - start - 1, ' ');
                result += line.substr(end + 1);
            }
        } else {
            result += line;
        }
    }
    return result;
}

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        result.push_back(token);
    }
    return result;
}
