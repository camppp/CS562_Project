#include <iostream>

// Forward declarations for restServer and kotekanMode
class restServer;
namespace kotekan {
    class kotekanMode;
}

class TrackerManager {
private:
    restServer* serverPtr;
    kotekan::kotekanMode* kotekanModePtr;

public:
    TrackerManager() : serverPtr(nullptr), kotekanModePtr(nullptr) {}

    void registerWithServer(restServer* rest_server) {
        serverPtr = rest_server;
        // Perform registration with the server
        // ...
        std::cout << "Registered with server" << std::endl;
    }

    void setKotekanModePtr(kotekan::kotekanMode* _kotekan_mode_ptr) {
        kotekanModePtr = _kotekan_mode_ptr;
    }
};

int main() {
    // Example usage
    TrackerManager trackerManager;
    restServer* server = new restServer();
    kotekan::kotekanMode* mode = new kotekan::kotekanMode();

    trackerManager.registerWithServer(server);
    trackerManager.setKotekanModePtr(mode);

    delete server;
    delete mode;

    return 0;
}
