#include "Test_impl.h"
#include <iostream>

class CustomServer : public Server_impl {
public:
    void shutdown() override {
        std::cout << "Initiating server shutdown process..." << std::endl;
        this->orb_->shutdown(0);
    }
};

// Test the CustomServer class
int main() {
    // Create an instance of CustomServer
    CustomServer customServer;

    // Call the shutdown method to test the graceful shutdown
    customServer.shutdown();

    return 0;
}
