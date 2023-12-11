#include <iostream>
#include <string>

int main() {
    std::string licenseType;
    std::string licenseVersion;

    // Read the license information from the comment block
    std::string commentBlock = "This file is part of LSPosed.\n\nLSPosed is free software: you can redistribute it and/or modify\n"
                                "it under the terms of the GNU General Public License as published by\n"
                                "the Free Software Foundation, either version 3 of the License, or\n"
                                "(at your option) any later version.";

    // Extract the license type and version from the comment block
    size_t pos = commentBlock.find("GNU General Public License");
    if (pos != std::string::npos) {
        licenseType = "GNU General Public License";
        pos = commentBlock.find("version", pos);
        if (pos != std::string::npos) {
            licenseVersion = commentBlock.substr(pos + 8, 1);
        }
    }

    // Output the license type and version
    std::cout << "License Type: " << licenseType << std::endl;
    std::cout << "License Version: " << licenseVersion << std::endl;

    return 0;
}
