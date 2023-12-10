#include <iostream>
#include <string>
#include <utility>

class LogEvent {
private:
    long long timestamp;
    std::string data;

public:
    LogEvent(long long ts, const std::string& d) : timestamp(ts), data(d) {}

    bool operator==(const LogEvent& other) const {
        return timestamp == other.timestamp;
    }

    bool operator!=(const LogEvent& other) const {
        return timestamp != other.timestamp;
    }
};

std::pair<LogEvent, LogEvent> make_next_log_events_test_pair() {
    LogEvent first(1000, "First event data");
    LogEvent second(1100, "Second event data");
    return std::make_pair(first, second);
}

int main() {
    auto [first, second] = make_next_log_events_test_pair();
    second = first;
    second.timestamp = first.timestamp + 100;
    bool equal = (first == second);
    std::cout << "Are the log events equal? " << std::boolalpha << equal << std::endl;
    return 0;
}
