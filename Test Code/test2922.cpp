#include <iostream>

// Forward declaration of Surface class
class Surface;

// Base class for rendering objects
class Renderable {
public:
    virtual void render(Surface &renderTarget) const = 0;
};

// Derived class for rendering sprites
class Sprite : public Renderable {
private:
    std::string image;  // Image data of the sprite

public:
    Sprite(const std::string &imageData) : image(imageData) {}

    void render(Surface &renderTarget) const override {
        // Render the sprite on the provided Surface
        std::cout << "Rendering sprite with image data: " << image << std::endl;
        // Actual rendering logic using renderTarget
    }
};

// Derived class for rendering text
class Text : public Renderable {
private:
    std::string text;  // Text to be rendered
    std::string font;  // Font style

public:
    Text(const std::string &displayText, const std::string &fontStyle) : text(displayText), font(fontStyle) {}

    void render(Surface &renderTarget) const override {
        // Render the text on the provided Surface
        std::cout << "Rendering text: " << text << " with font: " << font << std::endl;
        // Actual rendering logic using renderTarget
    }
};

// Sample usage of the rendering system
int main() {
    Surface renderSurface;  // Assume Surface class is defined elsewhere

    // Create a sprite and render it
    Sprite sprite("sprite_image_data");
    sprite.render(renderSurface);

    // Create a text object and render it
    Text text("Hello, World!", "Arial");
    text.render(renderSurface);

    return 0;
}
