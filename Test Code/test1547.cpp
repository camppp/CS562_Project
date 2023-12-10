#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

class ThreadPoolManager {
public:
    ThreadPoolManager(size_t num_threads) : alive_(true), running_tasks_count_(0) {
        for (size_t i = 0; i < num_threads; ++i) {
            threads_.emplace_back([this] { workerThread(); });
        }
    }

    void execute() {
        std::unique_lock<std::mutex> lk(mutex_);
        // At this point, if "alive_ == true" then tasks_pool_ cannot be empty (the lock was reacquired before evaluating the predicate).
        if (alive_) {
            Task task = tasks_pool_.front();
            tasks_pool_.pop();
            lk.unlock();

            ++running_tasks_count_;

            // Execute the task here using the obtained task
            task();  // Assuming Task is a callable object (e.g., function, lambda, functor)

            lk.lock();
            --running_tasks_count_;
            cv_.notify_one();
        }
    }

    void stop() {
        {
            std::lock_guard<std::mutex> lk(mutex_);
            alive_ = false;
        }
        cv_.notify_all();
        for (auto& thread : threads_) {
            thread.join();
        }
    }

private:
    using Task = std::function<void()>;

    std::queue<Task> tasks_pool_;
    std::vector<std::thread> threads_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool alive_;
    size_t running_tasks_count_;

    void workerThread() {
        while (true) {
            std::unique_lock<std::mutex> lk(mutex_);
            cv_.wait(lk, [this] { return !alive_ || !tasks_pool_.empty(); });
            if (!alive_ && tasks_pool_.empty()) {
                return;
            }
            execute();
        }
    }
};
