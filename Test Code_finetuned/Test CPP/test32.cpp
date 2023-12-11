#include <map>
#include <vector>
#include <string>

// Define the LogId type
typedef std::string LogId;

// Define the KVLogList type
typedef std::vector<std::pair<std::string, std::string>> KVLogList;

class Logger {
public:
    virtual void log(LogId id, KVLogList kv_list) = 0;
};

class MyLogger : public Logger {
private:
    std::map<LogId, KVLogList> log_map;

public:
    void log(LogId id, KVLogList kv_list) override {
        log_map[id] = kv_list;
    }

    KVLogList getLog(LogId id) {
        return log_map[id];
    }
};