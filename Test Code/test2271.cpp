#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

void sendMessage(int socketFd, struct sockaddr_in serverAddr, const char* message, size_t headerSize) {
  if (sendto(socketFd, message, strlen(message) + headerSize, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("sendto failed");
  }
}
