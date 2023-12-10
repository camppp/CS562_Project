#include <iostream>
#include <chrono>

class UserInterfaceLibrary {
private:
    std::chrono::milliseconds animationDuration;

public:
    void init() {
        // Initialization code
    }

    void openPanel() {
        if (animationDuration.count() == 0) {
            animationDuration = std::chrono::milliseconds(500); // Default duration
        }
        std::cout << "Opening panel with animation for " << animationDuration.count() << " milliseconds" << std::endl;
    }

    void closePanel() {
        if (animationDuration.count() == 0) {
            animationDuration = std::chrono::milliseconds(500); // Default duration
        }
        std::cout << "Closing panel with animation for " << animationDuration.count() << " milliseconds" << std::endl;
    }

    void setDuration(const std::chrono::milliseconds& duration) {
        animationDuration = duration;
    }
};

int main() {
    UserInterfaceLibrary uiLibrary;
    uiLibrary.init();
    uiLibrary.setDuration(std::chrono::milliseconds(1000)); // Set animation duration to 1000 milliseconds
    uiLibrary.openPanel();
    uiLibrary.closePanel();
    return 0;
}
