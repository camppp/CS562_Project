void handlePreProcessReplyMsg(const PreProcessReplyMsgSharedPtr& preProcessReplyMsg) {
    // Extract the data from the PreProcessReplyMsg object
    std::string data = preProcessReplyMsg->getData();

    // Print the extracted data to the console
    std::cout << "Extracted data: " << data << std::endl;

    // Calculate and print the length of the extracted data
    std::cout << "Length of extracted data: " << data.length() << std::endl;
}
