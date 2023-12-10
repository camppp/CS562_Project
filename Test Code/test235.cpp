#include <iostream>
#include <string>
#include <cstdint>

struct Metadata
{
    std::string title;
    std::string version;
    std::string developer;
    std::string iconFilepath;
    std::string entrySceneFilepath;
} metadata;

struct WindowSettings
{
    uint16_t height;
    uint16_t width;
} windowSettings;

void initializeDefaults() {
    metadata.title = "Untitled";
    metadata.version = "1.0";
    metadata.developer = "Unknown";
    metadata.iconFilepath = "default_icon.png";
    metadata.entrySceneFilepath = "default_scene.txt";

    windowSettings.height = 600;
    windowSettings.width = 800;
}

void updateMetadata(const std::string& title, const std::string& version, const std::string& developer,
                    const std::string& iconFilepath, const std::string& entrySceneFilepath) {
    metadata.title = title;
    metadata.version = version;
    metadata.developer = developer;
    metadata.iconFilepath = iconFilepath;
    metadata.entrySceneFilepath = entrySceneFilepath;
}

void updateWindowSettings(uint16_t height, uint16_t width) {
    windowSettings.height = height;
    windowSettings.width = width;
}

void displaySettings() {
    std::cout << "Metadata:\n";
    std::cout << "Title: " << metadata.title << "\n";
    std::cout << "Version: " << metadata.version << "\n";
    std::cout << "Developer: " << metadata.developer << "\n";
    std::cout << "Icon Filepath: " << metadata.iconFilepath << "\n";
    std::cout << "Entry Scene Filepath: " << metadata.entrySceneFilepath << "\n\n";

    std::cout << "Window Settings:\n";
    std::cout << "Height: " << windowSettings.height << "\n";
    std::cout << "Width: " << windowSettings.width << "\n";
}

int main() {
    initializeDefaults();
    displaySettings();

    updateMetadata("My App", "2.0", "John Doe", "app_icon.png", "main_scene.txt");
    updateWindowSettings(720, 1024);
    displaySettings();

    return 0;
}
