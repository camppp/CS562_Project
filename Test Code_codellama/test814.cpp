class cl_kernel_mgr {
private:
    std::map<std::string, cl_kernel_wrapper*> kernel_map;

public:
    cl_kernel_mgr() {}

    void registerKernel(const std::string& name, const std::string& binary_name) {
        // Check if the kernel is already registered
        if (kernel_map.find(name) != kernel_map.end()) {
            throw std::runtime_error("Kernel already registered");
        }

        // Create a new kernel wrapper
        cl_kernel_wrapper* wrapper = new cl_kernel_wrapper(name, binary_name);

        // Add the wrapper to the map
        kernel_map[name] = wrapper;
    }

    cl_kernel_wrapper* getKernel(const std::string& name) {
        // Check if the kernel is registered
        if (kernel_map.find(name) == kernel_map.end()) {
            throw std::runtime_error("Kernel not registered");
        }

        // Return the wrapper
        return kernel_map[name];
    }

    ~cl_kernel_mgr() {
        // Delete all kernel wrappers
        for (auto& wrapper : kernel_map) {
            delete wrapper.second;
        }
    }
};
