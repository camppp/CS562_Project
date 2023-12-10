#include <queue>
#include <memory>
#include <iostream>

// Event structure representing an event with a unique identifier and a timestamp
struct Event {
    int id;
    long long timestamp;
    // Other event properties and methods
    // ...
    void Delete() {
        // Implementation to delete the event
        std::cout << "Event " << id << " deleted." << std::endl;
    }
};

// Custom comparator for priority_queue to compare events based on their timestamps
struct EventComparator {
    bool operator()(const Event& e1, const Event& e2) const {
        return e1.timestamp > e2.timestamp; // Min heap based on timestamp
    }
};

class EventQueue {
private:
    std::priority_queue<Event, std::vector<Event>, EventComparator> events;

public:
    // Method to enqueue an event into the queue
    void Enqueue(const Event& event) {
        events.push(event);
    }

    // Method to dequeue an event from the queue and return it to the caller
    Event Dequeue() {
        Event dequeuedEvent = events.top();
        events.pop();
        return dequeuedEvent;
    }

    // Method to remove the event from the top of the queue and return it to the caller
    Event RemoveFromTop() {
        Event topEvent = events.top();
        events.pop();
        return topEvent;
    }
};

int main() {
    Event e1{1, 100}; // Sample events with unique identifiers and timestamps
    Event e2{2, 50};
    Event e3{3, 200};

    EventQueue eventQueue;
    eventQueue.Enqueue(e1);
    eventQueue.Enqueue(e2);
    eventQueue.Enqueue(e3);

    Event removedEvent = eventQueue.RemoveFromTop();
    removedEvent.Delete(); // Caller takes ownership and calls Delete on the removed event

    return 0;
}
