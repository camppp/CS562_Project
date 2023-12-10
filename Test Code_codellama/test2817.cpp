#include <iostream>
#include <vector>

template <typename T>
class SubsetDataset {
public:
    SubsetDataset(const std::vector<T>& elements) : elements(elements) {}

    T getElement(size_t id) {
        if (id >= elements.size()) {
            return T(); // return default value for type T
        }
        return elements[id];
    }

private:
    std::vector<T> elements;
};

int main() {
    std::vector<int> elements = {1, 2, 3, 4, 5};
    SubsetDataset<int> subset(elements);

    std::cout << subset.getElement(0) << std::endl; // prints 1
    std::cout << subset.getElement(5) << std::endl; // prints 0 (default value for int)
    std::cout << subset.getElement(10) << std::endl; // prints 0 (default value for int)

    return 0;
}
