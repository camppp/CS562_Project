#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>

class FenceManager {
public:
    void CreateFence(int fenceValue) {
        std::unique_lock<std::mutex> lock(_mutex);
        _fenceValues.push_back(fenceValue);
        _fences.push_back(false);
    }

    void SignalFence(int fenceValue) {
        std::unique_lock<std::mutex> lock(_mutex);
        auto it = std::find(_fenceValues.begin(), _fenceValues.end(), fenceValue);
        if (it != _fenceValues.end()) {
            size_t index = std::distance(_fenceValues.begin(), it);
            _fences[index] = true;
            _cv.notify_all();
        }
    }

    void WaitForFence(int fenceValue) {
        std::unique_lock<std::mutex> lock(_mutex);
        auto it = std::find(_fenceValues.begin(), _fenceValues.end(), fenceValue);
        if (it != _fenceValues.end()) {
            size_t index = std::distance(_fenceValues.begin(), it);
            _cv.wait(lock, [this, index] { return _fences[index]; });
        }
    }

private:
    std::vector<int> _fenceValues;
    std::vector<bool> _fences;
    std::mutex _mutex;
    std::condition_variable _cv;
};

int main() {
    FenceManager fenceManager;

    // Create fences
    fenceManager.CreateFence(1);
    fenceManager.CreateFence(2);
    fenceManager.CreateFence(3);

    // Signal fences from different threads
    std::thread t1([&fenceManager] { fenceManager.SignalFence(1); });
    std::thread t2([&fenceManager] { fenceManager.SignalFence(2); });
    std::thread t3([&fenceManager] { fenceManager.SignalFence(3); });

    t1.join();
    t2.join();
    t3.join();

    // Wait for fences to be signaled
    fenceManager.WaitForFence(1);
    fenceManager.WaitForFence(2);
    fenceManager.WaitForFence(3);

    std::cout << "All fences signaled." << std::endl;

    return 0;
}
