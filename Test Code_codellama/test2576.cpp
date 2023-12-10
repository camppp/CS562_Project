#include <iostream>
#include <string>
#include <map>
#include <vector>

// Service registry data structure
struct Service {
  std::string name;
  std::string version;
  std::string endpoint;
};

// Service registry map
std::map<std::string, std::vector<Service>> serviceRegistry;

// Add a new service to the registry
void addService(const std::string& name, const std::string& version, const std::string& endpoint) {
  Service service;
  service.name = name;
  service.version = version;
  service.endpoint = endpoint;
  serviceRegistry[name].push_back(service);
}

// Query for the endpoint of a specific service
std::string queryEndpoint(const std::string& name, const std::string& version) {
  auto it = serviceRegistry.find(name);
  if (it != serviceRegistry.end()) {
    for (const auto& service : it->second) {
      if (service.version == version) {
        return service.endpoint;
      }
    }
  }
  return "";
}

int main() {
  // Add a few services to the registry
  addService("service1", "v1", "http://localhost:8080");
  addService("service2", "v2", "http://localhost:8081");
  addService("service3", "v3", "http://localhost:8082");

  // Query for the endpoint of service1
  std::cout << queryEndpoint("service1", "v1") << std::endl;

  return 0;
}
