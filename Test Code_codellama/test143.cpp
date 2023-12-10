#include <iostream>
#include <map>

class MessageBuilder {
public:
    void Add(const std::string& message, int id) {
        messages_[id] = message;
    }

    std::string GetMessage(int id) {
        auto it = messages_.find(id);
        if (it != messages_.end()) {
            return it->second;
        }
        return "";
    }

private:
    std::map<int, std::string> messages_;
};

int main() {
    MessageBuilder builder;

    builder.Add("gaiaLoading", IDS_LOGIN_GAIA_LOADING_MESSAGE);
    builder.Add("gaiaError", IDS_LOGIN_GAIA_ERROR_MESSAGE);

    std::cout << builder.GetMessage(IDS_LOGIN_GAIA_LOADING_MESSAGE) << std::endl;
    std::cout << builder.GetMessage(IDS_LOGIN_GAIA_ERROR_MESSAGE) << std::endl;

    return 0;
}
