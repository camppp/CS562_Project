#include <iostream>
#include <vector>
#include <functional>
#include <omp.h>
#include <mutex>

class Callback {
public:
    void registerCallback(std::function<void()> callback) {
        std::lock_guard<std::mutex> lock(mutex);
        callbacks.push_back(callback);
    }

    void invokeCallbacks() {
        std::lock_guard<std::mutex> lock(mutex);
        for (auto& callback : callbacks) {
            callback();
        }
    }

private:
    std::vector<std::function<void()>> callbacks;
    std::mutex mutex;
};

int main() {
    Callback callback;

    // Registering callbacks
    callback.registerCallback([]() { std::cout << "Callback 1 invoked" << std::endl; });
    callback.registerCallback([]() { std::cout << "Callback 2 invoked" << std::endl; });

    // Simulating parallel processing
    int i = 0;
    omp_set_num_threads(2);
    #pragma omp parallel for for (i = 0; i < 10; i++) {
        // Invoke callbacks within the parallel loop
        callback.invokeCallbacks();
    }

    return 0;
}