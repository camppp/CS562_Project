float calculateLength(float dif, float length_bias, float length_min, float length_max) {
    dif = pow(dif, 1.0 / length_bias);
    return dif * (length_max - length_min) + length_min;
}
