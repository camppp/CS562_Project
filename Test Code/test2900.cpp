#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketException {
public:
    SocketException(const char* message, bool critical) : message(message), critical(critical) {}
    const char* getMessage() const { return message; }
    bool isCritical() const { return critical; }
private:
    const char* message;
    bool critical;
};

class CommunicatingSocket {
public:
    CommunicatingSocket() : socketDescriptor(-1) {}

    void connectToServer(const char* serverAddress, int port) {
        // Create a socket
        socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
        if (socketDescriptor < 0) {
            throw SocketException("Socket creation failed", true);
        }

        // Set up the server address
        sockaddr_in destAddr;
        memset(&destAddr, 0, sizeof(destAddr));
        destAddr.sin_family = AF_INET;
        destAddr.sin_addr.s_addr = inet_addr(serverAddress);
        destAddr.sin_port = htons(port);

        // Try to connect to the given port
        if (::connect(socketDescriptor, (sockaddr*)&destAddr, sizeof(destAddr)) < 0) {
            throw SocketException("Connect failed", true);
        }
    }

    void send(const void* buffer, int bufferLen) {
        if (::send(socketDescriptor, static_cast<const char*>(buffer), bufferLen, 0) < 0) {
            throw SocketException("Send failed", true);
        }
    }

    void receive(void* buffer, int bufferLen) {
        int bytesReceived = ::recv(socketDescriptor, static_cast<char*>(buffer), bufferLen, 0);
        if (bytesReceived < 0) {
            throw SocketException("Receive failed", false);
        }
    }

    ~CommunicatingSocket() {
        if (socketDescriptor >= 0) {
            close(socketDescriptor);
        }
    }

private:
    int socketDescriptor;
};
