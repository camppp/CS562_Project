void sortPoints(vector<Point> &points, const Point &p) {
    // Sort the points in counter-clockwise order with respect to the reference point p
    sort(points.begin(), points.end(), [&](const Point &a, const Point &b) {
        // Calculate the angle between the vectors OA and OB
        int angleA = atan2(a.y - p.y, a.x - p.x);
        int angleB = atan2(b.y - p.y, b.x - p.x);

        // If the angles are the same, compare the distances from the reference point
        if (angleA == angleB) {
            return distance(a, p) < distance(b, p);
        }

        // Otherwise, compare the angles
        return angleA < angleB;
    });
}
