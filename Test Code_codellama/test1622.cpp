#include <string>

std::string extractDomainName(const std::string& url) {
    // Find the position of the first '/' after the protocol
    size_t pos = url.find('/', 8);

    // If there is no '/' after the protocol, return an empty string
    if (pos == std::string::npos) {
        return "";
    }

    // Find the position of the next '.' after the '/'
    pos = url.find('.', pos + 1);

    // If there is no '.' after the '/', return an empty string
    if (pos == std::string::npos) {
        return "";
    }

    // Return the substring of the domain name
    return url.substr(pos + 1);
}
