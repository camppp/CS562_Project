#include <queue>
#include <vector>

template <typename T>
class PriorityQueue {
public:
    PriorityQueue() {}

    void enqueue(T item, int priority) {
        // Add the item to the queue with the specified priority
        queue_.push(std::make_pair(priority, item));

        // If the priority is higher than the current highest priority,
        // update the highest priority
        if (priority > highest_priority_) {
            highest_priority_ = priority;
        }
    }

    T dequeue() {
        // If the queue is empty, return an empty item
        if (queue_.empty()) {
            return T();
        }

        // Get the highest priority item from the queue
        auto highest_priority_item = queue_.front();
        queue_.pop();

        // Return the item with the highest priority
        return highest_priority_item.second;
    }

private:
    std::queue<std::pair<int, T>> queue_;
    int highest_priority_ = 0;
};
