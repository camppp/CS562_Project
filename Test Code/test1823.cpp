#include <vector>
#include <utility>

std::vector<std::pair<double, double>> calculateGridCellCenters(int resX, int resY) {
    std::vector<std::pair<double, double>> centers;
    for (int y = 0; y < resY; y++) {
        for (int x = 0; x < resX; x++) {
            double xCenter = (x + 0.5) / resX;
            double yCenter = (y + 0.5) / resY;
            centers.push_back(std::make_pair(xCenter, yCenter));
        }
    }
    return centers;
}
