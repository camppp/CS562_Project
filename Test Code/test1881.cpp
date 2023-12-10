#include <iostream>
#include <fstream>
#include <filesystem>

class CampaignSaveGame {
public:
    void SaveGame(const std::string& saveFileName, const std::string& gameData) {
        std::ofstream saveFile(saveFileName);
        if (saveFile.is_open()) {
            saveFile << gameData;
            saveFile.close();
            std::cout << "Game state saved to " << saveFileName << std::endl;
        } else {
            std::cerr << "Error: Unable to save game state to " << saveFileName << std::endl;
        }
    }

    void SaveAuto() {
        std::string autoSaveFileName = "auto_save.sav";
        // Assume gameData is the current game state
        SaveGame(autoSaveFileName, gameData);
    }

    void DeleteSave(const std::string& saveFileName) {
        if (std::filesystem::exists(saveFileName)) {
            std::filesystem::remove(saveFileName);
            std::cout << "Save file " << saveFileName << " and its associated directory deleted successfully" << std::endl;
        } else {
            std::cerr << "Error: Save file " << saveFileName << " does not exist" << std::endl;
        }
    }

private:
    std::string gameData;  // Assume this member variable holds the current game state
};
