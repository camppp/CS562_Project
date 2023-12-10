#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class ImageProcessor {
public:
    ImageProcessor(const std::string& inputFile) : inputFile(inputFile) {}

    void addOperation(const std::string& operation) {
        operations.push_back(operation);
    }

    void setDisplaySettings(int width, int height, int fps) {
        displayWidth = width;
        displayHeight = height;
        framesPerSecond = fps;
    }

    void processAndDisplay() {
        // Initialize OpenGL and process the image
        std::vector<std::string> args;
        args.push_back(inputFile);
        for (const auto& op : operations) {
            args.push_back(op);
        }
        Sprite::instance().init(args, framesPerSecond);
        Shader shader("./Shader/vertexShader.glsl", "./Shader/fragmentShader.glsl");
        glUseProgram(shader.id);
        assert(glGetError() == 0);
        // Display the processed image using OpenGL
        while (1) {
            // Display logic using OpenGL
        }
    }

private:
    std::string inputFile;
    std::vector<std::string> operations;
    int displayWidth;
    int displayHeight;
    int framesPerSecond;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_image_file>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    ImageProcessor processor(inputFile);
    processor.addOperation("grayscale");
    processor.addOperation("blur");
    processor.setDisplaySettings(800, 600, 30);
    processor.processAndDisplay();

    return 0;
}
