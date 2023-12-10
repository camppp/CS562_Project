void PathGoalRenderer::doDrawGeometry() const {
    // Assuming PathGoal class has methods to retrieve necessary data
    Menge::Math::Vector2 goalPosition = pathGoal.getPosition();
    float goalRadius = pathGoal.getRadius();

    // Assuming drawCircle method is available in the vector library
    drawCircle(goalPosition, goalRadius, Color::GREEN);
}
