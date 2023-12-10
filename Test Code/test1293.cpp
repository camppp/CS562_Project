void play() {
    if (_2d_effect) {
        std::cout << "Playing 2D sound at position (" << _position.x << ", " << _position.y << ")" << std::endl;
        // Additional logic to play the sound as a 2D effect
    } else {
        std::cout << "Playing non-2D sound" << std::endl;
        // Additional logic to play the sound without considering position
    }
}
