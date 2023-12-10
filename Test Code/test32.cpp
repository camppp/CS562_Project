#include <iostream>
#include <unordered_map>
#include <vector>

// Define LogId type
using LogId = int;

// Define KVLogList type
using KVLogList = std::vector<std::pair<std::string, std::string>>;

// Define Logger interface
class Logger {
public:
    virtual void log(LogId id, KVLogList kv_list) = 0;
};

// Implement MyLogger class
class MyLogger : public Logger {
private:
    std::unordered_map<LogId, KVLogList> logMap;

public:
    void log(LogId id, KVLogList kv_list) override {
        logMap[id] = kv_list;
    }

    // Method to retrieve logged key-value pairs for a given log ID
    KVLogList getLoggedValues(LogId id) {
        return logMap[id];
    }
};

int main() {
    // Create an instance of MyLogger
    MyLogger myLogger;

    // Log key-value pairs for log ID 1
    myLogger.log(1, {{"key1", "value1"}, {"key2", "value2"}});

    // Retrieve and print logged key-value pairs for log ID 1
    KVLogList loggedValues = myLogger.getLoggedValues(1);
    for (const auto& pair : loggedValues) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
