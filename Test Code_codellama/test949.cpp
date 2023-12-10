class Tunnel {
public:
    Tunnel() {}

    // Method to establish a connection to the application server
    void establishConnection(const std::string& serverAddress, const int serverPort) {
        // Open a connection to the application server
        m_serverConnection = std::make_unique<TCPConnection>(serverAddress, serverPort);

        // Start a thread to handle incoming data from the application client
        m_serverThread = std::thread([this]() {
            while (true) {
                // Read data from the application client connection
                std::string data = m_clientConnection->read();

                // Send the data to the application server
                m_serverConnection->write(data);
            }
        });
    }

    // Method to close the tunnel and associated connections
    void closeTunnel() {
        // Close the connection to the application server
        m_serverConnection->close();

        // Stop the thread that handles incoming data from the application client
        m_serverThread.join();

        // Close the connection to the application client
        m_clientConnection->close();
    }

    // Method to retrieve the connection to the application server
    TCPConnection* getServerConnection() {
        return m_serverConnection.get();
    }

private:
    // The connection to the application server
    std::unique_ptr<TCPConnection> m_serverConnection;

    // The thread that handles incoming data from the application client
    std::thread m_serverThread;

    // The connection to the application client
    std::unique_ptr<TCPConnection> m_clientConnection;
};
