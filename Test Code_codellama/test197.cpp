#include <cmath>

double calculateFinalPosition(double initialPosition, const std::string& physicsEngineType, double tolerance) {
    // Check if the initial position matches the expected initial result position within the tolerance
    EXPECT_NEAR(initialPosition, initialResultPosition, tolerance);

    // Move the angle to ensure that Joint::SetPosition works from non-zero initial values
    double finalPosition = initialPosition / 2.0;

    // If the physics engine is "bullet" and the absolute value of the final position is greater than 1e12,
    // set the final position to 0.0 to avoid numerical instability
    if (physicsEngineType == "bullet" && std::abs(finalPosition) > 1e12) {
        finalPosition = 0.0;
    }

    return finalPosition;
}
