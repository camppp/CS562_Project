#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TEST_PROTOCOL 0  // Replace with the actual protocol number

int createRawSocket(int argc, char *argv[]) {
    int socketFamily = AF_INET;  // Default to IPv4

    if (argc > 1) {
        if (!strcmp(argv[1], "-4"))
            socketFamily = AF_INET;
        else if (!strcmp(argv[1], "-6"))
            socketFamily = AF_INET6;
    }

    int fd = socket(socketFamily, SOCK_RAW, TEST_PROTOCOL);
    if (fd == -1) {
        perror("Socket creation failed");
        // Handle error or exit
    }

    return fd;
}
