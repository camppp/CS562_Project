#include <vector>
#include <tuple>
#include <cmath>

enum AccessPointType {
    LOCATION_AREA_ACCESSPOINT_GENERIC,
    LOCATION_AREA_ACCESSPOINT_ROAD,
    LOCATION_AREA_ACCESSPOINT_WATER,
    LOCATION_AREA_ACCESSPOINT_FOREST
};

std::pair<int, double> filterAndProcessAccessPoints(std::vector<std::tuple<int, std::pair<double, double>, double>> accessPoints, double areaRadiusB) {
    int totalAccessPoints = 0;
    double totalAngle = 0.0;

    for (const auto& accessPoint : accessPoints) {
        int type = std::get<0>(accessPoint);
        double posX = std::get<1>(accessPoint).first;
        double posY = std::get<1>(accessPoint).second;
        double angle = std::get<2>(accessPoint);

        // Calculate distance from the center
        double distance = std::sqrt(posX * posX + posY * posY);

        // Filter based on type and distance
        if (distance <= areaRadiusB && (type == LOCATION_AREA_ACCESSPOINT_ROAD || type == LOCATION_AREA_ACCESSPOINT_GENERIC)) {
            totalAccessPoints++;
            totalAngle += angle;
        }
    }

    // Calculate average angle
    double averageAngle = (totalAccessPoints > 0) ? (totalAngle / totalAccessPoints) : 0.0;

    return std::make_pair(totalAccessPoints, averageAngle);
}
