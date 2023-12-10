#include <iostream>
#include <vector>

class EventSuppressor {
public:
    // Constructor
    EventSuppressor(std::vector<int> eventsToSuppress) : eventsToSuppress_(eventsToSuppress) {}

    // Function to suppress events within the scope of the EventSuppressor instance
    void suppressEvents(std::vector<int> eventsToSuppress) {
        for (int event : eventsToSuppress) {
            eventsToSuppress_.push_back(event);
        }
    }

    // Function to unsuppress events within the scope of the EventSuppressor instance
    void unsuppressEvents(std::vector<int> eventsToUnsuppress) {
        for (int event : eventsToUnsuppress) {
            eventsToSuppress_.erase(std::remove(eventsToSuppress_.begin(), eventsToSuppress_.end(), event), eventsToSuppress_.end());
        }
    }

    // Function to check if an event is currently being suppressed
    bool isEventSuppressed(int event) {
        return std::find(eventsToSuppress_.begin(), eventsToSuppress_.end(), event) != eventsToSuppress_.end();
    }

private:
    std::vector<int> eventsToSuppress_;
};

int main() {
    // Create an instance of the EventSuppressor class with the events to suppress
    EventSuppressor suppressor({1, 2, 3});

    // Suppress the events within the scope of the EventSuppressor instance
    suppressor.suppressEvents({1, 2});

    // Check if the events are currently being suppressed
    std::cout << "Event 1 is suppressed: " << suppressor.isEventSuppressed(1) << std::endl;
    std::cout << "Event 2 is suppressed: " << suppressor.isEventSuppressed(2) << std::endl;
    std::cout << "Event 3 is suppressed: " << suppressor.isEventSuppressed(3) << std::endl;

    // Unsuppress the events within the scope of the EventSuppressor instance
    suppressor.unsuppressEvents({1, 2});

    // Check if the events are no longer being suppressed
    std::cout << "Event 1 is suppressed: " << suppressor.isEventSuppressed(1) << std::endl;
    std::cout << "Event 2 is suppressed: " << suppressor.isEventSuppressed(2) << std::endl;
    std::cout << "Event 3 is suppressed: " << suppressor.isEventSuppressed(3) << std::endl;

    return 0;
}
