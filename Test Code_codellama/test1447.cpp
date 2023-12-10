#include <iostream>
#include <vector>

void processCollection() {
    // Initialize a collection of integers
    std::vector<int> collection = {1, 2, 3, 4, 5};

    // Create an iterator for the collection
    std::vector<int>::iterator it = collection.begin();

    // Output the elements of the collection using the provided iterator
    while (it != collection.end()) {
        std::cout << *it << " ";
        it++;
    }
}

int main() {
    processCollection();
    return 0;
}
