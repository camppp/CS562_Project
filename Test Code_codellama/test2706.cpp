c
// wait for an acknowledgement from that remote server
//-----------------------------------------------------
char buf[MTU];
bzero(&buf, MTU);

int rxbytes = recv(sock, buf, MTU, 0);
if (rxbytes < 0) {
    // handle error
    printf("Error: Acknowledgement not received\n");
} else {
    // handle acknowledgement
    printf("Acknowledgement received\n");
    // proceed with further actions
}
