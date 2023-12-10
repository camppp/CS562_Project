#include <vector>
#include <utility>

std::vector<std::pair<double, double>> calculateGridCellCenters(int resX, int resY) {
    std::vector<std::pair<double, double>> centers;
    for (int j = 0; j < resY; j++) {
        for (int i = 0; i < resX; i++) {
            double x = ((double)i + 0.5) / (double)resX;
            double y = ((double)j + 0.5) / (double)resY;
            centers.push_back(std::make_pair(x, y));
        }
    }
    return centers;
}
