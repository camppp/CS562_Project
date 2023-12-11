#include <SFML/Network.hpp>
#include <iostream>

int main() {
    // Listen on port 55001
    sf::TcpListener listener;
    if (listener.listen(55001) != sf::Socket::Done) {
        std::cerr << "Error: Unable to bind and listen on port 55001" << std::endl;
        return 1;
    }

    std::cout << "Server is listening on port 55001..." << std::endl;

    // Endless loop that waits for new connections
    bool running = true;
    while (running) {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done) {
            // A new client just connected!
            std::string message = "Welcome to the server!";
            if (client.send(message.c_str(), message.length() + 1) != sf::Socket::Done) {
                std::cerr << "Error: Failed to send welcome message to the client" << std::endl;
            } else {
                std::cout << "Welcome message sent to the client" << std::endl;
            }
        }
    }

    return 0;
}
