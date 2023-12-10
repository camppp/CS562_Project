#include <vector>

class EuclideanVector {
public:
    // Other member variables and methods

    // Conversion operator from EuclideanVector to std::vector<double>
    operator std::vector<double>() const noexcept {
        return magnitudes_;
    }

    // Other member variables and methods
};
