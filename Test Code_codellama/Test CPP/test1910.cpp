class LogEvent {
private:
    long long timestamp;
    string data;

public:
    LogEvent(long long timestamp, string data) : timestamp(timestamp), data(data) {}

    bool operator==(const LogEvent& other) const {
        return timestamp == other.timestamp;
    }

    bool operator!=(const LogEvent& other) const {
        return timestamp != other.timestamp;
    }

    static pair<LogEvent, LogEvent> make_next_log_events_test_pair(const LogEvent& event) {
        long long next_timestamp = event.timestamp + 100;
        string next_data = "Next log event";
        return make_pair(LogEvent(next_timestamp, next_data), LogEvent(next_timestamp + 100, next_data));
    }
};
