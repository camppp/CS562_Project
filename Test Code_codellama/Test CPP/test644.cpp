CircleShape create() {
    CircleShape circle;
    // Set the position of the circle to a random point within the window
    circle.setPosition(Vector2f(rand() % 1000, rand() % 500));
    // Set the radius of the circle to a random value between 10 and 50
    circle.setRadius(rand() % 40 + 10);
    // Set the color of the circle to a random color
    circle.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
    return circle;
}
