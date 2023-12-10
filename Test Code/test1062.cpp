void processNameValuePairs(const std::vector<std::pair<std::string, std::string>>& nameValuePairs, Te* te) {
    for (const auto& pair : nameValuePairs) {
        const std::string& name = pair.first;
        const std::string& value = pair.second;

        if (name == "UA:")
            te->uvwA.x() = std::stof(value);
        else if (name == "VA:")
            te->uvwA.y() = std::stof(value);
        else if (name == "WA:")
            te->uvwA.z() = std::stof(value);
        else if (name == "UO:")
            te->uvO.x() = std::stof(value);
        else if (name == "VO:")
            te->uvO.y() = std::stof(value);
    }
}
