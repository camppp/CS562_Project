#include <iostream>
#include <string>
#include <cstdint>

class Packet {
public:
    uint16_t port;
    std::string data;
};

class ClientTester {
public:
    ClientTester(uint16_t port) : port_(port) {}

    void startListening() {
        // Initialize the listening socket
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock == -1) {
            std::cerr << "Error creating socket" << std::endl;
            return;
        }

        // Bind the socket to the specified port
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port_);
        addr.sin_addr.s_addr = INADDR_ANY;
        if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == -1) {
            std::cerr << "Error binding socket" << std::endl;
            return;
        }

        // Listen for incoming packets
        if (listen(sock, 1) == -1) {
            std::cerr << "Error listening for incoming packets" << std::endl;
            return;
        }

        // Process incoming packets
        while (true) {
            // Receive the packet
            sockaddr_in sender;
            int sender_len = sizeof(sender);
            char buffer[1024];
            int bytes_received = recvfrom(sock, buffer, 1024, 0, (sockaddr*)&sender, &sender_len);
            if (bytes_received == -1) {
                std::cerr << "Error receiving packet" << std::endl;
                return;
            }

            // Process the packet
            Packet packet;
            packet.port = sender.sin_port;
            packet.data = std::string(buffer, bytes_received);
            processPacket(packet);
        }
    }

    void processPacket(const Packet& packet) {
        // Implement packet processing logic here
        std::cout << "Received packet from port " << packet.port << ": " << packet.data << std::endl;
    }

private:
    uint16_t port_;
};
