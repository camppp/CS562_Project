#include <iostream>
#include <unordered_map>

class MessageBuilder {
private:
    std::unordered_map<std::string, std::string> messages;

public:
    void Add(const std::string& id, const std::string& message) {
        messages[id] = message;
    }

    std::string GetMessage(const std::string& id) {
        auto it = messages.find(id);
        if (it != messages.end()) {
            return it->second;
        } else {
            return "";
        }
    }
};

int main() {
    MessageBuilder* builder = new MessageBuilder();

    // Adding messages
    builder->Add("gaiaLoading", "Loading message for Gaia");

    // Retrieving messages
    std::cout << "Message for gaiaLoading: " << builder->GetMessage("gaiaLoading") << std::endl;
    std::cout << "Message for nonExistingID: " << builder->GetMessage("nonExistingID") << std::endl;

    delete builder;
    return 0;
}
