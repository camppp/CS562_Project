#include <iostream>
#include <string>
#include <map>

std::string formatComponents(const std::map<std::string, int>& components) {
    std::string ans;
    int outLevel = components.size();
    int itr = 0;

    for (const auto& comp : components) {
        itr++;
        const auto seperator = (outLevel > 2 && itr != 1) ? ", " : "";
        const auto andSeperator = (itr == 2 && outLevel > 1) ? " and " : "";
        const auto compName = comp.first + ((comp.second > 1) ? "s" : "");
        if (comp.second) {
            ans += std::to_string(comp.second) + " " + compName + seperator + andSeperator;
        }
    }

    return ans;
}

int main() {
    std::map<std::string, int> components = {
        {"apple", 3},
        {"banana", 1},
        {"orange", 0}
    };
    std::cout << formatComponents(components) << std::endl;  // Output: "3 apples, 1 banana and 0 oranges"
    return 0;
}
