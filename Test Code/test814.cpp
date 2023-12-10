#include <iostream>
#include <string>
#include <unordered_map>

class cl_kernel_wrapper {
    // Define the cl_kernel_wrapper class if not already defined
};

class cl_kernel_mgr {
private:
    std::unordered_map<std::string, cl_kernel_wrapper*> mMap;

public:
    cl_kernel_mgr() = default;
    ~cl_kernel_mgr() {
        for (auto& pair : mMap) {
            delete pair.second; // Free memory for registered kernel wrappers
        }
    }

    template <typename... Args>
    static cl_kernel_wrapper* registerKernel(const std::string& func_name, const std::string& bin_name, Args... argv) {
        if (nullptr == mRegistry) {
            // Create a registry
            mRegistry = new cl_kernel_mgr();
        }

        // Create and register a new kernel wrapper
        cl_kernel_wrapper* kernel = new cl_kernel_wrapper(/* pass Args as needed */);
        mRegistry->mMap[func_name] = kernel;

        return kernel;
    }

    cl_kernel_wrapper* getKernel(const std::string& func_name) {
        auto it = mMap.find(func_name);
        if (it != mMap.end()) {
            return it->second; // Return the registered kernel wrapper
        } else {
            return nullptr; // Kernel function not found
        }
    }
};

int main() {
    // Example usage
    cl_kernel_mgr::registerKernel("kernel1", "binary1");
    cl_kernel_mgr::registerKernel("kernel2", "binary2");

    cl_kernel_wrapper* kernel1 = cl_kernel_mgr::getKernel("kernel1");
    cl_kernel_wrapper* kernel2 = cl_kernel_mgr::getKernel("kernel2");

    if (kernel1) {
        // Use kernel1
    }

    if (kernel2) {
        // Use kernel2
    }

    return 0;
}
