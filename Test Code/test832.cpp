#include <iostream>
#include <string>

std::string getHelpMessage(std::string command) {
    if (command == "/help" || command == "/h") {
        return "Display list of available commands";
    } else {
        return "Invalid command";
    }
}

int main() {
    std::cout << getHelpMessage("/help") << std::endl;  // Output: "Display list of available commands"
    std::cout << getHelpMessage("/h") << std::endl;     // Output: "Display list of available commands"
    std::cout << getHelpMessage("/start") << std::endl; // Output: "Invalid command"
    return 0;
}
