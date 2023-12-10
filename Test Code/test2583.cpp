#include <iostream>

// Define the ProgramTyp enum and Color struct if not already defined
enum ProgramTyp { /* define enum values */ };
struct Color { /* define color structure */ };

// Define the useProg function if not already defined
void useProg(ProgramTyp materialTyp) {
    // Implementation of useProg function
}

class Material {
private:
    ProgramTyp materialTyp;
    Color defuse;
    Color specular;

public:
    Material(ProgramTyp materialTyp, Color defuse, Color specular) {
        this->materialTyp = materialTyp;
        this->defuse = defuse;
        this->specular = specular;
    }

    ~Material() {
        // Destructor implementation if needed
    }

    void use() {
        useProg(materialTyp);
    }
};

int main() {
    // Example usage of the Material class
    Color defuseColor, specularColor;
    Material material(ProgramTyp::/* specify material type */, defuseColor, specularColor);
    material.use();
    return 0;
}
