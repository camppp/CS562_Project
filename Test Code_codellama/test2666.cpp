void processMessage(const std::string& message) {
    // Echo the received message as the response
    std::string response = message;
    std::cout << "Processed message: " << message << std::endl;
    return response;
}
