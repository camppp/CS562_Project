#include <iostream>
#include <vector>

// Interface or base class for drawable objects
class Drawable {
public:
    virtual void draw() = 0;  // Pure virtual method for drawing
    virtual ~Drawable() {}    // Virtual destructor for polymorphic behavior
};

// Example drawable object class
class Circle : public Drawable {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Collection class to hold drawable objects
class Collection {
private:
    std::vector<Drawable*> objects;  // Collection of drawable objects

public:
    void add(Drawable* obj) {
        objects.push_back(obj);
    }

    void draw() {
        for (auto obj : objects) {
            obj->draw();  // Call draw method for each object
        }
    }

    ~Collection() {
        for (auto obj : objects) {
            delete obj;  // Release memory for drawable objects
        }
    }
};

int main() {
    Collection collection;

    // Create and add drawable objects to the collection
    Circle* circle1 = new Circle();
    Circle* circle2 = new Circle();
    collection.add(circle1);
    collection.add(circle2);

    // Draw all objects in the collection
    collection.draw();

    return 0;
}
