#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct DebrisSettings {
    bool freezeRotations;
    bool monochromeDebris;
    float debrisLifetime;
    float debrisScale;
    float velocityMultiplier;
    float drag;
};

bool LoadConfig(const std::string& filename, DebrisSettings& settings) {
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Error: Unable to open configuration file." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
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
    }

    configFile.close();
    return true;
}

void SetupConfig(const DebrisSettings& settings) {
    // Apply the loaded settings to the game's debris system
    // Example: Set up the game's debris system using the loaded settings
    std::cout << "Debris Settings:" << std::endl;
    std::cout << "Freeze Rotations: " << (settings.freezeRotations ? "true" : "false") << std::endl;
    std::cout << "Monochrome Debris: " << (settings.monochromeDebris ? "true" : "false") << std::endl;
    std::cout << "Debris Lifetime: " << settings.debrisLifetime << std::endl;
    std::cout << "Debris Scale: " << settings.debrisScale << std::endl;
    std::cout << "Velocity Multiplier: " << settings.velocityMultiplier << std::endl;
    std::cout << "Drag: " << settings.drag << std::endl;
}

int main() {
    DebrisSettings settings;
    if (LoadConfig("debris_config.txt", settings)) {
        SetupConfig(settings);
    }
    return 0;
}
