#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

int createRawSocket(int argc, char *argv[]) {
    int family = AF_INET; // default to IPv4
    if (argc > 1) {
        if (strcmp(argv[1], "-4") == 0) {
            family = AF_INET;
        } else if (strcmp(argv[1], "-6") == 0) {
            family = AF_INET6;
        }
    }
    int sock = socket(family, SOCK_RAW, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }
    return sock;
}
