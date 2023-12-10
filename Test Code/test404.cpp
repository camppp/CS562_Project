std::vector<Point> sortPoints(const std::vector<Point> &points) {
    std::vector<Point> sortedPoints = points;
    for (int i = 0; i < sortedPoints.size(); i++) {
        for (int j = i + 1; j < sortedPoints.size(); j++) {
            if (cross(sortedPoints[i], sortedPoints[j]) > 0) {
                std::swap(sortedPoints[i], sortedPoints[j]);
            }
        }
    }
    return sortedPoints;
}
