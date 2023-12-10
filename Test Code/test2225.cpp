class SingleConfigGL46TestPackage : public SingleConfigGL45TestPackage
{
private:
    int glVersion;

public:
    SingleConfigGL46TestPackage(int version) : glVersion(version), SingleConfigGL45TestPackage() {}

    void runTests() {
        std::cout << "Running tests for OpenGL version " << glVersion << std::endl;
        // Add test logic here
    }
};
