#include <iostream>
#include <string>

// Base class for rendering objects
class Renderable {
public:
    virtual void render(Surface& surface) = 0;
};

// Derived class for rendering sprites
class Sprite : public Renderable {
private:
    Image image; // Image data of the sprite
public:
    Sprite(const Image& image) : image(image) {}
    void render(Surface& surface) override {
        // Draw the sprite on the surface
        surface.draw(image);
    }
};

// Derived class for rendering text
class Text : public Renderable {
private:
    std::string text; // Text to be rendered
    Font font; // Font style
public:
    Text(const std::string& text, const Font& font) : text(text), font(font) {}
    void render(Surface& surface) override {
        // Draw the text on the surface
        surface.drawText(text, font);
    }
};

int main() {
    // Create a surface to render on
    Surface surface(100, 100);

    // Create a sprite and render it on the surface
    Image spriteImage("sprite.png");
    Sprite sprite(spriteImage);
    sprite.render(surface);

    // Create some text and render it on the surface
    std::string text("Hello, World!");
    Font font("Arial", 12);
    Text textObject(text, font);
    textObject.render(surface);

    // Display the rendered surface
    surface.display();

    return 0;
}
