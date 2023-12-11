#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>

std::map<std::string, std::pair<int, int>> parseHeaderFileStars(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: unable to open file " << filename << std::endl;
        return {};
    }

    std::map<std::string, std::pair<int, int>> header_stars;
    std::string line;
    while (std::getline(file, line)) {
        // Extract the header file path and star rating from the line
        std::string header_file_path = line.substr(line.find("<filename>") + 9, line.find("<gh_stars>") - line.find("<filename>") - 9);
        int lower_bound = std::stoi(line.substr(line.find("<gh_stars>") + 9, line.find("-") - line.find("<gh_stars>") - 9));
        int upper_bound = std::stoi(line.substr(line.find("-") + 1, line.find("</gh_stars>") - line.find("-") - 1));

        // Add the header file path and star rating to the map
        header_stars[header_file_path] = {lower_bound, upper_bound};
    }

    return header_stars;
}
