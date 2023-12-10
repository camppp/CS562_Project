#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <cctype>

class ConfigurationParser {
private:
    std::unordered_map<std::string, std::string> configMap;

    void trim(std::string& str) {
        str.erase(0, str.find_first_not_of(" \t\r\n"));
        str.erase(str.find_last_not_of(" \t\r\n") + 1);
    }

public:
    ConfigurationParser(const std::string& filePath) {
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line.empty() || line[0] == '#') {
                    continue;  // Ignore comments and empty lines
                }
                size_t delimiterPos = line.find('=');
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);
                    trim(key);
                    trim(value);
                    configMap[key] = value;
                }
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << filePath << std::endl;
        }
    }

    std::string getValue(const std::string& key) {
        auto it = configMap.find(key);
        if (it != configMap.end()) {
            return it->second;
        }
        return "null";
    }
};

int main() {
    ConfigurationParser parser("config.txt");
    std::cout << "Value of key1: " << parser.getValue("key1") << std::endl;
    std::cout << "Value of key2: " << parser.getValue("key2") << std::endl;
    std::cout << "Value of key3: " << parser.getValue("key3") << std::endl;
    std::cout << "Value of key4: " << parser.getValue("key4") << std::endl;
    return 0;
}
