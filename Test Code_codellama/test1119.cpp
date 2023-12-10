#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Die {
public:
    int roll() {
        return rand() % 6 + 1;
    }
};

class Roll {
private:
    int dice1Value;
    int dice2Value;
public:
    Roll(int d1, int d2) : dice1Value(d1), dice2Value(d2) {}
    void display() {
        cout << "Dice 1: " << dice1Value << ", Dice 2: " << dice2Value << endl;
    }
};

int main() {
    srand(time(0));
    Die dice1;
    Die dice2;
    vector<Roll> rollVector;

    for (int i = 0; i < 20; i++) {
        int dice1Value = dice1.roll();
        int dice2Value = dice2.roll();
        Roll roll(dice1Value, dice2Value);
        rollVector.push_back(roll);
    }

    for (const auto& roll : rollVector) {
        roll.display();
    }

    return 0;
}
