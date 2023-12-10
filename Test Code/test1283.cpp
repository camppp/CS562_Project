#include <vector>
#include <utility>
#include <cmath>

class SimplifyLine {
public:
    std::vector<std::pair<int, int>> simplify(const std::vector<std::pair<int, int>>& line) {
        std::vector<std::pair<int, int>> simplifiedLine;
        for (int i = 0; i < line.size(); i++) {
            if (i == 0 || i == line.size() - 1) {
                simplifiedLine.push_back(line[i]);
            } else {
                if (std::abs(line[i].first - line[i - 1].first) > 1 ||
                    std::abs(line[i].second - line[i - 1].second) > 1) {
                    simplifiedLine.push_back(line[i]);
                }
            }
        }
        return simplifiedLine;
    }
};
