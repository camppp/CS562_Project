#include <iostream>
#include <string>

namespace ignition {
  namespace gazebo {
    class ServiceManager {
    public:
        std::string service;

        // Implement the constructor
        ServiceManager() {
            service = "";
        }

        // Implement the setServiceName method
        void setServiceName(const std::string& serviceName) {
            service = serviceName;
        }

        // Implement the getServiceName method
        std::string getServiceName() {
            return service;
        }
    };
  }
}

using namespace ignition;
using namespace gazebo;

int main() {
    ServiceManager manager;
    manager.setServiceName("LocalizationService");
    std::cout << "Service Name: " << manager.getServiceName() << std::endl;
    return 0;
}
