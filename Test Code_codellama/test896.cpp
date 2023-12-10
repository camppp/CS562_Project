#include <iostream>
#include <vector>
#include <chrono>

class TestClass {
public:
    int integer;
};

int main() {
    // Create a list of pointers to TestClass objects
    std::vector<TestClass*> list;

    // Populate the list with a specified number of TestClass objects
    for (int i = 0; i < 1000; i++) {
        TestClass* obj = new TestClass();
        obj->integer = 0;
        list.push_back(obj);
    }

    // Iterate through the list and increment the integer member variable of each object by 5
    auto start = std::chrono::high_resolution_clock::now();
    for (auto obj : list) {
        obj->integer += 5;
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Measure the time taken for the iteration process
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken for iteration: " << elapsed.count() << " seconds" << std::endl;

    // Clear the list and release the memory occupied by the list
    list.clear();

    return 0;
}
