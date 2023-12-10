#include "CGameElement.h"

class CWeaponWrench : public CGameElement {
public:
    CWeaponWrench(const std::string& name, const std::string& sprite_name) : CGameElement(name, sprite_name) {}

    // Initialize the element area width and height
    void init_element_area() {
        element_area.width = 64;
        element_area.height = 64;
    }

    // Create a new instance of CWeaponWrench
    CWeaponWrench* create_self() {
        return new CWeaponWrench(name, sprite_name);
    }

    // Create a copy of the wrench sprite for the downward direction
    void create_sprite_down() {
        sprite_down = sprite_pool[DIRECTION_DOWN];
    }
};
