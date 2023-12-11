#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cout << "WSAStartup failed with error: " << iResult << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cout << "socket failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(27015);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
    {
        std::cout << "connect failed with error: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Receive data from the server
    char buffer[1024];
    int iResult = 0;
    while (iResult > 0)
    {
        iResult = recv(clientSocket, buffer, 1024, 0);
        if (iResult > 0)
        {
            std::cout << "Bytes received: " << iResult << std::endl;
        }
        else if (iResult == 0)
        {
            std::cout << "Connection closed" << std::endl;
            break;
        }
        else
        {
            std::cout << "recv failed with error: " << WSAGetLastError() << std::endl;
            break;
        }
    }

    // Shutdown the connection
    iResult = client.Shutdown(SD_BOTH);
    if (iResult == SOCKET_ERROR)
    {
        std::cout << "Shutdown failed with error: " << WSAGetLastError() << std::endl;
    }

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
