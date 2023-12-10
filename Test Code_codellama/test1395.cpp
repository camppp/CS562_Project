#include <vector>

using ArrayDimensions = std::vector<int>;

inline size_t getNumElements(const ArrayDimensions& dims) MW_NOEXCEPT {
    size_t retVal = 1;
    for (auto& elem : dims) {
        retVal *= elem;
    }
    return retVal;
}
