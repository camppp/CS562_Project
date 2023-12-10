#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> modifyTags(const std::vector<std::string>& tag_list) {
    std::vector<std::string> modified_tags;
    for (const auto& tag : tag_list) {
        // Find the position of the first colon
        size_t colon_pos = tag.find(':');
        if (colon_pos != std::string::npos) {
            // Extract the tag name after the colon and space
            std::string modified_tag = tag.substr(colon_pos + 2);
            modified_tags.push_back(modified_tag);
        }
    }
    return modified_tags;
}

int main() {
    std::vector<std::string> tag_list = {"Tag 1: Apple", "Tag 2: Banana", "Tag 3: Orange"};
    std::vector<std::string> modified_tags = modifyTags(tag_list);
    for (const auto& tag : modified_tags) {
        std::cout << tag << std::endl;
    }
    return 0;
}
