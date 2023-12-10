#include <iostream>
#include <string>

// Class to represent a message
class CMessage {
private:
    std::string content;

public:
    CMessage(const std::string& msg) : content(msg) {}

    std::string GetContent() const {
        return content;
    }
};

// Class representing a network server
class CNetworkServer {
private:
    CUDPSocket* m_pSocket;

public:
    // Constructor
    CNetworkServer() {
        m_pSocket = new CUDPSocket;
    }

    // Destructor
    ~CNetworkServer() {
        delete m_pSocket;
    }

    // Method to send a message over the network
    void SendMessage(const CMessage& message) {
        // Assume implementation of SendData method in CUDPSocket to send message content
        m_pSocket->SendData(message.GetContent());
    }
};

int main() {
    CNetworkServer server;
    CMessage message("Hello, world!");
    server.SendMessage(message);
    return 0;
}
