#include <iostream>
#include <string>

class Game {
public:
    static Game& instance() {
        static Game instance;
        return instance;
    }

    enum GameState {
        GS_MENU,
        GS_PLAYING
    };

    void SetGameState(GameState state) {
        // Set the game state
    }

    bool LoadMap(const std::string& mapPath) {
        // Load the map from the given path
        return true; // Replace with actual map loading logic
    }

    void PlayChunk(int sound) {
        // Play the specified audio chunk
    }

    void DestroyAllBullets() {
        // Destroy all bullets in the game
    }

    void DestroyAllAnimation() {
        // Destroy all animations in the game
    }
};

bool LoadLevel(int selectedLevel) {
    std::string level;
    if (selectedLevel == 0) {
        level = "data/map/temp";
    }

    if (Game::instance().LoadMap(level) == false) {
        Game::instance().SetGameState(Game::GS_MENU);
        return false;
    }

    Game::instance().PlayChunk(SOUND_GAMESTART);

    Game::instance().DestroyAllBullets();
    Game::instance().DestroyAllAnimation();

    return true;
}

int main() {
    int selectedLevel = 0;
    if (LoadLevel(selectedLevel)) {
        std::cout << "Level loaded successfully!" << std::endl;
    } else {
        std::cout << "Failed to load level. Returning to main menu." << std::endl;
    }
    return 0;
}
