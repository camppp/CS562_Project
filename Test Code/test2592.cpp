void TFrame::startForceFeedbackEffect(int player) {
    // Implementation of startForceFeedbackEffect
    std::cout << "Starting force feedback effect for player " << player << std::endl;
}

void TFrame::setPlayerLight(int player, bool on) {
    // Implementation of setPlayerLight
    if (on) {
        std::cout << "Turning on light for player " << player << std::endl;
    } else {
        std::cout << "Turning off light for player " << player << std::endl;
    }
}
