#include <cmath>
#include <limits>

bool almost_equal(const float x, const float y, int ulp)
{
    // Convert the floating-point numbers to their integer representations
    int x_int = *reinterpret_cast<const int*>(&x);
    int y_int = *reinterpret_cast<const int*>(&y);

    // Make the integer representations of negative numbers match their floating-point counterparts
    if (x_int < 0)
        x_int = std::numeric_limits<int>::max() - x_int + 1;
    if (y_int < 0)
        y_int = std::numeric_limits<int>::max() - y_int + 1;

    // Calculate the absolute difference in ULPs
    int ulp_diff = std::abs(x_int - y_int);

    // Check if the absolute difference is within the specified ULP tolerance
    return ulp_diff <= ulp;
}
