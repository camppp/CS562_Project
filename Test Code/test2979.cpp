#include <vector>
#include <cmath>

struct Point2 {
  double x, y;
  // Constructor and other methods are not shown for brevity
};

struct Point2Pair {
  Point2 first, second;
};

struct Rot2 {
  double angle;
  // Other methods are not shown for brevity

  static Rot2 fromAngle(double theta) {
    Rot2 r;
    r.angle = theta;
    return r;
  }
};

struct Pose2 {
  Rot2 rotation;
  Point2 translation;

  Pose2(Rot2 r, Point2 t) : rotation(r), translation(t) {}
};

Pose2 calculateRotationTranslation(const std::vector<Point2Pair>& pairs) {
  double c = 0, s = 0;
  Point2 cp = pairs[0].first;  // Assuming the first point in the first pair is the reference point
  Point2 cq = pairs[0].second; // Assuming the second point in the first pair is the reference point

  for (const Point2Pair& pair : pairs) {
    Point2 dq = pair.first - cp;
    Point2 dp = pair.second - cq;
    c += dp.x * dq.x + dp.y * dq.y;
    s += dp.y * dq.x - dp.x * dq.y;
  }

  double theta = atan2(s, c);
  Rot2 R = Rot2::fromAngle(theta);
  Point2 t = cq - R * cp;

  return Pose2(R, t);
}
