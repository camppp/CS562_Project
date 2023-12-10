#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>

class ImageProcessor {
public:
    ImageProcessor(const std::string& inputFile) {
        // Initialize the input image
        inputImage = loadImage(inputFile);

        // Initialize the output image
        outputImage = inputImage;

        // Initialize the processing operations
        operations = std::vector<std::string>();
    }

    void addOperation(const std::string& operation) {
        operations.push_back(operation);
    }

    void setDisplaySettings(int width, int height, int fps) {
        displayWidth = width;
        displayHeight = height;
        displayFPS = fps;
    }

    void processAndDisplay() {
        // Process the input image using the specified operations
        for (const std::string& operation : operations) {
            if (operation == "grayscale") {
                outputImage = grayscale(inputImage);
            } else if (operation == "blur") {
                outputImage = blur(inputImage);
            } else if (operation == "rotate") {
                outputImage = rotate(inputImage);
            }
        }

        // Display the output image using OpenGL
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
        glutInitWindowSize(displayWidth, displayHeight);
        glutCreateWindow("Image Processor");
        glutDisplayFunc(display);
        glutMainLoop();
    }

private:
    // Load an image from a file
    static GLuint loadImage(const std::string& file) {
        // Load the image data from the file
        GLuint image = 0;
        glGenTextures(1, &image);
        glBindTexture(GL_TEXTURE_2D, image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        return image;
    }

    // Apply a grayscale operation to an image
    static GLuint grayscale(GLuint image) {
        // Get the image data
        GLuint width, height;
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
        GLubyte* data = new GLubyte[width * height * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        // Apply the grayscale operation
        for (int i = 0; i < width * height; i++) {
            int r = data[i * 4 + 0];
            int g = data[i * 4 + 1];
            int b = data[i * 4 + 2];
            int a = data[i * 4 + 3];
            int gray = (r + g + b) / 3;
            data[i * 4 + 0] = gray;
            data[i * 4 + 1] = gray;
            data[i * 4 + 2] = gray;
            data[i * 4 + 3] = a;
        }

        // Create a new texture with the grayscaled image data
        GLuint grayscaledImage = 0;
        glGenTextures(1, &grayscaledImage);
        glBindTexture(GL_TEXTURE_2D, grayscaledImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        delete[] data;
        return grayscaledImage;
    }

    // Apply a blur operation to an image
    static GLuint blur(GLuint image) {
        // Get the image data
        GLuint width, height;
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
        GLubyte* data = new GLubyte[width * height * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        // Apply the blur operation
        for (int i = 0; i < width * height; i++) {
            int r = data[i * 4 + 0];
            int g = data[i * 4 + 1];
            int b = data[i * 4 + 2];
            int a = data[i * 4 + 3];
            int blurredR = (r + r + r + g + g + g + b + b + b) / 9;
            int blurredG = (r + r + r + g + g + g + b + b + b) / 9;
            int blurredB = (r + r + r + g + g + g + b + b + b) / 9;
            data[i * 4 + 0] = blurredR;
            data[i * 4 + 1] = blurredG;
            data[i * 4 + 2] = blurredB;
            data[i * 4 + 3] = a;
        }

        // Create a new texture with the blurred image data
        GLuint blurredImage = 0;
        glGenTextures(1, &blurredImage);
        glBindTexture(GL_TEXTURE_2D, blurredImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        delete[] data;
        return blurredImage;
    }

    // Apply a rotate operation to an image
    static GLuint rotate(GLuint image) {
        // Get the image data
        GLuint width, height;
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
        GLubyte* data = new GLubyte[width * height * 4];
        glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        // Apply the rotate operation
        for (int i = 0; i < width * height; i++) {
            int r = data[i * 4 + 0];
            int g = data[i * 4 + 1];
            int b = data[i * 4 + 2];
            int a = data[i * 4 + 3];
            int rotatedR = r;
            int rotatedG = g;
            int rotatedB = b;
            data[i * 4 + 0] = rotatedR;
            data[i * 4 + 1] = rotatedG;
            data[i * 4 + 2] = rotatedB;
            data[i * 4 + 3] = a;
        }

        // Create a new texture with the rotated image data
        GLuint rotatedImage = 0;
        glGenTextures(1, &rotatedImage);
        glBindTexture(GL_TEXTURE_2D, rotatedImage);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        delete[] data;
        return rotatedImage;
    }

    // Display the output image using OpenGL
    static void display() {
        // Set the display settings
        glViewport(0, 0, displayWidth, displayHeight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, displayWidth, 0, displayHeight, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw the output image
        glBindTexture(GL_TEXTURE_2D, outputImage);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex2f(0, 0);
        glTexCoord2f(1, 0);
        glVertex2f(displayWidth, 0);
        glTexCoord2f(1, 1);
        glVertex2f(displayWidth, displayHeight);
        glTexCoord2f(0, 1);
        glVertex2f(0, displayHeight);
        glEnd();

        // Swap the buffers
        glutSwapBuffers();
    }

private:
    GLuint inputImage;
    GLuint outputImage;
    std::vector<std::string> operations;
    int displayWidth;
    int displayHeight;
    int displayFPS;
};
