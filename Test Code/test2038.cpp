#include <iostream>
#include <map>
#include <string>
#include <memory>

// Define the BLEService class with a method to get the UUID
class BLEService {
public:
    std::string getUUID() {
        // Implementation to return the UUID of the service
        return "SampleUUID";
    }
};

// Define the BLEServiceMap class
class BLEServiceMap {
private:
    std::map<uint16_t, std::shared_ptr<BLEService>> m_handleMap;

public:
    // Method to add a service to the map
    void addService(uint16_t handle, std::shared_ptr<BLEService> service) {
        m_handleMap[handle] = service;
    }

    // Method to return a string representation of the service map
    std::string toString() {
        std::string res;
        char hex[5];
        for (const auto &myPair : m_handleMap) {
            res += "handle: 0x";
            snprintf(hex, sizeof(hex), "%04x", myPair.first);
            res += hex;
            res += ", uuid: " + myPair.second->getUUID() + "\n";
        }
        return res;
    }
};

int main() {
    // Create an instance of BLEServiceMap
    BLEServiceMap serviceMap;

    // Add sample services to the map
    serviceMap.addService(0x0010, std::make_shared<BLEService>());
    serviceMap.addService(0x0020, std::make_shared<BLEService>());

    // Print the string representation of the service map
    std::cout << serviceMap.toString();

    return 0;
}
