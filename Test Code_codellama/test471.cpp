#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> point;

vector<int> x, y;
int n;
bool done[1<<15];
double area[1<<15];

double calculateConvexHullArea() {
    // Initialize the area array with 0
    for (int i = 0; i < (1<<15); i++) {
        area[i] = 0;
    }

    // Sort the points based on their x-coordinates
    sort(x.begin(), x.end());

    // Initialize the done array with false
    for (int i = 0; i < (1<<15); i++) {
        done[i] = false;
    }

    // Calculate the area of the convex hull for different subsets of points
    for (int i = 0; i < n; i++) {
        // Calculate the area of the convex hull for the current point
        area[i] = calculateConvexHullAreaHelper(i);
    }

    // Return the maximum area of the convex hull
    return *max_element(area, area + (1<<15));
}

double calculateConvexHullAreaHelper(int i) {
    // If the current point has already been processed, return 0
    if (done[i]) {
        return 0;
    }

    // Mark the current point as processed
    done[i] = true;

    // Calculate the area of the convex hull for the current point
    double area = 0;
    for (int j = i + 1; j < n; j++) {
        if (!done[j]) {
            area += calculateTriangleArea(x[i], y[i], x[j], y[j]);
        }
    }

    // Recursively calculate the area of the convex hull for the remaining points
    for (int j = i + 1; j < n; j++) {
        if (!done[j]) {
            area += calculateConvexHullAreaHelper(j);
        }
    }

    return area;
}

double calculateTriangleArea(int x1, int y1, int x2, int y2) {
    return 0.5 * fabs(x1 * y2 - x2 * y1);
}
