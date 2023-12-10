c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void sendMessage(int socketFd, struct sockaddr_in serverAddr, const char* message, size_t headerSize) {
    // Construct the message
    char* msg = (char*)malloc(headerSize + strlen(message) + 1);
    memcpy(msg, &headerSize, sizeof(headerSize));
    memcpy(msg + headerSize, message, strlen(message));
    msg[headerSize + strlen(message)] = '\0';

    // Send the message over the socket
    if (sendto(socketFd, msg, strlen(msg), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("sendto failed");
    }

    // Free the message buffer
    free(msg);
}
