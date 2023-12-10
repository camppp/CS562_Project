#include <iostream>
#include <vector>
#include <string>

class Event {
private:
    int id;
    std::string title;
    std::string date;
    std::string description;

public:
    Event(int id, const std::string& title, const std::string& date, const std::string& description)
        : id(id), title(title), date(date), description(description) {}

    void updateEvent(const std::string& newTitle, const std::string& newDate, const std::string& newDescription) {
        title = newTitle;
        date = newDate;
        description = newDescription;
    }

    void deleteEvent() {
        // Implement deletion logic here, such as marking the event as deleted or removing it from the system
    }

    void displayEventDetails() const {
        std::cout << "Event ID: " << id << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

int main() {
    std::vector<Event> events;

    // Create events
    Event event1(1, "Birthday Party", "2022-05-15", "Join us for a fun-filled birthday celebration!");
    Event event2(2, "Conference", "2022-06-20", "A conference on emerging technologies");

    events.push_back(event1);
    events.push_back(event2);

    // Update event details
    events[0].updateEvent("Birthday Bash", "2022-05-15", "An amazing birthday bash!");

    // Delete an event
    events.erase(events.begin() + 1);

    // Display event details
    for (const auto& event : events) {
        event.displayEventDetails();
    }

    return 0;
}
