#include "PrinterSerMsg.hpp"
#include <unordered_map>
#include <string>

class PrinterMessageProcessor {
public:
    void addMessage(const PrinterMessage& message) {
        messages_.insert(std::make_pair(message.messageId, message.messageContent));
    }

    void removeMessage(int messageId) {
        messages_.erase(messageId);
    }

    void clearMessages() {
        messages_.clear();
    }

    int getMessageCount() {
        return messages_.size();
    }

    std::string getMessageById(int messageId) {
        auto it = messages_.find(messageId);
        if (it != messages_.end()) {
            return it->second;
        }
        return "";
    }

private:
    std::unordered_map<int, std::string> messages_;
};
