// wait for an acknowledgement from that remote server
//-----------------------------------------------------
char buf[MTU];
bzero(&buf, MTU);

int rxbytes = recv(sock, buf, MTU, 0);
if (rxbytes < 0) {
    // handle error
    perror("Error receiving acknowledgement");
} else if (rxbytes == 0) {
    // handle disconnection or empty message
    printf("Error: Acknowledgement not received\n");
} else {
    // handle received acknowledgement
    printf("Acknowledgement received\n");
    // Further actions based on the acknowledgement status
    // ...
}
