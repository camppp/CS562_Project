#include <iostream>
using namespace std;

int main() {
    float num1, num2, num3, sum, diff, prod, quot, average;

    cout << "Hello. Welcome to the OPERATIONS program.\n";
    cout << "Please enter three numbers to use this program.\n";
    cout << "(This program will calculate the sum, difference, product and quotient of the first two numbers.\n";
    cout << "The program will then calculate the average of all three numbers.)\n\n";

    cout << "Please enter the first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter the second number: ";
    while (!(cin >> num2)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter the third number: ";
    while (!(cin >> num3)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quot = num1 / num2;
    average = (num1 + num2 + num3) / 3;

    cout << "\nResults:\n";
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;
    cout << "Average: " << average << endl;

    return 0;
}
