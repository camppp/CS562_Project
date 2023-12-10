#include <iostream>
#include <cstdlib>
using namespace std;

void displayMenu() {
    cout << "1. Explore" << endl;
    cout << "2. Inventory" << endl;
    cout << "3. Save" << endl;
    cout << "4. Quit" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You decide to explore the area." << endl;
    } else if (choice == 2) {
        cout << "You check your inventory." << endl;
    } else if (choice == 3) {
        cout << "You save the game." << endl;
    } else if (choice == 4) {
        cout << "You decide to quit the game." << endl;
        return;
    } else {
        cout << "Invalid choice. Please try again." << endl;
        displayMenu();
    }
}
