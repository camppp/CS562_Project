#include <iostream>
#include <list>
#include <ctime>

class ClassTest {
public:
    int integer;
};

int main() {
    const size_t entttSNumber = 1000;  // Specify the number of TestClass objects

    std::list<ClassTest*> v;

    // Populate the list with TestClass objects
    for (size_t i = 0; i < entttSNumber; i++) {
        v.emplace(v.end(), new ClassTest());
    }

    // Measure the time before the iteration process
    clock_t begin_time = clock();

    // Iterate through the list and increment the integer member variable of each object by 5
    for (auto it = v.begin(); it != v.end(); ++it) {
        (*it)->integer += 5;
    }

    // Measure the time after the iteration process
    clock_t end_time = clock();

    // Output the time taken for the iteration process in clock ticks
    std::cout << "Time taken in clock ticks: " << end_time - begin_time << std::endl;

    // Output the time taken for the iteration process in seconds
    float time_seconds = static_cast<float>(end_time - begin_time) / CLOCKS_PER_SEC;
    std::cout << "Time taken in seconds: " << time_seconds << std::endl;

    // Clear the list and release the memory occupied by the list
    for (auto it = v.begin(); it != v.end(); ++it) {
        delete *it;
    }
    v.clear();

    return 0;
}
