float distanceSquared(std::pair<float, float> point1, std::pair<float, float> point2) {
    float x1 = point1.first;
    float y1 = point1.second;
    float x2 = point2.first;
    float y2 = point2.second;

    float squared_distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    return squared_distance;
}
