// adpt.cpp
#include "pch.h"
#include "adpt.h"
#include <iostream>
#include <sstream>

void CLIAdapter::registerCommandHandler(const std::string& command, std::function<void(const std::vector<std::string>&)> handler) {
    commandHandlers[command] = handler;
}

void CLIAdapter::parseAndExecuteCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string command;
    iss >> command;

    if (commandHandlers.find(command) != commandHandlers.end()) {
        std::vector<std::string> parameters;
        std::string parameter;
        while (iss >> parameter) {
            parameters.push_back(parameter);
        }
        commandHandlers[command](parameters);
    } else {
        std::cout << "Command not found: " << command << std::endl;
    }
}

void CLIAdapter::displayHelp() const {
    std::cout << "Available commands:" << std::endl;
    for (const auto& pair : commandHandlers) {
        std::cout << pair.first << std::endl;
    }
}
