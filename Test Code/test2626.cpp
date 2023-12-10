#include <iostream>

class HelloWorld {
public:
    std::ostream& os;

    HelloWorld(std::ostream& output) : os(output) {}

    void sayHello() {
        os << "Hello";
    }

    void sayWorld() {
        os << "World";
    }
};

int main() {
    HelloWorld hw(std::cout);
    hw.sayHello();
    hw.sayWorld();
    std::cout << std::endl;
    return 0;
}
