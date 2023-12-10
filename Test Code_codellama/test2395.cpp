c
#include <iostream>
#include <string>
#include <utility>

std::pair<std::string, std::string> parseHeaderFile(const std::string& headerContent) {
    std::string macroDefinition;
    std::string uniqueIdentifier;

    // Iterate over the lines of the header file
    for (const auto& line : headerContent) {
        // Check if the line contains a macro definition
        if (line.find("#define") != std::string::npos) {
            // Extract the macro definition from the line
            macroDefinition = line.substr(line.find("#define") + 7);
        }

        // Check if the line contains the unique identifier string
        if (line.find("IDSTR") != std::string::npos) {
            // Extract the unique identifier string from the line
            uniqueIdentifier = line.substr(line.find("IDSTR") + 6);
        }
    }

    // Return the extracted macro definition and unique identifier string
    return std::make_pair(macroDefinition, uniqueIdentifier);
}
