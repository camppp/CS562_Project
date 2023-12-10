#include <vector>
#include <cmath>

struct Point {
  double x, y, z;
};

double calculateProjectionAngle(const Point& point) {
  // Assuming the plane's normal vector is (0, 0, 1) for XY projection
  double dotProduct = point.z / sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
  return acos(dotProduct);
}

bool isSafeForXYProjection(const Point& point) {
  // Assuming the safe range for XY projection is when z coordinate is non-negative
  return point.z >= 0;
}

std::vector<int> filterPoints(const std::vector<Point>& flat_projected, const std::vector<int>& indices, double projection_angle_thresh, int dimension, bool xy_proj_safe) {
  std::vector<int> filteredIndices;
  for (int index : indices) {
    const Point& point = flat_projected[index];
    if (dimension == 2) {
      if (calculateProjectionAngle(point) <= projection_angle_thresh) {
        if (xy_proj_safe) {
          if (isSafeForXYProjection(point)) {
            filteredIndices.push_back(index);
          }
        } else {
          filteredIndices.push_back(index);
        }
      }
    } else if (dimension == 3) {
      filteredIndices.push_back(index);
    }
  }
  return filteredIndices;
}
