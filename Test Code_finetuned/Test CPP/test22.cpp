#include <SFML/Network.hpp>
#include <iostream>

int main() {
    // Listen on port 55001
    sf::TcpListener listener;
    listener.listen(55001);

    // Endless loop that waits for new connections
    bool running = true;
    while (running) {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done) {
            // A new client just connected!
            std::string message = "Welcome to the server!";
            client.send(message.c_str(), message.length() + 1);
        }
    }

    return 0;
}


#include <SFML/Network.hpp>
#include <iostream>

int main() {
    sf::TcpSocket socket;
    if (socket.connect("127.0.0.1", 55001) == sf::Socket::Done) {
        char buffer[100];
        std::size_t received;
        socket.receive(buffer, sizeof(buffer), received);
        std::cout << "Received: " << buffer << std::endl;
    } else {
        std::cout << "Failed to connect to server" << std::endl;
    }

    return 0;
}