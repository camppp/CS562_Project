#include <cmath>

struct Position2D {
    float x;
    float y;
    Position2D(float _x, float _y) : x(_x), y(_y) {}
};

float calculateDistance(const Position2D& p1, const Position2D& p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

TEST(ALPosition2DTest, Divers)
{
  Position2D pPos2D1(+1.2f, 1.3f);
  Position2D pPos2D2(2.5f, 3.7f);
  float distance = calculateDistance(pPos2D1, pPos2D2);
  // Assert the distance calculation here
}
