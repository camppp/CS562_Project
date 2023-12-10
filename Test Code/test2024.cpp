#include <iostream>
#include <WinSock2.h>

enum address_family {
    AF_INET,
    AF_INET6
};

class udp_socket {
    // Define the udp_socket class as per your requirements
};

class efef {
public:
    int GetLastError() {
        // Returns the last error encountered
        return WSAGetLastError();
    }

    udp_socket CreateUDPSocket(address_family family) {
        int af = 0;
        switch (family) {
            case AF_INET:
                af = AF_INET;
                break;
            case AF_INET6:
                af = AF_INET6;
                break;
        }
        SOCKET sock = socket(af, SOCK_DGRAM, IPPROTO_UDP);
        if (sock == INVALID_SOCKET) {
            std::cerr << "Failed to create UDP socket. Error code: " << WSAGetLastError() << std::endl;
            // Handle error or throw an exception
        }
        // Return the created UDP socket
        return udp_socket(sock);
    }
};
