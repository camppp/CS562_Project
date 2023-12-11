#include <iostream>

int main() {
    // Prompt the user to input the number of items
    std::cout << "Enter the number of items: ";
    int numItems;
    std::cin >> numItems;

    // Initialize an array to store the values of each item
    int values[numItems];

    // Loop through each item and prompt the user to enter the value
    for (int i = 0; i < numItems; i++) {
        std::cout << "Enter the value for item " << i + 1 << ": ";
        int value;
        std::cin >> value;

        // Validate the input to ensure that the value is greater than 0
        while (value <= 0) {
            std::cout << "Invalid input. Please enter a positive value: ";
            std::cin >> value;
        }

        // Store the valid value in the array
        values[i] = value;
    }

    // Calculate the total value of all the items
    int totalValue = 0;
    for (int i = 0; i < numItems; i++) {
        totalValue += values[i];
    }

    // Display the total value of all the items
    std::cout << "The total value of all the items is: " << totalValue << std::endl;

    return 0;
}
