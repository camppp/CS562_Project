#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x, y;
};

struct PairOfPointsWithDistance {
    Point p1, p2;
    double distance;
};

double Distance(const Point& a, const Point& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

PairOfPointsWithDistance FindClosestPairPointsInSubarray(
    const std::vector<Point>& points, int s, int e) {
    if (e - s <= 3) {
        return SolveByEnumerateAllPairs(points, s, e);
    }

    int mid = (s + e) / 2;
    PairOfPointsWithDistance left_closest = FindClosestPairPointsInSubarray(points, s, mid);
    PairOfPointsWithDistance right_closest = FindClosestPairPointsInSubarray(points, mid + 1, e);
    double min_distance = std::min(left_closest.distance, right_closest.distance);

    std::vector<Point> remain_points;
    for (int i = s; i <= e; ++i) {
        if (abs(points[i].x - points[mid].x) < min_distance) {
            remain_points.push_back(points[i]);
        }
    }

    PairOfPointsWithDistance closest_in_remain = FindClosestPairInRemain(&remain_points, min_distance);

    if (closest_in_remain.distance < min_distance) {
        return closest_in_remain;
    } else if (left_closest.distance < right_closest.distance) {
        return left_closest;
    } else {
        return right_closest;
    }
}

PairOfPointsWithDistance SolveByEnumerateAllPairs(const std::vector<Point>& points, int s, int e) {
    PairOfPointsWithDistance closest_pair;
    closest_pair.distance = std::numeric_limits<double>::max();

    for (int i = s; i <= e; ++i) {
        for (int j = i + 1; j <= e; ++j) {
            double dist = Distance(points[i], points[j]);
            if (dist < closest_pair.distance) {
                closest_pair.distance = dist;
                closest_pair.p1 = points[i];
                closest_pair.p2 = points[j];
            }
        }
    }

    return closest_pair;
}

PairOfPointsWithDistance FindClosestPairInRemain(std::vector<Point>* points, double d) {
    std::sort(points->begin(), points->end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });

    PairOfPointsWithDistance closest_pair;
    closest_pair.distance = std::numeric_limits<double>::max();

    for (size_t i = 0; i < points->size(); ++i) {
        for (size_t j = i + 1; j < points->size() && (points->at(j).y - points->at(i).y) < d; ++j) {
            double dist = Distance(points->at(i), points->at(j));
            if (dist < closest_pair.distance) {
                closest_pair.distance = dist;
                closest_pair.p1 = points->at(i);
                closest_pair.p2 = points->at(j);
            }
        }
    }

    return closest_pair;
}
