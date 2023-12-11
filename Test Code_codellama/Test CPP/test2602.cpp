#include <memory>
#include <string>

class BeaglePciDriverProviderLinux {
public:
    std::unique_ptr<KernelCoherentAllocator> CreateKernelCoherentAllocator(const std::string& device_path, size_t alignment_bytes, size_t size_bytes) {
        return std::make_unique<KernelCoherentAllocatorLinux>(device_path, alignment_bytes, size_bytes);
    }
};
