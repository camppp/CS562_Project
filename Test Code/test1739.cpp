#include <iostream>
#include <vector>
#include <utility>

// Event class
class Event {
public:
    Event(int id, int timestamp) : id_(id), timestamp_(timestamp) {}
    int getId() const { return id_; }
    int getTimestamp() const { return timestamp_; }

private:
    int id_;
    int timestamp_;
};

// Queue class
class Queue {
public:
    // Enqueue an event
    void enqueue(const Event& event) {
        events_.push_back(event);
    }

    // Dequeue an event
    Event dequeue() {
        // Remove the event with the earliest timestamp
        auto it = std::min_element(events_.begin(), events_.end(),
                                   [](const Event& lhs, const Event& rhs) {
                                       return lhs.getTimestamp() < rhs.getTimestamp();
                                   });
        Event event = *it;
        events_.erase(it);
        return event;
    }

    // Remove the event from the top of the queue and return it to the caller
    Event removeTop() {
        if (events_.empty()) {
            return Event();
        }
        Event event = events_.front();
        events_.pop_front();
        return event;
    }

private:
    std::vector<Event> events_;
};

int main() {
    Queue queue;

    // Enqueue some events
    queue.enqueue(Event(1, 100));
    queue.enqueue(Event(2, 200));
    queue.enqueue(Event(3, 300));

    // Dequeue an event
    Event event = queue.dequeue();
    std::cout << "Dequeued event with id " << event.getId() << " and timestamp " << event.getTimestamp() << std::endl;

    // Remove the event from the top of the queue and return it to the caller
    Event topEvent = queue.removeTop();
    std::cout << "Removed event with id " << topEvent.getId() << " and timestamp " << topEvent.getTimestamp() << std::endl;

    return 0;
}
