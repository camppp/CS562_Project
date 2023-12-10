#include <iostream>
#include <string>

std::string getBoostLicenseVersion(const std::string& code) {
    std::string license = "Boost Software License";
    std::string version = "Version 1.0";

    size_t pos = code.find(license);
    if (pos != std::string::npos) {
        pos += license.size() + 1; // skip over the comma
        size_t end = code.find(')', pos);
        if (end != std::string::npos) {
            std::string version_str = code.substr(pos, end - pos);
            if (version_str == version) {
                return version_str;
            }
        }
    }

    return "License information not found";
}

int main() {
    std::string code = "// Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)";
    std::cout << getBoostLicenseVersion(code) << std::endl;

    code = "// Distributed under the Some Other License";
    std::cout << getBoostLicenseVersion(code) << std::endl;

    return 0;
}
