#include <iostream>
#include <string>
#include <map>

// Define a macro to define a new log channel
#define SA_LOG_CHAN_DEFINE(name) \
    static constexpr char name[] = #name; \
    static constexpr size_t name##_len = sizeof(name) - 1; \
    static constexpr char name##_prefix[] = "[" #name "] "; \
    static constexpr size_t name##_prefix_len = sizeof(name##_prefix) - 1;

// Define a class to represent a log channel
class LogChannel {
public:
    LogChannel(const char* name, size_t name_len, const char* prefix, size_t prefix_len)
        : name(name), name_len(name_len), prefix(prefix), prefix_len(prefix_len) {}

    const char* name;
    size_t name_len;
    const char* prefix;
    size_t prefix_len;
};

// Define a class to represent the logger
class Logger {
public:
    // Constructor
    Logger() {}

    // Method to log a message to a specific channel
    void log(const char* channel, const char* message) {
        // Check if the channel is enabled
        if (enabled_channels.find(channel) != enabled_channels.end()) {
            // Log the message to the channel
            std::cout << prefix(channel) << message << std::endl;
        }
    }

    // Method to enable or disable a specific log channel
    void enableChannel(const char* channel) {
        enabled_channels.insert(channel);
    }

    void disableChannel(const char* channel) {
        enabled_channels.erase(channel);
    }

    // Method to define a new log channel using the SA_LOG_CHAN_DEFINE macro
    void defineChannel(const char* name, size_t name_len, const char* prefix, size_t prefix_len) {
        // Create a new log channel
        LogChannel channel(name, name_len, prefix, prefix_len);

        // Add the channel to the map of enabled channels
        enabled_channels.insert(channel);
    }

private:
    // Map of enabled log channels
    std::map<const char*, LogChannel> enabled_channels;

    // Method to generate the prefix for a log channel
    std::string prefix(const char* channel) {
        // Get the log channel
        LogChannel log_channel = enabled_channels[channel];

        // Generate the prefix
        return std::string(log_channel.prefix, log_channel.prefix_len) + channel + ": ";
    }
};

// Sample usage of the Logger class
int main() {
    // Create a new logger
    Logger logger;

    // Define a new log channel
    SA_LOG_CHAN_DEFINE(my_channel);

    // Enable the log channel
    logger.enableChannel("my_channel");

    // Log a message to the channel
    logger.log("my_channel", "Hello, world!");

    // Disable the log channel
    logger.disableChannel("my_channel");

    // Log a message to the channel (nothing will be logged)
    logger.log("my_channel", "Hello, world!");

    return 0;
}
