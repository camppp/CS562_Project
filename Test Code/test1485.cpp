#include <mutex>
#include <condition_variable>
#include <queue>

template <typename T>
class ThreadSafeQueue {
public:
    void push(const T& value) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(value);
        lock.unlock();  // Unlock before notifying to avoid waking up the waiting thread unnecessarily
        m_condition.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condition.wait(lock, [this] { return !m_queue.empty(); });
        T front = m_queue.front();
        m_queue.pop();
        return front;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

private:
    std::queue<T> m_queue;
    mutable std::mutex m_mutex;
    std::condition_variable m_condition;
};
