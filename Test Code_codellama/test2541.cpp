#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// Forward declaration of the Generator class
class Generator;

// Define the VoxelData struct
struct VoxelData {
    int x, y, z;
    bool is_empty;
};

// Define the AsyncGenerator class
class AsyncGenerator : public Generator {
public:
    AsyncGenerator(int size) : size_(size) {}

    void start() {
        // Start the generation thread
        std::thread gen_thread([this]() {
            // Generate the voxel data
            for (int i = 0; i < size_; i++) {
                VoxelData data;
                data.x = i;
                data.y = i;
                data.z = i;
                data.is_empty = false;
                voxel_data_.push_back(data);
            }

            // Notify the consumer that the generation is complete
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.notify_all();
        });

        // Start the consumer thread
        std::thread consumer_thread([this]() {
            // Wait for the generation to complete
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [this]() { return !voxel_data_.empty(); });

            // Iterate over the generated voxel data
            while (hasNext()) {
                VoxelData data = next();
                // Process the voxel data
                std::cout << "Voxel data: " << data.x << ", " << data.y << ", " << data.z << std::endl;
            }
        });

        // Join the generation and consumer threads
        gen_thread.join();
        consumer_thread.join();
    }

    bool hasNext() const {
        std::unique_lock<std::mutex> lock(mutex_);
        return !voxel_data_.empty();
    }

    VoxelData next() {
        std::unique_lock<std::mutex> lock(mutex_);
        VoxelData data = voxel_data_.front();
        voxel_data_.pop_front();
        return data;
    }

private:
    int size_;
    std::vector<VoxelData> voxel_data_;
    std::mutex mutex_;
    std::condition_variable cv_;
};
