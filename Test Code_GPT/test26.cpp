#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

// Assuming the LogId and KVLogList types are defined
using LogId = int;
using KeyValue = std::pair<std::string, std::string>;
using KVLogList = std::vector<KeyValue>;

class Logger {
public:
    virtual void log(LogId id, KVLogList kv_list) = 0;
};

class MyLogger : public Logger {
private:
    std::unordered_map<LogId, KVLogList> logData;

public:
    void log(LogId id, KVLogList kv_list) override {
        logData[id] = std::move(kv_list);
    }

    // Additional method to retrieve key-value pairs for a given LogId
    KVLogList getLogData(LogId id) const {
        auto it = logData.find(id);
        return (it != logData.end()) ? it->second : KVLogList();
    }
};

int main() {
    // Example usage of MyLogger
    MyLogger myLogger;

    // Log key-value pairs for LogId 1
    myLogger.log(1, {{"Key1", "Value1"}, {"Key2", "Value2"}});

    // Retrieve and print key-value pairs for LogId 1
    KVLogList logData = myLogger.getLogData(1);
    for (const auto& kv : logData) {
        std::cout << "Key: " << kv.first << ", Value: " << kv.second << std::endl;
    }

    return 0;
}
