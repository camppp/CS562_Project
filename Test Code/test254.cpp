#include <iostream>
#include <map>
#include <string>

std::string formatComponents(const std::map<std::string, int>& components) {
    std::string result;
    bool first = true;
    for (const auto& [name, quantity] : components) {
        if (quantity > 0) {
            if (!first) {
                result += ", ";
            }
            first = false;
            result += std::to_string(quantity) + " " + name;
            if (quantity > 1) {
                result += "s";
            }
        }
    }
    if (!result.empty()) {
        result += " and ";
    }
    return result;
}

int main() {
    std::map<std::string, int> components = {
        {"apple", 3},
        {"banana", 1},
        {"orange", 0}
    };
    std::cout << formatComponents(components) << std::endl;
    return 0;
}
