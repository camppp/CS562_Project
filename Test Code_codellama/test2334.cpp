std::vector<std::string> modifyTags(const std::vector<std::string>& tag_list) {
    std::vector<std::string> modified_tags;
    for (const auto& tag : tag_list) {
        std::string modified_tag = tag.substr(tag.find(':') + 1);
        modified_tags.push_back(modified_tag);
    }
    return modified_tags;
}
