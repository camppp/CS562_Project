#include <iostream>
#include <map>
#include <regex>
#include <string>

std::map<std::string, std::string> parseFileHeader(const std::string& fileContent) {
    std::map<std::string, std::string> metadata;

    std::regex pattern("@file\\s(\\S+)|@brief\\s(.+)|@author\\s(.+)|Copyright\\s(\\d+-\\d+)\\s(.+)");
    std::smatch matches;

    std::string::const_iterator searchStart(fileContent.cbegin());
    while (std::regex_search(searchStart, fileContent.cend(), matches, pattern)) {
        if (matches[1].matched) {
            metadata["file"] = matches[1];
        } else if (matches[2].matched) {
            metadata["brief"] = matches[2];
        } else if (matches[3].matched) {
            metadata["author"] = matches[3];
        } else if (matches[4].matched) {
            metadata["copyright"] = matches[4] + " " + matches[5];
        }
        searchStart = matches.suffix().first;
    }

    return metadata;
}

int main() {
    std::string fileContent = " *  @file example.cpp\n *  @brief Example file for parsing file headers\n *  @author John Doe\n *  Copyright 2010-2023 Acme Corp. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)";
    std::map<std::string, std::string> metadata = parseFileHeader(fileContent);

    for (const auto& entry : metadata) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
