std::vector<int> filterPoints(const std::vector<Point>& flat_projected, const std::vector<int>& indices, double projection_angle_thresh, int dimension, bool xy_proj_safe) {
    std::vector<int> filtered_indices;
    for (int i = 0; i < indices.size(); i++) {
        int index = indices[i];
        Point point = flat_projected[index];
        if (dimension == 2) {
            // Calculate the projection angle
            double projection_angle = acos(point.x * point.x + point.y * point.y);
            if (projection_angle < projection_angle_thresh) {
                filtered_indices.push_back(index);
            }
        } else if (dimension == 3) {
            // No filtering based on projection angle is required
            filtered_indices.push_back(index);
        }
        if (xy_proj_safe && !isSafeForProjection(point)) {
            // Skip the point if it is not safe for projection onto the XY plane
            continue;
        }
        filtered_indices.push_back(index);
    }
    return filtered_indices;
}
