#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <cstdlib>

std::vector<std::string> executeCommands() {
    std::vector<std::string> output;
    
    // Read commands from the file
    std::ifstream file(_commands_file);
    if (file.is_open()) {
        std::string command;
        while (std::getline(file, command)) {
            // Append command-line arguments to the command
            for (const auto& arg : _args) {
                command += " " + arg;
            }
            // Execute the command and store the output
            std::ostringstream oss;
            FILE* pipe = popen(command.c_str(), "r");
            if (pipe) {
                char buffer[128];
                while (fgets(buffer, 128, pipe) != nullptr) {
                    oss << buffer;
                }
                pclose(pipe);
            }
            output.push_back(oss.str());
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << _commands_file << std::endl;
    }
    
    return output;
}
