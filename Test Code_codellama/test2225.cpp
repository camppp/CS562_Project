#include <iostream>

class SingleConfigGL46TestPackage : public SingleConfigGL45TestPackage {
private:
    int glVersion;

public:
    SingleConfigGL46TestPackage(int glVersion) : SingleConfigGL45TestPackage(glVersion) {
        this->glVersion = glVersion;
    }

    void runTests() {
        std::cout << "Running tests for OpenGL version " << glVersion << std::endl;
        // Simulate running tests for the OpenGL configuration
    }
};
