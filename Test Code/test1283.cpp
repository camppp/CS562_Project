#include <vector>
#include <utility>
#include <cmath>

class SimplifyLine {
public:
    std::vector<std::pair<int, int>> simplify(const std::vector<std::pair<int, int>>& line) {
        std::vector<std::pair<int, int>> simplifiedLine;
        if (line.size() < 2) {
            return line;
        }
        
        simplifiedLine.push_back(line[0]);
        for (size_t i = 1; i < line.size() - 1; ++i) {
            if (!isCollinear(line[i - 1], line[i], line[i + 1])) {
                simplifiedLine.push_back(line[i]);
            }
        }
        simplifiedLine.push_back(line.back());
        
        return simplifiedLine;
    }

private:
    bool isCollinear(const std::pair<int, int>& p1, const std::pair<int, int>& p2, const std::pair<int, int>& p3) {
        return (p2.second - p1.second) * (p3.first - p2.first) == (p3.second - p2.second) * (p2.first - p1.first);
    }
};
