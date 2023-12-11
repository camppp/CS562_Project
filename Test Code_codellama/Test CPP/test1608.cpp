float moveTowardsAngle(float currentAngle, float targetAngle, float rotationChange) {
    // Calculate the difference between the current angle and the target angle
    float angleDiff = targetAngle - currentAngle;

    // Calculate the new orbit angle based on the rotation change and the angle difference
    float newOrbitAngle = currentAngle + rotationChange * angleDiff;

    // Return the new orbit angle
    return newOrbitAngle;
}
