c
#include <iostream>
#include <vector>
#include <string>

// EventType enumeration
enum EventType {
    gamepad_button_down_event,
    gamepad_button_up_event,
    quit_event,
    window_manager_event,
    video_resize_event,
    user_event
};

// Event class
class Event {
public:
    Event(EventType type, const std::string& data) : type(type), data(data) {}

    EventType type;
    std::string data;
};

// EventHandler class
class EventHandler {
public:
    void addEvent(EventType type, const std::string& data) {
        events.push_back(Event(type, data));
    }

    void processEvents() {
        for (const auto& event : events) {
            std::cout << "Event type: " << event.type << std::endl;
            std::cout << "Event data: " << event.data << std::endl;
        }
    }

private:
    std::vector<Event> events;
};

int main() {
    // Create an EventHandler instance
    EventHandler eventHandler;

    // Add some events
    eventHandler.addEvent(gamepad_button_down_event, "Button 1 down");
    eventHandler.addEvent(gamepad_button_up_event, "Button 1 up");
    eventHandler.addEvent(quit_event, "Quit event");
    eventHandler.addEvent(window_manager_event, "Window manager event");
    eventHandler.addEvent(video_resize_event, "Video resize event");
    eventHandler.addEvent(user_event, "User event");

    // Process the events
    eventHandler.processEvents();

    return 0;
}
