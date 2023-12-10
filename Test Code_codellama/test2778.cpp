#include <exception>
#include <stdexcept>

template <typename T>
class ResourceHolder {
private:
    bool gotResource;
    T resource;

public:
    ResourceHolder() : gotResource(false) {}

    const T& get() const {
        if (!gotResource) {
            throw std::logic_error("Resource not set");
        }
        return resource;
    }

    void set(const T& newResource) {
        resource = newResource;
        gotResource = true;
    }
};
