#include <ngraph/validation_util.hpp>
#include <vector>

bool validateInputArray(const std::vector<float>& inputArray, float minValue, float maxValue) {
    for (const auto& element : inputArray) {
        if (!ngraph::validate_value(element, {ngraph::element::f32, ngraph::element::f64}, "Input Array Element")) {
            return false;
        }
        if (element < minValue || element > maxValue) {
            return false;
        }
    }
    return true;
}
