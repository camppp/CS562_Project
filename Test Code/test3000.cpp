#include <SDL.h>
#include <SDL_video.h>
#include <string>

class MySDL {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* videoTexture;
    int videoWidth;
    int videoHeight;

public:
    MySDL(int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow("SimplePlayer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
    }

    void loadVideo(const std::string& filePath) {
        SDL_Surface* surface = SDL_LoadBMP(filePath.c_str()); // Replace with actual video loading function
        videoTexture = SDL_CreateTextureFromSurface(renderer, surface);
        videoWidth = surface->w;
        videoHeight = surface->h;
        SDL_FreeSurface(surface);
    }

    void renderFrame() {
        SDL_RenderClear(renderer);
        SDL_Rect dstRect = {0, 0, videoWidth, videoHeight};
        SDL_RenderCopy(renderer, videoTexture, NULL, &dstRect);
        SDL_RenderPresent(renderer);
    }

    ~MySDL() {
        SDL_DestroyTexture(videoTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};
