#include <mutex>
#include <vector>
#include <memory>

class ResourceDisposer {
public:
    void addResource(std::shared_ptr<Resource> resource) {
        std::lock_guard<std::mutex> lock(disposeMutex);
        resources.push_back(resource);
    }

    void disposeResources() {
        std::lock_guard<std::mutex> lock(disposeMutex);
        for (auto& resource : resources) {
            // Dispose the resource
            resource->dispose();
        }
        resources.clear();
    }

private:
    static std::mutex disposeMutex;
    std::vector<std::shared_ptr<Resource>> resources;
};

std::mutex ResourceDisposer::disposeMutex;
