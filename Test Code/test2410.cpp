#include <iostream>
#include <string>
#include "ljrserver.h"  // Assume the necessary library is included

ljrserver::Socket::ptr createTCPSocket(const std::string& domain) {
    ljrserver::IPAddress::ptr addr = ljrserver::Address::LookupAnyIPAddress(domain);
    if (addr) {
        ljrserver::Socket::ptr sock = ljrserver::Socket::CreateTCP(addr);
        return sock;
    } else {
        return nullptr;
    }
}

int main() {
    std::string domain = "www.baidu.com";
    ljrserver::Socket::ptr tcpSocket = createTCPSocket(domain);
    if (tcpSocket) {
        LJRSERVER_LOG_INFO(g_logger) << "TCP socket created successfully for domain: " << domain;
    } else {
        LJRSERVER_LOG_ERROR(g_logger) << "Failed to create TCP socket for domain: " << domain;
    }
    return 0;
}
