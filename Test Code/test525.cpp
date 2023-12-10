#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

void errorHandling(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        errorHandling("socket err");
    }
    struct sockaddr_in myAddr;
    memset(&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family      = AF_INET;
    myAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    myAddr.sin_port        = htons(6666);

    int bindFlag = bind(sock, (struct sockaddr *) &myAddr, sizeof(myAddr));

    if (bindFlag < 0) {
        errorHandling("bind err");
    }

    printf("Server is ready\n");

    return 0;
}
