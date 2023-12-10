class PageOrientation {
public:
    // Enumerations for page orientations
    enum Orientation {
        PORTRAIT,
        LANDSCAPE,
        REVERSE_PORTRAIT,
        REVERSE_LANDSCAPE
    };

    // Method to set the page orientation
    void setOrientation(Orientation orientation) {
        this->orientation = orientation;
    }

    // Method to get the current page orientation
    Orientation getOrientation() {
        return this->orientation;
    }

    // Support for enumerations that describe the available page orientations
    static const Orientation ORIENTATION_FEATURE = Orientation::PORTRAIT;

private:
    // Current page orientation
    Orientation orientation;
};
