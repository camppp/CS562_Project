#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    std::vector<int> frequencies(11, 0); // Initialize a vector to store the frequencies of sums 2 to 12

    const int numRolls = 1000; // Specify the number of times to roll the dice

    for (int i = 0; i < numRolls; ++i)
    {
        int dice1 = std::rand() % 6 + 1; // Roll the first die
        int dice2 = std::rand() % 6 + 1; // Roll the second die
        int sum = dice1 + dice2; // Calculate the sum of the two dice
        frequencies[sum - 2]++; // Increment the frequency for the corresponding sum
    }

    // Output the frequencies of each sum
    for (int i = 0; i < frequencies.size(); ++i)
    {
        std::cout << "Sum " << i + 2 << " occurred " << frequencies[i] << " times" << std::endl;
    }

    return 0;
}
