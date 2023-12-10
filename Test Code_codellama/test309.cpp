#include <iostream>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

void *UDPClientThread(void* args) {
    // Create a UDP socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return NULL;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        close(sock);
        return NULL;
    }

    // Send a message to the server
    char message[] = "Hello, Server!";
    send(sock, message, strlen(message), 0);

    // Receive a response from the server
    char response[1024];
    recv(sock, response, 1024, 0);
    std::cout << "Received response: " << response << std::endl;

    // Close the connection
    close(sock);

    return NULL;
}
