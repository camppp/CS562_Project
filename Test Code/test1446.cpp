#include <iostream>
#include <cstdlib>
using namespace std;

void displayMenu() {
    cout << "1. Explore" << endl;
    cout << "2. Inventory" << endl;
    cout << "3. Save" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Exploring the surroundings..." << endl;
                break;
            case 2:
                cout << "Inventory: Sword, Shield, Health Potion" << endl;
                break;
            case 3:
                cout << "Game saved successfully." << endl;
                break;
            case 4:
                cout << "Farewell! Exiting the game." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != 4) {
            cout << "Press any key to continue..." << endl;
            system("pause>nul");
        }

    } while (choice != 4);

    return 0;
}
