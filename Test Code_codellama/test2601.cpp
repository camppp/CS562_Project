void sendArraysObject(const std::vector<std::vector<std::string>>& arrays) {
    // Check if the arrays are empty
    if (arrays.empty()) {
        throw std::invalid_argument("Arrays are empty");
    }

    // Create a message to send to the remote server
    std::string message;
    for (const auto& array : arrays) {
        message += "[" + array.size() + "]";
        for (const auto& element : array) {
            message += "\"" + element + "\"";
        }
    }

    // Send the message to the remote server
    try {
        std::cout << "Sending message to remote server..." << std::endl;
        std::string response = sendMessage(message);
        std::cout << "Message sent successfully" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error sending message to remote server: " << e.what() << std::endl;
    }
}
