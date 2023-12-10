#include <string>

std::string processText(const std::string& text) {
    // Remove leading and trailing whitespace
    std::string trimmedText = text.trim();

    // Convert to lowercase
    std::string lowercaseText = trimmedText.toLower();

    // Replace "apple" with "orange"
    std::string modifiedText = lowercaseText.replace("apple", "orange");

    return modifiedText;
}
