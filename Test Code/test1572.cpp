#include "Font/LoadPSF.hpp"
#include <SDL.h>

#include <iostream>

SDL_Texture* DrawPSF(const char* psfFilePath, SDL_Renderer* renderer, int scale) {
    // Load the PSF file
    PSFFont psfFont = LoadPSF(psfFilePath);

    // Calculate the dimensions of the font characters
    int charWidth = psfFont.header->width;
    int charHeight = psfFont.header->height;

    // Create an SDL_Surface to draw the font pixels
    SDL_Surface* surface = SDL_CreateRGBSurface(0, charWidth, charHeight, 32, 0, 0, 0, 0);

    // Draw the font pixels to the surface
    for (int i = 0; i < 256; i++) {
        // Get the bitmap data for the character
        const uint8_t* bitmap = psfFont.chars[i];

        // Set the pixel color based on the bitmap data
        for (int y = 0; y < charHeight; y++) {
            for (int x = 0; x < charWidth; x++) {
                uint8_t pixel = (bitmap[y] >> (7 - x)) & 1;
                uint32_t color = pixel ? 0xFFFFFFFF : 0x00000000;
                *((uint32_t*)surface->pixels + y * charWidth + x) = color;
            }
        }

        // Create an SDL_Texture from the surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        // Scale the texture
        SDL_Rect dstRect = { i * charWidth * scale, 0, charWidth * scale, charHeight * scale };
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        // Clean up the texture
        SDL_DestroyTexture(texture);
    }

    // Clean up the surface
    SDL_FreeSurface(surface);

    return texture;
}
