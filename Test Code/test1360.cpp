#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include "Scene.h"  // Assume Scene class is defined in Scene.h

void renderThread(Scene& scene, Image& image, int width, int height, int startY, int endY) {
    for (int y = startY; y < endY; ++y) {
        for (int x = 0; x < width; ++x) {
            // Render the pixel at (x, y) in the image
            // Example: image.setPixel(x, y, scene.renderPixel(x, y));
        }
    }
}

int main() {
    const int numThreads = std::thread::hardware_concurrency();  // Get the number of available hardware threads
    Scene scene;  // Assume the scene is initialized
    Image image;  // Assume the image buffer is initialized
    int width = image.getWidth();
    int height = image.getHeight();

    std::vector<std::thread> threads;
    time_t start = time(0);

    for (int i = 0; i < numThreads; ++i) {
        int startY = (height * i) / numThreads;
        int endY = (height * (i + 1)) / numThreads;
        threads.emplace_back(renderThread, std::ref(scene), std::ref(image), width, height, startY, endY);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Rendering finished in " << difftime(time(0), start) << " seconds." << std::endl;

    std::string outfile_name = "rendered_image.png";  // Output file name
    std::cout << "Writing to " << outfile_name << "." << std::endl;
    image.save(outfile_name);

    return 0;
}
