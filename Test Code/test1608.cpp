java
public float moveTowardsAngle(float currentAngle, float targetAngle, float rotationChange) {
    float angleDifference = targetAngle - currentAngle;
    if (angleDifference > 180) {
        angleDifference -= 360;
    } else if (angleDifference < -180) {
        angleDifference += 360;
    }
    float newAngle = currentAngle + Math.min(Math.abs(angleDifference), rotationChange) * Math.signum(angleDifference);
    if (newAngle < 0) {
        newAngle += 360;
    } else if (newAngle >= 360) {
        newAngle -= 360;
    }
    return newAngle;
}
