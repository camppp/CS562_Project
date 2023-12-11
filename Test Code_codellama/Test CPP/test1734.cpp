#include <iostream>
#include <string>
#include <vector>

class Event {
public:
    Event(int id, const std::string& title, const std::string& date, const std::string& description)
        : id_(id), title_(title), date_(date), description_(description) {}

    void updateEvent(const std::string& newTitle, const std::string& newDate, const std::string& newDescription) {
        title_ = newTitle;
        date_ = newDate;
        description_ = newDescription;
    }

    void deleteEvent() {
        // Remove the event from the vector
        events_.erase(std::remove(events_.begin(), events_.end(), *this), events_.end());
    }

    void displayEventDetails() const {
        std::cout << "Event ID: " << id_ << std::endl;
        std::cout << "Title: " << title_ << std::endl;
        std::cout << "Date: " << date_ << std::endl;
        std::cout << "Description: " << description_ << std::endl;
    }

private:
    int id_;
    std::string title_;
    std::string date_;
    std::string description_;
    static std::vector<Event> events_;
};

std::vector<Event> Event::events_;

int main() {
    Event event1(1, "Birthday Party", "2022-05-15", "Join us for a fun-filled birthday celebration!");
    Event event2(2, "Conference", "2022-06-20", "A conference on emerging technologies");

    events_.push_back(event1);
    events_.push_back(event2);

    // Update event details
    events_[0].updateEvent("Birthday Bash", "2022-05-15", "An amazing birthday bash!");

    // Delete an event
    events_.erase(events_.begin() + 1);

    // Display event details
    for (const auto& event : events_) {
        event.displayEventDetails();
    }

    return 0;
}
