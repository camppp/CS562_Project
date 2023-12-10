void logMessage(const std::string& message) {
    std::string dateStr = getCurrentFormattedDate();
    lout << dateStr << " " << message << std::endl;
}
