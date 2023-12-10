string getHelpMessage(string command) {
    if (command == "/help" || command == "/h") {
        return "Display list of available commands";
    } else {
        return "Invalid command";
    }
}
