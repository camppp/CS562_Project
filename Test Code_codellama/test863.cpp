#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

const int PORT = 8080;

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket" << endl;
        return 1;
    }

    // Set up the server address
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cout << "Error binding socket" << endl;
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        cout << "Error listening for connections" << endl;
        return 1;
    }

    // Accept an incoming connection
    sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (sockaddr*)&client_addr, &client_addr_len);
    if (client_sock < 0) {
        cout << "Error accepting incoming connection" << endl;
        return 1;
    }

    // Read the request from the client
    char request[1024];
    int bytes_read = recv(client_sock, request, 1024, 0);
    if (bytes_read < 0) {
        cout << "Error reading request from client" << endl;
        return 1;
    }

    // Parse the request and perform the operation
    string operation = request.substr(0, request.find(' '));
    string operands = request.substr(request.find(' ') + 1);
    int result = 0;
    if (operation == "add") {
        result = stoi(operands) + stoi(operands);
    } else if (operation == "sub") {
        result = stoi(operands) - stoi(operands);
    } else if (operation == "mul") {
        result = stoi(operands) * stoi(operands);
    } else if (operation == "div") {
        result = stoi(operands) / stoi(operands);
    } else {
        cout << "Invalid operation" << endl;
        return 1;
    }

    // Send the result back to the client
    char response[1024];
    sprintf(response, "%d", result);
    send(client_sock, response, strlen(response), 0);

    // Close the socket
    close(client_sock);

    return 0;
}
