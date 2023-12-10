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
