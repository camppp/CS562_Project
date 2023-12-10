#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(const std::string& name) : name(name), score(0) {}

    ~Player() {
        std::cout << "Player " << name << " has been destroyed. Final score: " << score << std::endl;
    }
};

int main() {
    Player player1("Alice");
    Player player2("Bob");

    // Simulate game actions and update scores

    return 0;
}
