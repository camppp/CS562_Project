#include <SDL.h>

class MySDL {
public:
    MySDL(int width, int height) {
        // Initialize the SDL library
        SDL_Init(SDL_INIT_VIDEO);

        // Create a window
        window = SDL_CreateWindow("My SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

        // Create a renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    ~MySDL() {
        // Destroy the renderer
        SDL_DestroyRenderer(renderer);

        // Destroy the window
        SDL_DestroyWindow(window);

        // Quit the SDL library
        SDL_Quit();
    }

    void loadVideo(const char* filePath) {
        // Load the video file
        video = SDL_LoadBMP(filePath);

        // Check if the video was loaded successfully
        if (video == NULL) {
            printf("Failed to load video: %s\n", SDL_GetError());
            return;
        }

        // Set the video dimensions
        width = video->w;
        height = video->h;
    }

    void renderFrame() {
        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the video frame
        SDL_RenderCopy(renderer, video, NULL, NULL);

        // Update the window
        SDL_RenderPresent(renderer);
    }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* video;
    int width, height;
};
