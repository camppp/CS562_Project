#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    string choices[] = {"rock", "paper", "scissors"};
    int computerChoice = rand() % 3;  // Generate a random choice for the computer

    string userChoice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> userChoice;

    // Convert user's choice to lowercase for case-insensitive comparison
    for (char &c : userChoice) {
        c = tolower(c);
    }

    // Validate user's input
    if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
        cout << "Invalid choice. Please enter rock, paper, or scissors." << endl;
        system("pause");
        return 0;
    }

    cout << "You chose: " << userChoice << endl;
    cout << "Computer chose: " << choices[computerChoice] << endl;

    // Compare choices to determine the winner
    if (userChoice == choices[computerChoice]) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == "rock" && choices[computerChoice] == "scissors") ||
               (userChoice == "scissors" && choices[computerChoice] == "paper") ||
               (userChoice == "paper" && choices[computerChoice] == "rock")) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    system("pause");  // Wait for user to press a key before exiting
    return 0;
}
