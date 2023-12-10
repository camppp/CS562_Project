#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>

enum SocketStatus {
    Done,
    Error
};

namespace priv {
    class SocketImpl {
    public:
        static sockaddr_in createAddress(unsigned long address, int port) {
            sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = address;
            addr.sin_port = htons(static_cast<uint16_t>(port));
            return addr;
        }
    };
}

SocketStatus createAndBindSocket(int port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
        return Error;
    }

    // Bind the socket to the specified port
    sockaddr_in addr = priv::SocketImpl::createAddress(INADDR_ANY, port);
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
        close(sock);
        return Error;
    }

    // Return the socket status
    return Done;
}
