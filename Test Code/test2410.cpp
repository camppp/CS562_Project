#include <iostream>
#include <string>
#include <ljrserver/Address.h>
#include <ljrserver/Socket.h>

ljrserver::Socket* createTCPSocket(const std::string& domain) {
    // Lookup the IP address for the given domain
    ljrserver::Address address;
    if (!ljrserver::Address::LookupAnyIPAddress(domain, address)) {
        std::cerr << "Failed to lookup IP address for domain " << domain << std::endl;
        return nullptr;
    }

    // Create a TCP socket using the obtained IP address
    ljrserver::Socket* socket = ljrserver::Socket::CreateTCP(address);
    if (!socket) {
        std::cerr << "Failed to create TCP socket for domain " << domain << std::endl;
        return nullptr;
    }

    return socket;
}
