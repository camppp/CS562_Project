std::pair<int, double> filterAndProcessAccessPoints(std::vector<std::tuple<int, std::pair<double, double>, double>> accessPoints, double areaRadiusB) {
    // Filter the access points based on their type and distance from the center of the area
    std::vector<std::tuple<int, std::pair<double, double>, double>> filteredAccessPoints;
    for (auto& accessPoint : accessPoints) {
        int type = std::get<0>(accessPoint);
        double distance = std::get<1>(accessPoint).distance(std::make_pair(areaRadiusB, areaRadiusB));
        if (type == LOCATION_AREA_ACCESSPOINT_ROAD || type == LOCATION_AREA_ACCESSPOINT_WATER || type == LOCATION_AREA_ACCESSPOINT_FOREST) {
            if (distance <= areaRadiusB) {
                filteredAccessPoints.push_back(accessPoint);
            }
        }
    }

    // Calculate the total number of access points within a certain distance from the center
    int totalAccessPoints = 0;
    for (auto& accessPoint : filteredAccessPoints) {
        totalAccessPoints++;
    }

    // Determine the average angle of the access points within the specified distance
    double averageAngle = 0;
    for (auto& accessPoint : filteredAccessPoints) {
        averageAngle += std::get<2>(accessPoint);
    }
    averageAngle /= totalAccessPoints;

    return std::make_pair(totalAccessPoints, averageAngle);
}
