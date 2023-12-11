#include <vector>
#include <tuple>
#include <cmath>
#include <numeric>

std::pair<int, double> filterAndProcessAccessPoints(std::vector<std::tuple<int, std::pair<double, double>, double>> accessPoints, double areaRadiusB) {
    double totalAngle = 0;
    int count = 0;

    for (auto& accessPoint : accessPoints) {
        double distance = std::sqrt(std::pow(std::get<1>(accessPoint).first, 2) + std::pow(std::get<1>(accessPoint).second, 2));
        if (distance <= areaRadiusB) {
            totalAngle += std::get<2>(accessPoint);
            count++;
        }
    }

    double averageAngle = count > 0? totalAngle / count : 0;

    return std::make_pair(count, averageAngle);
}