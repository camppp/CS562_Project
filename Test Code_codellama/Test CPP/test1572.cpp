#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <string>

// Structure to represent a PSF character
struct PSFCharacter {
    int width;
    int height;
    int xoffset;
    int yoffset;
    int xadvance;
    int page;
    int chnl;
    unsigned char* data;
};

// Structure to represent a PSF font
struct PSFFont {
    int version;
    int numChars;
    int charWidth;
    int charHeight;
    int charXOffset;
    int charYOffset;
    int charXAdvance;
    int charPage;
    int charChnl;
    PSFCharacter* characters;
};

// Function to load a PSF font from a file
PSFFont* LoadPSFFont(const char* psfFilePath) {
    // Open the PSF file
    std::ifstream file(psfFilePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open PSF file: " << psfFilePath << std::endl;
        return nullptr;
    }

    // Read the PSF header
    PSFFont* font = new PSFFont();
    file.read((char*)&font->version, sizeof(int));
    file.read((char*)&font->numChars, sizeof(int));
    file.read((char*)&font->charWidth, sizeof(int));
    file.read((char*)&font->charHeight, sizeof(int));
    file.read((char*)&font->charXOffset, sizeof(int));
    file.read((char*)&font->charYOffset, sizeof(int));
    file.read((char*)&font->charXAdvance, sizeof(int));
    file.read((char*)&font->charPage, sizeof(int));
    file.read((char*)&font->charChnl, sizeof(int));

    // Allocate memory for the character data
    font->characters = new PSFCharacter[font->numChars];

    // Read the character data
    for (int i = 0; i < font->numChars; i++) {
        file.read((char*)&font->characters[i].width, sizeof(int));
        file.read((char*)&font->characters[i].height, sizeof(int));
        file.read((char*)&font->characters[i].xoffset, sizeof(int));
        file.read((char*)&font->characters[i].yoffset, sizeof(int));
        file.read((char*)&font->characters[i].xadvance, sizeof(int));
        file.read((char*)&font->characters[i].page, sizeof(int));
        file.read((char*)&font->characters[i].chnl, sizeof(int));
        font->characters[i].data = new unsigned char[font->characters[i].width * font->characters[i].height];
        file.read((char*)font->characters[i].data, font->characters[i].width * font->characters[i].height);
    }

    // Close the file
    file.close();

    return font;
}

// Function to draw a PSF character to an SDL_Texture
SDL_Texture* DrawPSFCharacter(const PSFCharacter* character, SDL_Renderer* renderer, int scale) {
    // Create a new SDL_Texture
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, character->width * scale, character->height * scale);
    if (!texture) {
        std::cerr << "Error: Could not create SDL_Texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Set the texture scaling
    SDL_SetTextureScaleMode(texture, SDL_ScaleModeNearest);

    // Lock the texture
    void* pixels;
    int pitch;
    if (SDL_LockTexture(texture, NULL, &pixels, &pitch) < 0) {
        std::cerr << "Error: Could not lock SDL_Texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Draw the character to the texture
    for (int y = 0; y < character->height; y++) {
        for (int x = 0; x < character->width; x++) {
            if (character->data[y * character->width + x]) {
                // Draw a pixel
                unsigned char* pixel = (unsigned char*)pixels + (y * scale + character->yoffset) * pitch + (x * scale + character->xoffset) * 4;
                pixel[0] = 0xFF;
                pixel[1] = 0xFF;
                pixel[2] = 0xFF;
                pixel[3] = 0xFF;
            }
        }
    }

    // Unlock the texture
    SDL_UnlockTexture(texture);

    return texture;
}

// Function to draw a PSF font to an SDL_Texture
SDL_Texture* DrawPSFFont(const PSFFont* font, SDL_Renderer* renderer, int scale) {
    // Create a new SDL_Texture
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, font->charWidth * scale, font->charHeight * scale);
    if (!texture) {
        std::cerr << "Error: Could not create SDL_Texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Set the texture scaling
    SDL_SetTextureScaleMode(texture, SDL_ScaleModeNearest);

    // Lock the texture
    void* pixels;
    int pitch;
    if (SDL_LockTexture(texture, NULL, &pixels, &pitch) < 0) {
        std::cerr << "Error: Could not lock SDL_Texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Draw the font to the texture
    for (int i = 0; i < font->numChars; i++) {
        // Draw the character to the texture
        SDL_Texture* characterTexture = DrawPSFCharacter(&font->characters[i], renderer, scale);
        if (!characterTexture) {
            std::cerr << "Error: Could not draw PSF character: " << SDL_GetError() << std::endl;
            return nullptr;
        }

        // Copy the character texture to the font texture
        SDL_Rect srcRect = {0, 0, characterTexture->w, characterTexture->h};
        SDL_Rect dstRect = {font->characters[i].xoffset * scale, font->characters[i].yoffset * scale, characterTexture->w, characterTexture->h};
        SDL_BlitSurface(characterTexture, &srcRect, texture, &dstRect);

        // Free the character texture
        SDL_DestroyTexture(characterTexture);
    }

    // Unlock the texture
    SDL_UnlockTexture(texture);

    return texture;
}

// Function to draw a PSF file to an SDL_Texture
SDL_Texture* DrawPSF(const char* psfFilePath, SDL_Renderer* renderer, int scale) {
    // Load the PSF font
    PSFFont* font = LoadPSFFont(psfFilePath);
    if (!font) {
        std::cerr << "Error: Could not load PSF font: " << psfFilePath << std::endl;
        return nullptr;
    }

    // Draw the PSF font to an SDL_Texture
    SDL_Texture* texture = DrawPSFFont(font, renderer, scale);
    if (!texture) {
        std::cerr << "Error: Could not draw PSF font: " << psfFilePath << std::endl;
        return nullptr;
    }

    // Free the PSF font
    delete font;

    return texture;
}
