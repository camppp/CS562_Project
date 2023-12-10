#include <deque>
#include <mutex>

template <typename T>
class ThreadSafeWorkQueue {
private:
    std::deque<T*> _works;
    std::mutex _work_lock;

public:
    void add(T* item) {
        std::lock_guard<std::mutex> lock(_work_lock);
        _works.push_back(item);
    }

    T* get() {
        std::lock_guard<std::mutex> lock(_work_lock);
        T* item = _works.front();
        _works.pop_front();
        return item;
    }

    void rest(T* t) {
        std::lock_guard<std::mutex> lock(_work_lock);
        for (typename std::deque<T*>::iterator iter = _works.begin(); iter != _works.end(); iter++) {
            if (*iter == t) {
                _works.erase(iter);
                break;
            }
        }
    }

    size_t available() const {
        std::lock_guard<std::mutex> lock(_work_lock);
        return _works.size();
    }
};
