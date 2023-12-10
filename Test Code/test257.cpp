#include <iostream>
#include <boost/process.hpp>

namespace bp = boost::process;

int main() {
    std::string command;
    std::cout << "Enter the command to execute: ";
    std::getline(std::cin, command);

    try {
        bp::ipstream pipe_stream;
        bp::child c(command, bp::std_out > pipe_stream);

        std::string line;
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()) {
            std::cout << line << std::endl;
        }

        c.wait();
    } catch (const std::exception& e) {
        std::cerr << "Error executing command: " << e.what() << std::endl;
    }

    return 0;
}
