#include <iostream>
#include <map>
#include <functional>

class HttpCommandManager {
public:
    void registerCommand(const std::string& command, std::function<void(const std::string&)> callback) {
        commands_[command] = callback;
    }

    void sendRequest(const std::string& command, const std::string& request) {
        // Send the HTTP request and store the response in a buffer
        std::string response;
        // Invoke the callback function associated with the command
        commands_[command](response);
    }

private:
    std::map<std::string, std::function<void(const std::string&)>> commands_;
};
