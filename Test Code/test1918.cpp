#include <iostream>
#include <unordered_map>
#include <string>

// Macro to define a new log channel
#define SA_LOG_CHAN_DEFINE(channel) static const std::string channel = #channel;

class Logger {
private:
    std::unordered_map<std::string, bool> channelStatus;

public:
    // Method to log messages to a specific channel
    void log(const std::string& channel, const std::string& message) {
        if (channelStatus.find(channel) != channelStatus.end() && channelStatus[channel]) {
            std::cout << "[" << channel << "] " << message << std::endl;
        }
    }

    // Method to enable or disable a specific log channel
    void setChannelStatus(const std::string& channel, bool status) {
        channelStatus[channel] = status;
    }
};

// Define log channels using the macro
SA_LOG_CHAN_DEFINE(Channel1)
SA_LOG_CHAN_DEFINE(Channel2)

int main() {
    Logger logger;

    // Enable or disable log channels
    logger.setChannelStatus(Channel1, true);
    logger.setChannelStatus(Channel2, false);

    // Log messages to specific channels
    logger.log(Channel1, "This message will be logged to Channel1");
    logger.log(Channel2, "This message will not be logged to Channel2");

    return 0;
}
