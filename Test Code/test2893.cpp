#include "Player.h"
#include <SDL_image.h>

void Player::init(int _x) {
    x = static_cast<int>(_x);
    surface = IMG_Load("Assets/BatTexture.png");
    if (surface == NULL) {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
        return;
    }
}
