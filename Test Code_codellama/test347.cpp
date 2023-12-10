class Size {
private:
    int width;
    int height;

public:
    Size(int width, int height) : width(width), height(height) {}

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    bool operator==(const Size& other) const {
        return width == other.width && height == other.height;
    }

    static const Size empty;
};

const Size Size::empty(0, 0);
