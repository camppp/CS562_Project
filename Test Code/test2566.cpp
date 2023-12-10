#include <iostream>

enum Mode { App, Editor, Settings };

class ModeManager {
private:
    Mode m_mode;

public:
    ModeManager() : m_mode(App) {}

    void setMode(Mode mode) {
        m_mode = mode;
    }

    void updateMode(int iconIndex) {
        if (m_mode != static_cast<Mode>(iconIndex) && iconIndex >= 0) {
            setMode(static_cast<Mode>(iconIndex));
        }
    }

    void update(int delta) {
        switch (m_mode) {
            case App:
                updateAppMode(delta);
                break;
            case Editor:
                updateEditorMode(delta);
                break;
            case Settings:
                updateSettingsMode(delta);
                break;
        }
    }

    void updateAppMode(int delta) {
        // Update the active mode for App
        std::cout << "Updating App mode with delta: " << delta << std::endl;
    }

    void updateEditorMode(int delta) {
        // Update the active mode for Editor
        std::cout << "Updating Editor mode with delta: " << delta << std::endl;
    }

    void updateSettingsMode(int delta) {
        // Update the active mode for Settings
        std::cout << "Updating Settings mode with delta: " << delta << std::endl;
    }
};

int main() {
    ModeManager modeManager;
    int iconIndex = 1; // Example icon index
    modeManager.updateMode(iconIndex);
    modeManager.update(10); // Example delta value
    return 0;
}
