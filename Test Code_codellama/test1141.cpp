#include <iostream>
#include <string>

using namespace std;

int main() {
    // Prompt the user to enter three numbers
    cout << "Enter three numbers: ";
    string input;
    cin >> input;

    // Check if the input is valid
    if (input.empty()) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Convert the input to a number
    int num1, num2, num3;
    try {
        num1 = stoi(input);
    } catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Prompt the user to enter the second number
    cout << "Enter the second number: ";
    cin >> input;

    // Check if the input is valid
    if (input.empty()) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Convert the input to a number
    try {
        num2 = stoi(input);
    } catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Prompt the user to enter the third number
    cout << "Enter the third number: ";
    cin >> input;

    // Check if the input is valid
    if (input.empty()) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Convert the input to a number
    try {
        num3 = stoi(input);
    } catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter three numbers." << endl;
        return 1;
    }

    // Calculate the sum, difference, product, quotient, and average of the three numbers
    int sum = num1 + num2 + num3;
    int diff = num1 - num2 - num3;
    int prod = num1 * num2 * num3;
    double quot = (double)num1 / (double)num2 / (double)num3;
    double avg = (double)(sum + diff + prod) / 3.0;

    // Display the calculated results
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;
    cout << "Average: " << avg << endl;

    return 0;
}
