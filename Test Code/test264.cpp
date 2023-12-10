#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

class SocketManager {
private:
    int _socket;
public:
    SocketManager(bool isLocal) {
        if (isLocal) {
            _socket = socket(AF_UNIX, SOCK_STREAM, 0);
        } else {
            _socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        }
    }

    bool isSocketCreatedSuccessfully() {
        return _socket >= 0;
    }
};

int main() {
    // Test the SocketManager class
    SocketManager localSocket(true);
    SocketManager networkSocket(false);

    std::cout << "Local socket created successfully: " << (localSocket.isSocketCreatedSuccessfully() ? "Yes" : "No") << std::endl;
    std::cout << "Network socket created successfully: " << (networkSocket.isSocketCreatedSuccessfully() ? "Yes" : "No") << std::endl;

    return 0;
}
