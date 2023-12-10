int FireStepSerial::executeCore(const std::string &request, std::string &response) {
    if (request == "status") {
        response = "System is operational";
    } else if (request == "move up") {
        response = "Moving up";
    } else if (request == "move down") {
        response = "Moving down";
    } else if (request == "stop") {
        response = "Stopping movement";
    } else if (request == "reset") {
        response = "Resetting system";
    } else {
        response = "Invalid command";
    }
    return 0; // Assuming 0 indicates successful execution
}
