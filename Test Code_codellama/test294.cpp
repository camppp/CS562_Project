#include <string>
#include <iostream>

class Model {
public:
    struct Position {
        double x, y, z;
    };
};

class Object {
public:
    // Constructors
    Object() : name(""), position(0, 0, 0) {}
    Object(const std::string &name, Model::Position position) : name(name), position(position) {}
    Object(const Object &rhs) : name(rhs.name), position(rhs.position) {}

    // Destructor
    ~Object() {}

    // Member functions
    const Model::Position& getPosition() const { return position; }
    const std::string& getName() const { return name; }
    void setPosition(Model::Position &position) { this->position = position; }
    bool isDestroy() { return destroyed; }
    void destroy() { destroyed = true; }
    bool isIntersect(const Object &object) {
        // Check for intersection between two objects
        // ...
        return false;
    }
    void setNotIntersection(bool notIntersection) {
        // Set the intersection status of the object
        // ...
    }

private:
    std::string name;
    Model::Position position;
    bool destroyed = false;
};
