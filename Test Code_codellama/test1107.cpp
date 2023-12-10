c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void errorHandling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main() {
    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
        errorHandling("socket() error");

    struct sockaddr_in yourAddr;
    memset(&yourAddr, 0, sizeof(yourAddr));
    yourAddr.sin_family = AF_INET;
    yourAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    yourAddr.sin_port = htons(atoi("YOUR_PORT_NUMBER"));

    if (bind(sock, (struct sockaddr *)&yourAddr, sizeof(yourAddr)) == -1)
        errorHandling("bind() error");

    // Handle incoming messages
    while (1) {
        char buffer[1024];
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int bytesReceived = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (bytesReceived == -1) {
            errorHandling("recvfrom() error");
        }

        // Process the received message
        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        char response[1024];
        sprintf(response, "Hello from the server!");
        sendto(sock, response, strlen(response), 0, (struct sockaddr *)&clientAddr, clientAddrLen);
    }

    close(sock);
    return 0;
}
