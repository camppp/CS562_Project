#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <regex>

std::map<std::string, std::pair<int, int>> parseHeaderFileStars(const std::string& filename) {
    std::map<std::string, std::pair<int, int>> headerStarsMap;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::smatch match;
            std::regex pattern("<filename>(.*?)<gh_stars>(\\d+)-(\\d+)");
            if (std::regex_search(line, match, pattern)) {
                std::string headerFilePath = match[1];
                int lowerBound = std::stoi(match[2]);
                int upperBound = std::stoi(match[3]);
                headerStarsMap[headerFilePath] = std::make_pair(lowerBound, upperBound);
            }
        }
        file.close();
    }
    return headerStarsMap;
}
