#include <ngraph/validation_util.hpp>

bool validateInputArray(const std::vector<float>& inputArray, float minValue, float maxValue) {
    // Check if all elements in the input array are within the range defined by minValue and maxValue
    for (const auto& element : inputArray) {
        if (!ngraph::op::util::is_finite(element) || element < minValue || element > maxValue) {
            return false;
        }
    }
    return true;
}
