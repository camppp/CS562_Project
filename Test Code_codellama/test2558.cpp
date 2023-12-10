#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> parseFileHeader(const std::string& fileContent) {
    std::map<std::string, std::string> metadata;

    // Find the first line of the file that starts with " *  @file"
    size_t fileLineIndex = fileContent.find(" *  @file");
    if (fileLineIndex != std::string::npos) {
        // Extract the file name from the line
        size_t fileStartIndex = fileLineIndex + 7; // " *  @file" has 7 characters
        size_t fileEndIndex = fileContent.find(' ', fileStartIndex);
        std::string file = fileContent.substr(fileStartIndex, fileEndIndex - fileStartIndex);

        // Add the file name to the metadata map
        metadata["file"] = file;
    }

    // Find the first line of the file that starts with " *  @brief"
    size_t briefLineIndex = fileContent.find(" *  @brief");
    if (briefLineIndex != std::string::npos) {
        // Extract the brief description from the line
        size_t briefStartIndex = briefLineIndex + 8; // " *  @brief" has 8 characters
        size_t briefEndIndex = fileContent.find(' ', briefStartIndex);
        std::string brief = fileContent.substr(briefStartIndex, briefEndIndex - briefStartIndex);

        // Add the brief description to the metadata map
        metadata["brief"] = brief;
    }

    // Find the first line of the file that starts with " *  @author"
    size_t authorLineIndex = fileContent.find(" *  @author");
    if (authorLineIndex != std::string::npos) {
        // Extract the author's name from the line
        size_t authorStartIndex = authorLineIndex + 9; // " *  @author" has 9 characters
        size_t authorEndIndex = fileContent.find(' ', authorStartIndex);
        std::string author = fileContent.substr(authorStartIndex, authorEndIndex - authorStartIndex);

        // Add the author's name to the metadata map
        metadata["author"] = author;
    }

    // Find the first line of the file that starts with " *  Copyright"
    size_t copyrightLineIndex = fileContent.find(" *  Copyright");
    if (copyrightLineIndex != std::string::npos) {
        // Extract the copyright information from the line
        size_t copyrightStartIndex = copyrightLineIndex + 11; // " *  Copyright" has 11 characters
        size_t copyrightEndIndex = fileContent.find(' ', copyrightStartIndex);
        std::string copyright = fileContent.substr(copyrightStartIndex, copyrightEndIndex - copyrightStartIndex);

        // Add the copyright information to the metadata map
        metadata["copyright"] = copyright;
    }

    return metadata;
}
