struct Point {
    int x, y;
};

pair<Point, Point> FindClosestPairPointsInSubarray(const vector<Point>& points, int start, int end) {
    // Initialize the closest pair to the first two points in the subarray
    int closest_distance = INT_MAX;
    Point closest_pair = {points[start], points[start + 1]};

    // Iterate over the remaining points in the subarray
    for (int i = start + 2; i <= end; i++) {
        // Calculate the distance between the current point and the previous point
        int distance = sqrt((points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x) +
                            (points[i].y - points[i - 1].y) * (points[i].y - points[i - 1].y));

        // If the distance is less than the current closest distance, update the closest pair
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_pair = {points[i - 1], points[i]};
        }
    }

    return closest_pair;
}
