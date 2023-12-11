#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Prompt the user to input their choice
    cout << "Enter your choice (rock, paper, or scissors): ";
    string userChoice;
    cin >> userChoice;

    // Generate a random choice for the computer
    srand(time(0));
    int computerChoice = rand() % 3;

    // Compare the user's choice with the computer's choice
    if (userChoice == "rock" && computerChoice == 0) {
        cout << "The user wins!" << endl;
    } else if (userChoice == "paper" && computerChoice == 1) {
        cout << "The user wins!" << endl;
    } else if (userChoice == "scissors" && computerChoice == 2) {
        cout << "The user wins!" << endl;
    } else if (userChoice == "rock" && computerChoice == 1) {
        cout << "The computer wins!" << endl;
    } else if (userChoice == "paper" && computerChoice == 2) {
        cout << "The computer wins!" << endl;
    } else if (userChoice == "scissors" && computerChoice == 0) {
        cout << "The computer wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    // Wait for the user to press a key before exiting
    cout << "Press any key to continue...";
    cin.ignore();
    return 0;
}
