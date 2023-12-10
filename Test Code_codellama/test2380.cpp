#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Enemy {
public:
    Enemy(const std::string& imageFile, int life, int score, int animSpeed, bool loop) {
        // Load the enemy sprites from the given image file
        SDL_Surface* surface = IMG_Load(imageFile.c_str());
        if (surface == NULL) {
            std::cout << "Failed to load enemy sprites: " << SDL_GetError() << std::endl;
            return;
        }

        // Create the texture from the surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == NULL) {
            std::cout << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(surface);
            return;
        }

        // Set the initial life and score of the enemy
        this->life = life;
        this->score = score;

        // Configure the animation speed and looping behavior
        this->animSpeed = animSpeed;
        this->loop = loop;

        // Create the animation structure
        this->AnimWasp = new Animation(texture, animSpeed, loop);

        // Create the collider for handling collisions with the enemy
        this->collider = new Collider(this->AnimWasp->getRect());

        // Associate a power-up with the enemy
        this->PowerUp = new PowerUp(this->AnimWasp->getRect());
    }

    ~Enemy() {
        // Free the texture and animation structure
        SDL_DestroyTexture(this->AnimWasp->getTexture());
        delete this->AnimWasp;

        // Free the collider
        delete this->collider;

        // Free the power-up
        delete this->PowerUp;
    }

    void update() {
        // Update the animation
        this->AnimWasp->update();

        // Update the collider
        this->collider->update();

        // Update the power-up
        this->PowerUp->update();
    }

    void render() {
        // Render the animation
        this->AnimWasp->render();

        // Render the collider
        this->collider->render();

        // Render the power-up
        this->PowerUp->render();
    }

    int getLife() {
        return this->life;
    }

    int getScore() {
        return this->score;
    }

    Animation* getAnimWasp() {
        return this->AnimWasp;
    }

    Collider* getCollider() {
        return this->collider;
    }

    PowerUp* getPowerUp() {
        return this->PowerUp;
    }

private:
    SDL_Texture* texture;
    int life;
    int score;
    int animSpeed;
    bool loop;
    Animation* AnimWasp;
    Collider* collider;
    PowerUp* PowerUp;
};
