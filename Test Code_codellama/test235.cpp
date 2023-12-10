#include <iostream>
#include <string>
#include <map>
#include <vector>

// Define data structures to store metadata and window settings
struct Metadata {
    std::string title;
    std::string author;
    int year;
};

struct WindowSettings {
    int width;
    int height;
    bool fullscreen;
};

// Define functions to initialize, update, and display metadata and window settings
void initializeMetadata(Metadata& metadata) {
    metadata.title = "Default Title";
    metadata.author = "Default Author";
    metadata.year = 2023;
}

void updateMetadata(Metadata& metadata, std::string title, std::string author, int year) {
    metadata.title = title;
    metadata.author = author;
    metadata.year = year;
}

void initializeWindowSettings(WindowSettings& windowSettings) {
    windowSettings.width = 800;
    windowSettings.height = 600;
    windowSettings.fullscreen = false;
}

void updateWindowSettings(WindowSettings& windowSettings, int width, int height, bool fullscreen) {
    windowSettings.width = width;
    windowSettings.height = height;
    windowSettings.fullscreen = fullscreen;
}

void displayMetadata(const Metadata& metadata) {
    std::cout << "Title: " << metadata.title << std::endl;
    std::cout << "Author: " << metadata.author << std::endl;
    std::cout << "Year: " << metadata.year << std::endl;
}

void displayWindowSettings(const WindowSettings& windowSettings) {
    std::cout << "Width: " << windowSettings.width << std::endl;
    std::cout << "Height: " << windowSettings.height << std::endl;
    std::cout << "Fullscreen: " << (windowSettings.fullscreen ? "true" : "false") << std::endl;
}

int main() {
    // Initialize metadata and window settings with default values
    Metadata metadata;
    initializeMetadata(metadata);
    WindowSettings windowSettings;
    initializeWindowSettings(windowSettings);

    // Update metadata and window settings with user-provided values
    std::string title, author;
    int year;
    std::cout << "Enter title: ";
    std::cin >> title;
    std::cout << "Enter author: ";
    std::cin >> author;
    std::cout << "Enter year: ";
    std::cin >> year;
    updateMetadata(metadata, title, author, year);

    int width, height;
    bool fullscreen;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;
    std::cout << "Enter fullscreen (true/false): ";
    std::cin >> fullscreen;
    updateWindowSettings(windowSettings, width, height, fullscreen);

    // Display current metadata and window settings
    displayMetadata(metadata);
    displayWindowSettings(windowSettings);

    return 0;
}
