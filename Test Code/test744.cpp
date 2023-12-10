#include <vector>
#include <algorithm>

enum Position { ADD_SPRITE_AT_START, ADD_SPRITE_AT_END };

class SpriteSheetManager {
private:
    std::vector<SpriteSheet> sprite_sheets;

public:
    void addSpriteSheetAtStart(const SpriteSheet& new_sprite_sheet) {
        sprite_sheets.insert(sprite_sheets.begin(), new_sprite_sheet);
    }

    void addSpriteSheetAtEnd(const SpriteSheet& new_sprite_sheet) {
        sprite_sheets.push_back(new_sprite_sheet);
    }

    void addSpriteSheetAtPosition(const SpriteSheet& new_sprite_sheet, size_t position) {
        if (position > sprite_sheets.size()) {
            sprite_sheets.push_back(new_sprite_sheet);
        } else {
            sprite_sheets.insert(sprite_sheets.begin() + position, new_sprite_sheet);
        }
    }
};
