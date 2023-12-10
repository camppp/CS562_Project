#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int owner_id;
    std::string name, info, all;
    float val;

    std::cout << "Enter owner id: ";
    std::cin >> owner_id;

    std::cout << "Enter owner's name: ";
    std::cin.ignore(); // Ignore the newline character in the input buffer
    std::getline(std::cin, name);

    std::cout << "Enter additional information: ";
    std::getline(std::cin, info);

    std::cout << "Enter value in floating point integer fixed up to 2 decimal places: ";
    std::cin >> std::setprecision(2) >> val;

    // Construct the formatted output
    all = "Owner ID: " + std::to_string(owner_id) + "\n"
          + "Name: " + name + "\n"
          + "Additional Information: " + info + "\n"
          + "Asset Value: " + std::to_string(val) + "\n";

    // Display the entered information
    std::cout << "\nEntered Information:\n" << all;

    return 0;
}
