#include <memory>

class UniquePtrContainer {
private:
    class Impl {
        // Define the implementation details of the Impl class
    };
    std::unique_ptr<Impl> impl;

public:
    UniquePtrContainer() : impl(std::make_unique<Impl>()) {}

    ~UniquePtrContainer() = default;

    // Other member functions can be added as needed
};
