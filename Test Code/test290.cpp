#include <iostream>
#include <vector>
#include <algorithm>

// Define an enum for different types of events
enum class EventType {
    MouseClick,
    KeyPress,
    FocusChange
};

// Define a class for event suppression
class EventSuppressor {
private:
    std::vector<EventType> suppressedEvents;

public:
    EventSuppressor(std::initializer_list<EventType> events) : suppressedEvents(events) {}

    void suppressEvents() {
        // Implement event suppression logic here
        std::cout << "Suppressing events: ";
        for (const auto& event : suppressedEvents) {
            std::cout << static_cast<int>(event) << " ";
        }
        std::cout << std::endl;
    }

    ~EventSuppressor() {
        // Automatically unsuppress events when the scope ends
        unsuppressEvents();
    }

    void unsuppressEvents() {
        // Implement event unsuppression logic here
        std::cout << "Unsuppressing events: ";
        for (const auto& event : suppressedEvents) {
            std::cout << static_cast<int>(event) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage of EventSuppressor
    {
        EventSuppressor suppressor1{EventType::MouseClick, EventType::KeyPress};
        suppressor1.suppressEvents();

        // Nested event suppression
        {
            EventSuppressor suppressor2{EventType::FocusChange};
            suppressor2.suppressEvents();
        } // suppressor2 goes out of scope, unsuppresses events

    } // suppressor1 goes out of scope, unsuppresses events

    return 0;
}
