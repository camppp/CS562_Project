#include <iostream>
#include <vector>
#include <algorithm>

class Collection {
private:
    std::vector<int> elements;

public:
    void addElement(int element) {
        elements.push_back(element);
    }

    void removeElement(int element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    int getMaxElement() {
        if (elements.empty()) {
            throw std::runtime_error("Collection is empty");
        }
        return *std::max_element(elements.begin(), elements.end());
    }

    int getMinElement() {
        if (elements.empty()) {
            throw std::runtime_error("Collection is empty");
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    std::vector<int> getElements() {
        return elements;
    }
};

int main() {
    // Usage of the Collection class
    Collection* mFgtCollectionPtr = nullptr;
    // Assuming eventPtr is a pointer to an event object
    // If eventPtr is not null, retrieve the collection of integers
    // and assign it to mFgtCollectionPtr
    if (eventPtr) {
        mFgtCollectionPtr = eventPtr->fgtCollection();
    }

    // Example usage of the Collection class
    Collection collection;
    collection.addElement(5);
    collection.addElement(10);
    collection.addElement(3);
    collection.removeElement(10);

    std::vector<int> elements = collection.getElements();
    for (int element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Max Element: " << collection.getMaxElement() << std::endl;
    std::cout << "Min Element: " << collection.getMinElement() << std::endl;

    return 0;
}
