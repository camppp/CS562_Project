#include "PrinterSerMsg.hpp"
#include <unordered_map>

class PrinterMessageProcessor {
private:
    std::unordered_map<int, std::string> messageMap;

public:
    void addMessage(const PrinterMessage& message) {
        messageMap[message.messageId] = message.messageContent;
    }

    void removeMessage(int messageId) {
        messageMap.erase(messageId);
    }

    void clearMessages() {
        messageMap.clear();
    }

    int getMessageCount() {
        return messageMap.size();
    }

    std::string getMessageById(int messageId) {
        auto it = messageMap.find(messageId);
        if (it != messageMap.end()) {
            return it->second;
        }
        return "";
    }
};
