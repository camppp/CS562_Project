#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> point;
vector<int> x, y;
int n;
bool done[1<<15];
double area[1<<15];

double crossProduct(const point& O, const point& A, const point& B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

double distance(const point& A, const point& B) {
    return hypot(B.first - A.first, B.second - A.second);
}

double calculateConvexHullArea() {
    vector<point> points;
    for (int i = 0; i < n; i++) {
        points.push_back(make_pair(x[i], y[i]));
    }
    sort(points.begin(), points.end());

    int k = 0;
    vector<point> hull(2 * n);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && crossProduct(hull[k - 2], hull[k - 1], points[i]) <= 0) {
            k--;
        }
        hull[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && crossProduct(hull[k - 2], hull[k - 1], points[i]) <= 0) {
            k--;
        }
        hull[k++] = points[i];
    }

    hull.resize(k - 1);

    double hullArea = 0.0;
    for (int i = 0; i < k - 1; i++) {
        hullArea += crossProduct(hull[0], hull[i], hull[i + 1]);
    }
    return abs(hullArea) / 2.0;
}

int main() {
    // Input points and initialize n, x, y
    // ...
    double convexHullArea = calculateConvexHullArea();
    cout << "Area of the convex hull: " << convexHullArea << endl;
    return 0;
}
