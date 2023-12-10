#include <vulkan/vulkan.h>

class VulkanInstanceManager {
private:
    VkInstanceCreateInfo m_instanceCreateInfo;
    VkApplicationInfo m_appInfo;

public:
    // Method to set pApplicationInfo to point to m_appInfo
    void setApplicationInfo() {
        this->m_instanceCreateInfo.pApplicationInfo = &this->m_appInfo;
    }
};

int main() {
    // Create an instance of VulkanInstanceManager
    VulkanInstanceManager manager;

    // Set the application info
    manager.setApplicationInfo();

    // Verify that pApplicationInfo points to m_appInfo
    if (manager.m_instanceCreateInfo.pApplicationInfo == &manager.m_appInfo) {
        // Success
    } else {
        // Failure
    }

    return 0;
}
