int countOverlappingPoints(vector<Point>& points) {
    int count = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                count++;
            }
        }
    }
    return count;
}
