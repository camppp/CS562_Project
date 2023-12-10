#include <vector>
#include <mutex>
#include <condition_variable>

template <typename T>
class LockableVector {
public:
    void push_back(const T& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        vector_.push_back(value);
    }

    void pop_back() {
        std::lock_guard<std::mutex> lock(mutex_);
        vector_.pop_back();
    }

    T& at(size_t index) {
        std::lock_guard<std::mutex> lock(mutex_);
        return vector_.at(index);
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return vector_.size();
    }

private:
    std::vector<T> vector_;
    std::mutex mutex_;
};
