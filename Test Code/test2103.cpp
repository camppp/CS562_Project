#include <iostream>
#include <vector>
#include <string>

enum EventType {
    gamepad_button_down_event,
    gamepad_button_up_event,
    quit_event,
    window_manager_event,
    video_resize_event,
    user_event
};

class Event {
public:
    EventType type;
    std::string data;
};

class EventHandler {
private:
    std::vector<Event> events;

public:
    void addEvent(EventType type, const std::string& data) {
        Event newEvent;
        newEvent.type = type;
        newEvent.data = data;
        events.push_back(newEvent);
    }

    void processEvents() {
        for (const auto& event : events) {
            std::string eventType;
            switch (event.type) {
                case gamepad_button_down_event:
                    eventType = "Gamepad Button Down Event";
                    break;
                case gamepad_button_up_event:
                    eventType = "Gamepad Button Up Event";
                    break;
                case quit_event:
                    eventType = "Quit Event";
                    break;
                case window_manager_event:
                    eventType = "Window Manager Event";
                    break;
                case video_resize_event:
                    eventType = "Video Resize Event";
                    break;
                case user_event:
                    eventType = "User Event";
                    break;
                default:
                    eventType = "Unknown Event";
                    break;
            }
            std::cout << "Event Type: " << eventType << ", Data: " << event.data << std::endl;
        }
    }
};

int main() {
    EventHandler eventHandler;
    eventHandler.addEvent(gamepad_button_down_event, "Button A");
    eventHandler.addEvent(quit_event, "User requested quit");
    eventHandler.addEvent(video_resize_event, "New resolution: 1920x1080");
    eventHandler.processEvents();

    return 0;
}
