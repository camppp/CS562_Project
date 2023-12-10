#include <cmath>

struct Point3D {
  double x, y, z;
};

double calculateTetrahedronVolume(const Point3D& x1, const Point3D& x2, const Point3D& x3, const Point3D& x4) {
  double volume = std::abs((1.0 / 6.0) * ((x2.x - x1.x) * ((x3.y - x1.y) * (x4.z - x1.z) - (x3.z - x1.z) * (x4.y - x1.y)) +
                                           (x2.y - x1.y) * ((x3.z - x1.z) * (x4.x - x1.x) - (x3.x - x1.x) * (x4.z - x1.z)) +
                                           (x2.z - x1.z) * ((x3.x - x1.x) * (x4.y - x1.y) - (x3.y - x1.y) * (x4.x - x1.x))));
  return volume;
}
