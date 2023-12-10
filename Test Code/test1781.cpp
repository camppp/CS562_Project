#include <vector>
#include <cmath>
#include <iostream>

namespace framework {
    template <typename T>
    struct Vector2 {
        T x, y;
    };
}

enum class SliderCurveType {
    LINEAR = 0,
    BEZIER = 1,
    CIRCLE = 2
};

struct SliderInfo {
    SliderCurveType curve_type;
    std::vector<framework::Vector2<float>> curve_points;
};

float distance(const framework::Vector2<float>& p1, const framework::Vector2<float>& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

float calculateLinearCurveLength(const std::vector<framework::Vector2<float>>& curve_points) {
    float length = 0.0f;
    for (size_t i = 1; i < curve_points.size(); ++i) {
        length += distance(curve_points[i - 1], curve_points[i]);
    }
    return length;
}

float calculateBezierCurveLength(const std::vector<framework::Vector2<float>>& curve_points) {
    // Implement numerical integration or approximation to calculate the length of the Bezier curve
    // This can involve methods like Simpson's rule or adaptive subdivision
    // For simplicity, let's assume a linear approximation for demonstration
    return calculateLinearCurveLength(curve_points);
}

float calculateCircleCurveLength(const std::vector<framework::Vector2<float>>& curve_points) {
    // Assuming the first and last points define the diameter of the circle
    float radius = distance(curve_points.front(), curve_points.back()) / 2.0f;
    return 2.0f * M_PI * radius;
}

float calculateSliderCurveLength(const SliderInfo& slider_info) {
    switch (slider_info.curve_type) {
        case SliderCurveType::LINEAR:
            return calculateLinearCurveLength(slider_info.curve_points);
        case SliderCurveType::BEZIER:
            return calculateBezierCurveLength(slider_info.curve_points);
        case SliderCurveType::CIRCLE:
            return calculateCircleCurveLength(slider_info.curve_points);
        default:
            std::cerr << "Invalid curve type" << std::endl;
            return 0.0f;
    }
}

int main() {
    // Example usage
    SliderInfo slider_info;
    slider_info.curve_type = SliderCurveType::LINEAR;
    slider_info.curve_points = {{0.0f, 0.0f}, {3.0f, 4.0f}, {6.0f, 8.0f}};
    std::cout << "Length of linear curve: " << calculateSliderCurveLength(slider_info) << std::endl;

    slider_info.curve_type = SliderCurveType::BEZIER;
    slider_info.curve_points = {{0.0f, 0.0f}, {3.0f, 4.0f}, {6.0f, 8.0f}};
    std::cout << "Length of Bezier curve: " << calculateSliderCurveLength(slider_info) << std::endl;

    slider_info.curve_type = SliderCurveType::CIRCLE;
    slider_info.curve_points = {{0.0f, 0.0f}, {6.0f, 0.0f}};
    std::cout << "Length of circle curve: " << calculateSliderCurveLength(slider_info) << std::endl;

    return 0;
}
