#include <iostream>

int main() {
    ExtSequencer obj1;
    ExtSequencer obj2;
    ExtSequencer obj3;

    std::cout << "Initial count: " << ExtSequencer::getInstanceCount() << std::endl;

    obj2.addInstance();
    std::cout << "Count after adding obj2: " << ExtSequencer::getInstanceCount() << std::endl;

    obj3.removeInstance();
    std::cout << "Count after removing obj3: " << ExtSequencer::getInstanceCount() << std::endl;

    return 0;
}
