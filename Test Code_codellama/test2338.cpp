std::pair<std::string, std::string> processText(const std::vector<std::pair<int, std::string>>& commands) {
    std::string origin = "";
    std::string keyword = "";

    for (const auto& command : commands) {
        switch (command.first) {
            case 1:
                if (!origin.empty()) origin += " ";
                origin += command.second;
                break;
            case 2:
                if (!keyword.empty()) keyword += " ";
                keyword = "";
                break;
            case 3:
                keyword = "";
                break;
            default:
                break;
        }
    }

    return {origin, keyword};
}
