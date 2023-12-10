#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

int cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool comparePoints(const Point &O, const Point &A, const Point &B) {
    return cross(O, A, B) > 0;
}

std::vector<Point> sortPoints(const std::vector<Point> &points) {
    Point origin = points[0];
    for (const auto &point : points) {
        if (point.y < origin.y || (point.y == origin.y && point.x < origin.x)) {
            origin = point;
        }
    }

    std::vector<Point> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [origin](const Point &A, const Point &B) {
        return comparePoints(origin, A, B);
    });

    return sortedPoints;
}

int main() {
    std::vector<Point> points = {{1, 1}, {2, 2}, {3, 3}, {1, 2}};
    std::vector<Point> sortedPoints = sortPoints(points);
    for (const auto &point : sortedPoints) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    return 0;
}
