float cosf32(float angle) {
    // Calculate the sine and cosine of the angle
    float sin = sinf32(angle);
    float cos = 1.0f - sin * sin;

    // Return the cosine of the angle
    return cos;
}

float tanf32(float angle) {
    // Calculate the sine and cosine of the angle
    float sin = sinf32(angle);
    float cos = 1.0f - sin * sin;

    // Return the tangent of the angle
    return sin / cos;
}
