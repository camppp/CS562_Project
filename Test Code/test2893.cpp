#include "Player.h"
#include <SDL_image.h>

void Player::init(int _x){
    x = static_cast<int>(_x);
    std::string imagePath = "Assets/BatTexture" + std::to_string(x) + ".png"; // Construct the image path based on the x-coordinate

    surface = IMG_Load(imagePath.c_str()); // Load the image file based on the constructed path

    if (surface == nullptr) {
        // Handle error if image loading fails
        std::cerr << "Failed to load image for player at x-coordinate: " << x << std::endl;
        // Additional error handling code can be added here, such as using a default image
    }
}
