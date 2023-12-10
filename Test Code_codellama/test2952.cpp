#include <atomic>

class Counter {
public:
    Counter() : count(0) {}

    void increment() {
        count.fetch_add(1, std::memory_order_relaxed);
    }

    void decrement() {
        count.fetch_sub(1, std::memory_order_relaxed);
    }

    int get() const {
        return count.load(std::memory_order_relaxed);
    }

private:
    std::atomic<int> count;
};
