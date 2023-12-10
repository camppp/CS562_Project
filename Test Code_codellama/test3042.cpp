enum class Part {
    Scrollbar,
    Track,
    Thumb
};

enum class State {
    Normal,
    Hover,
    Pressed
};

struct ExtraParams {
    int width;
    int height;
};

int GetAuraScrollbarSize(Part part, State state, ExtraParams extraParams) {
    int size = CommonThemeGetPartSize(part, state, extraParams);
    if (size != 0) {
        return size;
    }

    switch (part) {
        case Part::Scrollbar:
            return 10;
        case Part::Track:
            return 10;
        case Part::Thumb:
            return 10;
        default:
            return 0;
    }
}
