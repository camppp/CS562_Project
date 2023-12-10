// Drawable interface or base class
class Drawable {
public:
    virtual void draw() = 0;
};

// Collection class
class Collection {
public:
    void draw() {
        for (auto& object : objects) {
            object->draw();
        }
    }

private:
    std::vector<std::unique_ptr<Drawable>> objects;
};

// Specific drawable object class
class Circle : public Drawable {
public:
    void draw() override {
        // Drawing code for a circle
    }
};

// Specific drawable object class
class Rectangle : public Drawable {
public:
    void draw() override {
        // Drawing code for a rectangle
    }
};
