#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

class SocketManager {
private:
    int _socket;
    bool _isLocal;

public:
    SocketManager(bool isLocal) : _isLocal(isLocal) {
        if (_isLocal) {
            _socket = socket(AF_UNIX, SOCK_STREAM, 0);
        } else {
            _socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        }
    }

    bool isSocketCreatedSuccessfully() {
        return _socket >= 0;
    }

    void closeSocket() {
        if (_socket >= 0) {
            close(_socket);
            _socket = -1;
        }
    }
};
