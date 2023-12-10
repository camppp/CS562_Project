#include <iostream>

class GameCharacter {
public:
    uint32 Heal_Timer;

    void UpdateAI(const uint32 diff) {
        // Decrease the Heal_Timer by the time difference
        if (Heal_Timer >= diff) {
            Heal_Timer -= diff;
        } else {
            // If the Heal_Timer has elapsed, perform healing action
            PerformHealingAction();
            // Reset the Heal_Timer for the next healing event
            Heal_Timer = 2000;  // Reset to the default healing interval
        }
    }

    void PerformHealingAction() {
        // Placeholder for the healing action, e.g., restoring health points
        std::cout << "Character is healing itself" << std::endl;
    }
};

int main() {
    GameCharacter character;
    character.Heal_Timer = 2000;  // Set the initial healing timer

    // Simulate game loop with regular calls to UpdateAI
    for (int i = 0; i < 10; ++i) {
        character.UpdateAI(1000);  // Simulate a time difference of 1000 milliseconds
    }

    return 0;
}
