void handlePreProcessReplyMsg(const std::shared_ptr<PreProcessReplyMsg>& msg) {
    // Extract the data from the message
    std::string data = msg->getData();

    // Print the extracted data to the console
    std::cout << "Received data: " << data << std::endl;

    // Calculate and print the length of the extracted data
    std::cout << "Length of data: " << data.length() << std::endl;
}
