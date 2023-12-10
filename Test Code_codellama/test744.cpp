class SpriteSheetManager {
private:
    std::vector<SpriteSheet> spriteSheets;

public:
    void addSpriteSheetAtStart(const SpriteSheet& spriteSheet) {
        spriteSheets.insert(spriteSheets.begin(), spriteSheet);
    }

    void addSpriteSheetAtEnd(const SpriteSheet& spriteSheet) {
        spriteSheets.push_back(spriteSheet);
    }

    void addSpriteSheetAtPosition(const SpriteSheet& spriteSheet, int position) {
        if (position >= 0 && position < spriteSheets.size()) {
            spriteSheets.insert(spriteSheets.begin() + position, spriteSheet);
        } else {
            spriteSheets.push_back(spriteSheet);
        }
    }

    const std::vector<SpriteSheet>& getSpriteSheets() const {
        return spriteSheets;
    }
};
