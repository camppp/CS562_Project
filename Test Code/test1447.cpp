#include <iostream>
#include <vector>

void processCollection() {
    std::vector<int> collection = {1, 2, 3, 4, 5};  // Initialize a collection of integers

    for (auto iter = collection.begin(); iter != collection.end(); ++iter) {
        std::cout << *iter;  // Output the elements of the collection using the iterator
    }

    std::cout << std::endl;
}

int main() {
    processCollection();  // Call the function to process the collection
    return 0;
}
