#include <iostream>
#include <vector>

class Queue {
public:
    void enqueue(int value) {
        if (options->HasKey(constants::kEnqueueKey)) {
            EXTENSION_FUNCTION_VALIDATE(
                options->GetBoolean(constants::kEnqueueKey, &can_enqueue));
            if (can_enqueue) {
                queue.push_back(value);
            }
        } else {
            queue.push_back(value);
        }
    }

    int dequeue() {
        if (queue.empty()) {
            return -1;
        }
        int value = queue.front();
        queue.pop_front();
        return value;
    }

    bool isEmpty() {
        return queue.empty();
    }

private:
    std::vector<int> queue;
    bool can_enqueue;
};
