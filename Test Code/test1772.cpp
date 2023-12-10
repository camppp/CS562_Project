#include <string>

std::string convertString(const std::string& inputStr) {
    std::string outputStr;
    outputStr.reserve(inputStr.size() + 2);
    outputStr.push_back(std::toupper(inputStr[0]));
    outputStr.append(inputStr.substr(1, inputStr.size() - 2));
    outputStr.push_back(std::toupper(inputStr[inputStr.size() - 1]));
    return outputStr;
}
