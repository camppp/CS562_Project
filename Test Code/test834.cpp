#include <queue>
#include <functional>

enum class Priority {
    High,
    Medium,
    Low
};

struct Item {
    std::string record_string;
    Priority event_priority;
    ReportQueue::EnqueueCallback cb;
};

class PriorityQueue {
public:
    void Enqueue(const std::string& record_string, Priority event_priority, ReportQueue::EnqueueCallback cb) {
        items.push({record_string, event_priority, cb});
    }

    void Dequeue() {
        if (!items.empty()) {
            auto item = items.top();
            items.pop();
            // Process the dequeued item
            item.cb(item.record_string, item.event_priority);
        }
    }

private:
    std::priority_queue<Item, std::vector<Item>, std::function<bool(const Item&, const Item&)>> items{
        [](const Item& a, const Item& b) {
            return static_cast<int>(a.event_priority) < static_cast<int>(b.event_priority);
        }
    };
};
