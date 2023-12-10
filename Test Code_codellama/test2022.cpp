#include <cmath>

bool NT2_TEST_ULP_EQUAL(double actual, double expected, int ulp_tolerance, const char* description) {
  // Check if the actual value is a special value (infinity, NaN, etc.)
  if (std::isinf(actual) || std::isnan(actual)) {
    // If the actual value is a special value, check if it matches the expected value
    return (actual == expected);
  }

  // If the actual value is not a special value, check if it is within the allowed range of ulps
  double diff = std::fabs(actual - expected);
  return (diff <= ulp_tolerance);
}
