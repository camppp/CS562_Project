#include <iostream>
#include <unordered_map>
#include <string>

class Stream {
public:
    void configureStream(std::unordered_map<std::string, std::string>& settings) {
        // Read port from settings
        int enabled = (settings.at("streams.Mjpg.enabled") == "true") ? 1 : 0;
        int port = std::stoi(settings.at("streams.Mjpg.streamPort"));
        int quality = std::stoi(settings.at("streams.Mjpg.quality"));
        int fps = std::stoi(settings.at("streams.Mjpg.fps"));

        // Use port up to well-known ports range
        if (port >= 0 && port <= 1023) {
            // Configure the stream with the extracted settings
            std::cout << "Stream configured with the following settings:" << std::endl;
            std::cout << "Enabled: " << enabled << std::endl;
            std::cout << "Port: " << port << std::endl;
            std::cout << "Quality: " << quality << std::endl;
            std::cout << "FPS: " << fps << std::endl;
        } else {
            std::cout << "Error: Port number is not within the well-known ports range." << std::endl;
        }
    }
};

int main() {
    // Example usage
    std::unordered_map<std::string, std::string> settings = {
        {"streams.Mjpg.enabled", "true"},
        {"streams.Mjpg.streamPort", "8080"},
        {"streams.Mjpg.quality", "80"},
        {"streams.Mjpg.fps", "30"}
    };

    Stream stream;
    stream.configureStream(settings);

    return 0;
}
