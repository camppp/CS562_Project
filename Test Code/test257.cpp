#include <iostream>
#include <boost/process.hpp>

int main() {
    // Prompt the user to input a command to execute
    std::cout << "Enter a command to execute: ";
    std::string command;
    std::getline(std::cin, command);

    // Use the Boost.Process library to execute the command
    boost::process::child c(command);

    // Capture the standard output of the executed command
    std::string output;
    c.get_stdout(output);

    // Display the captured output to the user
    std::cout << "Output of command: " << output << std::endl;

    // Handle any potential errors that may occur during the command execution or output capture
    if (c.get_exit_code() != 0) {
        std::cerr << "Error executing command: " << c.get_exit_code() << std::endl;
    }

    return 0;
}
