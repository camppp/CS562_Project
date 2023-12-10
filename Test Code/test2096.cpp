#include <vector>
#include <mutex>

template<typename T>
class LockableVector : public std::vector<T>
{
private:
    std::mutex mtx; // Mutex for synchronization

public:
    void push_back(const T& value) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        std::vector<T>::push_back(value); // Add element to the vector
    }

    void pop_back() {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        if (!std::vector<T>::empty()) {
            std::vector<T>::pop_back(); // Remove the last element from the vector
        }
    }

    T& at(size_t index) {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        return std::vector<T>::at(index); // Return reference to the element at the specified index
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
        return std::vector<T>::size(); // Return the number of elements in the vector
    }
};
