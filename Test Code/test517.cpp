#include <iostream>
#include <string>

class TitForTatStrategy {
public:
    std::string getStrategyName() {
        return "TitForTat";
    }

    char makeChoice(char opponentPreviousChoice) {
        if (opponentPreviousChoice == '\0') {
            return 'C'; // Cooperate in the first round
        } else {
            return opponentPreviousChoice; // Mimic opponent's previous choice
        }
    }
};
