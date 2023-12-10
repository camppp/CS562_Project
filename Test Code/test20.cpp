#include <iostream>
#include <string>
#include <exception>

class CommandExecutionException : public std::exception {
private:
    std::string errorMessage;

public:
    CommandExecutionException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
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
