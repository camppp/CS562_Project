class BoxInterface {
public:
    // Constructor
    BoxInterface(int width, int height) {
        // Initialize member variables
        div_pop = 0;
        div_stats = 0;
        div_controls = 0;
        div_vis = 0;
        pop_canvas = 0;
        org_canvas = 0;
        anim = 0;
        d1 = 0;
        d2 = 0;
        d3 = 0;

        // Resize the data vector based on the size of the world
        data.resize(width * height);
    }

    // Add a new box to the world
    void CreateBox(int width, int height) {
        // Create a new box object
        Box box(width, height);

        // Add the box to the data vector
        data.push_back(box);
    }

    // Move a box to a new position in the world
    void MoveBox(int boxIndex, int newX, int newY) {
        // Get the box at the specified index
        Box& box = data[boxIndex];

        // Update the position of the box
        box.x = newX;
        box.y = newY;
    }

    // Remove a box from the world
    void RemoveBox(int boxIndex) {
        // Remove the box at the specified index from the data vector
        data.erase(data.begin() + boxIndex);
    }

    // Visualize the current state of the boxes in the world
    void VisualizeBoxes() {
        // Draw the boxes on the canvas
        for (int i = 0; i < data.size(); i++) {
            Box& box = data[i];
            pop_canvas.drawRect(box.x, box.y, box.width, box.height);
        }
    }

private:
    // Member variables
    int div_pop;
    int div_stats;
    int div_controls;
    int div_vis;
    int pop_canvas;
    int org_canvas;
    int anim;
    int d1;
    int d2;
    int d3;

    // Data vector to store the boxes
    std::vector<Box> data;
};
