#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    // Extract the repository name and star range from the input
    std::string reponame;
    int lower_bound, upper_bound;
    std::stringstream ss(input);
    ss >> reponame >> lower_bound >> upper_bound;

    // Print the extracted repository name
    std::cout << "Repository Name: " << reponame << std::endl;

    // Print all the integers within the star range (inclusive of the upper and lower bounds) in ascending order, separated by a space
    for (int i = lower_bound; i <= upper_bound; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
