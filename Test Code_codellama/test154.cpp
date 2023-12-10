#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "QEMU.h"

// Helper function to generate a random MAC address
std::string generateRandomMACAddress() {
    std::string mac_address;
    for (int i = 0; i < 6; i++) {
        mac_address += std::to_string(rand() % 256);
        if (i < 5) {
            mac_address += ":";
        }
    }
    return mac_address;
}

// Helper function to generate a link name for the interface
std::string generateLinkName(const std::string &prefix, int length) {
    std::string link_name;
    for (int i = 0; i < length; i++) {
        link_name += std::to_string(rand() % 256);
        if (i < length - 1) {
            link_name += "-";
        }
    }
    return link_name;
}

// Function to set up the network environment for a QEMU virtualization instance
int setupNetworkEnvironment(QemuContext &ctx) {
    // Allocate a TUN/TAP network interface
    std::string tun_interface = QEMU_allocate_tun(ctx);
    if (tun_interface.empty()) {
        std::cerr << "Failed to allocate TUN/TAP network interface" << std::endl;
        return -1;
    }

    // Generate a random MAC address
    std::string mac_address = generateRandomMACAddress();

    // Create a link name for the interface
    std::string link_name = generateLinkName("qemu", 8);

    // Allocate a MACVTAP interface
    std::string macvtap_interface = QEMU_allocate_macvtap(ctx, mac_address, link_name);
    if (macvtap_interface.empty()) {
        std::cerr << "Failed to allocate MACVTAP network interface" << std::endl;
        return -1;
    }

    // Open a QMP socket
    int qmp_socket = QEMU_OpenQMPSocket(ctx);
    if (qmp_socket < 0) {
        std::cerr << "Failed to open QMP socket" << std::endl;
        return -1;
    }

    // Return the socket file descriptor
    return qmp_socket;
}
