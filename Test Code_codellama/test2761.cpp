void Window_NOTHREAD::update() {
    // Update the texture with new pixel data
    SDL_LockTexture(texture, NULL, &pixels, &pitch);
    for (int y = 0; y < texture->h; y++) {
        for (int x = 0; x < texture->w; x++) {
            // Calculate the new pixel value based on the current time
            Uint32 pixel = SDL_MapRGB(texture->format, x, y, 0);
            pixels[y * pitch + x * 4] = pixel;
        }
    }
    SDL_UnlockTexture(texture);

    // Render the texture to the window
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
