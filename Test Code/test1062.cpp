void processNameValuePairs(const std::vector<std::pair<std::string, std::string>>& nameValuePairs, Te* te) {
    for (const auto& pair : nameValuePairs) {
        const std::string& name = pair.first;
        const std::string& value = pair.second;
        if (name == "UA:") {
            te->uvwA.x = lexical_cast<float>(value);
        } else if (name == "VA:") {
            te->uvwA.y = lexical_cast<float>(value);
        } else if (name == "WA:") {
            te->uvwA.z = lexical_cast<float>(value);
        } else if (name == "UO:") {
            te->uvO.x = lexical_cast<float>(value);
        } else if (name == "VO:") {
            te->uvO.y = lexical_cast<float>(value);
        }
    }
}
