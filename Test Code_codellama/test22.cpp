#include <SFML/Network.hpp>

int main()
{
    // connections on port 55001
    sf::TcpListener listener;
    listener.listen(55001);
    // Endless loop that waits for new connections
    bool running = true;
    while (running)
    {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done)
        {
            // A new client just connected!
            std::string message = "Welcome to the server!";
            client.send(message.c_str(), message.length() + 1);
        }
    }
    return 0;
}
