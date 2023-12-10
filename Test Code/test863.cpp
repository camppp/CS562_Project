#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "tcp_server.h"

class ArithmeticHandler : public tcp_server::request_handler {
public:
    std::string handle_request(const std::string& request) override {
        std::istringstream iss(request);
        std::string operation;
        int operand1, operand2;
        iss >> operation >> operand1 >> operand2;

        if (operation == "add") {
            return std::to_string(operand1 + operand2);
        } else if (operation == "subtract") {
            return std::to_string(operand1 - operand2);
        } else if (operation == "multiply") {
            return std::to_string(operand1 * operand2);
        } else if (operation == "divide") {
            if (operand2 != 0) {
                return std::to_string(operand1 / operand2);
            } else {
                return "Error: Division by zero";
            }
        } else {
            return "Error: Invalid operation";
        }
    }
};

int main() {
    const int PORT = 18811;
    tcp_server server(PORT, std::make_shared<ArithmeticHandler>());
    server.run();
    return 0;
}
