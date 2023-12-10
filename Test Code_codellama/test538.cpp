#include <fstream>
#include <iostream>
#include <string>

struct DebrisSettings {
    bool freezeRotations;
    bool monochromeDebris;
    float debrisLifetime;
    float debrisScale;
    float velocityMultiplier;
    float drag;
};

bool LoadConfig(const std::string& filename, DebrisSettings& settings) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open configuration file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string key, value;
        std::stringstream ss(line);
        ss >> key >> value;

        if (key == "freezeRotations") {
            settings.freezeRotations = (value == "true");
        } else if (key == "monochromeDebris") {
            settings.monochromeDebris = (value == "true");
        } else if (key == "debrisLifetime") {
            settings.debrisLifetime = std::stof(value);
        } else if (key == "debrisScale") {
            settings.debrisScale = std::stof(value);
        } else if (key == "velocityMultiplier") {
            settings.velocityMultiplier = std::stof(value);
        } else if (key == "drag") {
            settings.drag = std::stof(value);
        }
    }

    file.close();
    return true;
}

void SetupConfig(const DebrisSettings& settings) {
    // Apply the loaded settings to the game's debris system
    // ...
}
