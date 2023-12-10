#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

// Utility function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return lowerStr;
}

// Utility function to print with indentation
void print(int indent, const std::string& str) {
    std::cout << std::string(indent, ' ') << str << std::endl;
}

// Definition of EnumItems
using EnumItems = std::vector<int>;

// Function to generate the string map for the enumeration
void generateStringMap(const EnumItems &enumItems, std::string displayName) {
    std::string variableName = toLower(displayName) + "Names";
    print(0, "const std::map<", displayName, ", std::string> ", variableName, "({");
    for (const auto& value : enumItems) {
        // Assuming getDisplayName is a function that retrieves the display name for the enumeration value
        std::string enumDisplayName = getDisplayName(value);
        print(4, "{", value, ", \"", enumDisplayName, "\"},");
    }
    print(0, "});");
}

// Example usage
int main() {
    EnumItems enumItems = {1, 2, 3};
    generateStringMap(enumItems, "EnumType");
    return 0;
}
