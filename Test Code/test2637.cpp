#include <cmath>

double calculateTetrahedronVolume(const Point3D& x1, const Point3D& x2, const Point3D& x3, const Point3D& x4) {
  double volume = 0.0;
  volume = (x2.x - x1.x) * ((x3.x - x1.x) * (x4.x - x1.x));
  volume += (x2.y - x1.y) * ((x3.y - x1.y) * (x4.y - x1.y));
  volume += (x2.z - x1.z) * ((x3.z - x1.z) * (x4.z - x1.z));
  volume /= 6.0;
  return volume;
}
