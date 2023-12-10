#include <string>
#include <vector>
#include <utility>

class Logger {
public:
    // Append a log with a unique identifier and a JSON payload
    int append_log(const std::string& unique_id, const std::string& payload) {
        // Create a pair of the unique identifier and the JSON payload
        std::pair<std::string, std::string> log(unique_id, payload);

        // Add the log to the vector of logs
        logs.push_back(log);

        // Return the index of the new log
        return logs.size() - 1;
    }

    // Get the index and timestamp of the last log
    void get_last_log(int& index, int& timestamp) {
        // Check if there are any logs
        if (logs.empty()) {
            index = 0;
            timestamp = 0;
            return;
        }

        // Get the last log
        std::pair<std::string, std::string> last_log = logs.back();

        // Set the index and timestamp of the last log
        index = last_log.first;
        timestamp = last_log.second;
    }

private:
    // Data structure to store logs
    std::vector<std::pair<std::string, std::string>> logs;
    int last_index = 0;
};
