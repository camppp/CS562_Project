#include <mutex>
#include <vector>

class ResourceDisposer {
public:
    void addResource(std::shared_ptr<void> resource) {
        std::lock_guard<std::mutex> lock(mutex_);
        resources_.push_back(resource);
    }

    void disposeResources() {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto& resource : resources_) {
            resource->dispose();
        }
        resources_.clear();
    }

private:
    std::mutex mutex_;
    std::vector<std::shared_ptr<void>> resources_;
};
