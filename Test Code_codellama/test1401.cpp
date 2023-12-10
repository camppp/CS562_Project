class Cylinder {
public:
    // Default constructor with default parameters
    Cylinder(int levels = 16) {
        // Initialize the cylinder with the default parameters
        radius = 1.0f;
        height = 2.0f;
        levels = 16;
    }

    // Constructor with explicit parameters
    Cylinder(float radius, float height, int levels = 16) {
        // Initialize the cylinder with the specified parameters
        this->radius = radius;
        this->height = height;
        this->levels = levels;
    }

    // Method to draw the cylinder
    void draw() {
        // Draw the cylinder using the specified parameters
        glBegin(GL_QUADS);
        for (int i = 0; i < levels; i++) {
            float angle = (float)i / levels * 2.0f * M_PI;
            glVertex3f(radius * cos(angle), radius * sin(angle), 0.0f);
            glVertex3f(radius * cos(angle), radius * sin(angle), height);
            glVertex3f(radius * cos(angle + 2.0f * M_PI / levels), radius * sin(angle + 2.0f * M_PI / levels), height);
            glVertex3f(radius * cos(angle + 2.0f * M_PI / levels), radius * sin(angle + 2.0f * M_PI / levels), 0.0f);
        }
        glEnd();
    }

private:
    float radius;
    float height;
    int levels;
};
