#include <iostream>
#include <cmath>

using namespace std;

// Structure to represent a 3D point
struct Point {
    double x, y, z;
};

// Function to calculate the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// Function to find the shortest distance between two points
tuple<Point, Point, double> find_shortest_distance(const vector<Point>& points) {
    double min_distance = INFINITY;
    Point p1, p2;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            double distance = distance(points[i], points[j]);
            if (distance < min_distance) {
                min_distance = distance;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    return make_tuple(p1, p2, min_distance);
}

int main() {
    vector<Point> points = {
        {25, 93, -46},
        {33, 93, -40},
        {41, 88, -44},
        {33, 90, -58},
        {17, 114, 122},
        {15, 122, 113},
        {0, 123, 115},
        {0, 118, 123},
        {30, 109, 120},
        {22, 121, 111},
        {34, 108, 112},
        {25, 120, 97},
        {33, 103, 83},
        {23, 118, 79}
    };

    tuple<Point, Point, double> result = find_shortest_distance(points);
    cout << "The shortest distance between " << get<0>(result) << " and " << get<1>(result) << " is " << get<2>(result) << "." << endl;

    return 0;
}
