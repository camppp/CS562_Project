void CLIAdapter::registerCommandHandler(const std::string& command, std::function<void(const std::vector<std::string>&)> handler) {
    commandHandlers[command] = handler;
}
