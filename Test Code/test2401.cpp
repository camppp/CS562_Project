class FullscreenQuad {
public:
    // Member variables and other member functions are not shown for brevity

    bool operator<(const FullscreenQuad& other) const {
        // Assuming a specific comparison criterion based on member variables x and y
        if (this->x < other.x) {
            return true;
        } else if (this->x == other.x) {
            return this->y < other.y;
        }
        return false;
    }
};
