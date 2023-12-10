void logs::logMessage(const std::string& message) {
    if (lout.is_open()) {
        lout << getCurrentFormattedDate() << " " << message << std::endl;
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}
