#include <vector>
#include <algorithm>

enum class EDeviceType {
    Mobile,
    Laptop,
    Tablet,
    Desktop
};

class Device {
    int _id;
    EDeviceType _type;

public:
    Device(int id, EDeviceType type) : _id(id), _type(type) {}
    // Other methods and members not shown for brevity
};

class Context {
    std::vector<Device> _devs;
    int _id;

public:
    Context(int id) : _id(id) {}

    bool create(EDeviceType type) {
        // Find the maximum ID of existing devices
        int maxId = 0;
        for (const auto& dev : _devs) {
            maxId = std::max(maxId, dev._id);
        }

        // Create a new device with a unique ID
        _devs.emplace_back(maxId + 1, type);
        return true; // Return true on successful creation
    }
    // Other methods and members not shown for brevity
};
