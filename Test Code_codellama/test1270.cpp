#include <iostream>
#include <string>

class TrackerManager {
public:
    TrackerManager() {}

    void registerWithServer(restServer* server) {
        // Register with the provided server
        std::cout << "Registering with server: " << server->getServerAddress() << std::endl;
    }

    void setKotekanModePtr(kotekanMode* mode) {
        // Set the pointer to the current kotekan mode object
        this->mode = mode;
    }

private:
    kotekanMode* mode;
};
