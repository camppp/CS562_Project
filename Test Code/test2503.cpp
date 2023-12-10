#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream fin("verification_times.txt");
    if (!fin) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::map<std::string, double> timeMap;
    std::string stage;
    double time;

    while (fin >> stage >> time) {
        timeMap[stage] += time;
    }

    for (auto& entry : timeMap) {
        entry.second /= 1.0;  // Assuming there is a valid count for each stage
        std::cout << "Average time for " << entry.first << ": " << entry.second << " milliseconds" << std::endl;
    }

    auto maxTimeStage = std::max_element(timeMap.begin(), timeMap.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "Stage with longest time: " << maxTimeStage->first << " (" << maxTimeStage->second << " milliseconds)" << std::endl;

    return 0;
}
