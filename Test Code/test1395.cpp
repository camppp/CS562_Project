#include <vector>
#include <iostream>

using ArrayDimensions = std::vector<size_t>;

/**
 * @throw - none.
 */
inline size_t getNumElements(const ArrayDimensions& dims) MW_NOEXCEPT {
    size_t retVal = 1;
    for (auto& elem : dims) {
        retVal *= elem;
    }
    return retVal;  // Return the total number of elements in the multi-dimensional array
}

int main() {
    // Example usage
    ArrayDimensions dimensions = {3, 4, 2};  // Represents a 3x4x2 multi-dimensional array
    size_t totalElements = getNumElements(dimensions);
    std::cout << "Total number of elements: " << totalElements << std::endl;
    return 0;
}
