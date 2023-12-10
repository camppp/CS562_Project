struct Description {
    std::string type;  // Type of window
    int width;         // Width of window
    int height;        // Height of window
};

void initialize(Description& desc) {
    desc.type = "structural";
    desc.width = 1280;
    desc.height = 720;
}

void update(Rectangle area, Input& input) {
    // Handle user input within the specified area
    // ...
}
