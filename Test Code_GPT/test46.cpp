#include <iostream>
#include <sstream>
#include <unordered_map>

class StringMap {
public:
    std::unordered_map<std::string, std::string> data;
};

class Stream {
public:
    void configureStream(const StringMap& settings) {
        // Check if the "streams.Mjpg.enabled" setting is present
        if (settings.data.find("streams.Mjpg.enabled") != settings.data.end()) {
            // Convert the "streams.Mjpg.enabled" setting to an integer (1 for true, 0 for false)
            int enabled = (settings.data["streams.Mjpg.enabled"] == "true") ? 1 : 0;
            std::cout << "Setting MJPG stream enabled: " << enabled << std::endl;
        }

        // Check if the required MJPG stream settings are present
        if (settings.data.find("streams.Mjpg.streamPort") != settings.data.end() &&
            settings.data.find("streams.Mjpg.quality") != settings.data.end() &&
            settings.data.find("streams.Mjpg.fps") != settings.data.end()) {

            // Convert "streams.Mjpg.streamPort" to an integer
            int streamPort;
            std::istringstream(settings.data["streams.Mjpg.streamPort"]) >> streamPort;

            // Convert "streams.Mjpg.quality" to an integer
            int quality;
            std::istringstream(settings.data["streams.Mjpg.quality"]) >> quality;

            // Convert "streams.Mjpg.fps" to an integer
            int fps;
            std::istringstream(settings.data["streams.Mjpg.fps"]) >> fps;

            // Check if the streamPort is within the well-known ports range
            if (streamPort >= 0 && streamPort <= 1023) {
                std::cout << "Setting MJPG stream configuration: Port=" << streamPort
                          << ", Quality=" << quality << ", FPS=" << fps << std::endl;
            } else {
                std::cerr << "Error: MJPG stream port is not within the well-known ports range." << std::endl;
            }
        } else {
            std::cerr << "Error: MJPG stream settings are incomplete." << std::endl;
        }
    }
};

int main() {
    // Example usage
    StringMap settings;
    settings.data["streams.Mjpg.enabled"] = "true";
    settings.data["streams.Mjpg.streamPort"] = "8080";
    settings.data["streams.Mjpg.quality"] = "80";
    settings.data["streams.Mjpg.fps"] = "30";

    Stream stream;
    stream.configureStream(settings);

    return 0;
}
