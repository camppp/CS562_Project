#include <iostream>
#include <string>
#include <map>

class BLEServiceMap {
public:
    std::string toString() {
        std::string result;
        for (const auto& handle_service : m_handleMap) {
            const auto& handle = handle_service.first;
            const auto& service = handle_service.second;
            result += "handle: 0x" + std::to_string(handle) + ", uuid: " + service.getUUID() + "\n";
        }
        return result;
    }

private:
    std::map<int, BLEService> m_handleMap;
};
