#include <iostream>
#include <vector>
#include <string>
#include <map>

std::pair<std::map<std::string, std::string>, std::vector<std::string>> parseArguments(const std::vector<std::string>& arguments) {
    std::map<std::string, std::string> parsedOptions;
    std::vector<std::string> standaloneArguments;

    for (size_t i = 1; i < arguments.size(); ++i) {
        if (arguments[i].find("--") == 0) {
            size_t pos = arguments[i].find('=');
            if (pos != std::string::npos) {
                std::string key = arguments[i].substr(2, pos - 2);
                std::string value = arguments[i].substr(pos + 1);
                parsedOptions[key] = value;
            } else {
                parsedOptions[arguments[i].substr(2)] = arguments[i + 1];
                ++i;
            }
        } else if (arguments[i].find('-') == 0) {
            parsedOptions[arguments[i].substr(1)] = arguments[i + 1];
            ++i;
        } else {
            standaloneArguments.push_back(arguments[i]);
        }
    }

    return {parsedOptions, standaloneArguments};
}

int main() {
    std::vector<std::string> input = {"./program", "-f", "file.txt", "--output=output.txt", "arg1", "arg2"};
    auto result = parseArguments(input);

    std::cout << "Parsed options:" << std::endl;
    for (const auto& pair : result.first) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Standalone arguments:" << std::endl;
    for (const auto& arg : result.second) {
        std::cout << arg << std::endl;
    }

    return 0;
}
