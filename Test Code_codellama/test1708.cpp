#include <string>
#include <tuple>

std::tuple<std::string, std::string> extractLicenseInfo(const std::string& header) {
    std::string copyright;
    std::string license;

    // Find the first occurrence of "Copyright :"
    size_t pos = header.find("Copyright :");
    if (pos != std::string::npos) {
        // Extract the copyright information
        copyright = header.substr(pos + 11); // 11 is the length of "Copyright :"
    }

    // Find the first occurrence of "SPDX-License-Identifier:"
    pos = header.find("SPDX-License-Identifier:");
    if (pos != std::string::npos) {
        // Extract the SPDX license identifier
        license = header.substr(pos + 22); // 22 is the length of "SPDX-License-Identifier:"
    }

    return std::make_tuple(copyright, license);
}
