#include <iostream>
#include <vector>

using namespace std;

tuple<int, int> find_missing_point(const vector<int>& x, const vector<int>& y) {
    // Check if the input vectors are valid
    if (x.size() != 3 || y.size() != 3) {
        throw invalid_argument("Input vectors must have size 3");
    }

    // Calculate the slope of the two lines formed by the three points
    double slope1 = (y[1] - y[0]) / (x[1] - x[0]);
    double slope2 = (y[2] - y[1]) / (x[2] - x[1]);

    // Calculate the intersection point of the two lines
    int x_intersection = (slope1 * x[1] - slope2 * x[2]) / (slope1 - slope2);
    int y_intersection = slope1 * (x_intersection - x[1]) + y[1];

    // Return the coordinates of the missing point
    return make_tuple(x_intersection, y_intersection);
}

int main() {
    vector<int> x = {1, 1, 2};
    vector<int> y = {4, 1, 1};

    tuple<int, int> missing_point = find_missing_point(x, y);

    cout << "Missing point: (" << get<0>(missing_point) << ", " << get<1>(missing_point) << ")" << endl;

    return 0;
}
