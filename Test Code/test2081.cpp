#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    char buffer[1024];

    // Create a UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set socket options to allow reusing the address and port
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        exit(1);
    }

    // Bind the socket to a specific port and address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server_addr, server_len) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Receive incoming UDP datagrams
    while (1) {
        int n = recvfrom(sock, buffer, 1024, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom failed");
            exit(1);
        }

        // Process the received datagram and send a response back to the client
        // ...

        // Send the response back to the client
        sendto(sock, buffer, n, 0, (struct sockaddr *)&server_addr, server_len);
    }

    return 0;
}
