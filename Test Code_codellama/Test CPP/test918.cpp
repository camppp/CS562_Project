#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    // Read the directory containing the files
    std::string directory = "path/to/directory";
    std::vector<std::string> files;
    std::ifstream dir(directory);
    while (dir >> file) {
        files.push_back(file);
    }

    // Loop through each file and extract the file name and extension
    for (const auto& file : files) {
        std::string fileName = file.substr(0, file.find_last_of('.'));
        std::string fileExtension = file.substr(file.find_last_of('.') + 1);

        // Check if the file extension is ".txt"
        if (fileExtension == ".txt") {
            // Check if the file name matches the pattern using regular expressions
            std::regex pattern("^[a-zA-Z0-9]{3}");
            std::smatch match;
            if (std::regex_match(fileName, match, pattern)) {
                // Extract the motion number from the first 3 characters of the file name
                std::string motionNumber = fileName.substr(0, 3);

                // Print the motion number and file name
                std::cout << motionNumber << " " << fileName << std::endl;
            } else {
                // Print "motionfile" if the file name does not match the pattern
                std::cout << "motionfile" << std::endl;
            }
        }
    }

    return 0;
}
