class PathGenerator {
public:
    void tryPut(int id, int position, int data) {
        // Check if the path generator is full
        if (pathGenerator.size() == MAX_PATH_GENERATOR_SIZE) {
            // If the path generator is full, remove the oldest entry
            pathGenerator.pop_front();
        }

        // Add the new entry to the path generator
        pathGenerator.push_back(std::make_tuple(id, position, data));
    }

private:
    std::deque<std::tuple<int, int, int>> pathGenerator;
    const int MAX_PATH_GENERATOR_SIZE = 100;
};

class WaitQueue {
public:
    void push(int id, int position, int randomWaitTime, int timePoint) {
        // Check if the wait queue is full
        if (waitQueue.size() == MAX_WAIT_QUEUE_SIZE) {
            // If the wait queue is full, remove the oldest entry
            waitQueue.pop_front();
        }

        // Add the new entry to the wait queue
        waitQueue.push_back(std::make_tuple(id, position, randomWaitTime, timePoint));
    }

private:
    std::deque<std::tuple<int, int, int, int>> waitQueue;
    const int MAX_WAIT_QUEUE_SIZE = 100;
};
