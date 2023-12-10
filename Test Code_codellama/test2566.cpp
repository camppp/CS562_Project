class ModeManager {
public:
    ModeManager() {
        // Initialize the active mode to App
        activeMode = Mode::App;
    }

    void setMode(int iconIndex) {
        // Update the active mode based on the selected icon index
        switch (iconIndex) {
            case 0:
                activeMode = Mode::App;
                break;
            case 1:
                activeMode = Mode::Editor;
                break;
            case 2:
                activeMode = Mode::Settings;
                break;
        }
    }

    void updateMode() {
        // Update the active mode based on the selected icon index
        switch (activeMode) {
            case Mode::App:
                updateApp();
                break;
            case Mode::Editor:
                updateEditor();
                break;
            case Mode::Settings:
                updateSettings();
                break;
        }
    }

    void updateApp() {
        // Perform specific updates for the App mode
    }

    void updateEditor() {
        // Perform specific updates for the Editor mode
    }

    void updateSettings() {
        // Perform specific updates for the Settings mode
    }

private:
    enum class Mode {
        App,
        Editor,
        Settings
    };

    Mode activeMode;
};
