#include <iostream>
#include "blit.h"

enum Direction { DIR_LEFT, DIR_RIGHT };

class GameCharacter {
public:
    blit::Point l_location;
    Direction l_move;

    void handleUserInput() {
        if ((blit::pressed(blit::Button::DPAD_LEFT)) || (blit::joystick.x < -0.3f)) {
            l_move = DIR_LEFT;
            updateTargetLocations();
        }
        if ((blit::pressed(blit::Button::DPAD_RIGHT)) || (blit::joystick.x > 0.3f)) {
            l_move = DIR_RIGHT;
            updateTargetLocations();
        }
    }

    void updateTargetLocations() {
        if (l_move == DIR_LEFT) {
            l_target = l_location - blit::Point(2, 0);
            l_crate_target = l_location - blit::Point(4, 0);
        } else if (l_move == DIR_RIGHT) {
            l_target = l_location + blit::Point(2, 0);
            l_crate_target = l_location + blit::Point(4, 0);
        }
    }
};
