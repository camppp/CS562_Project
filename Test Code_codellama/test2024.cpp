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

    // Create a UDP socket for the specified address family
    SOCKET sock = socket(af, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
        // Handle error
        return udp_socket();
    }

    // Return the created UDP socket
    return udp_socket(sock);
}
