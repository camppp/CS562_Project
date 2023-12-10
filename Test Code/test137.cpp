bool comparePoints(const Point2D& p1, const Point2D& p2) {
    double distance1 = sqrt(p1.x * p1.x + p1.y * p1.y);
    double distance2 = sqrt(p2.x * p2.x + p2.y * p2.y);

    if (distance1 < distance2) {
        return true;
    } else if (distance1 == distance2) {
        return p1.x < p2.x;
    } else {
        return false;
    }
}
