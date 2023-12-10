void update() {
    // Calculate time elapsed since the start
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    double elapsed = (now.tv_sec - start.tv_sec) + (now.tv_nsec - start.tv_nsec) / 1e9;

    // Example: Update texture with a simple pattern (checkerboard)
    const int patternSize = 20;
    uint32_t pixels[w * h];
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            bool color = ((x / patternSize) + (y / patternSize)) % 2 == 0;
            pixels[y * w + x] = color ? 0xFFFFFFFF : 0xFF000000; // White or black
        }
    }

    // Update the texture with the new pixel data
    SDL_UpdateTexture(texture, NULL, pixels, w * sizeof(uint32_t));

    // Clear the renderer and render the updated texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
