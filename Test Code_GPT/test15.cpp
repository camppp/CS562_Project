#include <iostream>
#include <stdexcept>
#include <string>

class CommandExecutionException : public std::exception {
public:
    CommandExecutionException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

class Command {
public:
    void execute() {
        throw CommandExecutionException("Error executing command: Invalid input");
    }
};

int main() {
    try {
        Command cmd;
        cmd.execute();
    } catch (const CommandExecutionException& ex) {
        std::cerr << "Command execution error: " << ex.what() << std::endl;
    }

    return 0;
}
