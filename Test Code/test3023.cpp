#include <string>
#include <cctype>

std::string generateHeaderGuard(const std::string& fileName) {
    std::string guardIdentifier = "INCLUDED_";
    for (char c : fileName) {
        if (std::isalnum(c)) {
            guardIdentifier += std::toupper(c);
        } else {
            guardIdentifier += '_';
        }
    }
    return guardIdentifier;
}
