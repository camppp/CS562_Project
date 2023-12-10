#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> executeCommands() {
    // Open the file containing the commands
    std::ifstream commandsFile(_commands_file);

    // Read the commands from the file
    std::string line;
    while (std::getline(commandsFile, line)) {
        _commands.push_back(line);
    }

    // Append any command-line arguments to the list of commands
    for (const auto& arg : _args) {
        _commands.push_back(arg);
    }

    // Execute the commands
    std::vector<std::string> output;
    for (const auto& command : _commands) {
        std::stringstream ss;
        ss << command;
        std::string outputLine;
        while (std::getline(ss, outputLine)) {
            output.push_back(outputLine);
        }
    }

    return output;
}
