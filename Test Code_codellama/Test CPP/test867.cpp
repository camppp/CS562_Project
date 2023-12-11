#include <iostream>
#include <vector>
#include <cmath>

double calculatePolygonArea(const std::vector<std::pair<double, double>>& vertices) {
    if (vertices.empty() || vertices.size() < 3) {
        return 0;
    }

    double area = 0;
    for (int i = 0; i < vertices.size() - 1; i++) {
        area += (vertices[i].first * vertices[i + 1].second - vertices[i + 1].first * vertices[i].second);
    }

    return fabs(area) / 2;
}

int main() {
    std::vector<std::pair<double, double>> vertices = {
        {0, 0}, {4, 0}, {4, 3}, {0, 3}
    };

    std::cout << "Area of the polygon: " << calculatePolygonArea(vertices) << std::endl;

    return 0;
}
