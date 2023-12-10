#include <string>
#include <algorithm>

std::string extractHeaderFileName(const std::string& fileContent) {
    // Find the last occurrence of the forward slash '/'
    auto slashPos = fileContent.find_last_of('/');

    // If the forward slash is not found, return an empty string
    if (slashPos == std::string::npos) {
        return "";
    }

    // Find the first occurrence of the "hpp" suffix
    auto hppPos = fileContent.find(".hpp");

    // If the "hpp" suffix is not found, return an empty string
    if (hppPos == std::string::npos) {
        return "";
    }

    // Return the substring between the last occurrence of the forward slash and the "hpp" suffix
    return fileContent.substr(slashPos + 1, hppPos - slashPos - 1);
}
