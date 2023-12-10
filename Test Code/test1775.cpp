SocketStatus createAndBindSocket(int port) {
    int socketHandle = socket(AF_INET, SOCK_STREAM, 0);
    if (socketHandle == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return Error;
    }

    sockaddr_in address = priv::SocketImpl::createAddress(INADDR_ANY, port);
    if (bind(socketHandle, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == -1) {
        std::cerr << "Failed to bind socket to port " << port << std::endl;
        close(socketHandle);
        return Error;
    }

    return Done;
}
