#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

class IoServicePool {
public:
    IoServicePool(size_t num_threads) {
        // Initialize the pool of I/O service instances
        for (size_t i = 0; i < num_threads; ++i) {
            io_services_.emplace_back(new boost::asio::io_service());
        }

        // Initialize the queue of work objects
        work_queue_.reserve(num_threads);
        for (size_t i = 0; i < num_threads; ++i) {
            work_queue_.emplace_back(new boost::asio::io_service::work(*io_services_[i]));
        }
    }

    ~IoServicePool() {
        // Stop all the I/O services gracefully
        for (auto& io_service : io_services_) {
            io_service->stop();
        }
    }

    void submit_task(boost::asio::io_service::work& work) {
        // Submit the task to the I/O service with the least number of pending tasks
        std::lock_guard<std::mutex> lock(mutex_);
        size_t min_pending_tasks = std::numeric_limits<size_t>::max();
        size_t min_pending_tasks_index = 0;
        for (size_t i = 0; i < io_services_.size(); ++i) {
            if (io_services_[i]->pending_tasks() < min_pending_tasks) {
                min_pending_tasks = io_services_[i]->pending_tasks();
                min_pending_tasks_index = i;
            }
        }
        work_queue_[min_pending_tasks_index].push_back(work);
    }

    void stop_services() {
        // Stop all the I/O services gracefully
        for (auto& io_service : io_services_) {
            io_service->stop();
        }
    }

private:
    std::vector<boost::asio::io_service*> io_services_;
    std::vector<boost::asio::io_service::work*> work_queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
