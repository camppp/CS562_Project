size_t countSelfIntersections(const Polygon& polygon) {
    size_t numSelfIntersections = 0;
    for (size_t i = 0; i < polygon.size() - 1; i++) {
        for (size_t j = i + 1; j < polygon.size(); j++) {
            if (intersects(polygon[i], polygon[j])) {
                numSelfIntersections++;
            }
        }
    }
    return numSelfIntersections;
}
