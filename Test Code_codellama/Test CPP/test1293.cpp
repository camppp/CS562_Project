#include <iostream>

class Sound {
private:
    struct Position {
        int x;
        int y;
    };

    Position _position;
    bool _2d_effect;

public:
    void setPosition(int x, int y) {
        _position.x = x;
        _position.y = y;
        _2d_effect = true;
    }

    void play() {
        if (_2d_effect) {
            // Play the sound as a 2D effect
            std::cout << "Playing sound at position (" << _position.x << ", " << _position.y << ")" << std::endl;
        } else {
            // Play the sound as a 3D effect
            std::cout << "Playing sound at position (" << _position.x << ", " << _position.y << ", " << _position.z << ")" << std::endl;
        }
    }
};
