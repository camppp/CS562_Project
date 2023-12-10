void * UDPClientThread(void* args) {
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[1024];

    // Create UDP socket
    if ((clientSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error creating socket");
        pthread_exit(NULL);
    }

    // Set up server address
    memset((char *)&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Send message to server
    const char *message = "Hello, Server!";
    if (sendto(clientSocket, message, strlen(message), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error sending message");
        close(clientSocket);
        pthread_exit(NULL);
    }

    // Receive response from server
    int recvBytes = recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, &addrLen);
    if (recvBytes < 0) {
        perror("Error receiving response");
    } else {
        buffer[recvBytes] = '\0';
        std::cout << "Received from server: " << buffer << std::endl;
    }

    // Close the socket
    close(clientSocket);

    pthread_exit(NULL);
}
