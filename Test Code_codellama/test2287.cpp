class MessageQueue {
public:
    MessageQueue() : is_native_loop(false) {}

    void enqueue(WorkItem item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
    }

    WorkItem dequeue() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            return WorkItem();
        }
        WorkItem item = queue_.front();
        queue_.pop();
        return item;
    }

    void execute(WorkItem item) {
        std::lock_guard<std::mutex> lock(mutex_);
        item.execute();
    }

    void setNativeLoop(bool is_native_loop) {
        std::lock_guard<std::mutex> lock(mutex_);
        this->is_native_loop = is_native_loop;
    }

    bool isNativeLoop() {
        std::lock_guard<std::mutex> lock(mutex_);
        return is_native_loop;
    }

    void handleWorkScheduling() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (is_native_loop) {
            // Handle native loop scheduling
        } else {
            // Handle work scheduling
        }
    }

private:
    std::mutex mutex_;
    std::queue<WorkItem> queue_;
    bool is_native_loop;
};
