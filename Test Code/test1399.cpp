#include "serviceList.h"

namespace serviceCommon {
    serviceList::serviceList() {
        // Initialize the instances map
        instances = std::unordered_map<int, serviceInstance>();
    }

    void serviceList::addServiceInstance(const serviceInstance& instance) {
        // Add the service instance to the instances map
        instances[instance.id] = instance;
    }

    void serviceList::removeServiceInstance(int id) {
        // Remove the service instance from the instances map
        instances.erase(id);
    }

    serviceInstance serviceList::getServiceInstance(int id) const {
        // Return the service instance with the given ID
        return instances.at(id);
    }
}
