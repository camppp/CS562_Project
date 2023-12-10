#include <iostream>
#include <string>
#include <vector>

class InventoryMonitor {
public:
    InventoryMonitor(const std::string& impl) : impl_(impl) {}

    void collectInventory(const InventorySnapshot& snapshot) {
        if (!impl_.available()) {
            ORTE_ERROR_LOG(ORCM_ERR_NOT_AVAILABLE);
            return;
        }

        impl_.collectInventory(snapshot);
    }

    void logInventory(const std::string& hostname, const InventorySnapshot& snapshot) {
        if (!impl_.available()) {
            ORTE_ERROR_LOG(ORCM_ERR_NOT_AVAILABLE);
            return;
        }

        impl_.logInventory(hostname, snapshot);
    }

private:
    std::string impl_;
};
