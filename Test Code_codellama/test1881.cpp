class SaveGameManager {
public:
    // Constructor
    SaveGameManager() {
        // Initialize the save game list
        saveGameList = std::vector<SaveGame>();
    }

    // Save the current game state to a new save file
    void saveGame(const std::string& saveFileName) {
        // Create a new save game object
        SaveGame saveGame(saveFileName);

        // Add the save game to the list
        saveGameList.push_back(saveGame);
    }

    // Automatically save the game state to an auto-save file
    void autoSave() {
        // Create a new save game object
        SaveGame saveGame("auto_save.sav");

        // Add the save game to the list
        saveGameList.push_back(saveGame);
    }

    // Delete a specific save file and its associated directory
    void deleteSaveFile(const std::string& saveFileName) {
        // Find the save game in the list
        auto it = std::find_if(saveGameList.begin(), saveGameList.end(),
            [&](const SaveGame& saveGame) {
                return saveGame.getFileName() == saveFileName;
            });

        // Check if the save game was found
        if (it != saveGameList.end()) {
            // Delete the save game and its associated directory
            std::filesystem::remove(it->getFilePath());
            std::filesystem::remove(it->getDirectoryPath());

            // Remove the save game from the list
            saveGameList.erase(it);
        }
    }

private:
    // List of save games
    std::vector<SaveGame> saveGameList;
};
