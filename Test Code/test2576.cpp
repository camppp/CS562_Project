#include <unordered_map>
#include <string>
#include <memory>

// Define a structure to represent a service
struct Service {
    std::string name;
    std::string version;
    std::string endpoint;

    Service(const std::string& name, const std::string& version, const std::string& endpoint)
        : name(name), version(version), endpoint(endpoint) {}
};

// ServiceRegistry class to store and retrieve service information
class ServiceRegistry {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> registry;

public:
    // Add a new service to the registry
    void addService(const std::string& name, const std::string& version, const std::string& endpoint) {
        registry[name][version] = endpoint;
    }

    // Query the endpoint of a specific service by name and version
    std::string getServiceEndpoint(const std::string& name, const std::string& version) {
        if (registry.find(name) != registry.end() && registry[name].find(version) != registry[name].end()) {
            return registry[name][version];
        }
        return "Service not found";
    }
};

int main() {
    // Create an instance of ServiceRegistry
    ServiceRegistry registry;

    // Add services to the registry
    registry.addService("AuthService", "v1", "http://auth-service.com/api/v1");
    registry.addService("DataService", "v2", "http://data-service.com/api/v2");

    // Query for the endpoint of a specific service
    std::cout << "AuthService v1 endpoint: " << registry.getServiceEndpoint("AuthService", "v1") << std::endl;
    std::cout << "DataService v2 endpoint: " << registry.getServiceEndpoint("DataService", "v2") << std::endl;
    std::cout << "InvalidService v3 endpoint: " << registry.getServiceEndpoint("InvalidService", "v3") << std::endl;

    return 0;
}
