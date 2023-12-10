#include <cmath>
#include <vector>

using namespace std;

float calculate_polygon_area(const vector<pair<float, float>>& vertices) {
    float area = 0;
    for (int i = 0; i < vertices.size(); i++) {
        int j = (i + 1) % vertices.size();
        area += fabs(vertices[i].first * vertices[j].second - vertices[j].first * vertices[i].second);
    }
    return area / 2;
}
