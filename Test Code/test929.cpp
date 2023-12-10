#include <vector>
#include <unordered_map>

struct Point {
    int x;
    int y;
};

int countOverlappingPoints(std::vector<Point>& points) {
    int overlap = 0;
    std::unordered_map<std::pair<int, int>, int> pointCount;

    for (const auto& p : points) {
        pointCount[{p.x, p.y}]++;
    }

    for (const auto& pair : pointCount) {
        if (pair.second > 1) {
            overlap += pair.second - 1;
        }
    }

    return overlap;
}
