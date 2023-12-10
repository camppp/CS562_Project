#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>
#include <sys/socket.h>

class CUDPSocket {
public:
    CUDPSocket(int port) {
        // Initialize UDP socket
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            std::cerr << "Error creating UDP socket" << std::endl;
            exit(1);
        }

        // Set up socket address
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
    }

    ~CUDPSocket() {
        close(sock);
    }

    void send(const char* message, int length) {
        sendto(sock, message, length, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    }

private:
    int sock;
    struct sockaddr_in server_addr;
};

class CMessage {
public:
    CMessage(const char* content) {
        this->content = content;
    }

    const char* getContent() {
        return content;
    }

private:
    const char* content;
};

class CNetworkServer {
public:
    CNetworkServer(int port) {
        // Initialize UDP socket
        socket = new CUDPSocket(port);
    }

    ~CNetworkServer() {
        delete socket;
    }

    void sendMessage(CMessage* message) {
        socket->send(message->getContent(), strlen(message->getContent()));
    }

private:
    CUDPSocket* socket;
};

int main() {
    CNetworkServer server(1234);
    CMessage message("Hello, world!");
    server.sendMessage(&message);
    return 0;
}
