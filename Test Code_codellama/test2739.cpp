#include <iostream>

// Define the memory modes
const int MODE_1 = 1;
const int MODE_2 = 2;
const int MODE_3 = 3;

// Define the default memory mode
const int DEFAULT_MODE = MODE_1;

// Define the memory mode control system
class MemoryModeControl {
public:
    // Set the current memory mode
    void setMemoryMode(int mode) {
        currentMode = mode;
    }

    // Get the current memory mode
    int getMemoryMode() {
        return currentMode;
    }

    // Reset the current memory mode to the default
    void resetMemoryMode() {
        currentMode = DEFAULT_MODE;
    }

private:
    // The current memory mode
    int currentMode = DEFAULT_MODE;
};

int main() {
    // Create a memory mode control system
    MemoryModeControl mmc;

    // Set the current memory mode to MODE_1
    mmc.setMemoryMode(MODE_1);

    // Get the current memory mode
    std::cout << "Current memory mode: " << mmc.getMemoryMode() << std::endl;

    // Set the current memory mode to MODE_2
    mmc.setMemoryMode(MODE_2);

    // Get the current memory mode
    std::cout << "Current memory mode: " << mmc.getMemoryMode() << std::endl;

    // Reset the current memory mode to the default
    mmc.resetMemoryMode();

    // Get the current memory mode
    std::cout << "Current memory mode: " << mmc.getMemoryMode() << std::endl;

    return 0;
}
