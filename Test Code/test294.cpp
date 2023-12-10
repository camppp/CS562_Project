#include <string>

namespace Model {
    struct Position {
        float x, y, z;
    };
}

class Object {
private:
    std::string name;
    Model::Position position;
    bool isDestroyed;
    bool isNotIntersection;

public:
    // Default constructor
    Object() : name("DefaultObject"), position({0.0f, 0.0f, 0.0f}), isDestroyed(false), isNotIntersection(false) {}

    // Constructor with specified name and position
    explicit Object(const std::string &name, Model::Position position) : name(name), position(position), isDestroyed(false), isNotIntersection(false) {}

    // Destructor
    virtual ~Object() {}

    // Copy constructor
    Object(const Object &rhs) : name(rhs.name), position(rhs.position), isDestroyed(rhs.isDestroyed), isNotIntersection(rhs.isNotIntersection) {}

    // Assignment operator
    Object& operator=(const Object &rhs) {
        if (this != &rhs) {
            name = rhs.name;
            position = rhs.position;
            isDestroyed = rhs.isDestroyed;
            isNotIntersection = rhs.isNotIntersection;
        }
        return *this;
    }

    // Get the position of the object
    const Model::Position& getPosition() const {
        return position;
    }

    // Get the name of the object
    const std::string& getName() const {
        return name;
    }

    // Set the position of the object
    void setPosition(Model::Position &newPosition) {
        position = newPosition;
    }

    // Check if the object is destroyed
    bool isDestroy() {
        return isDestroyed;
    }

    // Destroy the object
    void destroy() {
        isDestroyed = true;
    }

    // Check if the object intersects with another object
    bool isIntersect(const Object &object) {
        // Implement intersection logic here
        // Return true if the objects intersect, false otherwise
        return false; // Placeholder return value
    }

    // Set the intersection status of the object
    void setNotIntersection(bool notIntersection) {
        isNotIntersection = notIntersection;
    }
};
