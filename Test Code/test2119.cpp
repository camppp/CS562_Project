#include <iostream>
#include <string>

namespace ignition {
  namespace gazebo {
    class ServiceManager {
    public:
        std::string service;

        // Constructor
        ServiceManager() {
            service = "";
        }

        // Set service name
        void setServiceName(const std::string& serviceName) {
            service = serviceName;
        }

        // Get service name
        std::string getServiceName() {
            return service;
        }
    };
  }
}
