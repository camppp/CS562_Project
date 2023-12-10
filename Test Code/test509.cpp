#include <iostream>
#include <vector>
#include <stdexcept>

class IntegerCollection {
private:
    std::vector<int> elements;

public:
    // Adds a new integer to the collection
    void addElement(int value) {
        elements.push_back(value);
    }

    // Removes the first occurrence of the specified integer from the collection
    void removeElement(int value) {
        auto it = std::find(elements.begin(), elements.end(), value);
        if (it != elements.end()) {
            elements.erase(it);
        } else {
            throw std::invalid_argument("Element not found in collection");
        }
    }

    // Returns the minimum value in the collection
    int getMinValue() const {
        if (elements.empty()) {
            throw std::invalid_argument("Collection is empty");
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    // Returns the maximum value in the collection
    int getMaxValue() const {
        if (elements.empty()) {
            throw std::invalid_argument("Collection is empty");
        }
        return *std::max_element(elements.begin(), elements.end());
    }

    // Returns the sum of all integers in the collection
    int getSum() const {
        if (elements.empty()) {
            throw std::invalid_argument("Collection is empty");
        }
        return std::accumulate(elements.begin(), elements.end(), 0);
    }
};

int main() {
    IntegerCollection collection;
    collection.addElement(1);
    collection.addElement(2);
    collection.addElement(3);
    std::cout << "Min value: " << collection.getMinValue() << std::endl;
    std::cout << "Max value: " << collection.getMaxValue() << std::endl;
    std::cout << "Sum: " << collection.getSum() << std::endl;
    collection.removeElement(2);
    std::cout << "Min value after removing 2: " << collection.getMinValue() << std::endl;
    std::cout << "Max value after removing 2: " << collection.getMaxValue() << std::endl;
    std::cout << "Sum after removing 2: " << collection.getSum() << std::endl;
    return 0;
}
