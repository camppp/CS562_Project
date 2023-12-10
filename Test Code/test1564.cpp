#include <string>
#include <vector>
#include <utility>
#include <chrono>

class Logger {
public:
    // Append a log with a unique identifier and a JSON payload
    int append_log(const std::string& unique_id, const std::string& payload) {
        logs.emplace_back(unique_id, payload);
        last_index = logs.size();
        return last_index;
    }

    // Get the index and timestamp of the last log
    void get_last_log(int& index, int& timestamp) {
        if (logs.empty()) {
            index = 0;
            timestamp = 0;
        } else {
            index = last_index;
            timestamp = static_cast<int>(std::chrono::system_clock::now().time_since_epoch().count());
        }
    }

private:
    // Data structure to store logs
    std::vector<std::pair<std::string, std::string>> logs;
    int last_index = 0;
};
