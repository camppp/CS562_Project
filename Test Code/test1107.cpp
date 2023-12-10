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

    char buffer[1024];
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    // Receive and process messages
    for (int i = 0; i < 3; i++) {
        int recvLen = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (recvLen == -1)
            errorHandling("recvfrom() error");

        printf("Received message %d: %s\n", i+1, buffer);
        // Process the received message as needed
        // Example: Handle different message types or sizes

        // Clear the buffer for the next message
        memset(buffer, 0, sizeof(buffer));
    }

    close(sock);
    return 0;
}
