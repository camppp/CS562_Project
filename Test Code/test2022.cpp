python
import math

def test_ulp_equal(actual, expected, ulp_tolerance, description):
    if math.isnan(actual) or math.isnan(expected):
        return math.isnan(actual) and math.isnan(expected)

    if math.isinf(actual) or math.isinf(expected):
        return actual == expected

    if actual == expected:
        return True

    if actual == 0 or expected == 0:
        return abs(actual - expected) < 0.5 * ulp_tolerance

    a = abs(actual - expected)
    b = ulp_tolerance * math.pow(2, -52)
    return a <= b

# Test cases
test_cases = [
    (pow(float('inf'), 4), float('inf'), 0, "Positive infinity raised to the power of 4"),
    (pow(float('-inf'), 3), float('-inf'), 0, "Negative infinity raised to the power of 3"),
    (pow(float('-inf'), 4), float('inf'), 0, "Negative infinity raised to the power of 4"),
    (pow(float('nan'), 3), float('nan'), 0, "NaN raised to the power of 3")
]

for actual, expected, ulp_tolerance, description in test_cases:
    result = test_ulp_equal(actual, expected, ulp_tolerance, description)
    print(f"Test '{description}': {'Passed' if result else 'Failed'}")
