class Animation {
public:
    Animation(float x, float y, float r, float g, float b) {
        // Initialize position and color animators with initial values
        positionAnimator = new PositionAnimator(x, y);
        colorAnimator = new ColorAnimator(r, g, b);
    }

    void update(float dt) {
        // Update position and color animators over time
        positionAnimator->update(dt);
        colorAnimator->update(dt);
    }

    void draw() {
        // Retrieve current position and color values from animators
        float x = positionAnimator->getCurrentValue();
        float y = positionAnimator->getCurrentValue();
        float r = colorAnimator->getCurrentValue();
        float g = colorAnimator->getCurrentValue();
        float b = colorAnimator->getCurrentValue();

        // Draw a filled circle at the specified position with the specified color
        drawFilledCircle(x, y, r, g, b);
    }

private:
    PositionAnimator* positionAnimator;
    ColorAnimator* colorAnimator;
};
