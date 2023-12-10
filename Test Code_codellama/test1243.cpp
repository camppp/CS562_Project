#include <vector>
#include <string>

class TraceChannel {
public:
    TraceChannel(const std::string& name) : name(name) {}

    void logMessage(const std::string& message) {
        messages.push_back(message);
    }

    std::vector<std::string> retrieveMessages() const {
        return messages;
    }

private:
    std::string name;
    std::vector<std::string> messages;
};

TraceChannel& getTraceChannel() {
    static TraceChannel traceChannel("RCF");
    return traceChannel;
}
