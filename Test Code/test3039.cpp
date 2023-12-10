#include <iostream>
#include <cstdint>

// Assume the existence of a Packet class with appropriate attributes and methods
class Packet {
    // Attributes and methods of the Packet class
};

class ClientTester {
private:
    uint16_t port;

public:
    // Constructor to initialize the port
    ClientTester(uint16_t port) : port(port) {}

    // Method to start listening on the specified port
    void startListening() {
        std::cout << "Listening on port " << port << std::endl;
        // Logic to start listening for incoming packets
    }

    // Method to process the incoming packet
    void processPacket(const Packet& packet) {
        // Logic to process the incoming packet
        std::cout << "Processing packet" << std::endl;
    }
};

int main() {
    // Example usage of the ClientTester class
    ClientTester client(8080); // Initialize with port 8080
    client.startListening();   // Start listening on the specified port

    // Simulate receiving a packet and process it
    Packet receivedPacket;
    client.processPacket(receivedPacket);

    return 0;
}
