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

int main() {
    // Create a TraceChannel object with the name "RCF"
    TraceChannel& rcfTraceChannel = getTraceChannel();

    // Log some messages to the channel
    rcfTraceChannel.logMessage("Message 1");
    rcfTraceChannel.logMessage("Message 2");
    rcfTraceChannel.logMessage("Message 3");

    // Retrieve and print the logged messages
    std::vector<std::string> loggedMessages = rcfTraceChannel.retrieveMessages();
    for (const auto& message : loggedMessages) {
        std::cout << message << std::endl;
    }

    return 0;
}
