#include <iostream>
#include <array>

template <typename T, size_t N>
class rect_tt {
private:
    std::array<T, N> dimensions;

public:
    rect_tt() {
        dimensions.fill(T{});
    }

    rect_tt(const std::array<T, N>& dims) : dimensions(dims) {}

    const std::array<T, N>& getDimensions() const {
        return dimensions;
    }

    void setDimensions(const std::array<T, N>& dims) {
        dimensions = dims;
    }

    T area() const {
        T result = T{1};
        for (const auto& dim : dimensions) {
            result *= dim;
        }
        return result;
    }

    bool containsPoint(const std::array<T, N>& point) const {
        for (size_t i = 0; i < N; ++i) {
            if (point[i] < T{} || point[i] > dimensions[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Example usage for rect_tt
    rect_tt<int, 2> rectInt2D({3, 4});
    std::cout << "Area of rectInt2D: " << rectInt2D.area() << std::endl;

    std::array<int, 2> pointInside = {2, 3};
    std::array<int, 2> pointOutside = {5, 6};
    std::cout << "Point {2, 3} is inside rectInt2D: " << std::boolalpha << rectInt2D.containsPoint(pointInside) << std::endl;
    std::cout << "Point {5, 6} is inside rectInt2D: " << std::boolalpha << rectInt2D.containsPoint(pointOutside) << std::endl;

    rect_tt<float, 3> rectFloat3D({1.5f, 2.5f, 3.5f});
    std::cout << "Area of rectFloat3D: " << rectFloat3D.area() << std::endl;

    std::array<float, 3> point3DInside = {1.0f, 2.0f, 3.0f};
    std::array<float, 3> point3DOutside = {2.0f, 3.0f, 4.0f};
    std::cout << "Point {1.0, 2.0, 3.0} is inside rectFloat3D: " << std::boolalpha << rectFloat3D.containsPoint(point3DInside) << std::endl;
    std::cout << "Point {2.0, 3.0, 4.0} is inside rectFloat3D: " << std::boolalpha << rectFloat3D.containsPoint(point3DOutside) << std::endl;

    return 0;
}
