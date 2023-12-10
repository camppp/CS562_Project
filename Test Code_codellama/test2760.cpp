#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class Channel {
public:
    void send(T message) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(message);
        condition_.notify_one();
    }

    T receive() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        T message = queue_.front();
        queue_.pop();
        return message;
    }

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};
