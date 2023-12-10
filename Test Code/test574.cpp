#include <vector>
#include <string>
#include <unordered_set>

std::vector<std::string> findForbiddenTags(const std::vector<std::string>& iwyuPragmas) {
    std::unordered_set<std::string> forbiddenTagsSet;
    for (const std::string& pragma : iwyuPragmas) {
        size_t startPos = pragma.find("no_forward_declare");
        if (startPos != std::string::npos) {
            size_t tagStartPos = pragma.find("::", startPos);
            if (tagStartPos != std::string::npos) {
                size_t tagEndPos = pragma.find(" ", tagStartPos);
                if (tagEndPos != std::string::npos) {
                    std::string tag = pragma.substr(tagStartPos, tagEndPos - tagStartPos);
                    forbiddenTagsSet.insert(tag);
                }
            }
        }
    }
    return std::vector<std::string>(forbiddenTagsSet.begin(), forbiddenTagsSet.end());
}
