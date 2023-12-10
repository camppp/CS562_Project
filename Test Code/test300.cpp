#include <iostream>
#include <string>

class ConnectionChecker {
private:
    bool is_open_;

public:
    // Constructor to initialize the connection status
    ConnectionChecker(bool initialStatus) : is_open_(initialStatus) {}

    // Method to set the connection status to open
    void open() {
        is_open_ = true;
    }

    // Method to set the connection status to closed
    void close() {
        is_open_ = false;
    }

    // Method to get the current connection status
    std::string getStatus() const {
        return is_open_ ? "opened" : "closed";
    }
};

int main() {
    ConnectionChecker conn(true); // Initialize with open status
    std::cout << "Connection status: " << conn.getStatus() << std::endl;

    conn.close(); // Set status to closed
    std::cout << "Connection status: " << conn.getStatus() << std::endl;

    conn.open(); // Set status to open
    std::cout << "Connection status: " << conn.getStatus() << std::endl;

    return 0;
}
