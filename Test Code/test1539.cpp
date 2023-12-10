#include <iostream>
#include <vector>
#include <algorithm>

class Point {
public:
    int x, y;

    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool compare(const Point &p1, const Point &p2, const Point &p) {
    int crossProduct = cross(p, p1, p2);
    if (crossProduct == 0) {
        return (p1.x - p.x) * (p1.x - p.x) + (p1.y - p.y) * (p1.y - p.y) < (p2.x - p.x) * (p2.x - p.x) + (p2.y - p.y) * (p2.y - p.y);
    }
    return crossProduct > 0;
}

void sortPoints(std::vector<Point> &points, const Point &p) {
    std::sort(points.begin(), points.end(), [&](const Point &p1, const Point &p2) {
        return compare(p1, p2, p);
    });
}

int main() {
    // Example usage
    std::vector<Point> points = {{1, 1}, {2, 3}, {3, 2}, {1, 3}, {2, 2}};
    Point referencePoint = {2, 2};
    sortPoints(points, referencePoint);
    for (const auto &point : points) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    return 0;
}
