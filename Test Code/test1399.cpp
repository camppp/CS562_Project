#include <unordered_map>
#include "dbConnection.h"
#include "serviceInstance.h"
#include "serviceList.h"

using namespace std;
using namespace dbUtilities;

namespace serviceCommon {
    serviceList::serviceList() {
        // Constructor implementation
    }

    void serviceList::addServiceInstance(const serviceInstance& instance) {
        instances[instance.id] = instance;
    }

    void serviceList::removeServiceInstance(int id) {
        instances.erase(id);
    }

    serviceInstance serviceList::getServiceInstance(int id) const {
        auto it = instances.find(id);
        if (it != instances.end()) {
            return it->second;
        } else {
            // Handle error or return a default instance
            return serviceInstance(); // Assuming default constructor exists
        }
    }
}
