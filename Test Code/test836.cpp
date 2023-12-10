// Assume the necessary includes and definitions are present

int main() {
    // Assume the client object is initialized and connected to the server

    int iResult;
    char receiveBuffer[512];

    iResult = client.Shutdown();
    do {
        iResult = client.Receive(receiveBuffer, 512);
        if (iResult > 0)
            printf("Bytes received: %d\n", iResult);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());
    } while (iResult > 0);

    // Additional code for closing the client connection and cleanup

    return 0;
}
