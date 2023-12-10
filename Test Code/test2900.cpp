// Sample usage of the CommunicatingSocket class
int main() {
    CommunicatingSocket clientSocket;

    try {
        clientSocket.connectToServer("127.0.0.1", 8080);

        const char* dataToSend = "Hello, Server!";
        clientSocket.send(dataToSend, strlen(dataToSend));

        char receivedData[100];
        clientSocket.receive(receivedData, sizeof(receivedData));

        std::cout << "Received data: " << receivedData << std::endl;
    } catch (const SocketException& ex) {
        std::cerr << "Socket exception occurred: " << ex.getMessage() << std::endl;
        if (ex.isCritical()) {
            // Handle critical error, possibly terminate the program
            std::cerr << "Critical error occurred. Terminating the program." << std::endl;
            return 1;
        }
    }

    return 0;
}
