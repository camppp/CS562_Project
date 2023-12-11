#include <iostream>

class TFrame {
public:
    void startForceFeedbackEffect(int player);
    void stopForceFeedbackEffect(int player);
    void setPlayerLight(int player, bool on);
};

void TFrame::startForceFeedbackEffect(int player) {
    // Initiate the force feedback effect for the specified player
    std::cout << "Starting force feedback effect for player " << player << std::endl;
}

void TFrame::stopForceFeedbackEffect(int player) {
    // Stop the force feedback effect for the specified player
    std::cout << "Stopping force feedback effect for player " << player << std::endl;
}

void TFrame::setPlayerLight(int player, bool on) {
    // Turn the player light on or off for the specified player
    if (on) {
        std::cout << "Turning player light on for player " << player << std::endl;
    } else {
        std::cout << "Turning player light off for player " << player << std::endl;
    }
}

int main() {
    TFrame frame;
    frame.startForceFeedbackEffect(1);
    frame.setPlayerLight(2, true);
    frame.setPlayerLight(1, false);
    frame.stopForceFeedbackEffect(2);
    return 0;
}
