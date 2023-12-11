bool almost_equal(const float x, const float y, int ulp) {
    // Calculate the difference between the two numbers
    float diff = std::abs(x - y);

    // Calculate the maximum possible difference for the given ULP tolerance
    float max_diff = std::numeric_limits<float>::epsilon() * std::pow(2, ulp);

    // Check if the difference is within the maximum possible difference
    return diff <= max_diff;
}
