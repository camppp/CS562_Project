class MyLogger : public Logger {
public:
    void log(LogId id, KVLogList kv_list) override {
        // Store the key-value pairs in a map with the log ID as the key
        kv_map[id] = kv_list;
    }

private:
    std::map<LogId, KVLogList> kv_map;
};
