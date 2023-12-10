#include <vector>
#include <tuple>
#include <cmath>

std::pair<int, double> filterAndProcessAccessPoints(std::vector<std::tuple<int, std::pair<double, double>, double>> accessPoints, double areaRadiusB) {
    int totalAccessPoints = 0;
    double totalAngle = 0.0;

    for (const auto& point : accessPoints) {
        int type = std::get<0>(point);
        double posX = std::get<1>(point).first;
        double posY = std::get<1>(point).second;
        double distance = std::sqrt(posX * posX + posY * posY);
        double angle = std::get<2>(point);

        if (distance <= areaRadiusB) {
            totalAccessPoints++;
            totalAngle += angle;
        }
    }

    double averageAngle = totalAccessPoints > 0 ? totalAngle / totalAccessPoints : 0.0;
    return std::make_pair(totalAccessPoints, averageAngle);
}
