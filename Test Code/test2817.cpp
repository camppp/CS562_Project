#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
class SubsetDataset {
private:
    std::vector<T> subdataset;

public:
    SubsetDataset(const std::vector<T>& data) : subdataset(data) {}

    T getElement(size_t id) {
        if (id < subdataset.size()) {
            return subdataset[id];
        } else {
            // Return a default value based on the type T
            return T{};
        }
    }
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    SubsetDataset<int> dataset(data);

    std::cout << dataset.getElement(2) << std::endl;  // Output: 3
    std::cout << dataset.getElement(5) << std::endl;  // Output: 0 (default value for int)

    return 0;
}
