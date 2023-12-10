#include <iostream>
using namespace std;

int main() {
    int items;
    double totalValue = 0.0;

    cout << "Enter the number of items: ";
    cin >> items;

    while (items <= 0) {
        cout << "Number of items must be greater than 0. Enter a valid number: ";
        cin >> items;
    }

    for (int index = 0; index < items; index++) {
        double temp_v;
        cout << "Enter the value of item " << index + 1 << ": ";
        cin >> temp_v;

        while (temp_v <= 0) {
            cout << "Value must be greater than 0. Enter a valid value for item " << index + 1 << ": ";
            cin >> temp_v;
        }

        totalValue += temp_v;
    }

    cout << "Total value of all items: " << totalValue << endl;

    return 0;
}
