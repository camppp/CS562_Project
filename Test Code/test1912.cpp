#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

struct Line {
    Point start, end;
};

bool onSegment(const Point& p, const Point& q, const Point& r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)) {
        return true;
    }
    return false;
}

int orientation(const Point& p, const Point& q, const Point& r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (std::abs(val) < 1e-9) {
        return 0;  // Collinear
    }
    return (val > 0) ? 1 : 2;  // Clockwise or counterclockwise
}

bool doIntersect(const Line& l1, const Line& l2) {
    int o1 = orientation(l1.start, l1.end, l2.start);
    int o2 = orientation(l1.start, l1.end, l2.end);
    int o3 = orientation(l2.start, l2.end, l1.start);
    int o4 = orientation(l2.start, l2.end, l1.end);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && onSegment(l1.start, l2.start, l1.end)) {
        return true;
    }

    if (o2 == 0 && onSegment(l1.start, l2.end, l1.end)) {
        return true;
    }

    if (o3 == 0 && onSegment(l2.start, l1.start, l2.end)) {
        return true;
    }

    if (o4 == 0 && onSegment(l2.start, l1.end, l2.end)) {
        return true;
    }

    return false;
}

size_t countSelfIntersections(const std::vector<Point>& polygon) {
    size_t count = 0;
    size_t n = polygon.size();

    for (size_t i = 0; i < n; i++) {
        Line current = {polygon[i], polygon[(i + 1) % n]};
        for (size_t j = i + 1; j < n; j++) {
            Line other = {polygon[j], polygon[(j + 1) % n]};
            if (doIntersect(current, other)) {
                count++;
            }
        }
    }

    return count;
}
