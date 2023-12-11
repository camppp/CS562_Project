#include <cmath>

float distance(const AL::Math::Position2D& p1, const AL::Math::Position2D& p2)
{
  float dx = p1.x - p2.x;
  float dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}
