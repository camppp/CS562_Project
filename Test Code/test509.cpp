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
        }
    }

    // Returns the minimum value in the collection
    int getMinValue() const {
        if (elements.empty()) {
            throw std::logic_error("Collection is empty");
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    // Returns the maximum value in the collection
    int getMaxValue() const {
        if (elements.empty()) {
            throw std::logic_error("Collection is empty");
        }
        return *std::max_element(elements.begin(), elements.end());
    }

    // Returns the sum of all integers in the collection
    int getSum() const {
        int sum = 0;
        for (int value : elements) {
            sum += value;
        }
        return sum;
    }
};

int main() {
    // Test your IntegerCollection class here
    IntegerCollection collection;
    collection.addElement(5);
    collection.addElement(10);
    collection.addElement(3);
    collection.removeElement(10);
    std::cout << "Minimum value: " << collection.getMinValue() << std::endl;
    std::cout << "Maximum value: " << collection.getMaxValue() << std::endl;
    std::cout << "Sum of all values: " << collection.getSum() << std::endl;
    return 0;
}
