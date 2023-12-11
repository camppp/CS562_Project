#include <SFML/Network.hpp>
#include <iostream>

int main() {
    sf::TcpSocket socket;

    // Attempt to connect to the server
    if (socket.connect("127.0.0.1", 55001) != sf::Socket::Done) {
        std::cerr << "Error: Unable to connect to the server" << std::endl;
        return 1;
    }

    std::cout << "Connected to the server!" << std::endl;

    // Receive and display the welcome message
    char buffer[100];
    std::size_t received;
    if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
        std::cerr << "Error: Failed to receive welcome message from the server" << std::endl;
    } else {
        std::cout << "Received: " << buffer << std::endl;
    }

    return 0;
}
