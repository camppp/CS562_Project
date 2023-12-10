void setupUnixSocketAddress(int family, const std::string& port, struct sockaddr_storage& sockaddr_) {
    // Initialize the sockaddr_un structure
    struct sockaddr_un addr;
    addr.sun_family = family;
    memmove(addr.sun_path, port.c_str(), port.size());

    // Set up the sockaddr_storage structure
    memmove(&sockaddr_, (struct sockaddr_storage *)&addr, sizeof(addr));
}
