#include <mutex>
#include <condition_variable>
#include <queue>
#include <voxel/async_generator.hpp>

namespace VOXEL_NAMESPACE
{
    class AsyncGenerator : public Generator
    {
    public:
        AsyncGenerator(int size) : Generator(size), running(false) {}

        void start()
        {
            running = true;
            generation_thread = std::thread(&AsyncGenerator::generateData, this);
        }

        bool hasNext() const
        {
            std::lock_guard<std::mutex> lock(queue_mutex);
            return !data_queue.empty();
        }

        VoxelData next()
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            data_available.wait(lock, [this] { return !data_queue.empty() || !running; });

            if (!running && data_queue.empty())
            {
                throw std::runtime_error("No more data available");
            }

            VoxelData nextData = data_queue.front();
            data_queue.pop();
            return nextData;
        }

        ~AsyncGenerator()
        {
            running = false;
            if (generation_thread.joinable())
            {
                generation_thread.join();
            }
        }

    private:
        std::thread generation_thread;
        std::queue<VoxelData> data_queue;
        mutable std::mutex queue_mutex;
        std::condition_variable data_available;
        bool running;

        void generateData()
        {
            // Simulated data generation
            for (int i = 0; i < getSize(); ++i)
            {
                VoxelData newData = /* Generate voxel data */;
                {
                    std::lock_guard<std::mutex> lock(queue_mutex);
                    data_queue.push(newData);
                }
                data_available.notify_one();
            }
            running = false;
        }
    };
}  // namespace VOXEL_NAMESPACE
