#include <iostream>

class Message {
public:
    void SetContent(const std::string& content) {
        content_ = content;
    }

    const std::string& GetContent() const {
        return content_;
    }

private:
    std::string content_;
};

class NetworkManager {
public:
    void SendMessage(Message* message) {
        // Simulate sending the message
        std::cout << "Sending message: " << message->GetContent() << std::endl;
    }

    static int32 CheckConnectionThread(void* cookie) {
        NetworkManager* manager = static_cast<NetworkManager*>(cookie);
        manager->CheckInternetConnection();
        return 0;
    }

    void CheckInternetConnection() {
        // Simulate checking internet connection
        std::cout << "Checking internet connection..." << std::endl;
    }
};
