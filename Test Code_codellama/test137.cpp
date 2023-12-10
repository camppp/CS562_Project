bool comparePoints(const Point2D& p1, const Point2D& p2) {
    // Calculate the distances from the origin
    double dist1 = std::sqrt(p1.x * p1.x + p1.y * p1.y);
    double dist2 = std::sqrt(p2.x * p2.x + p2.y * p2.y);

    // Compare the distances
    if (dist1 < dist2) {
        return true;
    } else if (dist1 == dist2) {
        // If the distances are equal, compare the x-coordinates
        return p1.x < p2.x;
    } else {
        return false;
    }
}
