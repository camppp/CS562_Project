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

int main() {
    TitForTatStrategy player;
    std::cout << "Strategy Name: " << player.getStrategyName() << std::endl;
    std::cout << "Player's choice for the current round: " << player.makeChoice('D') << std::endl; // Example usage
    return 0;
}
