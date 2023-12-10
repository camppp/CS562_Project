#include <Menge/Math/Vector.h>

class PathGoalRenderer : public BaseRenderer {
 public:
  void doDrawGeometry() {
    // Draw the geometry associated with the path goals
    for (const auto& goal : _pathGoals) {
      // Draw a circle at the center of the goal
      Menge::Math::Vector2f center = goal.getCenter();
      float radius = goal.getRadius();
      Menge::Math::Vector2f start = center - radius;
      Menge::Math::Vector2f end = center + radius;
      Menge::Math::drawCircle(start, end, 10);

      // Draw a line connecting the center of the goal to the edge of the goal
      Menge::Math::Vector2f edge = goal.getEdge();
      Menge::Math::drawLine(center, edge, 10);
    }
  }

 private:
  std::vector<PathGoal> _pathGoals;
};
