#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

int main() {
    std::string directoryPath = "path_to_directory";  // Replace with the actual directory path
    std::regex rx2("pattern2");  // Replace with the actual regular expression pattern
    std::regex rx3("pattern3");  // Replace with the actual regular expression pattern

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::string fileName = entry.path().filename().string();
            std::string fileExtension = entry.path().extension().string();

            if (fileExtension == ".txt") {
                std::smatch m;
                if (std::regex_search(fileName, m, rx3)) {
                    int motion_no = std::stoi(fileName.substr(0, 3));
                    std::cout << fileName << ": No." << motion_no << std::endl;
                } else if (std::regex_search(fileName, m, rx2)) {
                    std::cout << "motionfile" << std::endl;
                }
            }
        }
    }

    return 0;
}
