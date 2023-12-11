void CalculateSinCos(float angleInDegrees, float& sinValue, float& cosValue) {
    // Convert the angle from degrees to radians
    float angleInRadians = angleInDegrees * 3.14159 / 180.0;

    // Calculate the sine and cosine values using the trigonometric functions
    sinValue = sin(angleInRadians);
    cosValue = cos(angleInRadians);
}
