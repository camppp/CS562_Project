#include <iostream>
#include <thread>

int main() {
    std::mutex mtx;
    IdentifierManager manager(&mtx);

    // Thread 1: Add identifier "ID1"
    std::thread t1([&manager]() {
        manager.addIdentifier("ID1");
    });

    // Thread 2: Remove identifier "ID1"
    std::thread t2([&manager]() {
        manager.removeIdentifier("ID1");
    });

    // Thread 3: Check if identifier "ID1" exists
    std::thread t3([&manager]() {
        bool exists = manager.isIdentifierExists("ID1");
        std::cout << "ID1 exists: " << std::boolalpha << exists << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
