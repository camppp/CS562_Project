#include <iostream>
#include <sstream>
#include <string>

void parseFailureConnectionCondition(const std::string& input, std::string& name) {
    std::stringstream stream(input);
    char discard; // To discard characters like '#', '=', '(', etc.

    // Discard the initial characters until the opening parenthesis
    while (stream >> discard && discard != '(') {}

    // Read the name until the next comma
    std::getline(stream, name, ',');

    // Remove leading and trailing whitespaces from the extracted name
    name.erase(0, name.find_first_not_of(" \t\n\v\f\r"));
    name.erase(name.find_last_not_of(" \t\n\v\f\r") + 1);
}

int main() {
    std::string input = "#123= IFCFAILURECONNECTIONCONDITION(Example Failure Condition, ...";
    std::string name;
    parseFailureConnectionCondition(input, name);
    std::cout << "Name of the failure connection condition: " << name << std::endl;
    return 0;
}
